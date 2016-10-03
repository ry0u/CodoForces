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
	int n,m;
	cin >> n >> m;

	vector<string> v(n);
	map<string,bool> ma;
	rep(i,n) 
	{
		string s;
		cin >> s;

		rep(j,s.size())	
		{
			string t = s.substr(0,j) + s.substr(j+1,s.size()-j-1);
			ma[t] = true;
		}
	}

	rep(i,m)
	{
		string s;
		cin >> s;

		bool flag = true;
		rep(j,s.size())
		{
			string t = s.substr(0,j) + s.substr(j+1,s.size()-j-1);
			if(ma[t]) 
			{
				cout << "YES" << endl;
				flag = false;
				break;
			}
		}

		if(flag) cout << "NO" << endl;
	}

	
	return 0;
}
