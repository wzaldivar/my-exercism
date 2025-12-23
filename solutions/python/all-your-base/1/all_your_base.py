from unicodedata import digit


def rebase(input_base, digits, output_base):
    if input_base < 2:
        raise ValueError("input base must be >= 2")

    if output_base < 2:
        raise ValueError("output base must be >= 2")

    decimal = 0
    n = len(digits)-1
    for i in digits:
        if i < 0 or i >= input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")

        decimal += i * input_base**n
        n -= 1
    result = []
    n = 1
    while output_base**n < decimal:
        n += 1

    while n >= 0:
        digit = decimal // output_base**n
        rest = decimal % output_base**n

        if len(result) != 0 or digit != 0 or n == 0:
            result.append(digit)

        decimal = rest
        n -= 1

    return result
