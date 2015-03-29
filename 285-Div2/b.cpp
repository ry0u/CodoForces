#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<string,string> m;
	map<string,bool> can;
	map<string,bool> used;
	vector<pair<string,string> > v;

	rep(i,n)
	{
		string s,s2;
		cin >> s >> s2;
		
		m[s] = s2;
		can[s] = true;
		v.push_back(make_pair(s,s2));
	}

	vector<pair<string,string> > res;
	rep(i,n)
	{
		string temp = v[i].first;
		if(used[temp]) continue;
		while(can[temp] && !used[temp])
		{
			used[temp] = true;
			temp = m[temp];
		}

		res.push_back(make_pair(v[i].first,temp));
	}

	sort(res.begin(),res.end());

	cout << res.size() << endl;
	rep(i,res.size())
	{
		cout << res[i].first << " " << res[i].second << endl;
	}

}
