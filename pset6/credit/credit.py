from cs50 import get_int


def main():
    card = str(get_card())

    if check_card(card):
        return print(get_card_types(card))
    return "INVALID"




# function
def get_card():
    while True:
        n = get_int("Number: ")
        if len(str(n)) > 9:
            break
    return n


def check_card(card):
    sum = 0
    for n in range(len(card) - 2, -1, -2):
        digit = int(card[n]) * 2
        if digit > 9:
            digit -= 9
        sum += digit
    for n in range(len(card) - 1, -1, -2):
        sum += int(card[n])
    return True if sum % 10 == 0 else print("INVALID")


def get_card_types(card):
    first_two_digits = int(card[:2])

    if first_two_digits in range(34, 38):
        return "AMEX"
    if first_two_digits in range(51, 56):
        return "MASTERCARD"
    if first_two_digits // 10 == 4:
        return "VISA"
    else:
        return "INVALID"


main()
