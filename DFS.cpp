#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define pb emplace_back
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi>vii;

void dfs(int cur,vii &g,vb &p, vi &r)
{
	queue<int>q;
	p[cur] = true;
	r.pb(cur);
	for (int i = 0, s = p.size(); i < s; ++i)
	{
		if (g[cur][i]==1&&!p[i] && i != cur)
			q.emplace(i);
	}
	while (q.size() != 0)
	{
		int next = q.front();
		q.pop();
		dfs(next, g, p, r);
	}
	
	return;
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
	vb p(m,false);
	vi r;
	dfs(5,g, p, r);

	return 0;
}