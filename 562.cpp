/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.050s
Memory : 
*/

#include<bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_COINS 100
#define MAX_SUM 25001

using namespace std;

int n,testCase=1;
int m,i,k,total_sum;
int coin_values[MAX_COINS];
int data[MAX_COINS][MAX_SUM];

void reset()
{
    mem(data,-1);

    total_sum = k;

    if(k%2 == 0)
        k /= 2;
    else
    {
        k--;
        k /= 2;
        k++;
    }
}

int dp(int index, int weight)
{
    if(index >= m)
        return 0;
    if(data[index][weight] != -1)
        return data[index][weight];

    int profit1=0,profit2=0;

    if(weight + coin_values[index] <= k)
        profit1 = coin_values[index] + dp(index+1, weight + coin_values[index]);

    profit2 = dp(index+1, weight);

    return data[index][weight] = max(profit1,profit2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &n);

    while(testCase<=n)
    {
        scanf("%d", &m);

        k=0;

        for(i=0; i<m; i++)
        {
            scanf("%d", &coin_values[i]);
            k += coin_values[i];
        }

        reset();

        int result = dp(0,0);

        int temp1 = total_sum - result;
        int temp2 = total_sum - temp1;

        printf("%d\n", abs(temp1-temp2));

        testCase++;
    }
    return 0;
}
