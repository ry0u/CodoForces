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

    vector<int> v(n*n);
    map<int,int> m;
    rep(i,n*n) {
        cin >> v[i];
        m[v[i]]++;
    }

    vector<int> ans;
    while(m.size()) {
        int t = m.rbegin()->first;
        m[t]--;
        if(m[t] <= 0) m.erase(t);

        rep(i,ans.size()) {
            int d = __gcd(t, ans[i]);
            m[d] -= 2;
            if(m[d] <= 0) m.erase(d);
        }

        ans.push_back(t);
    }

    rep(i,ans.size()) {
        cout << ans[i];

        if(i == ans.size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
