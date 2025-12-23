"""
An [Armstrong number](https://en.wikipedia.org/wiki/Narcissistic_number) 
is a number that is the sum of its own digits each raised to the power of the number of digits.
"""

def is_armstrong_number(number):
    """
    :param number: int - number to be checked
    :return: bool - is Armstrong number
    """
    if number == 0:
        return True

    number_of_digits = 0
    digits = []

    current_number = number
    while(current_number > 0):
        number_of_digits += 1
        digits.append(current_number % 10)
        current_number = current_number // 10

    sum = 0
    for digit in digits:
        sum += digit**number_of_digits

    return number == sum
