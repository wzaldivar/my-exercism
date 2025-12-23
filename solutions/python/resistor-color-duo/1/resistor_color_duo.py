color_values = {
    "black": 0,
    "brown": 1,
    "red": 2,
    "orange": 3,
    "yellow": 4,
    "green": 5,
    "blue": 6,
    "violet": 7,
    "grey": 8,
    "white": 9
}


def value(colors):
    if len(colors) == 0:
        return 0
    if len(colors) == 1:
        return color_values[colors[0]]
    return color_values[colors[0]] * 10 + color_values[colors[1]]
