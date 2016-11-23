## This code is not recommended since the line 12 is only a gimmick.

def brackets2(input_string):
    li = []
    for i, j in enumerate(input_string):
        if j in ['(', '[', '{']:
            li.append(j)

        else:
            if len(li) == 0:
                return "NO"

            elif ord(j) - ord(li[-1]) in [1, 2]:
                li.pop()

            else:
                return "NO"

    return "YES" if len(li) == 0 else "NO"

for _ in range(int(input())):
    print(brackets2(input()))
