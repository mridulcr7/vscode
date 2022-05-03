
def main():
    a = ['mridul', 'akshay', 'arth', 'kalash','anuj']
    a = reverse(a)
    print(a)


def reverse(a):
    for i in range(0,len(a)):
        str=a[i][-1::-1]
        a[i]=str
    return a    

main()
