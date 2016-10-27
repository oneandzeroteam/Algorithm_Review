#이것도 알수 없는 이유로 시간초과

def fence(numb_string):
    length_of_string = len(numb_string)
    if length_of_string == 1:
        return numb_string
    else:
        area_li = []
        divided_string1 = numb_string[:int(length_of_string / 2)]
        divided_string2 = numb_string[int(length_of_string / 2):]
        for i in range(1, min([int(divided_string1[-1]), int(divided_string2[0])]) + 1):
            count = 2
            for j in range(2, len(divided_string1) + 1):
                if int(divided_string1[-j]) >= i: count += 1
                else: break
            for j in range(1, len(divided_string2)):
                if int(divided_string2[j]) >= i: count += 1
                else: break
            area_li.append(count * i)
        area_li.append(int(fence(divided_string1)))
        area_li.append(int(fence(divided_string2)))
        return max(area_li)

for i in range(0, int(input())):
    ignore_this = input()
    print(fence(input().replace(" ", "")))
