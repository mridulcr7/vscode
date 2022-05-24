#reverse a list
# return list squaring each element in list
def main():
    a = [1, 3, 5, 7]
    a = reverse(a)
    print(a)


def reverse(a):
    b=[]
    while(len(a)):
        b.append(a.pop())
    return b    

main()
