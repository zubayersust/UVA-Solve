# Online Judge : UVA Online Judge
# Problem No   : 1207
# Problem Name : AGTC
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 3.000s
# CPU          : 0.070s
# Memory       :
# Algorithm    : Dynamic Programming (Edit Distance)


import sys

inp = sys.stdin
out = sys.stdout


def edit_distance(s1, s2, m, n, d=None) -> int:
    if d is None:
        d = {}

    k = m, n

    if m == 0:
        return n

    if n == 0:
        return m

    if k in d:
        return d[k]

    if s1[m - 1] == s2[n - 1]:
        return edit_distance(s1, s2, m - 1, n - 1, d)

    d[k] = 1 + min(
        edit_distance(s1, s2, m - 1, n, d),  # delete
        edit_distance(s1, s2, m, n - 1, d),  # insert
        edit_distance(s1, s2, m - 1, n - 1, d)  # replace
    )

    return d[k]


def main():
    global inp, out

    try:
        inp = open("input.txt", "r")
    except:
        pass

    while True:
        line1 = inp.readline().strip()
        if not len(line1):
            break

        line2 = inp.readline().strip()

        m, s1 = line1.split(" ")
        n, s2 = line2.split(" ")

        distance = edit_distance(s1, s2, int(m), int(n))
        out.write(f"{distance}\n")


if __name__ == '__main__':
    main()
