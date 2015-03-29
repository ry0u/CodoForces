#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <iterator>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	string s,t;
	cin >> s >> t;

	map<char,int> m,m2,all;

	rep(i,s.size()) 
	{
		m[s[i]]++;
		all[s[i]]++;
	}
	rep(i,t.size()) 
	{
		m2[t[i]]++;
		all[t[i]]++;
	}

	int ans = 0,ret = 0;

	map<char,int>::iterator ite;
	for(ite = all.begin();ite != all.end();ite++)
	{
		char c = ite->first;
		int x = min(m[c],m2[c]);
		m[c] -= x;
		m2[c] -= x;
		ans += x;
	}

	rep(i,26)
	{
		int x = min(m['a'+i],m2['A'+i]);
		m['a'+i] -= x;
		m2['A'+i] -= x;
		ret += x;
	}

	rep(i,26)
	{
		int x = min(m['A'+i],m2['a'+i]);
		m['A'+i] -= x;
		m2['a'+i] -= x;
		ret += x;
	}

	cout << ans << " " << ret << endl;

	return 0;
	
}
