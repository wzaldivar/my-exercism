def response(hey_bob):
    if len(hey_bob.strip()) == 0 :
        return "Fine. Be that way!"

    upper = hey_bob.isupper()

    if hey_bob.strip()[-1] == '?':
        
        if upper:
            return "Calm down, I know what I'm doing!"

        return "Sure."
    
    if upper:
        return "Whoa, chill out!"

    return "Whatever."
