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

    int res = 0;
    int ans[3] = {0};
    vector<int> A(3),B(3);

    rep(i,3) {
        cin >> A[i] >> B[i];

        res += A[i];
        ans[i] += A[i];
    }

    rep(i,3) {
        if(res >= n) break;

        REP(j,A[i]+1,B[i]+1) {
            res++;
            ans[i]++;

            if(res >= n) break;
        }
    }

    rep(i,3) {
        cout << ans[i];

        if(i == 2) cout << endl;
        else cout << " " << endl;
    }

    return 0;
}
