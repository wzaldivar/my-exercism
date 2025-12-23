"""
Calculate the number of grains of wheat on a chessboard given that the number
on each square doubles.
"""

def square(number):
    """
    :param number: int - square number
    :return: int - how many grains were on a given square
    """
    if number < 1 or number > 64:
        raise ValueError('square must be between 1 and 64')

    return 2**(number-1)


def total():
    """
    :return: int - the total number of grains on the chessboard
    """
    return 2**64-1
