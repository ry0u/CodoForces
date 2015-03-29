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
	int n,q;
	cin >> n >> q;

	map<string,bool> m;
	rep(i,n) 
	{
		string s;
		cin >> s;

		rep(j,s.size())
		{
			if(s[j] == 'a')
			{
				s[j] = 'b';
				m[s] = true;
				s[j] = 'c';
				m[s] = true;

				s[j] = 'a';
			}
			else if(s[j] == 'b')
			{
				s[j] = 'a';
				m[s] = true;
				s[j] = 'c';
				m[s] = true;

				s[j] = 'b';
			}
			else if(s[j] == 'c')
			{
				s[j] = 'a';
				m[s] = true;
				s[j] = 'b';
				m[s] = true;
				
				s[j] = 'c';
			}
		}
	}

	rep(i,q)
	{
		string s;
		cin >> s;

		if(m[s]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
