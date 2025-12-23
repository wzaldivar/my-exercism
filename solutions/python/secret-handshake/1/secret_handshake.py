secrets = {
    1: 'wink',
    2: 'double blink',
    3: 'close your eyes',
    4: 'jump'
}


def commands(binary_str):
    values = []
    for key in secrets.keys():
        if binary_str[-key] == '1':
            values.append(secrets[key])
    if binary_str[0] == '1':
        values.reverse()
    return values
