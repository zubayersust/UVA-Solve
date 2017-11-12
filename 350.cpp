/**
Online Judge : UVA Online Judge
Problem No   : 350
Problem Name : Pseudo-Random Numbers
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.05s
Memory       :
Algorithm    : Floyd Cycle Finding
*/

#include<bits/stdc++.h>

using namespace std;

class Random
{
public:
    int val;
    Random *next;

    Random(int val, Random *next)
    {
        this->val  = val;
        this->next = next;
    }

    Random()
    {

    }
};

map<int, bool> mp;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int z,i,m,l;
    int caseNum=1;

    while(scanf("%d %d %d %d", &z, &i, &m, &l)==4)
    {
        if(z==0 && i==0 && m==0 && l==0)
            return 0;

        Random *root = NULL;
        Random *ptr  = NULL;

        int rd_num;
        int n = 0;

        while(true)
        {
            rd_num = ((z*l)+i)%m;

            if(mp[rd_num]==true)
            {
                Random *node = root;

                while(node->val != rd_num)
                {
                    node = node->next;
                    n++;
                }

                ptr->next = node;

                break;
            }
            else
            {
                if(root==NULL)
                {
                    root       = new Random(rd_num, NULL);
                    ptr        = root;
                    mp[rd_num] = true;
                }
                else
                {
                    Random *node   = new Random(rd_num, NULL);
                    ptr->next      = node;
                    ptr            = node;
                    mp[rd_num]     = true;
                }
            }

            l = rd_num;
        }

        if(n==0)
            printf("Case %d: %d\n",caseNum++, mp.size());
        else
            printf("Case %d: %d\n",caseNum++, mp.size()-n);

        mp.clear();
    }
    return 0;
}
