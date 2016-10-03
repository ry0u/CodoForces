#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	
	map<char,int> m;
	rep(i,s.size())
	{
		m[s[i]]++;
	}

	int cnt = 0;
	rep(i,26)
	{
		if(m['a'+i]) cnt++;
	}

	if(cnt < n)
	{
		cout << "NO" << endl;
		return 0;
	}

	bool used[10000];
	memset(used,0,sizeof(used));
	
	cout << "YES" << endl;
	cout << s[0];
	used[s[0]-'0'] = true;

	int ans = 1;
	REP(i,1,s.size())
	{
		if(!used[s[i]-'0'] && ans < n)
		{
			cout << endl;
			used[s[i]-'0'] = true;
			ans++;
		}

		cout << s[i];
	}
	cout << endl;

	return 0;
}
