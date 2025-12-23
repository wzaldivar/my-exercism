def triangle_inequality(sides):
    return sides[0]+sides[1] >= sides[2] and sides[0]+sides[2] >= sides[1] and sides[1]+sides[2] >= sides[0]

def all_zero(sides):
    return sides[0] == 0 and sides[1] == 0 and sides[2] == 0

def equilateral(sides):
    if not triangle_inequality(sides) or all_zero(sides):
        return False
    return sides[0] == sides[1] and sides[1] == sides[2]


def isosceles(sides):
    if not triangle_inequality(sides) or all_zero(sides):
        return False
    return sides[0] == sides[1] or sides[0] == sides[2] or sides [1] == sides[2]


def scalene(sides):
    if not triangle_inequality(sides) or all_zero(sides):
        return False
    return sides[0] != sides[1] and sides[0] != sides[2] and sides [1] != sides[2]
