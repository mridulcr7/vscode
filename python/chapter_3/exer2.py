name = input("Enter name\n")
age = int(input("Enter age\n"))
if (name[0] == 'a' or name[0] == 'A') and (age > 19):
    print("You can watch the movie")
else:
    print("You can't watch")
