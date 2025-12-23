use core::fmt;
use std::fmt::{write, Debug};

pub struct Clock {
    hours: i32,
    minutes: i32,
}

fn to_hours(hours: i32) -> i32 {
    let mut new_hours: i32 = hours;
    if new_hours < 0 {
        new_hours = -new_hours;
        new_hours = new_hours % 24;
        new_hours = 24 - new_hours;
    }

    new_hours = new_hours % 24;
    new_hours
}

fn to_clock(minutes: i32) -> Clock {
    let mut new_minutes: i32 = minutes;
    let mut new_hours: i32;
    if new_minutes < 0 {
        new_minutes = -new_minutes;
        new_hours = -(new_minutes / 60);
        new_minutes = new_minutes % 60;
        if new_minutes > 0 {
            new_hours -= 1;
        }
        new_minutes = 60 - new_minutes;
    } else {
        new_hours = new_minutes / 60;
    }

    new_minutes = new_minutes % 60;

    Clock {
        hours: new_hours,
        minutes: new_minutes,
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let clock = to_clock(minutes);
        let new_hours = to_hours(hours + clock.hours);
        Self {
            hours: new_hours,
            minutes: clock.minutes,
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let clock = to_clock(self.minutes + minutes);
        let new_hours = to_hours(self.hours + clock.hours);
        Self {
            hours: new_hours,
            minutes: clock.minutes,
        }
    }
}

impl Debug for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        return write!(f, "{:02}:{:02}", self.hours, self.minutes);
    }
}

impl ToString for Clock {
    fn to_string(&self) -> String {
        return format!("{:02}:{:02}", self.hours, self.minutes);
    }
}

impl PartialEq for Clock {
    fn eq(&self, other: &Self) -> bool {
        self.hours == other.hours && self.minutes == other.minutes
    }
}
