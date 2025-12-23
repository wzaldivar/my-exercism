"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language: https://en.wikipedia.org/wiki/Guido_van_Rossum
"""

EXPECTED_BAKE_TIME = 40
"""constant that returns how many minutes the lasagna should bake in the oven"""

PREPARATION_TIME = 2
"""constant equal to the time it takes to prepare a single layer"""


def bake_time_remaining(elapsed_bake_time):
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - elapsed_bake_time


def preparation_time_in_minutes(number_of_layers):
    """
    Calculate preparation time in minutes

    :param number_of_layers: int - the number of layers you want to add to the lasagna
    :return: int - how many minutes you would spend making them

    Function that takes the number of layers you want to add to the lasagna as an argument
    and returns how many minutes you would spend making them.
    """
    return PREPARATION_TIME * number_of_layers

def elapsed_time_in_minutes(number_of_layers, elapsed_bake_time):
    """
    Calculate total elapsed cooking time (prep + bake) in minutes

    :param number_of_layers: int - the number of layers added to the lasagna
    :param elapsed_bake_time: int - the number of minutes the lasagna has been baking in the oven
    :return: int - the total number of minutes you've been cooking

    Function that has two parameters: number_of_layers (the number of layers added to the lasagna)
    and elapsed_bake_time (the number of minutes the lasagna has been baking in the oven).
    This function should return the total number of minutes you've been cooking,
    or the sum of your preparation time and the time the lasagna has already spent baking in the oven.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time
