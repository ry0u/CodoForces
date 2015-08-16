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

    string s;
    cin >> s;

    vector<int> left;
    vector<int> right;
    rep(i,s.size()) {
        if(s[i] != '.') continue;

        int l = i,r = i;
        REP(j,i,s.size()) {
            if(s[i] == s[j]) {
                i++;
                r++;
            } else break;
        }

        left.push_back(l);
        right.push_back(r);
    }

    int size = left.size();
    int ans = 0;

    rep(i,size) {
        ans += right[i] - left[i];
    }

    rep(i,m) {
        int x;
        char c;
        cin >> x >> c;

        x--;

        int l = 0, r = s.size();
        while(r - l > 0) {
            int mid = (l+r) / 2;
            int L = left[mid];
            int R = right[mid];

            if(x < L) {
                r = mid;
            } else if(R < x) {
                l = mid;
            } else {
                break;
            }
        }

        if(c == '.') {

        } else {

        }

    }
    return 0;
}
