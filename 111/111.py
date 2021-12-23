# Online Judge : UVA Online Judge
# Problem No   : 111
# Problem Name : History Grading
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 3.000s
# CPU          : 0.130s
# Memory       :
# Algorithm    : LCS

import sys
from typing import List


def LCS(s1: List[int], s2: List[int]) -> int:
    lcs = [[0 for _ in range(max(len(s1), len(s2)) + 1)] for _ in range(2)]

    bi = bool

    for i in range(len(s1) + 1):
        bi = i & 1
        for k in range(len(s2) + 1):
            if i == 0 or k == 0:
                lcs[bi][k] = 0
            elif s1[i - 1] == s2[k - 1]:
                lcs[bi][k] = 1 + lcs[1 - bi][k - 1]
            else:
                lcs[bi][k] = max(lcs[1 - bi][k], lcs[bi][k - 1])

    return lcs[bi][len(s2)]


def main():
    try:
        sys.stdin = open("input", "r")
    except:
        pass

    while True:
        n = int(sys.stdin.readline().strip())
        order = sys.stdin.readline().strip().split(" ")

        s1 = [0 for _ in range(21)]
        for idx, num in enumerate(order):
            s1[int(num)] = idx + 1

        while True:
            line = sys.stdin.readline().strip()
            if not line:
                break

            line = line.split(" ")
            s2 = [0 for _ in range(21)]
            for idx, num in enumerate(line):
                s2[int(num)] = idx + 1

            s1 = [x for x in s1 if x]
            s2 = [x for x in s2 if x]

            score = LCS(s1, s2)
            sys.stdout.write(str(score) + "\n")

        break


if __name__ == '__main__':
    main()
