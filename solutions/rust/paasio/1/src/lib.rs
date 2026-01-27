use std::io::{Read, Result, Write};
// the PhantomData instances in this file are just to stop compiler complaints
// about missing generics; feel free to remove them

pub struct ReadStats<R> {
    reads_number: usize,
    read_bytes: usize,
    data: R,
}

impl<R: Read> ReadStats<R> {
    // _wrapped is ignored because R is not bounded on Debug or Display and therefore
    // can't be passed through format!(). For actual implementation you will likely
    // wish to remove the leading underscore so the variable is not ignored.
    pub fn new(_wrapped: R) -> ReadStats<R> {
        ReadStats {
            reads_number: 0,
            read_bytes: 0,
            data: _wrapped,
        }
    }

    pub fn get_ref(&self) -> &R {
        &self.data
    }

    pub fn bytes_through(&self) -> usize {
        self.read_bytes
    }

    pub fn reads(&self) -> usize {
        self.reads_number
    }
}

impl<R: Read> Read for ReadStats<R> {
    fn read(&mut self, buf: &mut [u8]) -> Result<usize> {
        self.reads_number += 1;
        let current_read_bytes = self.data.read(buf)?;
        self.read_bytes += current_read_bytes;
        Ok(current_read_bytes)
    }
}

pub struct WriteStats<W> {
    data: W,
    written_bytes: usize,
    writes_number: usize,
}

impl<W: Write> WriteStats<W> {
    // _wrapped is ignored because W is not bounded on Debug or Display and therefore
    // can't be passed through format!(). For actual implementation you will likely
    // wish to remove the leading underscore so the variable is not ignored.
    pub fn new(_wrapped: W) -> WriteStats<W> {
        WriteStats {
            data: _wrapped,
            written_bytes: 0,
            writes_number: 0,
        }
    }

    pub fn get_ref(&self) -> &W {
        &self.data
    }

    pub fn bytes_through(&self) -> usize {
        self.written_bytes
    }

    pub fn writes(&self) -> usize {
        self.writes_number
    }
}

impl<W: Write> Write for WriteStats<W> {
    fn write(&mut self, buf: &[u8]) -> Result<usize> {
        self.writes_number += 1;
        let current_written_bytes = self.data.write(buf)?;
        self.written_bytes += current_written_bytes;
        Ok(current_written_bytes)
    }

    fn flush(&mut self) -> Result<()> {
        self.data.flush()
    }
}
