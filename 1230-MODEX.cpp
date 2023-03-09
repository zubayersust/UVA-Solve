/**
Online Judge : UVA Online Judge
Problem No   : 1230
Problem Name : MODEX
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : Math/Binary Exponentiation
*/

#include<bits/stdc++.h>

using namespace std;

int T, x, y, n;

int bin_expo(int x, int y, int n)
{
    x %= n;

    int res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x % n;

        x = x * x % n;
        y >>= 1;
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d", &T) == 1)
    {
        if (T == 0)
            break;

        for(int i = 0; i < T; i++)
        {
            scanf("%d %d %d", &x, &y, &n);
            int result = bin_expo(x, y, n);
            printf("%d\n", result);
        }
    }

    return 0;
}
