def color_code(color):
    index = 0
    for m_color in colors():
        if m_color == color:
            return index
        index += 1
    return -1


def colors():
    return [
        "black",
        "brown",
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "violet",
        "grey",
        "white",
    ]
