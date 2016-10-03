#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

vector<pair<int,int> > G[101];
bool used[101];
int ans = 0;

void dfs(int s,int c,int t)
{
	if(s == t) 
	{
		ans++;
		return;
	}
	else
	{
		rep(i,G[s].size())
		{
			if(G[s][i].second == c && !used[G[s][i].first])
			{
				used[G[s][i].first] = true;
				dfs(G[s][i].first,G[s][i].second,t);
			}
		}
	}
}

int main()
{
	int n,m;
	cin >> n >> m;

	rep(i,m)
	{
		int a,b,c;
		cin >> a >> b >> c;

		a--;
		b--;

		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}

	int q;
	cin >> q;
	rep(i,q)
	{
		int a,b;
		cin >> a >> b;

		a--;
		b--;
		ans = 0;

		vector<int> c;
		rep(j,G[a].size())
		{
			vector<int>::iterator it = find(c.begin(),c.end(),G[a][j].second);
			if(it == c.end())
			{
				c.push_back(G[a][j].second);
			}
		}

		rep(j,c.size())
		{
			rep(k,n) used[k] = false;
			used[a] = true;
			dfs(a,c[j],b);
		}

		cout << ans << endl;
	}
}
