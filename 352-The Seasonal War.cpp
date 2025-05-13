/**
Online Judge : UVA Online Judge
Problem No   : 572
Problem Name : The Seasonal War
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
int dir_y[] = {0, 1, -1, 0, +1, -1, 1, -1};

void DFS(int node_x, int node_y, int n, vector<string> &v, vector<vector<bool>> &visited)
{
	visited[node_x][node_y] = true;

	for(int i = 0; i < 8; i++) {
		int next_x = node_x + dir_x[i];
		int next_y = node_y + dir_y[i];

		if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visited[next_x][next_y] == false) {
			visited[next_x][next_y] = true;

			if(v[next_x][next_y] == '1')
				DFS(next_x, next_y, n, v, visited);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

	int n;
	string pixel;
	int imageCount = 1;

	while(scanf("%d", &n) == 1) {
		vector<string> v;
		vector<vector<bool>> visited(n, vector<bool>(n, false));

		for(int i = 0; i < n; i++) {
			cin >> pixel;

			v.push_back(pixel);
		}

		int result = 0;

		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				if(v[i][k] == '1' && visited[i][k] == false) {
					result++;
					DFS(i, k, n, v, visited);
				}

		printf("Image number %d contains %d war eagles.\n", imageCount, result);

		imageCount++;
	}

	return 0;
}
