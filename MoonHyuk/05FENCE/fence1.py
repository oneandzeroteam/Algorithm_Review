#this works but time exceeded

import re
from collections import OrderedDict

def function(numb_string):
    li = []
    length_of_string = len(numb_string)
    if length_of_string == 1:
        li.append(numb_string)

    elif length_of_string == 2:
        if numb_string[0] == '0' or numb_string[1] == '0' or numb_string[0] == numb_string[1]:
            li.append(numb_string)
        elif numb_string[0] > numb_string[1]:
            li.extend([numb_string[0] + '0', numb_string[1] * 2])
        else:
            li.extend(['0' + numb_string[1], numb_string[0] * 2])

    else:
        divide_li1 = function(numb_string[:int(length_of_string / 2)])
        divide_li2 = function(numb_string[int(length_of_string / 2):])
        for i in range(0, len(divide_li1)):
            for j in range(0, len(divide_li2)):
                if divide_li1[i][-1] == '0' or divide_li2[j][0] == '0':
                    li.extend([str(divide_li1[i]) + '0' * len(divide_li2[j]), '0' * len(divide_li1[i]) + str(divide_li2[j])])

                elif divide_li1[i][-1] == divide_li2[j][0]:
                    li.append(divide_li1[i] + divide_li2[j])

                elif divide_li1[i][-1] > divide_li2[j][0]:
                    li.append(divide_li1[i] + '0' * len(divide_li2[j]))
                    p = re.compile('[^0]')
                    divide_li1[i] = p.sub(divide_li2[j][0], divide_li1[i])
                    li.append(divide_li1[i] + divide_li2[j])

                else:
                    li.append('0' * len(divide_li1[i]) + divide_li2[j])
                    p = re.compile('[^0]')
                    divide_li2[j] = p.sub(divide_li1[i][-1], divide_li2[j])
                    li.append(divide_li1[i] + divide_li2[j])

    return list(OrderedDict.fromkeys(li))


def sum_str(string):
    sum = 0
    for i in range(0, len(string)):
        sum += int(string[i])
    return sum


def find_max(li):
    sum_li = []
    for i in range(0, len(li)):
        sum_li.append(sum_str(li[i]))
    return max(sum_li)

test_case = int(input())

for i in range(0, test_case):
    ignore_this = input()
    print(find_max(function(input().replace(" ", ""))))
