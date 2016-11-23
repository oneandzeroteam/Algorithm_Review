for i in range(int(input())):
    n, k = input().split()
    li = list(range(1, int(n) + 1))
    k = int(k)
    index = 0

    while len(li) > 2:
        del li[index]
        index = (index + k - 1) % len(li)

    print("{0} {1}".format(li[0], li[1]))
