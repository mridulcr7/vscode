# return list squaring each element in list
def main():
    a=[1,3,5,7]
    a=square(a)
    print(a)
def square(a):
    for i in range(0,len(a)):
        a[i]=a[i]*a[i]
    return a
main()        



