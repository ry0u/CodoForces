#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


set<ull> st[300];
vector<string> ss[600000];
ull P = 100000007;
ull pw[300];

int main()
{
	int n,m;
	cin >> n >> m;
	
	pw[0] = 1;
	REP(i,1,300) pw[i] = pw[i-1]*P;

	rep(i,n)
	{
		string s;
		cin >> s;
		
		if(s.size() > 300000) continue;
		if(s.size() < 300)
		{
			ull t = 0;
			rep(j,s.size())
			{
				t += s[j]*pw[j];
			}

			st[s.size()].insert(t);
		}
		else ss[s.size()].push_back(s);
	}

	rep(i,m)
	{
		string s;
		cin >> s;

		if(s.size() < 300)
		{
			ull t = 0;
			rep(j,s.size())
			{
				t += s[j]*pw[j];
			}
			
			bool flag = false;
			rep(j,s.size())
			{
				ull nt = t;
				t -= s[j]*pw[j];

				rep(k,3)
				{
					if(s[j] != 'a' + k)
					{
						if(st[s.size()].count(t+(pw[j]*('a' + k)))) flag = true;
					}
				}
				
				t += s[j]*pw[j];
			}

		
			if(flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else
		{
			bool flag = false;

			rep(j,ss[s.size()].size())
			{
				int cnt = 0;
				rep(k,s.size())
				{
					if(ss[s.size()][j][k] != s[k]) cnt++;

					if(cnt > 1) break;
				}

				if(cnt == 1) flag = true;
				if(flag) break;
			}

			if(flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}


	return 0;
}
