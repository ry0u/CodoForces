#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	ll a,b,c;
	cin >> a >> b >> c;

	ll ans = a + b + c;
	ans = min(ans, a * 2 + b * 2);
	ans = min(ans, a * 2 + c * 2);
	ans = min(ans, b * 2 + c * 2);

	cout << ans << endl;

	return 0;
}
