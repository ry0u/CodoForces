#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
   	ll r,x,y,x2,y2;
	cin >> r >> x >> y >> x2 >> y2;

	double res = sqrt( (x2-x)*(x2-x) + (y2-y)*(y2-y) );
	int ans = 0;

	while(res > 0)
	{
		ans++;
		res -= 2*r;
	}

	cout << ans << endl;

	return 0;
}
