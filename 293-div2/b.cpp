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
	string s,t;
	cin >> s >> t;

	map<char,int> m;
	rep(i,t.size())
	{
		m[t[i]]++;
	}

	int y = 0,w = 0;
	rep(i,s.size())
	{
		if(m[s[i]] > 0)
		{
			y++;
			m[s[i]]--;
		}
		else w++;
	}

	cout << y << " " << w << endl;
	return 0;
}
