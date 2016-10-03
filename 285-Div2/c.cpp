#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

vector<int> G[700000];

int main()
{
	int n;
	cin >> n;

	int d[1<<17],xo[1<<17],q[1<<17];
	memset(q,0,sizeof(q));
	rep(i,n)
	{
		cin >> d[i] >> xo[i];

		if(d[i] == 1) 
		{
			q[++q[0]] = i;
		}
	}

	vector<pair<int,int> > ans;
	REP(i,1,q[0]+1)
	{
		int x = q[i];
		if(d[x] == 0) continue;

		ans.push_back(make_pair(x,xo[x]));
		xo[xo[x]] ^= x;
		d[xo[x]]--;
		d[x]--;

		if(d[xo[x]] == 1)
		{
			q[++q[0]] = xo[x];
		}
	}

	cout << ans.size() << endl;
	rep(i,ans.size())
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
