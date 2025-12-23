def __rotate(word, index):
    return word[index:] + word[:index]


def translate(text):
    words = text.split()

    for word_index in range(len(words)):
        first_vowel_index = -1

        word_len = len(words[word_index])
        vowel_index = 0

        while first_vowel_index < 0 and vowel_index < word_len:
            if words[word_index][vowel_index] in ('a', 'e', 'i', 'o', 'u'):
                first_vowel_index = vowel_index
            vowel_index += 1

        if first_vowel_index != 0:
            # rule 1
            if words[word_index].find('xr') == 0 or words[word_index].find('yt') == 0:
                pass
            else:
                y_index = words[word_index][:first_vowel_index].find('y') if first_vowel_index > 1 else words[
                    word_index].find('y')
                # rule 4
                if y_index > 0:
                    words[word_index] = __rotate(words[word_index], y_index)
                # rule 3
                elif first_vowel_index > 0 and words[word_index][first_vowel_index] == 'u' \
                        and words[word_index][first_vowel_index - 1] == 'q':
                    words[word_index] = __rotate(words[word_index], first_vowel_index + 1)
                # rule 2
                elif first_vowel_index > 0:
                    words[word_index] = __rotate(words[word_index], first_vowel_index)

        words[word_index] += 'ay'

    return ' '.join(words)
