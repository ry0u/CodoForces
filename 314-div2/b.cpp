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

int cnt[1000005];

int main() {

    int n;
    cin >> n;

    memset(cnt,0,sizeof(cnt));
    set<int> st;

    rep(i,n) {
        string s;
        int r;
        cin >> s >> r;

        if(s == "+") {
            cnt[r]++;
        }else {
            cnt[r]--;
        }

        st.insert(r);
    }

    int ans = 0;
    set<int>::iterator ite;
    for(ite = st.begin();ite != st.end(); ite++) {
        if(cnt[*ite] <= 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
