#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int n;
	cin >> n;

	vector<ll> v(n),t;
	rep(i,n) 
	{
		cin >> v[i];
	}

	sort(v.begin(),v.end(),greater<ll>());
	
	ull ans = 0;
	rep(i,n-1)
	{
		ll a = abs(v[i+1]-v[i]);
		
		if(a <= 1)
		{
			t.push_back(v[i+1]);
			i++;
		}
	}

	if(t.size() <= 1) cout << 0 << endl;
	else
	{
		rep(i,t.size()-1)
		{
			ans += t[i]*t[i+1];
			i++;
		}

		cout << ans << endl;
	}

	return 0;
}
