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

    vector<string> v(n);
    rep(i,n) cin >> v[i];

    int ans = 0;
    rep(i,n) {
        int cnt = 0;
        rep(j,n) {
            if(v[i][j] == '0') {
                rep(k,n) {
                    v[k][j] = v[k][j] == '0' ? '1' : '0';
                }
            }
        }

        rep(j,n) {
            bool flag = true;
            rep(k,n) {
                if(v[j][k] == '0') flag = false;
            }
            if(flag) cnt++;
        }

        ans = max(ans,cnt);
    }

    cout << ans << endl;


    return 0;
}
