testCase = int(input())

def function(string):
    length = 1
    if string[0] == 'x':
        list = []
        for i in range(1, 5):

            list.append(function(string[length:]))
            length += len(list[i-1])

        list[0], list[2] = list[2], list[0]
        list[1], list[3] = list[3], list[1]

        return "x" + "".join(list)

    else:
        return string[0]


for i in range(0, testCase):
    print(function(input()))
