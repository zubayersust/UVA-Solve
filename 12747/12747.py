# Online Judge : UVA Online Judge
# Problem No   : 12747
# Problem Name : Back to Edit Distance
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 3.000s
# CPU          : 0.000s
# Memory       :
# Algorithm    : Dynamic Programming (Edit Distance)


import sys

inp = sys.stdin
out = sys.stdout


def LCS(s1, s2) -> int:
    m = len(s1)
    n = len(s2)

    lookup = [0] * (n + 1)

    for i in range(m + 1):
        prev = lookup[0]
        for j in range(n + 1):
            backup = lookup[j]

            if i == 0 or j == 0:
                lookup[j] = 0
            elif s1[i - 1] == s2[j - 1]:
                lookup[j] = prev + 1
            else:
                lookup[j] = max(lookup[j], lookup[j - 1])

            prev = backup

    return lookup[n]


def main():
    global inp, out

    try:
        inp = open("input.txt", "r")
    except:
        pass

    test_case = 1
    T = int(inp.readline().strip())

    while test_case <= T:
        N = int(inp.readline().strip())

        s1 = inp.readline().strip().split(" ")
        s2 = inp.readline().strip().split(" ")

        out.write(f"Case {test_case}: {(2 * N) - (2 * LCS(s1, s2))}\n")
        test_case += 1


if __name__ == '__main__':
    main()
