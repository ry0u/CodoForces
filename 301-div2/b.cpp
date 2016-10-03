#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int main()
{
	int n,k,p,x,y;
	cin >> n >> k >> p >> x >> y;

	int sum = 0;
	int pre = y;
	vector<int> v(k);
	rep(i,k)
	{
		cin >> v[i];
		sum += v[i];
	}

	vector<int> ans;
	bool flag = true;
	int cnt = n-k;

	if(cnt + sum > x) 
	{
		flag = false;
	}
	else
	{
		rep(i,cnt)
		{
			ans.push_back(1);
		}

		if(pre != 1) 
		{
			int res = x - (sum + cnt);
			int ret = res/(pre-1);

			for(int i=0;i<ret;i++)
			{
				if(i >= ans.size()) break;
				ans[i] += pre-1;
			}
		}
	}

	if(flag)
	{
		rep(i,ans.size()) v.push_back(ans[i]);
		sort(v.begin(),v.end());

		if(v[v.size()/2] >= y)
		{
			rep(i,ans.size())
			{
				cout << ans[i];
				if(i == ans.size()-1) cout << endl;
				else cout << " ";
			}
		}
		else cout << -1 << endl;
	}
	else
	{
		cout << -1 << endl;
	}


	return 0;
}
