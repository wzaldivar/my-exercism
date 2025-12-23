def rotate_char(c, key, first):
    return chr(ord(first)+(ord(c)-ord(first)+key) % 26)


def rotate(text, key):
    if key % 26 == 0:
        return text

    n = len(text)

    if n == 0:
        return text

    result = [None]*n

    for i in range(n):
        if 'a' <= text[i] <= 'z':
            result[i] = rotate_char(text[i], key, 'a')
        elif 'A' <= text[i] <= 'Z':
            result[i] = rotate_char(text[i], key, 'A')
        else:
            result[i] = text[i]

    return ''.join(result)
