#[derive(Debug, PartialEq, Eq)]
pub enum Error {
    NotEnoughPinsLeft,
    GameComplete,
}

#[derive(Debug, PartialEq, Eq, Clone, Copy)]
enum FrameType {
    Open,
    Spare,
    Strike,
}

struct Frame {
    frame_type: Option<FrameType>,
    pins_up: u16,
    rolls: Vec<u16>,
}

struct FillBalls {
    max_rolls: usize,
    pins_up: u16,
    rolls: Vec<u16>,
}

pub struct BowlingGame {
    frames: Vec<Frame>,
    fill_balls: Option<FillBalls>,
}

impl Frame {
    fn new() -> Self {
        Frame {
            frame_type: None,
            pins_up: 10,
            rolls: Vec::new(),
        }
    }

    fn is_complete(&self) -> bool {
        self.frame_type.is_some()
    }

    pub fn roll(&mut self, pins: u16) -> Result<(), Error> {
        if self.is_complete() {
            return Err(Error::GameComplete);
        }

        if self.pins_up < pins {
            return Err(Error::NotEnoughPinsLeft);
        }

        self.pins_up -= pins;
        self.rolls.push(pins);

        if self.pins_up == 0 {
            if self.rolls.len() == 1 {
                self.frame_type = Some(FrameType::Strike);
            } else {
                self.frame_type = Some(FrameType::Spare);
            }
        } else if self.rolls.len() == 2 {
            self.frame_type = Some(FrameType::Open);
        }

        Ok(())
    }
}

impl FillBalls {
    fn new(last_type: FrameType) -> Self {
        let expected_rolls = match last_type {
            FrameType::Strike => 2,
            FrameType::Spare => 1,
            _ => 0,
        };

        FillBalls {
            max_rolls: expected_rolls,
            pins_up: 10,
            rolls: Vec::new(),
        }
    }

    fn is_complete(&self) -> bool {
        self.rolls.len() == self.max_rolls
    }

    fn roll(&mut self, pins: u16) -> Result<(), Error> {
        if self.is_complete() {
            return Err(Error::GameComplete);
        }

        if self.pins_up < pins {
            return Err(Error::NotEnoughPinsLeft);
        }

        self.pins_up -= pins;
        self.rolls.push(pins);

        if self.pins_up == 0 {
            self.pins_up = 10;
        }

        Ok(())
    }
}

impl BowlingGame {
    pub fn new() -> Self {
        BowlingGame {
            frames: vec![Frame::new()],
            fill_balls: None,
        }
    }

    fn all_frames_complete(&self) -> bool {
        self.frames.len() == 10 && self.frames.last().unwrap().is_complete()
    }

    fn fill_balls_complete(&self) -> bool {
        (self.frames.last().unwrap().frame_type.unwrap() == FrameType::Open
            && self.fill_balls.is_none())
            || self.fill_balls.as_ref().is_some_and(|fill_balls| fill_balls.is_complete())
    }

    fn is_complete(&self) -> bool {
        self.all_frames_complete() && self.fill_balls_complete()
    }

    pub fn roll(&mut self, pins: u16) -> Result<(), Error> {
        if self.all_frames_complete()
            && self.frames.last().unwrap().frame_type.unwrap() != FrameType::Open
            && self.fill_balls.is_none()
        {
            self.fill_balls = Some(FillBalls::new(
                self.frames.last().unwrap().frame_type.unwrap(),
            ));
        }

        if self.is_complete() {
            return Err(Error::GameComplete);
        }

        if self.frames.last().unwrap().is_complete() && self.frames.len() < 10 {
            self.frames.push(Frame::new());
        }

        if self.fill_balls.is_some() {
            return self.fill_balls.as_mut().unwrap().roll(pins);
        }

        self.frames.last_mut().unwrap().roll(pins)
    }

    pub fn score(&self) -> Option<u16> {
        if !self.is_complete() {
            return None;
        }

        let mut score = 0;

        let mut prev_prev_frame_type: Option<FrameType> = None;
        let mut prev_frame_type: Option<FrameType> = None;

        self.frames.iter().for_each(|frame| {
            if prev_frame_type.is_some_and(|frame_type: FrameType| frame_type == FrameType::Spare) {
                score += frame.rolls[0];
            }

            if prev_prev_frame_type.is_some_and(|frame_type: FrameType| frame_type == FrameType::Strike) {
                score += frame.rolls[0];
            }

            if prev_frame_type.is_some_and(|frame_type: FrameType| frame_type == FrameType::Strike)
            {
                score += frame.rolls.iter().sum::<u16>();
            }

            score += frame.rolls.iter().sum::<u16>();
            prev_prev_frame_type = prev_frame_type;
            prev_frame_type = frame.frame_type;
        });

        if self.fill_balls.is_some() {
            if prev_prev_frame_type.is_some_and(|frame_type: FrameType| frame_type == FrameType::Strike) {
                score += self.fill_balls.as_ref().unwrap().rolls[0];
            }

            score += self.fill_balls.as_ref().unwrap().rolls.iter().sum::<u16>();
        }

        Some(score)
    }
}
