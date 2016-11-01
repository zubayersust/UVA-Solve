/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.00s
Memory : 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<climits>
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>

#define MAX_NODES 105

using namespace std;

int residual_capacity[MAX_NODES][MAX_NODES];
int parent[MAX_NODES],cost[MAX_NODES];
bool visited[MAX_NODES],path;

queue<int> q;

void reset()
{
    int i,j;

    for(i=0; i<MAX_NODES; i++)
        for(j=0; j<MAX_NODES; j++)
            residual_capacity[i][j]=0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n,s,t,c,i,j,node1,node2,bandwith,maxflow,network=1;

    while(scanf("%d", &n)==1)
    {
        if(n==0)
            return 0;
        scanf("%d %d %d", &s, &t, &c);

        maxflow = 0;

        reset();

        for(i=0; i<c; i++)
        {
            scanf("%d %d %d", &node1, &node2, &bandwith);
            residual_capacity[node1][node2] += bandwith;
            residual_capacity[node2][node1] +=bandwith;
        }

        path = true;

        while(path)
        {
            path=false;

            for(i=0; i<MAX_NODES; i++)
                visited[i]=false;

            q.push(s);
            parent[s]=s;
            cost[s]=INT_MAX;
            visited[s]=true;

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                if(u==t)
                {
                    while(!q.empty())
                        q.pop();
                    path=true;
                    break;
                }

                for(i=1; i<=100; i++)
                {
                    if(residual_capacity[u][i] > 0 && visited[i] == false)
                    {
                        parent[i]=u;
                        visited[i]=true;
                        cost[i]=min(cost[u], residual_capacity[u][i]);
                        q.push(i);
                    }
                }
            }

            if(path)
            {
                int u = t;
                while(parent[u] != u)
                {
                    residual_capacity[parent[u]][u] -= cost[t];
                    residual_capacity[u][parent[u]] += cost[t];
                    u = parent[u];
                }
                maxflow += cost[t];
            }
        }

        printf("Network %d\n",network++);
        printf("The bandwidth is %d.\n\n", maxflow);
    }

    return 0;
}
