#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,m,k;
	cin >> n >> m >> k;

	vector<vector<int> > v;
	vector<int> t;
	int j = 0;
	bool flag = false;
	rep(i,n) 
	{
		int a;
		cin >> a;
		t.push_back(a);
		
		j++;
		flag = false;

		if(j == k)
		{
			v.push_back(t);
			t.clear();
			j = 0;
			flag = true;
		}
	}

	if(!flag) v.push_back(t);

	int ans = 0;
	rep(i,m)
	{
		int b;
		cin >> b;

		int cnt = 0;
		rep(j,v.size())
		{
			if(find(v[j].begin(),v[j].end(),b) == v[j].end())
			{
				cnt++;
				continue;
			}


			if(j == 0 && v[j][0] == b) break;
			else if(v[j][0] == b)
			{
				swap(v[j-1][k-1],v[j][0]);
			}
			else
			{
				int k = 0;
				rep(l,v[j].size()) if(v[j][l] == b) k = l;

				swap(v[j][k-1],v[j][k]);
			}
			break;
		}

		ans += cnt + 1;
	}

	cout << ans << endl;


	
	return 0;
}
