def is_paired(input_string):
    prev = []
    for char in input_string:
        if char == '(' or char == '[' or char == '{':
            prev.append(char)
        elif char == ')':
            if len(prev) > 0 and prev[-1] == '(':
                prev.pop()
            else:
                return False
        elif char == ']':
            if len(prev) > 0 and prev[-1] == '[':
                prev.pop()
            else:
                return False
        elif char == '}':
            if len(prev) > 0 and prev[-1] == '{':
                prev.pop()
            else:
                return False
    return len(prev) == 0
