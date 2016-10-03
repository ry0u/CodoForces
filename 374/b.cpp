#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	int n, k;
	cin >> n >> k;

	vector<string> v(n);
	rep(i, n) cin >> v[i];

	string s;
	cin >> s;

	map<int, vector<string> > m;
	rep(i, n) {
		int sz = v[i].size();

		m[sz].push_back(v[i]);
	}

	int ans = 0, cnt = 0;
	each(it, m) {
		vector<string> x = it->second;

		if(it->first == s.size()) {
			int a = ans + 1;

			int res = cnt + x.size();
			if(res / k > 0) {
				ans += (res / k) * 5;

				if(res % k == 0) ans -= 5;
			}
			ans += x.size();

			cout << a << " " << ans << endl;

			break;
		} else {
			int res = cnt + x.size();
			if(res / k > 0) {
				ans += (res / k) * 5;
			}
			cnt = (cnt + x.size()) % k;
			ans += x.size();
		}
	}

	return 0;
}
