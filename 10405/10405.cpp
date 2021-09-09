/**
Online Judge : UVA Online Judge
Problem No   : 10405
Problem Name : Longest Common Subsequence
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : Dynamic Programming (LCS)
*/

#include<bits/stdc++.h>

#define MAX_CHAR 1000

using namespace std;

int lcs[MAX_CHAR+1][MAX_CHAR+1];

void LCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    for(int i=n; i>=0; i--)
        for(int j=m; j>=0; j--)
        {
            if(i==n || j==m)
            {
                lcs[i][j]=0;
                continue;
            }

            if(s1[i]==s2[j])
                lcs[i][j]=1+lcs[i+1][j+1];
            else lcs[i][j]=max(lcs[i+1][j], lcs[i][j+1]);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    string s1, s2;

    while(getline(cin, s1))
    {
        getline(cin, s2);

        LCS(s1, s2);

        printf("%d\n", lcs[0][0]);
    }
    return 0;
}
