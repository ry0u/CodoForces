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

	map<char,bool> m;
	rep(i,s.size())
	{
		m[s[i]] = true;
	}

	bool flag = true;
	rep(i,26)
	{
		char c = 'a' + i;
		char c2 = 'A' + i;
		
		if(!m[c] && !m[c2]) flag = false;
	}

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
