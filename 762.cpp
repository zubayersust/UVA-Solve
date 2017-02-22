/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.033s
Memory : 
*/

#include<bits/stdc++.h>

using namespace std;

map<string,vector<string>> mp;
map<string,string> parent;
map<string,int> visited;

void __init__()
{
    mp.clear();
    parent.clear();
    visited.clear();
}

int _bfs(string _start, string _end)
{
    queue<string> q;

    visited[_start]=1;
    parent[_start]=_start;
    q.push(_start);

    int len,i;
    string str,s;

    while(!q.empty())
    {
        str=q.front();
        q.pop();

        len=mp[str].size();

        for(i=0; i<len; i++)
        {
            s=mp[str][i];

            if(!visited[s])
            {
                visited[s]=1;
                q.push(s);
                parent[s]=str;
            }
            if(s==_end)
                break;
        }

        if(s==_end)
            return 1;
    }
    return -1;
}

void printPath(string _start,string _end)
{
    if(_end==_start)
        return;
    printPath(_start,parent[_end]);
    cout<<parent[_end]<<" "<<_end<<endl;
}

int main()
{
    int testCase;

    bool newLine=false;

    while(cin>>testCase)
    {
        __init__();

        int i;
        string str1,str2;

        for(i=0; i<testCase; i++)
        {
            cin>>str1>>str2;

            mp[str1].push_back(str2);
            mp[str2].push_back(str1);

            visited[str1]=0;
            visited[str2]=0;
        }

        cin>>str1>>str2;

        if(newLine)
            cout<<endl;
        newLine=true;

        if(str1==str2)
            cout<<str1<<" "<<str2<<endl;
        else if(_bfs(str1,str2)==-1)
            cout<<"No route"<<endl;
        else
            printPath(str1,str2);
    }
    return 0;
}
