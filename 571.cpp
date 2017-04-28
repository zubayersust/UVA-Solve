/**
Author    : Zubayer Rahman
Email     : zubayer.csesust@gmail.com
CPU       : 0.050s
Memory    : 
Algorithm : BFS
*/

#include<bits/stdc++.h>

#define MAX_ROWS 1005
#define MAX_COLUMNS 1005

using namespace std;

int ca,cb,n;
int dest_row,dest_col;

class Data
{
public:
    int row;
    int col;
    int step;
    string str;

    int parent_row;
    int parent_col;

    Data()
    {

    }

    Data(int row, int col, int step,string str, int parent_row, int parent_col)
    {
        this->row  = row;
        this->col  = col;
        this->step = step;
        this->str  = str;

        this->parent_row = parent_row;
        this->parent_col = parent_col;
    }

    bool operator< (const Data& data)
    const
    {
        return step > data.step;
    }
};

Data data[MAX_ROWS][MAX_COLUMNS];

void reset(int max_row, int max_col)
{
    int i;
    int j;

    for(i=0; i<=max_row; i++)
        for(j=0; j<=max_col; j++)
        {
            data[i][j].row  = i;
            data[i][j].col  = j;
            data[i][j].step = INT_MAX;
        }
}

queue<Data> Q;
priority_queue<Data> q;

void BFS()
{
    data[0][0].row  = 0;
    data[0][0].col  = 0;
    data[0][0].step = 0;

    data[0][0].parent_row = -1;
    data[0][0].parent_col = -1;

    Q.push(data[0][0]);

    int _ca,_cb,_step;
    int _xa,_xb,step_count;

    Data nod;

    while(!Q.empty())
    {
        nod = Q.front();
        Q.pop();

        _ca   = nod.row;
        _cb   = nod.col;
        _step = nod.step;

        if(_cb == n)
        {
            while(!Q.empty())
                Q.pop();

            dest_row = _ca;
            dest_col = n;

            return;
        }

        if(_ca == 0)
        {
            _xa = _ca + ca;
            step_count = _step + 1;

            if(data[_xa][_cb].step>step_count)
            {
                data[_xa][_cb].row  = _xa;
                data[_xa][_cb].col  = _cb;
                data[_xa][_cb].step = step_count;
                data[_xa][_cb].str  = "fill A";

                data[_xa][_cb].parent_row = _ca;
                data[_xa][_cb].parent_col = _cb;

                Q.push(data[_xa][_cb]);
            }
        }

        if(_cb == 0)
        {
            _xb = _cb + cb;
            step_count = _step + 1;

            if(data[_ca][_xb].step>step_count)
            {
                data[_ca][_xb].row  = _ca;
                data[_ca][_xb].col  = _xb;
                data[_ca][_xb].step = step_count;
                data[_ca][_xb].str  = "fill B";

                data[_ca][_xb].parent_row = _ca;
                data[_ca][_xb].parent_col = _cb;

                Q.push(data[_ca][_xb]);
            }
        }

        if(_ca != 0)
        {
            _xa = 0;
            step_count = _step + 1;

            if(data[_xa][_cb].step > step_count)
            {
                data[_xa][_cb].row  = _xa;
                data[_xa][_cb].col  = _cb;
                data[_xa][_cb].step = step_count;
                data[_xa][_cb].str  = "empty A";

                data[_xa][_cb].parent_row = _ca;
                data[_xa][_cb].parent_col = _cb;

                Q.push(data[_xa][_cb]);
            }
        }

        if(_cb != 0)
        {
            _xb = 0;
            step_count = _step + 1;

            if(data[_ca][_xb].step > step_count)
            {
                data[_ca][_xb].row  = _ca;
                data[_ca][_xb].col  = _xb;
                data[_ca][_xb].step = step_count;
                data[_ca][_xb].str  = "empty B";

                data[_ca][_xb].parent_row = _ca;
                data[_ca][_xb].parent_col = _cb;

                Q.push(data[_ca][_xb]);
            }
        }

        if(_ca != 0 && _cb != cb)
        {
            _xa = max(0,(_cb+_ca)-cb);
            _xb = min(cb, _cb+_ca);

            step_count = _step + 1;

            if(data[_xa][_xb].step > step_count)
            {
                data[_xa][_xb].row  = _xa;
                data[_xa][_xb].col  = _xb;
                data[_xa][_xb].step = step_count;
                data[_xa][_xb].str  = "pour A B";

                data[_xa][_xb].parent_row = _ca;
                data[_xa][_xb].parent_col = _cb;

                Q.push(data[_xa][_xb]);
            }
        }

        if(_ca != ca && _cb != 0)
        {
            _xa = min(ca, _ca+_cb);
            _xb = max(0,(_ca+_cb)-ca);

            int step_count = _step + 1;

            if(data[_xa][_xb].step > step_count)
            {
                data[_xa][_xb].row  = _xa;
                data[_xa][_xb].col  = _xb;
                data[_xa][_xb].step = step_count;
                data[_xa][_xb].str  = "pour B A";

                data[_xa][_xb].parent_row = _ca;
                data[_xa][_xb].parent_col = _cb;

                Q.push(data[_xa][_xb]);
            }
        }
    }
}

void printResult()
{
    int dr,dc;

    while(dest_row != -1 && dest_col != -1)
    {
        q.push(data[dest_row][dest_col]);

        dr = data[dest_row][dest_col].parent_row;
        dc = data[dest_row][dest_col].parent_col;

        dest_row = dr;
        dest_col = dc;
    }

    q.pop();

    while(!q.empty())
    {
        cout<<q.top().str<<endl;
        q.pop();
    }

    printf("success\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d %d %d", &ca,&cb,&n)==3)
    {
        reset(ca,cb);

        BFS();

        printResult();
    }
    return 0;
}
