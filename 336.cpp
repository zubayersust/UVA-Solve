#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> vec[50];
map<int,int> mp;

struct data
{
    int x;
    int value;
    int visit;
    data(int x,int value,int visit)
    {
        this->x=x;
        this->value=value;
        this->visit=visit;
    }
    data() {}
};

data ara[50];

queue<data> Q;

void reset()
{
    for(int i=0; i<50; i++)
    {
        ara[i].x=i;
        ara[i].value=0;
        ara[i].visit=0;
    }
}

int bfs(int a,int b,int n)
{
    int h=0,result;

    ara[a].visit=1;
    data m(a,0,1);
    Q.push(m);

    while(!Q.empty())
    {
        data f=Q.front();
        Q.pop();

        a=f.x;
        int c=f.value,len=vec[a].size();

        for(int i=0; i<len; i++)
        {
            int d=vec[a][i];
            if(ara[d].visit==0)
            {
                ara[d].value=c+1;
                if(ara[d].value<=b)
                    h++;
                ara[d].visit=1;
                Q.push(data(d,ara[d].value,1));
            }
        }
    }
    result = n-h-1;
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int connection,a,b,p=1,sn,ttl,fresult;
    while(scanf("%d", &connection)==1)
    {
        if(connection==0)
            return 0;

        int temp=0,x,y,node=0;

        for(int i=0; i<connection; i++)
        {
            scanf("%d %d", &a, &b);

            if(mp[a]==0)
            {
                mp[a]=++temp;
                node++;
            }
            if(mp[b]==0)
            {
                mp[b]=++temp;
                node++;
            }

            x=mp[a];
            y=mp[b];
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        while(true)
        {
            scanf("%d %d", &sn, &ttl);

            reset();

            if(sn==0 && ttl==0)
                break;

            int snn=mp[sn];
            fresult=bfs(snn,ttl,node);

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",p++,fresult,sn,ttl);
        }

        for(int i=0; i<=35; i++)
            vec[i].clear();
        mp.clear();
    }
    return 0;
}
