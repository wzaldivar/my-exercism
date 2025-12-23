prev_pair = {
    ')': '(',
    ']': '[',
    '}': '{'
}


def is_paired(input_string):
    prev = []
    for char in input_string:
        if char in prev_pair.values():
            prev.append(char)
        elif char in prev_pair.keys():
            if len(prev) > 0 and prev[-1] == prev_pair[char]:
                prev.pop()
            else:
                return False
    return len(prev) == 0
