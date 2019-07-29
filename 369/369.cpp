/**
Online Judge : UVA Online Judge
Problem No   : 369
Problem Name : Combinations
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.013s
Memory       :
Algorithm    : Combinatorics
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n,m;

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int p=n,q=m;

        if(n==0 && m==0)
            return 0;

        long long i,j,temp=1;

        if(n-m<m)
            m=n-m;

        for(i=1,n=n; i<=m; i++,n--)
        {
            temp=temp*n;
            temp=temp/i;
        }

        printf("%d things taken %d at a time is %lld exactly.\n",p,q,temp);
    }
    return 0;
}
