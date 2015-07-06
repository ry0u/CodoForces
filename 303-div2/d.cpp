#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    rep(i,n) cin >> v[i];

    ll ans = 0;
    int cnt = 0;
    sort(v.begin(),v.end());

    rep(i,n) {
        if(ans <= v[i]) {
            cnt++;
            ans += v[i];
        }
    }

    cout << cnt << endl;
    return 0;

}
