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

    vector<ll> v(n*n);
    rep(i,n*n) cin >> v[i];

    bool flag = true;
    rep(i,n*n) {
        if(v[0] != v[i]) flag = false;
    }

    if(flag) {
        rep(i,n) {
            cout << v[0];

            if(i == n-1) cout << endl;
            else cout << " ";
        }

        return 0;
    }

    map<int,int> m;
    rep(i,n*n) {
        m[v[i]]++;
    }

    vector<int> ans;

    map<int,int>::iterator ite;
    for(ite = m.begin(); ite != m.end(); ite++) {
        if(ite->second % 2 == 1) {
            ans.push_back(ite->first);
        }
    }

    while(ans.size() < n) {
        ans.push_back(1);
    }

    rep(i,ans.size()) {
        cout << ans[i];

        if(i == ans.size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
