import sys


def myFunction(A, B, n1, n2):
    pass


if __name__ == "__main__":
    testCases = 0

    while True:
        n1, n2 = map(int, input().split())
        testCases += 1

        if n1 == 0 and n2 == 0:
            break

        A = list(map(int, input().split()))
        B = list(map(int, input().split()))

        print('Twin Towers #%d' % testCases)
        print('Number of Tiles : %d' % myFunction(A, B, n1, n2))
        print()
