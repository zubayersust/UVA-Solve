# Online Judge : UVA Online Judge
# Problem No   : 10405
# Problem Name : Longest Common Subsequence
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 3.000s
# CPU          : 0.170s
# Memory       :
# Algorithm    : Dynamic Programming (LCS)

import sys

MAX_CHAR = 1000
lcs = [[0 for i in range(MAX_CHAR + 1)] for j in range(MAX_CHAR + 1)]


def LCS(s1, s2):
    n = len(s1)
    m = len(s2)

    for i in reversed(range(n + 1)):
        for j in reversed(range(m + 1)):
            if i == n or j == m:
                lcs[i][j] = 0
                continue

            if s1[i] == s2[j]:
                lcs[i][j] = 1 + lcs[i + 1][j + 1]
            else:
                lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1])


def main():
    inp = sys.stdin
    out = sys.stdout

    try:
        inp = open("input.txt", "r")
    except:
        pass

    while True:
        try:
            s1 = inp.readline().strip()
            s2 = inp.readline().strip()

            if not len(s1):
                break

            LCS(s1, s2)

            out.write(f"{lcs[0][0]}\n")
        except:
            break


if __name__ == '__main__':
    main()
