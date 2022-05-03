
def main():
    a = [1, 2, 3, 4, 7, 8, 9]
    b = [4, 5, 6, 7, 9]
    print(common(a, b))


def common(a, b):
    c = []
    for i in a:
        if i in b:
            c.append(i)
    return c


main()
