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
	string s;
	cin >> n >> s;

	int ans = 0;
	map<char,int> m;
	rep(i,s.size())
	{
		m[s[i]]++;

		int id = s[i+1]-'A';
		if(m['a'+id] > 0)
		{
			m['a'+id]--;
		}
		else ans++;

		i++;
	}

	cout << ans << endl;
	
	return 0;
}
