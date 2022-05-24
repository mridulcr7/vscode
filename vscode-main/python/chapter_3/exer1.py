import random
n=random.randint(0,10)
user=int(input("enter the number\n"))
if n==user:
    print("YOU WIN")
elif user<n:
    print("TOO LOW")
else:
    print("TOO HIGH")        