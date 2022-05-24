
def main():
    a = [1, 2, [3, 4], [8, 4, 7], 9]
    print(no(a))

def no(a):
    c = 0
    b=[]
    for i in a:
        if type(i) == type(b):
            c=c+1
    return c    

main()
