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

vector<ll> divisor(ll n) {
    vector<ll> res;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> res = divisor(n);
    res.push_back(1);
    res.push_back(n);

    sort(res.begin(), res.end());

    set<ll> st;

    rep(i,res.size()) {
        st.insert(res[i]*res[i]);
    }

    for(int i=res.size()-1; i >= 0; i--) {
        if(st.find(res[i]) == st.end()) {
            cout << res[i] << endl;
            return 0;
        } else {
            st.erase(res[i]);
        }
    }

    return 0;
}
