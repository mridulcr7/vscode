#reverse a list
# return list squaring each element in list
def main():
    a = [1,2,3,4,5,6,7,8,9]
    print(filter(a))


def filter(a):
    b=[[],[]]
    for i in a:
        if i%2==0:
            b[0].append(i)
        else:
            b[1].append(i)    
    return b


main()
