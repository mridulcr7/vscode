import random

win=random.randint(1,100)
i=1

while True:
    n = int(input("guess the no.\n"))
    if n>win:
        print("Too high")
    elif n<win:
        print("Too low")
    else:
        print(f"you win in {i}th attempt")
        break
    i=i+1