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

    vector<int> v;
    set<int> S,T;

    rep(i,n*n) {
        int s,t;
        cin >> s >> t;

        if(S.find(s) != S.end() || T.find(t) != T.end()) {
            continue;
        } else {
            S.insert(s);
            T.insert(t);
            v.push_back(i+1);
        }
    }

    rep(i,v.size()) {
        cout << v[i];

        if(i == v.size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
