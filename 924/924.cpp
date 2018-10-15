/**
Online Judge : UVA Online Judge
Problem No   : 924
Problem Name : Spreading The News
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : BFS
*/

#include<bits/stdc++.h>

#define MAX_EMPLOYEES 2500

using namespace std;

int n,testCases;

int visited[MAX_EMPLOYEES];
int day[MAX_EMPLOYEES];

vector<int> vec[MAX_EMPLOYEES];

class Data
{
public:
    int day;
    int boom_size;

    Data(int day, int boom_size)
    {
        this->day       = day;
        this->boom_size = boom_size;
    }

    bool operator< (const Data& data)
    const
    {
        if(data.boom_size == boom_size)
            return day > data.day;

        return boom_size < data.boom_size;
    }
};

class Node
{
public:
    int idx;
    int level;

    Node(int idx, int level)
    {
        this->idx   = idx;
        this->level = level;
    }
};

queue<Node> q;
priority_queue<Data> Q;

void BFS(int source)
{
    visited[source] = 1;
    q.push(Node(source,0));

    while(!q.empty())
    {
        Node nod = q.front();
        q.pop();

        int idx   = nod.idx;
        int level = nod.level;

        int len = vec[idx].size();

        int i;
        int k;

        for(i=0; i<len; i++)
        {
            k = vec[idx][i];

            if(!visited[k])
            {
                visited[k] = 1;
                day[level+1]++;
                q.push(Node(k,level+1));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d", &n)==1)
    {
        int i;
        int k;

        for(i=0; i<n; i++)
        {
            scanf("%d", &k);

            int j;
            int m;

            for(j=0; j<k; j++)
            {
                scanf("%d", &m);
                vec[i].push_back(m);
            }
        }

        scanf("%d", &testCases);

        int source;

        while(testCases--)
        {
            scanf("%d", &source);

            BFS(source);

            for(i=0; i<n; i++)
                Q.push(Data(i,day[i]));

            Data data = Q.top();

            if(data.boom_size == 0)
                printf("0\n");
            else
                printf("%d %d\n", data.boom_size,data.day);

            memset(visited,0,sizeof(visited));
            memset(day,0,sizeof(day));

            while(!Q.empty())
                Q.pop();
        }
        for(i=0; i<n; i++)
            vec[i].clear();
    }
    return 0;
}
