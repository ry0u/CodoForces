#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
	int n,m,k;
	cin >> n >> m >> k;

	vector<int> v(n),p(n+1);
	rep(i,n)
	{
		int a;
		cin >> a;

		v[i] = a;
		p[a] = i;
	}

	ll ans = 0;

	rep(i,m)
	{
		int b;
		cin >> b;
		
		ans += p[b] / k;
		ans++;
		if(p[b] == 0) continue;

		int t = v[p[b]-1];

		p[b]--;
		p[t]++;

		v[p[b]] = b;
		v[p[t]] = t;
	}

	cout << ans << endl;
	

	return 0;
}
