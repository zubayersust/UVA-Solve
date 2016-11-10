/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.009s
Memory : 
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>

#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_N 5
#define MAX_W 7490

using namespace std;

ll n;
int cost[]= {50,25,10,5,1};

ll ara[MAX_N][MAX_W];

ll Function(int i, ll w)
{
    if (i >= MAX_N)
    {
        if (w == 0)
            return 1;
        else return 0;
    }

    if(ara[i][w]!=-1)
        return ara[i][w];

    int ret1=0,ret2=0;

    if(w - cost[i] >=0)
        ret1 = Function(i, w - cost[i]);

    ret2 = Function(i+1, w);

    ara[i][w] = (ret1 + ret2);

    return ara[i][w];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    mem(ara,-1);

    while(scanf("%lld", &n)==1)
    {
        ll result = Function(0, n);

        printf("%lld\n", result);
    }
    return 0;
}
