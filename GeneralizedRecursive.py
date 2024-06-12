from typing import List, Tuple

a = []
b = []
dic = [[-1 for _ in range(100)] for _ in range(100)]
c = 0
d = 0


def RF(x: int, y: int) -> int:
    ans = 0
    if x <= 0 or y <= 0:
        return d
    else:
        if dic[x][y] != -1:
            return dic[x][y]
        else:
            for i in range(len(a)):
                ans += RF(x - a[i], y - b[i])
            ans += c
            dic[x][y] = ans
    return ans



caseN = int(input())
for _ in range(caseN):
    for i in range(100):
        for j in range(100):
            dic[i][j] = -1
    s = input()
    pairs = list(map(int, s.split()))
    a.extend(pairs[::2][:-1])
    b.extend(pairs[1::2][:-1])
    c = pairs[-2]
    d = pairs[-1]
    s = input()
    xy_coords = list(map(int, s.split()))
    for x, y in zip(xy_coords[::2], xy_coords[1::2]):
        print(RF(x, y))
    print()
    a.clear()
    b.clear()

