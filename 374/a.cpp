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

vector<string> samesplit(string s) {
	vector<string> ret;
	rep(i,s.size()) {
		stringstream ss;
		ss << s[i];
		REP(j,i+1,s.size()) {
			if(s[i] == s[j]) {
				ss << s[j];
				i++;
			}
			else break;
		}
		ret.push_back(ss.str());
	}
	return ret;
}

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<string> ret = samesplit(s);
	vector<int> v;
	rep(i, ret.size()) {
		if(ret[i][0] == 'B') v.push_back(ret[i].size());
	}

	cout << v.size() << endl;
	rep(i, v.size()) {
		cout << v[i];

		if(i == int(v.size()) - 1) cout << endl;
		else cout << " ";
	}

	return 0;
}
