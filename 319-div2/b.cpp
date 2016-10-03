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
    int n,m;
    cin >> n >> m;

    vector<int> v(n);
    rep(i,n) cin >> v[i];

    sort(v.begin(),v.end());
    bool flag = false;

    vector<int> res;
    rep(i,n) {
        vector<int> t;
        rep(j,res.size()) {
            int tmp = res[j] + v[i];
            tmp %= m;
            t.push_back(tmp);
        }

        t.push_back(v[i]);

        rep(j,t.size()) {
            if(t[j] % m == 0) {
                flag = true;
                break;
            }
            res.push_back(t[j]);
        }

        if(flag) {
            break;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
