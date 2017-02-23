/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.185s
Memory : 
*/

#include<bits/stdc++.h>

#define INF 10000000

using namespace std;

int cost[110][110];
map<int,int> mp;
vector<int> vnode;

void reset()
{
    int i,j;

    for(i=0; i<110; i++)
        for(j=0; j<110; j++)
        {
            if(i==j)
                cost[i][j]=0;
            else cost[i][j]=INF;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int u,v,k,i,j,len,p=1;

    while(scanf("%d %d",&u,&v)==2)
    {
        int node=0,total=0;

        if(u==0 && v==0)
            return 0;

        reset();

        cost[u][v]=1;
        vnode.push_back(u);
        vnode.push_back(v);
        mp[u]=1;
        mp[v]=1;

        while(1)
        {
            scanf("%d %d",&u,&v);

            if(u==0 && v==0)
                break;

            cost[u][v]=1;

            if(mp[u]==0)
            {
                mp[u]=1;
                vnode.push_back(u);
                node++;
            }

            if(mp[v]==0)
            {
                mp[v]=1;
                vnode.push_back(v);
                node++;
            }
        }

        for(k=1; k<105; k++)
            for(i=1; i<105; i++)
                for(j=1; j<105; j++)
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);

        len=vnode.size();

        for(i=0; i<len; i++)
        {
            u=vnode[i];
            for(j=0; j<len; j++)
            {
                v=vnode[j];
                total+=cost[u][v];
            }
        }

        double a,b,c;
        a=total;
        b=len*(len-1);
        c=a/b;

        cout<<setprecision(3)<<fixed;
        cout<<"Case "<<p++<<":"<<" average length between pages = "<<c<<" clicks"<<endl;

        mp.clear();
        vnode.clear();
    }
    return 0;
}
