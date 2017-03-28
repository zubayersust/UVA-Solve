/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.00s
Memory : 
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

#define MAX_HOUSE 35

using namespace std;

int testCase,caseNum=1;
int M,N,P;
int dis[MAX_HOUSE];
bool visited[MAX_HOUSE];

map<string,int> mp;
vector<int> vec[MAX_HOUSE];
queue<int> Q;

void reset()
{
    mp.clear();

    int i;

    for(i=0; i<MAX_HOUSE; i++)
        vec[i].clear();
}

void reset2()
{
    int i;

    for(i=0; i<MAX_HOUSE; i++)
    {
        dis[i]=0;
        visited[i]=false;
    }
}

void BFS(int src)
{
    dis[src]=0;
    visited[src]=true;
    Q.push(src);

    int u,v;
    int i;

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        int len=vec[u].size();

        for(i=0; i<len; i++)
        {
            v=vec[u][i];

            if(!visited[v])
            {
                visited[v]=true;
                dis[v]=dis[u]+1;
                Q.push(v);
            }
        }
    }
}

void printResult(int num, int dest)
{
    if(dis[dest]==0)
        printf("NO SHIPMENT POSSIBLE\n");
    else
    {
        int Cost;
        Cost = num * dis[dest] * 100;
        printf("$%d\n",Cost);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    printf("SHIPPING ROUTES OUTPUT\n\n");

    while(caseNum <= testCase)
    {
        scanf("%d %d %d", &M, &N, &P);

        reset();

        int i,temp=0;
        string s;

        for(i=0; i<M; i++)
        {
            cin>>s;
            if(mp[s]==0)
            {
                mp[s]=temp++;
            }
        }

        string s1,s2;
        int u,v;

        for(i=0; i<N; i++)
        {
            cin>>s1>>s2;

            u=mp[s1];
            v=mp[s2];

            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        int w;

        printf("DATA SET %2d\n\n",caseNum++);

        for(i=0; i<P; i++)
        {
            cin>>w>>s1>>s2;

            u=mp[s1];
            v=mp[s2];

            reset2();

            BFS(u);
            printResult(w,v);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");

    return 0;
}
