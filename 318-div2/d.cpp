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

    vector<int> v(n);
    rep(i,n) cin >> v[i];

    int ans = 0;
    while(true) {
        if(v.size() == 0) break;

        cout << "   -- -- : " << ans << endl;

        vector<int> diff(v.size());
        diff[0] = v[0];
        diff[v.size()-1] = v.back();

        rep(i,v.size()-1) {
            if(v[i] > v[i+1]) {
                diff[i] = max(diff[i],v[i] - v[i+1]);
            }
        }

        for(int i=v.size()-1; i >= 0; i--) {
            if(v[i] > v[i-1]) {
                diff[i] = max(diff[i], v[i] - v[i-1]);
            }
        }

        rep(i,v.size()) {
            if(diff[i] == 0) diff[i] = 1;
        }

        rep(i,v.size()) {
            v[i] -= diff[i];
        }

        vector<int> t;
        rep(i,v.size()) {
            if(v[i] > 0) t.push_back(v[i]);
        }

        copy(t.begin(),t.end(),back_inserter(v));
        ans++;
    }

    cout << ans << endl;

    return 0;
}
