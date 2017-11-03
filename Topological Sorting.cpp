#include<iostream>
#include<vector>
#include<ctime>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool>vb;
typedef pair<int, int> ii;
#define pb emplace_back
void topological(int p,vvi g, vb &v,vi &r)
{
	v[p] = true;
	for (int i = 0; i < g[p].size(); ++i)
	{
		if (!v[g[p][i]])
			topological(g[p][i], g, v, r);
	}
	r.pb(p);
}

vi topologicalsort(vvi g)
{
	vb v(g.size(),false);
	vi r;
	for (int i = 0; i < g.size(); ++i)
	{
		if (!v[i])
		{
			topological(i,g, v,r);
		}
	}
	return r;

}

int main()
{
	vvi g(6);
	g[5].pb(2);
	g[5].pb(0);
	g[4].pb(0);
	g[4].pb(1);
	g[2].pb(3);
	g[3].pb(1);
	vi r = topologicalsort(g);
	return 0;
}