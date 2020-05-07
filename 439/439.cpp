/**
Online Judge : UVA Online Judge
Problem No   : 439
Problem Name : Knight Moves
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.182s
Memory       :
Algorithm    : BFS
*/

#include<bits/stdc++.h>

using namespace std;

struct data
{
    int x;
    int y;
    int l;
    int v;

    data(int a, int b, int c, int d)
    {
        x = a;
        y = b;
        l = c;
        v = d;
    }

    data() {}
};

data a[10][10];

queue<data> q;

void reset()
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            a[i][j].x = i;
            a[i][j].y = j;
            a[i][j].l = 0;
            a[i][j].v = 0;
        }
}

int dx[] = {+2,-2, 0, 0};
int dy[] = { 0, 0,+2,-2};
int dz[] = {+1,-1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    string s1,s2;

    while(cin>>s1)
    {
        cin>>s2;

        reset();

        int sx,sy,desx,desy,i,j;

        sx=s1[1]-'0';
        sy=s1[0]-96;

        desx=s2[1]-'0';
        desy=s2[0]-96;

        data p(sx,sy,0,0);
        q.push(p);

        while(!q.empty())
        {
            data f=q.front();
            q.pop();
            for(i=0; i<4; i++)
            {
                int nx=f.x+dx[i];
                int ny=f.y+dy[i];
                a[f.x][f.y].v=1;
                if(dy[i]==0)
                {
                    for(int k=0; k<2; k++)
                    {
                        int nyy=ny+dz[k];
                        if(nx>=1 && nx<=8 && nyy>=1 && nyy<=8 && a[nx][nyy].v==0)
                        {
                            a[nx][nyy].l=f.l+1;
                            int temp=a[nx][nyy].l;
                            data p(nx,nyy,temp,0);
                            q.push(p);
                        }
                    }
                }

                if(dx[i]==0)
                {
                    for(int k=0; k<2; k++)
                    {
                        int nxx=nx+dz[k];
                        if(nxx>=1 && nxx<=8 && ny>=1 && ny<=8 && a[nxx][ny].v==0)
                        {
                            a[nxx][ny].l=f.l+1;
                            int temp=a[nxx][ny].l;
                            data p(nxx,ny,temp,1);
                            q.push(p);
                        }
                    }
                }
            }
        }

        int temp=a[desx][desy].l;

        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<temp<<" knight moves."<<endl;
    }
    return 0;
}
