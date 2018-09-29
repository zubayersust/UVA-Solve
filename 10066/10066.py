# Online Judge : UVA Online Judge
# Problem No   : 10066
# Problem Name : The Twin Towers
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 3.000s
# CPU          : 0.060s
# Memory       :
# Algorithm    : Dynamic Programming


def myFunction(i, j):

    if i == n1 or j == n2:
        return 0

    if visited[i][j]:
        return dp[i][j]

    block = 0
    val1 = None
    val2 = None

    if A[i] == B[j]:
        block = 1 + myFunction(i+1, j+1)
    else:
        val1 = myFunction(i+1, j)
        val2 = myFunction(i, j+1)
        block = max(val1, val2)

    visited[i][j] = 1

    dp[i][j] = block

    return dp[i][j]


def reset(visited, n1, n2):
    for i in range(n1):
        for j in range(n2):
            visited[i][j] = 0


if __name__ == "__main__":
    maxBlocks = 105
    testCases = 0

    dp = [[0 for x in range(maxBlocks)] for y in range(maxBlocks)]
    visited = [[0 for x in range(maxBlocks)] for y in range(maxBlocks)]

    while True:
        n1, n2 = map(int, input().split())
        testCases += 1

        if n1 == 0 and n2 == 0:
            break

        A = list(map(int, input().split()))
        B = list(map(int, input().split()))

        reset(visited, n1, n2)

        print('Twin Towers #%d' % testCases)
        print('Number of Tiles : %d' % myFunction(0, 0))
        print()
