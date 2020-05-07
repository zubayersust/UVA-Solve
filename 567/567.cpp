/**
Online Judge : UVA Online Judge
Problem No   : 567
Problem Name : Risk
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.102s
Memory       :
Algorithm    : BFS
*/

#include<bits/stdc++.h>

#define INF 100000000

using namespace std;

int node[30][30];

void func()
{
    int i,j;

    for(i=1; i<30; i++)
        for(j=1; j<30; j++)
        {
            if (i==j)
                node[i][j]=0;
            else node[i][j]=INF;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n,i,x,j,k,s,e,p=1;

    while(scanf("%d",&n)==1)
    {
        func();

        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            node[1][x]=1;
            node[x][1]=1;
        }

        for(i=2; i<=19; i++)
        {
            scanf("%d",&n);
            for(j=0; j<n; j++)
            {
                scanf("%d",&x);
                node[i][x]=1;
                node[x][i]=1;
            }
        }

        for(k=1; k<21; k++)
            for(i=1; i<21; i++)
                for(j=1; j<21; j++)
                {
                    node[i][j]=min(node[i][j],node[i][k]+node[k][j]);
                }

        scanf("%d",&n);

        printf("Test Set #%d\n",p++);

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&s,&e);
            cout<<setw(2)<<s<<" to "<<setw(2)<<e<<": ";
            printf("%d\n",node[s][e]);
        }
        cout<<endl;
    }
    return 0;
}
