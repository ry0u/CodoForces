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
    int n,m;
    cin >> n >> m;

    if(n%2 == 0) {
        if(1 <= m && m <= n/2) {
            cout << m + 1 << endl;
        }

        if(n/2 + 1 <= m && m <= n) {
            cout << m - 1 << endl;
        }

    } else {
        if(1 <= m && m < n/2 + 1) {
            cout << m + 1 << endl;
        }

        if(n/2 + 1 <= m && m <= n) {
            if(m-1 >= 1) {
                cout << m - 1 << endl;
            } else {
                cout << m << endl;
            }
        }
    }

    return 0;
}
