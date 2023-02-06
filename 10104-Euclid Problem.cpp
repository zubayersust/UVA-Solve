/**
Online Judge : UVA Online Judge
Problem No   : 10104
Problem Name : Euclid Problem
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.010s
Memory       :
Algorithm    : Extended Euclid
*/

#include<bits/stdc++.h>

using namespace std;

int A, B;

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d %d", &A, &B) == 2)
    {
        int x, y;
        int gcd = extendedEuclid(A, B, &x, &y);

        printf("%d %d %d\n", x, y, gcd);
    }

    return 0;
}
