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
	int n, m;
	cin >> n >> m;

	vector<int> f(n), b(m);
	vector<vector<int > > v(100005);
	rep(i, n) {
		cin >> f[i];
		v[f[i]].push_back(i+1);
	}

	rep(i, m) {
		cin >> b[i];
	}

	bool flag = false;
	bool ch = true;
	vector<int> ans;

	rep(i, m) {
		if(v[b[i]].size() > 0) {
			int d = v[b[i]].back();
			ans.push_back(d);

			if(v[b[i]].size() >= 2) {
				flag = true;
			}
		} else {
			ch = false;
		}
	}

	if(ch) {

		if(flag) cout << "Ambiguity" << endl;
		else {
			cout << "Possible" << endl;
			rep(i, m) {
				cout << ans[i];
				if(i == m-1) cout << endl;
				else cout << " "; 
			}
		}
	} else cout << "Impossible" << endl;

	return 0;
}
