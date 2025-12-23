"""
This exercise stub and the test suite contain several enumerated constants.

Since Python 2 does not have the enum module, the idiomatic way to write
enumerated constants has traditionally been a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
from operator import le
import re


SUBLIST = 10
SUPERLIST = 11
EQUAL = 0
UNEQUAL = 1


def sublist(list_one, list_two):
    len_one = len(list_one)
    len_two = len(list_two)

    if len_one == len_two:
        for i in range(len_one):
            if list_one[i] != list_two[i]:
                return UNEQUAL
        return EQUAL

    if len_one < len_two:
        if len_one == 0:
            return SUBLIST
        j = 0
        while list_one[0] in list_two[j:]:
            j += list_two[j:].index(list_one[0])
            if sublist(list_one, list_two[j:j+len_one]) == EQUAL:
                return SUBLIST
            j += 1
        return UNEQUAL

    if len_two == 0:
        return SUPERLIST

    j = 0
    while list_two[0] in list_one[j:]:
        j += list_one[j:].index(list_two[0])
        if sublist(list_one[j:j+len_two], list_two) == EQUAL:
            return SUPERLIST
        j += 1
    return UNEQUAL

    return UNEQUAL
