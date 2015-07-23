#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

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

    bool flag = false;
    rep(i,n) {
        int a;
        cin >> a;

        if(a == 1) {
            flag = true;
        }
    }

    if(flag) cout << -1 << endl;
    else cout << 1 << endl;

    return 0;
}
