from cs50 import get_int

def main():
    height = get_positive()
    
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        bricks = "#" * i
        print(f"{spaces}{bricks}")


def get_positive():
    while True:
        n = get_int("Height: ")
        if 0 < n < 9:
            break
    return n


main()
