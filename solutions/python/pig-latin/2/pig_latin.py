def __rotate(word, index):
    return word[index:] + word[:index]


def translate(text):
    words = text.split()

    for i in range(len(words)):
        first_vowel = None
        first_vowel_index = -1

        for vowel in ('a', 'e', 'i', 'o', 'u'):
            index = words[i].find(vowel)
            if first_vowel_index < 0 <= index or 0 <= index < first_vowel_index:
                first_vowel_index = index
                first_vowel = vowel

        if first_vowel_index != 0:
            # rule 1
            if words[i].find('xr') == 0 or words[i].find('yt') == 0:
                pass
            else:
                y_index = words[i][:first_vowel_index].find('y') if first_vowel_index > 1 else words[i].find('y')
                # rule 4
                if y_index > 0:
                    words[i] = __rotate(words[i], y_index)
                # rule 3
                elif first_vowel_index > 0 and first_vowel == 'u' and words[i][first_vowel_index - 1] == 'q':
                    words[i] = __rotate(words[i], first_vowel_index + 1)
                # rule 2
                elif first_vowel_index > 0:
                    words[i] = __rotate(words[i], first_vowel_index)

        words[i] += 'ay'

    return ' '.join(words)
