value = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'x': 10
}


def is_valid(isbn):
    isbn = isbn.replace('-', '').lower()
    if(len(isbn) != 10):
        return False
    s = 0
    d = 10
    for c in isbn:
        i = value.get(c)
        if i is None:
            return False

        if d != 1 and i > 9:
            return False
            
        s += d*i
        d -= 1
    return s % 11 == 0
