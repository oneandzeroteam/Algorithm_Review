# 풀긴 풀었는데 뭔가 편법인거 같은 기분이..
import re

for i in range(int(input())):
    re_string = input().replace('?', '.').replace('*', '\w*')
    string_list = []
    for j in range(int(input())):
        input_string = input()
        if re.match(re_string + '$', input_string):
            string_list.append(input_string)

    for j in string_list.sort():
        print(j)
        
