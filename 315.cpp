/**
Online Judge : UVA Online Judge
Problem No   : 315
Problem Name : Network
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.000s
Memory       :
Algorithm    : Articulation Point/Bridge
*/

#include<bits/stdc++.h>

#define MAX_NODES 100

using namespace std;

int n;

vector<int> vec[MAX_NODES+5];
set<int> s;

int visited[MAX_NODES],dis[MAX_NODES],low[MAX_NODES],parent[MAX_NODES];

int tim;

void DFS(int root)
{
    visited[root] = 1;
    dis[root]     = ++tim;
    low[root]     = dis[root];

    int v,child=0;
    int len = vec[root].size();

    while(!vec[root].empty())
    {
        v = *vec[root].begin();
        vec[root].erase(vec[root].begin());

        if(!visited[v])
        {
            child++;
            parent[v] = root;

            DFS(v);

            low[root] = min(low[root], low[v]);

            if(dis[root] <= low[v] && parent[root] != -1)
                s.insert(root);

            if(child>1 && parent[root]==-1)
                s.insert(root);
        }
        else if(parent[root] != v)
            low[root] = min(low[root], dis[v]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d", &n)==1)
    {
        getchar();

        if(n==0)
            return 0;

        char str[1000];

        char *point;
        int u,v;

        while(scanf("%[^\n]", str) && strcmp(str, "0"))
        {
            getchar();

            point = strtok(str, " ");
            u = atoi(point);

            point = strtok(NULL, " ");

            while(point != NULL)
            {
                v = atoi(point);

                vec[u].push_back(v);
                vec[v].push_back(u);

                point = strtok(NULL, " ");
            }
        }

        memset(visited,0,sizeof(visited));
        memset(dis,0,sizeof(dis));
        memset(low,0,sizeof(low));
        memset(parent,-1,sizeof(parent));

        s.clear();

        tim=0;

        DFS(1);

        cout<<s.size()<<endl;
    }
    return 0;
}
