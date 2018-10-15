/**
Online Judge : UVA Online Judge
Problem No   : 357
Problem Name : Let Me Count The Ways
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.0s
Memory       :
Algorithm    : Coin Change
*/

#include<bits/stdc++.h>

#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_N 30000

using namespace std;

int n;
int ara[]= {0,1,5,10,25,50};
ll dp[6][MAX_N+1];

long long coin_change(int i, int amount)
{
    if(i>5)
    {
        if(amount==0)
            return 1;
        return 0;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount];

    ll result1=0,result2=0;

    if(amount-ara[i]>=0)
        result1 += coin_change(i,amount-ara[i]);
    result2 = coin_change(i+1,amount);

    return dp[i][amount] = result1+result2;
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

        if(result==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",result,n);
    }
    return 0;
}
