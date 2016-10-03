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
    ll a,b,c;
	cin >> a >> b >> c;

	a = abs(a);
	b = abs(b);

	if(a + b == c) cout << "Yes" << endl;
	else if(a + b < c)
	{
		c -= a+b;
		if(c%2 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else cout << "No" << endl;
	return 0;
}
