/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.00s
Memory : 
*/

#include<bits/stdc++.h>

#define MAX_LEVEL  30
#define MAX_ROW    30
#define MAX_COLUMN 30

using namespace std;

int l,r,c;
char ara[MAX_LEVEL][MAX_ROW][MAX_COLUMN];
int length[MAX_LEVEL][MAX_ROW][MAX_COLUMN];

int dirx[] = {0, 0, 1,-1, 0, 0};
int diry[] = {1,-1, 0, 0, 0, 0};
int dirz[] = {0, 0, 0, 0, 1,-1};

class Data
{
public:
    int level;
    int row;
    int column;

    Data(int level, int row, int column)
    {
        this->level  = level;
        this->row    = row;
        this->column = column;
    }

    Data()
    {

    }
};

Data start,escape;

void restore(int l, int r, int c)
{
    int i,j,k;

    for(i=0; i<l; i++)
        for(j=0; j<r; j++)
            for(k=0; k<c; k++)
                length[i][j][k] = INT_MAX;
}

bool BFS(Data &start, Data &escape)
{
    int start_level  = start.level;
    int start_row    = start.row;
    int start_column = start.column;

    int escape_level  = escape.level;
    int escape_row    = escape.row;
    int escape_column = escape.column;

    length[start_level][start_row][start_column] = 0;

    queue<Data> Q;

    Q.push(Data(start_level, start_row, start_column));

    while(!Q.empty())
    {
        Data data = Q.front();
        Q.pop();

        int level  = data.level;
        int row    = data.row;
        int column = data.column;

        if(level == escape_level && row == escape_row && column == escape_column)
            return true;

        int i;

        for(i=0; i<6; i++)
        {
            int level_new  = level  + dirz[i];
            int row_new    = row    + dirx[i];
            int column_new = column + diry[i];

            if((level_new>=0 && level_new<l) && (row_new>=0 && row_new<r) && (column_new>=0 && column_new<c) &&
                    (ara[level_new][row_new][column_new] != '#') &&
                    (length[level_new][row_new][column_new] == INT_MAX))
            {
                length[level_new][row_new][column_new] = length[level][row][column] + 1;
                Q.push(Data(level_new, row_new, column_new));
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

    while(scanf("%d %d %d", &l, &r, &c)==3)
    {
        if(l==0 && r==0 && c==0)
            return 0;

        restore(l, r, c);

        int i,j,k;

        for(i=0; i<l; i++)
            for(j=0; j<r; j++)
                for(k=0; k<c; k++)
                {
                    cin>>ara[i][j][k];

                    if(ara[i][j][k] == 'S')
                    {
                        start.level  = i;
                        start.row    = j;
                        start.column = k;
                    }

                    if(ara[i][j][k] == 'E')
                    {
                        escape.level  = i;
                        escape.row    = j;
                        escape.column = k;
                    }
                }
        bool possible = BFS(start, escape);

        if(!possible)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", length[escape.level][escape.row][escape.column]);
    }
    return 0;
}
