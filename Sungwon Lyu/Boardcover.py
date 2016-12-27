import numpy as np
import collections as col
global count


def check_avail(lists):
    num_dot = sum(x.count(".") for x in lists)
    return num_dot % 3 == 0


def select_left_top(array):
    for i in range(len(array)):
        for j in range(len(array[i])):
            if array[i, j] == ".":
                return i, j


def cover(array):
    if "." not in array:
        count += 1
    else:
        i, j = select_left_top(array)
        if [array[i, j], array[i + 1, j], array[i, j + 1]] == ['.', '.', '.']:
            array[i, j] = "#"
            array[i + 1, j] = "#"
            array[i, j + 1] = "#"
            cover(array)
        elif [array[i, j], array[i + 1, j], array[i + 1, j + 1]] == ['.', '.', '.']:
            array[i, j] = "#"
            array[i + 1, j] = "#"
            array[i + 1, j + 1] = "#"
            cover(array)
        elif [array[i, j], array[i, j + 1], array[i + 1, j + 1]] == ['.', '.', '.']:
            array[i, j] = "#"
            array[i, j + 1] = "#"
            array[i + 1, j + 1] = "#"
            cover(array)
        elif [array[i, j], array[i, j + 1], array[i - 1, j + 1]] == ['.', '.', '.']:
            array[i, j] = "#"
            array[i, j + 1] = "#"
            array[i - 1, j + 1] = "#"
            cover(array)
        else:
            pass

f = open('Boardcover_input.py', 'r')
n = int(f.readline())
for i in range(n):
    a, b = map(int, f.readline().split())
    board = []
    for j in range(a):
        line = list(f.readline())
        board.append(line)
    if check_avail(board):
        board_array = np.array(board)
        count = 0
        cover(board_array)
        print(count)
    else:
        print('false')

for i in
