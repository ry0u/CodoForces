#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define REP(i,k,n) for(int i=k<;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	
	string S = "SL",T = "LS";

	int cnt = 0;
	vector<string> s;
	rep(i,n)
	{
		stringstream ss;
		rep(j,n)
		{
			if(i%2 == 0)
			{
				if(cnt >= k) 
				{
				   	ss << "S";
					continue;
				}

				ss << T[j%2];
				if(j%2 == 0) cnt++;
			}
			else
			{
				if(cnt >= k)
				{
					ss << "S";
					continue;
				}

				ss << S[j%2];
				if(j%2 != 0) cnt++;
			}
		}
		s.push_back(ss.str());
	}

	if(cnt == k)
	{
		cout << "YES" << endl;
		rep(i,s.size()) cout << s[i] << endl;
	}
	else cout << "NO" << endl;

	return 0;
}
