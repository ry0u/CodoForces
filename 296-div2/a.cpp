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
    ll a,b;
	cin >> a >> b;

	ll ans = 0;
	while(true)
	{
		ll q = (a/b);
		ans += q;
		a = a - q*b;

		if(a == 0) break;
		if(a < b) swap(a,b);

		if(b == 1)
		{
			ans += a;
			break;
		}
	}
	
	cout << ans << endl;
	return 0;
}
