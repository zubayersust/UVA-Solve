/**
Online Judge : UVA Online Judge
Problem No   : 111
Problem Name : History Grading
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : LCS
*/

#include<bits/stdc++.h>

using namespace std;

int LCS(int s1[], int s2[], int length)
{
    int lcs [2][length+1] = {{0}};

    for(int i=0; i<2; i++)
        for(int k=0; k<length+1; k++)
            lcs[i][k] = 0;

    bool bi;

    for(int i=0; i<=length+1; i++)
    {
        bi = i & 1;
        for(int k=0; k<=length+1; k++)
        {
            if(i==0 || k==0)
                lcs[bi][k+1] = 0;
            else if(s1[i] == s2[k])
                lcs[bi][k+1] = 1 + lcs[1-bi][k+1];
            else lcs[bi][k+1] = max(lcs[1-bi][k+1], lcs[bi][k]);
        }
    }

    return lcs[bi][length+1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
#endif // ONLINE_JUDGE

    int n;

    while(scanf("%d", &n) == 1)
    {
        int s1[n+1], s2[n+1];

        for (int i=1; i<=n; i++)
        {
            int a;

            scanf("%d", &a);
            s1[a] = i;
        }

        while(true)
        {
            int a;

            for(int i=1; i<=n; i++)
            {
                if (scanf("%d", &a) != 1)
                    return 0;

                s2[a] = i;
            }

            int result = LCS(s1, s2, n);
            printf("%d\n", result);
        }
    }

    return 0;
}
