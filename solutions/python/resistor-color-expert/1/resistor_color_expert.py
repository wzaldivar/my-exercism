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

color_tolerance = {
    'grey': '0.05%',
    'violet': '0.1%',
    'blue': '0.25%',
    'green': '0.5%',
    'brown': '1%',
    'red': '2%',
    'gold': '5%',
    'silver': '10%'
}

ohms_label = {
    9: 'giga',
    6: 'mega',
    3: 'kilo',
}


def resistor_label(colors):
    if len(colors) == 1:
        return '0 ohms'

    colors_input = []
    colors_input.extend(colors)
    colors_input.reverse()

    tolerance = color_tolerance[colors_input[0]]
    multiplier = 10 ** color_number[colors_input[1]]

    i = 0
    value = 0
    for color in colors_input[2:]:
        value += color_number[color] * 10 ** i
        i += 1

    value *= multiplier

    for key in ohms_label.keys():
        base = 10 ** key
        if value >= base:
            if value % base == 0:
                return '{} {}ohms ±{}'.format(value // base, ohms_label[key], tolerance)
            else:
                return '{} {}ohms ±{}'.format(value / base, ohms_label[key], tolerance)
    return '{} ohms ±{}'.format(value, tolerance)