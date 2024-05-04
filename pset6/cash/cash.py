from cs50 import get_float


def main():
    cash = get_positive()
    print(minimunCurrency(cash))


# functions
def minimunCurrency(cash):
    cents = round(cash * 100)
    sum = 0

    for coin in [25, 10, 5, 1]:
        sum += cents // coin
        cents %= coin

    return sum


def get_positive():
    while True:
        n = get_float("Change woed: ")
        if n > 0:
            break
    return n


main()
