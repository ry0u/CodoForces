#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;

	if(n%2 == 0)
	{
		stringstream ss;
		ss << n;
		string s = ss.str();

		int m = 0;
		rep(i,s.size()-1)
		{
			if(s[i] >= s[m])
			{
				m = i;
			}
		}

		swap(s[0],s[m]);


		string s2 = ss.str();
		m = s2.size()-1;
		rep(i,s2.size()-1)
		{
			if((s2[i] - '0')%2 == 0)
			{
				if(s2[i] < s2[m])
				{
					m = i;
				}
			}
		}

		swap(s2[s.size()-1],s2[m]);
		cout << max(s,s2) << endl;
	}
	else
	{
		stringstream ss;
		ss << n;
		string s = ss.str();

		int m = INF;
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i] - '0')%2 == 0)
			{
				m = i;
			}
		}

		if(m == INF) cout << -1 << endl;
		else
		{
			rep(i,s.size())
			{
				if((s[i]-'0')%2 == 0)
				{
					if(s[i] > s[s.size()-1])
					{
						if(s[i] <= s[m])
						{
							m = i;
						}
					}
					else
					{
						if(s[i] < s[m])
						{
							m = i;
						}
					}
				}
			}

			swap(s[s.size()-1],s[m]);
			cout << s << endl;
		}
	}

	return 0;
}
