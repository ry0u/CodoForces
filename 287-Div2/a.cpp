#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;

	vector<pair<int,int> > v;
	v.resize(n);

	rep(i,n)
	{
		int temp;
		cin >> temp;

		v[i].first = temp;
		v[i].second = i+1;
	}

	sort(v.begin(),v.end());

	vector<int> ans;
	rep(i,n)
	{
		if(k <= 0) break;

		if(k - v[i].first >= 0)
		{
			k -= v[i].first;
			ans.push_back(v[i].second);
		}
	}

	sort(ans.begin(),ans.end());

	cout << ans.size() << endl;
	rep(i,ans.size())
	{
		cout << ans[i];

		if(i == ans.size()-1) cout << endl;
		else cout << " ";
	}
}
