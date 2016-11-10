/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.110s
Memory : 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
#include<algorithm>

#define MAX_TRACKS 21
#define MAX_N 32800

using namespace std;

int n,tracks,result;

int duration[MAX_TRACKS],data[MAX_TRACKS][MAX_N];

class Next
{
public:
    int index;
    int weight;

    Next(int index, int weight)
    {
        this->index  = index;
        this->weight = weight;
    }

    Next()
    {

    }
};

Next dir[MAX_TRACKS][MAX_N];

void reset()
{
    int i,j;
    Next nxt;

    for(i=0; i<MAX_TRACKS; i++)
        for(j=0; j<MAX_N; j++)
        {
            data[i][j]=-1;

            nxt = Next(i,-1);
            dir[i][j]=nxt;
        }
}

int knapsack(int i, int weight)
{
    if(i > tracks)
        return 0;

    if(data[i][weight] != -1)
        return data[i][weight];

    int profit1,profit2;

    if(weight + duration[i] <= n)
        profit1 = duration[i] + knapsack(i+1, weight + duration[i]);
    else profit1 = 0;

    profit2 = knapsack(i+1, weight);

    if(profit1>profit2)
    {
        Next nxt = Next(i+1,weight+duration[i]);
        dir[i][weight]=nxt;

        return data[i][weight] = profit1;
    }
    else
    {
        Next nxt = Next(i+1,weight);
        dir[i][weight]=nxt;

        return data[i][weight] = profit2;
    }
}

void printPath()
{
    Next nxt = dir[1][0];
    int weight = 0;

    while(nxt.weight != -1)
    {
        if(nxt.weight != weight && nxt.weight != 0)
            printf("%d ", duration[nxt.index-1]);

        weight = nxt.weight;
        nxt = dir[nxt.index][nxt.weight];
    }
}

int main()
{
    int i;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d", &n)==1)
    {
        scanf("%d", &tracks);

        for(i=1; i<=tracks; i++)
            scanf("%d", &duration[i]);

        reset();

        result = knapsack(1,0);

        printPath();
        printf("sum:%d\n", result);
    }
    return 0;
}
