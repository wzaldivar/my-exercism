def convert(number):
    result = ''

    divides = False

    if number % 3 == 0:
        divides = True
        result += 'Pling'

    if number % 5 == 0:
        divides = True
        result += 'Plang'

    if number % 7 == 0:
        divides = True
        result += 'Plong'

    if not divides:
        result += str(number)

    return result
