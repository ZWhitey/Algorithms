#include<iostream>
#include<vector>
#include<ctime>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool>vb;
typedef pair<int, int> ii;
#define pb emplace_back
void dfs(vvi g, int start,vi &v,vb &p,int t)
{
	queue<int>q;
	p[start] = true;
	v.pb(start);
	for (int i = 0; i < g[start].size(); ++i)
		if(!p[g[start][i]]&&g[start][i]!=t)
			q.emplace(g[start][i]);
	while (q.size()!=0)
	{
		int next = q.front();
		q.pop();
		if(!p[next])
			dfs(g, next, v, p,t);
	}
}
vi AP(vvi g)
{
	vi r;
	for (int i = 0; i < g.size(); ++i)
	{
		vi v;
		vb p(g.size(),false);
		if(i==0)
			dfs(g, 1, v, p, i);
		else
			dfs(g, 0, v, p, i);
		if(v.size()!=g.size()-1)
			r.pb(i);
	}
	return r;
}

void addedge(vvi &g,int a,int b)
{
	g[a].pb(b);
	g[b].pb(a);
}

int main()
{
	vvi g1(5);
	addedge(g1, 1, 0);
	addedge(g1, 0, 2);
	addedge(g1, 2, 1);
	addedge(g1, 0, 3);
	addedge(g1, 3, 4);
	vi r1 = AP(g1);
	vvi g2(4);
	addedge(g2, 0, 1);
	addedge(g2, 1, 2);
	addedge(g2, 2, 3);
	vi r2 = AP(g2);
	vvi g3(7);
	addedge(g3, 0, 1);
	addedge(g3, 1, 2);
	addedge(g3, 2, 0);
	addedge(g3, 1, 3);
	addedge(g3, 1, 4);
	addedge(g3, 1, 6);
	addedge(g3, 3, 5);
	addedge(g3, 4, 5);
	vi r3 = AP(g3);
	return 0;
}