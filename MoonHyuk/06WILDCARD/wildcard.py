# 풀긴 풀었는데 뭔가 편법인거 같은 기분이..
import re

test_case = int(input())
for i in range(test_case):
    re_string = input().replace('?', '.').replace('*', '\w*')
    string_list = []
    numbs_string = int(input())
    for j in range(numbs_string):
        input_string = input()
        if re.match(re_string + '$', input_string):
            string_list.append(input_string)

    string_list.sort()

    for j in string_list:
        print(j)
