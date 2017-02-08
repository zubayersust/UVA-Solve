/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.00s
Memory : 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<algorithm>

#define MAXN 1000

using namespace std;

int n;

vector<int> vec[MAXN+1];

int dp[MAXN+1][2];
int parent[MAXN+1];

void reset()
{
    int i,j;

    for(i=1; i<=MAXN; i++)
    {
        vec[i].clear();
        parent[i] = i;

        for(j=0; j<=1; j++)
            dp[i][j] = -1;
    }
}

int minimum_vertex_cover(int u, int isExit)
{
    if(vec[u].size() == 0)
        return 0;
    if(dp[u][isExit] != -1)
        return dp[u][isExit];

    int i,v,sum=0;
    int len = vec[u].size();

    for(i=0; i<len; i++)
    {
        v = vec[u][i];

        if(v != parent[u])
        {
            parent[v] = u;

            if(isExit == 0)
                sum += minimum_vertex_cover(v,1);
            else sum += min(minimum_vertex_cover(v,1), minimum_vertex_cover(v,0));

        }
    }

    return dp[u][isExit] = sum + isExit;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d", &n)==1)
    {
        if(n==0)
            return 0;

        reset();

        int i,j,m,p;

        for(i=1; i<=n; i++)
        {
            scanf("%d", &m);

            for(j=0; j<m; j++)
            {
                scanf("%d", &p);

                vec[i].push_back(p);
            }
        }

        int numExit = 0;

        if(n==1)
            printf("1\n");
        else
        {
            numExit = min(minimum_vertex_cover(1,1), minimum_vertex_cover(1,0));
            printf("%d\n", numExit);
        }
    }
    return 0;
}
