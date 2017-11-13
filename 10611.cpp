/**
Online Judge : SPOJ
Problem No   : 10798
Problem Name : WACHOVIA - Wachovia Bank
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.02s
Memory       : 2.9M
Algorithm    : 0/1 Knapsack
*/

#include<bits/stdc++.h>

#define MAX_N 50000
#define MAX_Q 25000

using namespace std;

int ara[MAX_N+1];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n;

    while(scanf("%d", &n)==1)
    {
        int i;

        for(i=0; i<n; i++)
            scanf("%d", &ara[i]);

        int q;

        scanf("%d", &q);

        for(i=0; i<q; i++)
        {
            int m;

            scanf("%d", &m);

            if(n==1 && m==ara[0])
                printf("X X\n");
            else if(m>ara[n-1])
                printf("%d X\n",ara[n-1]);
            else if(m<ara[0])
                printf("X %d\n",ara[0]);
            else
            {
                int _begin = 0;
                int _end   = n-1;
                int pos    = -1;
                int mid;

                while(_begin<=_end)
                {
                    mid = (_begin+_end)/2;

                    if(m==ara[mid])
                    {
                        pos  = mid;
                        _end = mid-1;
                    }
                    else if(m<ara[mid])
                        _end = mid-1;
                    else if(m>ara[mid])
                        _begin = mid+1;
                }

                if(pos==-1)
                    printf("%d %d\n",ara[_begin-1],ara[_begin]);
                else
                {
                    int l_pos = pos;
                    int r_pos = pos;

                    while(r_pos<n && !(ara[r_pos]>ara[pos]))
                        r_pos = r_pos+1;

                    while(l_pos>-1 && !(ara[l_pos]<ara[pos]))
                        l_pos = l_pos-1;

                    if(l_pos>=0 && r_pos<n)
                        printf("%d %d\n",ara[l_pos],ara[r_pos]);
                    else if(l_pos<0 && r_pos<n)
                        printf("X %d\n",ara[r_pos]);
                    else if(l_pos>=0 && r_pos==n)
                        printf("%d X\n",ara[l_pos]);
                    else printf("X X\n");
                }
            }
        }
    }
    return 0;
}
