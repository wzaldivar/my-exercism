pub fn find<T, A>(data: A, key: T) -> Option<usize>
where
    T: PartialOrd + PartialEq,
    A: AsRef<[T]>,
{
    let data = data.as_ref();

    if data.is_empty() {
        return None;
    }

    let mut start: usize = 0;
    let mut end: usize = data.len() - 1;
    let mut index: usize;

    while start <= end {
        index = start + (end - start) / 2;
        if data[index] == key {
            return Some(index);
        } else if data[index] > key {
            if index == 0 {
                break;
            }
            end = index - 1;
        } else {
            start = index + 1;
        }
    }

    None
}
