use std::fmt::format;

fn verse1(n: u32) -> String {
    match n {
        0 => "No more bottles of beer on the wall, no more bottles of beer.".to_string(),
        _ => {
            let s = if n > 1 { "s" } else { "" };
            format!("{n} bottle{s} of beer on the wall, {n} bottle{s} of beer.")
        }
    }
}

fn verse2(n: u32) -> String {
    match n {
        0 => "Go to the store and buy some more, 99 bottles of beer on the wall.".to_string(),
        1 => "Take it down and pass it around, no more bottles of beer on the wall.".to_string(),
        _ => format!("Take one down and pass it around, {} bottle{} of beer on the wall.",
                     n - 1,
                     if n > 2 { "s" } else { "" })
    }
}

pub fn verse(n: u32) -> String {
    format!("{}\n{}", verse1(n), verse2(n))
}

pub fn sing(start: u32, end: u32) -> String {
    let mut n = start;
    let mut ret = String::new();
    loop {
        if n != start {
            ret.push_str("\n\n");
        }
        ret.push_str(&verse(n));
        if n == end {
            break;
        }
        n -= 1;
    }
    ret
}
