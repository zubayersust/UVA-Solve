/**
Online Judge : UVA Online Judge
Problem No   : 572
Problem Name : Oil Deposits
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.0s
Memory       :
Algorithm    : DFS
*/

#include<bits/stdc++.h>

using namespace std;

int dir_x[] = {+1, +1, +1, -1, -1, -1, 0, 0};
int dir_y[] = {+1, -1, 0, +1, -1, 0, +1, -1};

void DFS(int node_x, int node_y, int m, int n, vector<string> &v, vector<vector<bool>> &visited)
{
	visited[node_x][node_y] = true;

	for(int i = 0; i < 8; i++) {
		int next_x = node_x + dir_x[i];
		int next_y = node_y + dir_y[i];

		if(next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && visited[next_x][next_y] == false) {
			visited[next_x][next_y] = true;

			if(v[next_x][next_y] == '@')
				DFS(next_x, next_y, m, n, v, visited);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

	int m, n;
	string s;

	while(true) {
		cin >> m >> n;

		if(m == 0) break;

		vector<string> v;
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for(int i = 0; i < m; i++) {
			cin >> s;

			v.push_back(s);
		}

		int result = 0;

		for(int i = 0; i < m; i++) {
			for(int k = 0; k < n; k++) {
				if(v[i][k] == '@' && visited[i][k] == false) {
					result++;

					DFS(i, k, m, n, v, visited);
				}
			}
		}

		cout << result << endl;
	}

	return 0;
}
