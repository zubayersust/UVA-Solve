/**
Online Judge : UVA Online Judge
Problem No   : 11137
Problem Name : Ingenuous Cubrency
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.0s
Memory       :
Algorithm    : Coin Change
*/

#include<bits/stdc++.h>

#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_N 10000

using namespace std;

int n;
ll dp[22][MAX_N+1];

ll coin_change(int i, int amount)
{
    if(i>21)
    {
        if(amount==0)
            return 1;
        return 0;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount];

    ll result1=0,result2=0;

    if(amount-(i*i*i)>=0)
        result1 += coin_change(i, amount-(i*i*i));
    result2 = coin_change(i+1,amount);

    return dp[i][amount]=result1+result2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    mem(dp,-1);

    while(scanf("%d", &n)==1)
    {
        ll result = coin_change(1,n);
        printf("%lld\n",result);
    }
    return 0;
}
