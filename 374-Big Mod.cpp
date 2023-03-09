/**
Online Judge : UVA Online Judge
Problem No   : 374
Problem Name : Big Mod
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : Math/Binary Exponentiation
*/

#include<bits/stdc++.h>

using namespace std;

int B, P, M;

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

    while(scanf("%d %d %d", &B, &P, &M) == 3)
    {
        int result;

        if(B == 0)
            result = 0;
        else
            result = bin_expo(B, P, M);

        printf("%d\n", result);
    }

    return 0;
}
