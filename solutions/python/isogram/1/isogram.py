def is_isogram(string):
    string = string.lower()

    chars = set()
    counter = 0
    
    for c in string:
        if 'a' <= c <= 'z':
            counter += 1
            chars.add(c)

    return len(chars) == counter
