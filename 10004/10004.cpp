/**
Online Judge : UVA Online Judge
Problem No   : 10004
Problem Name : Bicoloring
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : BFS
*/

#include<bits/stdc++.h>

using namespace std;

#define MAX_NODES 200

vector<int> v[MAX_NODES];
int level[MAX_NODES], visited[MAX_NODES];
queue<int> q;

void reset()
{
    int i;
    for(i=0; i<MAX_NODES; i++)
    {
        level[i]=0;
        visited[i]=0;
        v[i].clear();
    }
}

int BFS(int n)
{
    int temp,i,idx;

    level[0]=0;
    visited[0]=1;
    q.push(0);

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        for(i=0; i<v[temp].size(); i++)
        {
            idx=v[temp][i];
            if(!visited[idx])
            {
                level[idx]=level[temp]+1;
                visited[idx]=1;
                q.push(idx);
            }
            else if(level[temp]==level[idx])
                return -1;
        }
    }

    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n,l,i,a,b,c;

    while(scanf("%d",&n)==1)
    {
        if(n==0)
            return 0;

        scanf("%d",&l);
        reset();

        for(i=0; i<l; i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        c=BFS(n);
        if(c==1)
            printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");

        while(!q.empty())
            q.pop();
    }

    return 0;
}
