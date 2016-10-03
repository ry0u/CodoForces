#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int lcm(int m,int n)
{
	if(m == 0 || n == 0) return 0;
	return ((m / __gcd(m,n)) * n);
}

int main()
{
	int n,m;
	cin >> n >> m;

	vector<bool> v(n);
	rep(i,n) v[i] = false;

	vector<bool> p(m);
	rep(i,m) p[i] = false;

	int b;
	cin >> b;
	rep(i,b)
	{
		int t;
		cin >> t;

		v[t] = true;
	}

	int g;
	cin >> g;
	rep(i,g)
	{
		int t;
		cin >> t;

		p[t] = true;
	}
	
	int i = 0;
	int j = 0;
	
	rep(k,10000000)
	{
		if(v[i] || p[j])
		{
			v[i] = true;
			p[j] = true;
		}

		i++;
		j++;

		i %= n;
		j %= m;
	}

	bool flag = true;
	rep(i,n) if(!v[i]) flag = false;
	rep(i,m) if(!p[i]) flag = false;

	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl; 

	return 0;
}
