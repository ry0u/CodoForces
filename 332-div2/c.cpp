#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	int n;
	cin >> n;

	vector<ll> v(n);
	map<ll, vector<int> > m;

	vector<ll> t(n);
	ll index = INF;
	ll ch = INF;
	rep(i, n) {
		cin >> v[i];
		ch = min(ch, v[i]);
	}

	ll cnt = 0;
	vector<ll> v2;
	ll pre = -1, val = 0;
	ll now = ch;
	rep(i, n) {
		ll d = v[i];
		int len = 1;

		REP(j, i+1, n) {
			if(d == v[j]) {
				len++;
				i++;
				continue;
			} else break;
		}

		if(len >= 2) {
			cnt += len-1;
		}

		v2.push_back(d);
		val = d;
		pre = len - 1;
	}

	rep(i, v2.size()) {
		t[i] = v2[i];
		index = min(index, v2[i]);
		m[v2[i]].push_back(i);
	}

	REP(i, 1, v2.size()) {
		t[i] = max(t[i], t[i-1]);
	}

	rep(i, v2.size()) {
		int j = m[index].back();
		if(j > i) {
			i = j;
			index = t[j];

		}

		cnt++;
	}

	cout << cnt << endl;
	return 0;
}
