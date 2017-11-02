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
vector<ii> mst(vvi g, vi &d,int start)
{
	vb p(d.size(), false);
	p[start] = true;
	d[start] = 0;
	int v = 1;
	vector<ii> edge;
	vector<ii> Tedge;
	for (int i = 0; i < g[start].size(); ++i)
		if (g[start][i] != 0)
			edge.pb(ii(start, i));
	while (v++ < d.size())
	{
		ii min=edge[0];
		int e = 0;
		for (int i = 1; i < edge.size(); ++i)
		{
			if (!p[edge[i].first]&&!p[edge[i].second])
				continue;
			int cde = max(d[edge[i].first],d[edge[i].second]);
			int cd = max(d[min.first], d[min.second]);
			if (cde+g[edge[i].first][edge[i].second] < cd+g[min.first][min.second])//shortest distence
			{
				min = edge[i];
				e = i;
			}
		}
		Tedge.pb(min);
		p[min.second] = true;
		d[min.second] = d[min.first] + g[min.first][min.second];
		edge.clear();
		for (int i=0;i<p.size();++i)
			if (p[i])
			{
				for (int j = 0; j < g.size(); ++j)
				{
					if (!p[j]&& g[i][j] != 0)
					{
						edge.pb(ii(i, j));
					}
				}
			}

	}
	return Tedge;
}
int main()
{
	vvi g= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};
	vi d(g.size(),-1);
	vector<ii> Tedge = mst(g, d, 0);


	return 0;
}