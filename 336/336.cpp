/**
Online Judge : UVA Online Judge
Problem No   : 336
Problem Name : A Node Too Far
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.050s
Memory       :
Algorithm    : BFS
*/

#include<bits/stdc++.h>

using namespace std;

#define MAX_NODES 30

vector<int> vec[MAX_NODES + 1];
vector<int> visited(MAX_NODES + 1);
vector<int> value(MAX_NODES + 1);
map<int, int> mp;
queue<int> Q;

void reset()
{
    for(int i = 0; i < MAX_NODES + 1; i++)
    {
        visited[i] = 0;
        value[i] = 0;
    }
}

int bfs(int a, int b, int n)
{
    int h = 0, result;

    visited[a] = 1;
    value[a] = 0;
    Q.push(a);

    while(!Q.empty())
    {
        int node_x = Q.front();
        Q.pop();

        int val = value[node_x], len = vec[node_x].size();

        for(int i = 0; i < len; i++)
        {
            int node_y = vec[node_x][i];

            if(visited[node_y] == 0)
            {
                value[node_y] = val + 1;

                if(value[node_y] <= b) h++;

                visited[node_y] = 1;
                Q.push(node_y);
            }
        }
    }

    return n - h - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int connection, a, b, p = 1, sn, ttl, result;

    while(scanf("%d", &connection) == 1)
    {
        if(connection == 0)
            return 0;

        int temp = 0, x, y, node = 0;

        for(int i = 0; i < connection; i++)
        {
            scanf("%d %d", &a, &b);

            if(mp[a] == 0)
            {
                mp[a] = ++temp;
                node++;
            }

            if(mp[b] == 0)
            {
                mp[b] = ++temp;
                node++;
            }

            x = mp[a];
            y = mp[b];

            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        while(true)
        {
            scanf("%d %d", &sn, &ttl);

            reset();

            if(sn == 0 && ttl == 0)
                break;

            int snn = mp[sn];
            result = bfs(snn, ttl, node);

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", p++, result, sn, ttl);
        }

        for(int i = 0; i < MAX_NODES + 1; i++) vec[i].clear();
        mp.clear();
    }

    return 0;
}
