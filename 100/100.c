/**
Online Judge : UVA Online Judge
Problem No   : 100
Problem Name : The 3n + 1 problem
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.602s
Memory       :
Algorithm    : Ad-hoc
*/

#include<stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int a,b,n,m=1,temp1,temp2,p,q,length,max=1,c,d;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        max=1;
        c=a;
        d=b;
        p=a;
        q=b;
        if(a>b)
        {
            p=b;
            q=a;
        }
        for(a=p; a<=q; a++)
        {
            n=a;
            if(n==1)
                m=1;
            if(n>1)
            {
                m=1;
                while(n!=1)
                {
                    if(n%2==1)
                    {
                        n=3*n+1;
                        m++;
                    }
                    if(n%2==0)
                    {
                        n=n/2;
                        m++;
                    }
                }
            }
            length=m;
            if(length>max)
                max=length;
            else length=length;
        }
        printf("%d %d %d\n",c,d,max);
    }
    return 0;
}
