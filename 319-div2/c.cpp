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

bool used[10005];

int main() {
    int n;
    cin >> n;

    memset(used,0,sizeof(used));
    vector<int> v;
    vector<int> ans;

    REP(i,2,n+1) {
        if(used[i]) continue;

        vector<int> t;
        t.push_back(i);

        rep(j,v.size()) {
            if(v[j] % i == 0 || i % v[j] == 0) continue;
            if(v[j] * i <= n && !used[v[j] * i]) {
                used[v[j] * i] = true;
                t.push_back(v[j] * i);
            }
        }

        rep(j,t.size()) {
            v.push_back(t[j]);
        }

        used[i] = true;
        ans.push_back(i);

    }

    cout << ans.size() << endl;
    rep(i,ans.size()) {
        cout << ans[i];

        if(i == ans.size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
