#include<bits/stdc++.h>

using namespace std;

int T, A, B, C, P;
int testCase = 1;

int extendedEuclid(int a, int b, int *x, int *y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;

        return a;
    }

    int x1, y1;
    int gcd = extendedEuclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int findAllSolutions(int a, int b, int c, int minx, int maxx, int miny, int maxy)
{
    int x, y;
    int gcd = extendedEuclid(A, B, &x, &y);

    if(c % gcd)
        return 0;


}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &T);
    while(testCase <= T)
    {
        scanf("%d%d%d%d", &A, &B, &C, &P);

        int result = 0;
        int z = 0;
        while(P - C * z > 0)
        {
            int q = P - C * z;
            result += findAllSolutions(A, B, q, 0, P, 0, P);

            z++;
        }

        printf("Case %d: %d\n", testCase++, result);
    }

    return 0;
}
