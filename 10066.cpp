/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.00s
Memory : 
*/

#include<bits/stdc++.h>

#define maxBlock 105

using namespace std;

int n1,n2;
int testCase=0;
int ara1[maxBlock],ara2[maxBlock];
int dp[maxBlock][maxBlock],visited[maxBlock][maxBlock];

void Reset()
{
    int i,j;

    for(i=0; i<n1; i++)
        for(j=0; j<n2; j++)
            visited[i][j]=0;
}

int myFunction(int i, int j)
{
    if(i==n1 || j==n2)
        return 0;

    if(visited[i][j])
        return dp[i][j];

    int block=0;
    int val1,val2;

    if(ara1[i]==ara2[j])
        block = 1+myFunction(i+1, j+1);
    else
    {
        val1 = myFunction(i+1, j);
        val2 = myFunction(i, j+1);
        block = max(val1, val2);
    }

    visited[i][j]=1;

    return dp[i][j] = block;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    while(scanf("%d %d", &n1, &n2)==2)
    {
        if(n1==0 && n2==0)
            return 0;

        int i,ans;

        for(i=0; i<n1; i++)
            scanf("%d", &ara1[i]);
        for(i=0; i<n2; i++)
            scanf("%d", &ara2[i]);

        Reset();

        ans = myFunction(0,0);

        cout<<"Twin Towers #"<<++testCase<<endl;
        cout<<"Number of Tiles : "<<ans<<"\n"<<endl;
    }
    return 0;
}
