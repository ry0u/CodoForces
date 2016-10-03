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
	int n;
	cin >> n;

	vector<ll> v(n);
	map<int, pair<int,int> > m;
	vector<ll> id(n), t(n);
	rep(i, n) {
		cin >> v[i];
		id[i] = v[i];
		t[i] = v[i];

		if(m.count(v[i]) == 0) {
			m[v[i]] = mp(i, i);
		} else {
			m[v[i]].first = min(m[v[i]].first, i);
			m[v[i]].second = max(m[v[i]].second, i);
		}
	}

	REP(i, 1, n) {
		t[i] = max(t[i], t[i-1]);
	}

	set<int> st;
	map<int, int> res;
	rep(i, n) {
		if(st.find(v[i]) == st.end()) {
			st.insert(v[i]);
			int k = v[i];
			int len = 0;
			REP(j, i+1, n) {
				if(k == v[j]) {
					len++;
					i++;
					continue;
				} else break;
			}

			res[k] = len;
		}

	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());


	int right = -1;
	int cnt = 0;
	ll d = 0;

	rep(i, v.size()) {
		int j = m[v[i]].second;
		if(t[j] > v[i]) {
			i++;
			j = max(j, m[v[i]].second);
			continue;
		}
		if(right < j) {
			cnt++;
			if(t[j] <= v[i]) {
				cnt += res[v[i]];
			}
			right = j;
		}
	}

	cout << cnt << endl;

	return 0;
}
