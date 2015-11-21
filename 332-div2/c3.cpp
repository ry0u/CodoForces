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

	vector<int> v(n), t(n);
	rep(i, n) {
		cin >> v[i];
		t[i] = v[i];
	}

	sort(t.begin(), t.end());
	int ans = 0;
	map<int, int> m;

	rep(i, n) {
		if(m[v[i]] == -1) {
			m.erase(v[i]);
		} else {
			m[v[i]]++;
		}

		if(m[t[i]] == 1) {
			m.erase(t[i]);
		} else {
			m[t[i]]--;
		}

		if(m.size() == 0) {
			ans++;
		}
	}

	cout << ans << endl;



	return 0;
}
