# Score categories.
# Change the values as you see fit.
YACHT = "YACHT"
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = "FULL_HOUSE"
FOUR_OF_A_KIND = "FOUR_OF_A_KIND"
LITTLE_STRAIGHT = "LITTLE_STRAIGHT"
BIG_STRAIGHT = "BIG_STRAIGHT"
CHOICE = "CHOICE"


def counters(dice):
    c = {}
    for d in dice:
        if d in c.keys():
            c[d] += 1
        else:
            c[d] = 1
    
    return c


def multiply(dice, category):
    c = counters(dice)
    if category in c.keys():
        return category * c[category]

    return 0


def full_house(dice):
    c = counters(dice)
    keys = list(c.keys())
    if len(c) == 2 and (c[keys[0]] == 2 or c[keys[0]] == 3):
        return sum(dice)
    
    return 0


def four_of_a_kind(dice):
    c = counters(dice)
    print(c)
    keys = list(c.keys())
    if len(c) == 1:
        return 4 * keys[0]
    elif len(c) == 2 and (c[keys[0]] == 1 or c[keys[0]] == 4):
        if c[keys[0]] == 4:
            return 4 * keys[0]
        else:
            return 4 * keys[1]
    
    return 0


def straight(dice, category):
    c = counters(dice)
    if len(c) == 5 and ((category == LITTLE_STRAIGHT and 6 not in c.keys()) or (category == BIG_STRAIGHT  and 1 not in c.keys())):
            return 30
    return 0


def yatch(dice):
    c = counters(dice)
    if len(c) == 1:
        return 50
    else:
        return 0


def score(dice, category):
    if category == ONES or category == TWOS or category == THREES or category == FOURS or category == FIVES or category == SIXES:
        return multiply(dice, category)
    
    if category == FULL_HOUSE:
        return full_house(dice)

    if category == FOUR_OF_A_KIND:
        return four_of_a_kind(dice)

    if category == LITTLE_STRAIGHT or category == BIG_STRAIGHT:
        return straight(dice, category)

    if category == CHOICE:
        return sum(dice)

    if category == YACHT:
        return yatch(dice)
