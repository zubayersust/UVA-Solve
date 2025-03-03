/**
Online Judge : UVA Online Judge
Problem No   : 11518
Problem Name : Dominos 2
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.020s
Memory       :
Algorithm    : BFS
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int T;
    int n, m, l;
    int x, y;
    int z;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d %d", &n, &m, &l);

        vector<vector<int>> dominos(n + 1);

        for(int idx = 1; idx <= m; idx++)
        {
            scanf("%d %d", &x, &y);
            dominos[x].push_back(y);
        }

        queue<int> Q;
        vector<bool> knocked(n + 1, false);

        for(int idx = 1; idx <= l; idx++)
        {
            scanf("%d", &z);

            if(!knocked[z])
            {
                Q.push(z);
                knocked[z] = true;
            }
        }

        int result = 0;

        while(!Q.empty())
        {
            int domino = Q.front();
            Q.pop();

            result++;

            for(int item : dominos[domino])
            {
                if(!knocked[item])
                {
                    Q.push(item);
                    knocked[item] = true;
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
