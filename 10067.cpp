/**
Author    : Zubayer Rahman
Email     : zubayer.csesust@gmail.com
CPU       : 0.050s
Memory    : 
Algorithm : BFS
*/

#include<bits/stdc++.h>

using namespace std;

int testCase,n;
int a1,b1,c1,d1;
int a2,b2,c2,d2;
int ara[10][10][10][10];

int dirw[] = {0, 0, 0, 0, 0, 0, 1,-1};
int dirx[] = {0, 0, 0, 0, 1,-1, 0, 0};
int diry[] = {0, 0, 1,-1, 0, 0, 0, 0};
int dirz[] = {1,-1, 0, 0, 0, 0, 0, 0};

class Data
{
public:
    int w;
    int x;
    int y;
    int z;

    Data(int w, int x, int y, int z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Data()
    {

    }

    bool equalTo(Data &data)
    {
        if((data.w == w) && (data.x == x) && (data.y == y) && (data.z == z))
            return true;
        else return false;
    }
};

void reset()
{
    int i,j,k,l;

    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            for(k=0; k<10; k++)
                for(l=0; l<10; l++)
                    ara[i][j][k][l] = INT_MAX;
}

bool BFS(Data &start, Data &optimal)
{
    ara[start.w][start.x][start.y][start.z] = 0;

    queue<Data> Q;
    Q.push(start);

    while(!Q.empty())
    {
        Data data = Q.front();
        Q.pop();

        if(data.equalTo(optimal))
            return true;

        int i;

        for(i=0; i<8; i++)
        {
            int _w = data.w + dirw[i];
            int _x = data.x + dirx[i];
            int _y = data.y + diry[i];
            int _z = data.z + dirz[i];

            if(_w<0)
                _w += 10;
            else if(_w>9)
                _w -= 10;

            if(_x<0)
                _x += 10;
            else if(_x>9)
                _x -= 10;

            if(_y<0)
                _y += 10;
            else if(_y>9)
                _y -= 10;

            if(_z<0)
                _z += 10;
            else if(_z>9)
                _z -= 10;

            if(ara[_w][_x][_y][_z] == INT_MAX)
            {
                ara[_w][_x][_y][_z] = ara[data.w][data.x][data.y][data.z] + 1;
                Q.push(Data(_w, _x, _y, _z));
            }
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    while(testCase--)
    {
        scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
        scanf("%d %d %d %d", &a2, &b2, &c2, &d2);

        Data start(a1, b1, c1, d1);
        Data optimal(a2, b2, c2, d2);

        scanf("%d", &n);

        reset();

        int i;
        int a,b,c,d;

        for(i=0; i<n; i++)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            ara[a][b][c][d] = -1;
        }

        bool reachable = BFS(start, optimal);

        if(reachable)
            printf("%d\n", ara[a2][b2][c2][d2]);
        else printf("-1\n");
    }
    return 0;
}
