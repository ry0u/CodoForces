#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

bool check(string s)
{
	rep(i,s.size()/2)
	{
		if(s[i] != s[s.size()-1-i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string s;
	cin >> s;

	vector<char> v;
	rep(i,s.size())
	{
		v.push_back(s[i]);
	}

	bool flag = true;
	string ans;

	rep(i,s.size())
	{
		if(!flag) break;
		string ns = "";
		ns.resize(s.size()+1);
		
		rep(j,i) 
		{
			ns[j] = s[j];
		}

		rep(j,v.size())
		{
			if(!flag) break;

			ns[i] = v[j];

			REP(k,i+1,s.size()+1)
			{
				ns[k] = s[k-1];
			}

			if(check(ns))
			{
				flag = false;
				ans = ns;
			}
		}
	}

	if(flag)
	{
		string ns;
		ns.resize(s.size()+1);

		rep(i,s.size()) ns[i] = s[i];

		rep(i,v.size())
		{
			ns[ns.size()-1] = v[i];
				
			if(check(ns))
			{
				flag = false;
				ans = ns;
				break;
			}
		}
	}

	if(flag) cout << "NA" << endl;
	else cout << ans << endl;
}
