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
typedef pair<ll, ll> P;

struct abs_sort {
	bool operator()(P a, P b) const {
		if(abs(a.first) != abs(b.first)) return abs(a.first) > abs(b.first);
		if(a.first != b.first) return a.first > b.first;
		return a.second > b.second;
	}
};


int main() {
	int n, k; ll x;

	cin >> n >> k >> x;

	ll vmin = INF, vcnt = 0;
	vector<ll> v(n);
	rep(i, n) {
		cin >> v[i];
		vmin = min(vmin, v[i]);

		if(v[i] < 0) vcnt++;
	}

	priority_queue<P, vector<P>, abs_sort> Q;
	rep(i, n) {
		Q.push(mp(v[i], i));
	}
	if(vcnt % 2 == 0) {
		P top = Q.top(); Q.pop();

		ll cnt = (abs(top.first) + 1) / x;
		if((abs(top.first) + 1) % x != 0) cnt++;

		if(cnt <= k) {
			k -= cnt;
		} else {
			cnt = k;
			k = 0;
		}

		if(top.first >= 0) {
			top.first -= cnt * x;
		} else {
			top.first += cnt * x;
		}

		Q.push(top);
	}

	rep(i, k) {
		P p = Q.top(); Q.pop();
		if(p.first >= 0) {
			Q.push(mp(p.first + x, p.second));
		} else {
			Q.push(mp(p.first - x, p.second));
		}
	}

	vector<P> ans;
	while(Q.size()) {
		P p = Q.top(); Q.pop();
		ans.push_back(mp(p.second, p.first));
	}

	sort(ans.begin(), ans.end());
	rep(i, n) {
		if(i) cout << " ";
		cout << ans[i].second;
	}
	cout << endl;
	
	return 0;
}
