#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn is_sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> bool {
    if _first_list.is_empty() {
        return true;
    }

    _second_list
        .windows(_first_list.len())
        .any(|window| window == _first_list)
}

pub fn sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> Comparison {
    let first_len = _first_list.len();
    let second_len = _second_list.len();

    if first_len == second_len {
        match _first_list == _second_list {
            true => Comparison::Equal,
            false => Comparison::Unequal,
        }
    } else if first_len < second_len {
        match is_sublist(_first_list, _second_list) {
            true => Comparison::Sublist,
            false => Comparison::Unequal,
        }
    } else {
        match is_sublist(_second_list, _first_list) {
            true => Comparison::Superlist,
            false => Comparison::Unequal,
        }
    }
}
