#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define pb emplace_back
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi>vii;

vi bfs(int start,vii g,int m)
{
	vb p(m, false);
	queue<int>q;
	vi r(1, start);
	p[start] = true;
	for (int i = 0, s = g[start].size(); i < s; ++i)
		if (g[start][i] == 1&&i!=start)
			q.emplace(i);
	while (q.size() != 0)
	{
		int cur = q.front();
		q.pop();
		p[cur] = true;
		r.pb(cur);
		for (int i = 0, s = g[cur].size(); i < s; ++i)
			if (g[cur][i] == 1 && i != cur&&!p[i])
				q.emplace(i);
	}
	return r;
}

int main()
{
	vi input { 0, 1, 0, 2, 0, 3, 1, 4, 1, 6, 2, 5, 5, 7, 5, 8, 7, 10, 8, 9 };
	int m = *max_element(input.begin(), input.end())+1;
	vii g(m,vi(m,0));
	for (int i = 0, s = input.size(); i < s; i+=2)
	{
		g[input[i]][input[i + 1]] = 1;
		g[input[i+1]][input[i]] = 1;
	}
	vii p(m, vector<int>(m, 0));
	vi r = bfs(5,g,m);
	return 0;
}