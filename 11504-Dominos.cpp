/**
Online Judge : UVA Online Judge
Problem No   : 11504
Problem Name : Dominos
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.080s
Memory       :
Algorithm    : DFS
*/

#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int T, caseNumber = 1;
int n, m, x, y;
int visited[MAX_N + 1];
vector<int> v[MAX_N + 1];
stack<int> stk;

void reset()
{
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i < MAX_N + 1; i++)
        v[i].clear();
}

void DFS(int node)
{
    visited[node] = 1;
    for(auto child : v[node])
        if(visited[child] == 0)
            DFS(child);

    stk.push(node);
}

void DFS2(int node)
{
    visited[node] = 1;
    for(auto child : v[node])
        if(visited[child] == 0)
            DFS2(child);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &T);
    while(caseNumber <= T)
    {
        reset();

        scanf("%d %d", &n, &m);
        for(size_t i = 0; i < m ; i++)
        {
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
        }

        for(size_t i = 1; i <= n ; i++)
            if(visited[i] == 0)
                DFS(i);

        memset(visited, 0, sizeof(visited));

        int result = 0;
        while(!stk.empty())
        {
            int node = stk.top();
            stk.pop();

            if(visited[node] == 0)
            {
                result++;
                DFS2(node);
            }
        }

        printf("%d\n", result);
        caseNumber++;
    }

    return 0;
}
