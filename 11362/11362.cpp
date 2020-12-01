/**
Online Judge : UVA Online Judge
Problem No   : 11362
Problem Name : Phone List
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 5.000s
CPU          : 0.190s
Memory       :
Algorithm    : Trie
*/

#include<bits/stdc++.h>

using namespace std;

bool compareFunc(string s1, string s2)
{
    return s1.size() > s2.size();
}

priority_queue<string, vector<string>, function<bool(string, string)> > q(compareFunc);

class Node
{
public:
    bool word;
    Node *next[10+1];

    Node()
    {
        word = false;

        for(int i=0; i<10; i++)
            next[i] = NULL;
    }
};

Node *root;
bool consistent;

void Insert(string s, int len)
{
    Node *current_node = root;

    for(int i=0; i<len; i++)
    {
        int id = s.at(i) - '0';

        if(current_node->next[id] == NULL)
            current_node->next[id] = new Node();
        else
        {
            current_node = current_node->next[id];

            if(current_node->word)
            {
                consistent = false;

                return;
            }

            continue;
        }

        current_node = current_node->next[id];
    }
    current_node->word = true;
}

void reset(Node *current_node)
{
    int i;

    for(i=0; i<10; i++)
        if(current_node->next[i])
            reset(current_node->next[i]);

    delete(current_node);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int testCases;
    int n;

    scanf("%d", &testCases);

    while(testCases--)
    {
        scanf("%d", &n);

        int i;
        string s;

        for(i=0; i<n; i++)
        {
            cin>>s;
            q.push(s);
        }

        root = new Node();
        consistent = true;

        while(!q.empty())
        {
            string str = q.top();
            q.pop();
            Insert(str, str.size());
        }

        if(consistent)
            printf("YES\n");
        else printf("NO\n");

        reset(root);
    }
    return 0;
}
