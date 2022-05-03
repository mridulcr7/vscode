def palindrome(str):
    rev=str[-1::-1]
    if(rev==str):
        print("palindrome")
    else:
        print("not palindrome")    

name=input("Enter the string\n")
palindrome(name)        