#이것도 시간초과

def fence(numbs_li):
    length_of_string = len(numbs_li)
    if length_of_string == 1:
        return int(numbs_li[0])
    else:
        area_li = []
        divided_li1 = numbs_li[:int(length_of_string / 2)]
        divided_li2 = numbs_li[int(length_of_string / 2):]
        for i in range(1, min([int(divided_li1[-1]), int(divided_li2[0])]) + 1):
            count = 2
            for j in range(2, len(divided_li1) + 1):
                if int(divided_li1[-j]) >= i: count += 1
                else: break
            for j in range(1, len(divided_li2)):
                if int(divided_li2[j]) >= i: count += 1
                else: break
            area_li.append(count * i)
        area_li.append(fence(divided_li1))
        area_li.append(fence(divided_li2))
        return max(area_li)

for i in range(0, int(input())):
    ignore_this = input()
    print(fence(input().split(" ")))
