color_number = {
    'black': 0,
    'brown': 1,
    'red': 2,
    'orange': 3,
    'yellow': 4,
    'green': 5,
    'blue': 6,
    'violet': 7,
    'grey': 8,
    'white': 9
}

ohms_label = {
    9: 'giga',
    6: 'mega',
    3: 'kilo',
}


def label(colors):
    value = (color_number[colors[0]] * 10 + color_number[colors[1]]) * 10 ** color_number[colors[2]]
    for key in ohms_label.keys():
        base = 10 ** key
        if value % base == 0 and value >= base:
            return '{} {}ohms'.format(value // 10 ** key, ohms_label[key])
    return '{} ohms'.format(value)
