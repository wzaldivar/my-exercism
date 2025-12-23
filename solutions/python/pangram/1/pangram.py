from operator import le


def is_pangram(sentence):
    chars = set()
    for c in range(ord('a'), ord('z')+1):
        chars.add(chr(c))

    if(len(sentence) < len(chars)):
        return False

    sentence = sentence.lower()
    for c in sentence:
        chars.discard(c)

    return len(chars) == 0
