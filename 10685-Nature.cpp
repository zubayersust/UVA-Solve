/**
Online Judge : UVA Online Judge
Problem No   : 10685
Problem Name : Nature
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.021s
Memory       :
Algorithm    : DSU
*/

#include<bits/stdc++.h>

using namespace std;

int find_set(int v, vector<int> &parent)
{
    if(parent[v] == v) return v;

    return parent[v] = find_set(parent[v], parent);
}

int union_sets(int x, int y, vector<int> &parent, vector<int> &_size)
{
    x = find_set(x, parent);
    y = find_set(y, parent);

    if(x != y)
    {
        parent[x] = y;
        _size[y] += _size[x];
    }

    return _size[y];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int c, r;

    while(scanf("%d %d", &c, &r) == 2)
    {
        if(c == 0 && r == 0) break;

        map<string, int> M;
        vector<int> v(c + 1);
        vector<int> _size(c + 1, 1);

        int counter = 0;

        for(int idx = 1; idx <= c; idx++) v[idx] = idx;

        for(int idx = 1; idx <= c; idx++)
        {
            string s;
            cin >> s;
            M[s] = ++counter;
        }

        int result = 1;

        for(int idx = 1; idx <= r; idx++)
        {
            string s1, s2;

            cin >> s1 >> s2;

            result = max(result, union_sets(M[s1], M[s2], v, _size));
        }

        cout << result << endl;
    }

    return 0;
}
