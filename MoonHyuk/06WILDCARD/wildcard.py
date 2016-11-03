# 풀긴 풀었는데 뭔가 편법인거 같은 기분이..
import re

test_case = int(input())
for i in range(test_case):
    re_string = input()
    string_list = []

    re_string = re_string.replace('?', '.')  # 문제에서 쓰인 ?는 정규표현식에서 .의 역할이므로 바꿔줍니다.
    re_string = re_string.replace('*', '[a-zA-Z0-9]*')  # *앞에는 반복될 표현이 써져있어야 하므로 바꿔줍니다.

    numbs_string = int(input())
    for j in range(numbs_string):
        input_string = input()
        if re.match(re_string + '$', input_string):
            string_list.append(input_string)

    string_list.sort()

    for j in string_list:
        print(j)
