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
    string s,t;
    cin >> s >> t;

    int cnt = 0;
    rep(i,s.size()) {
        if(s[i] != t[i]) cnt++;
    }

    if(cnt%2 == 0) {
       int res = 0;
       rep(i,s.size()) {
           if(s[i] != t[i]) {
                if(s[i] == '0') s[i] = '1';
                else if(s[i] == '1') s[i] = '0';
                
                res++;
                if(cnt/2 == res) break;
           }    
       }

       cout << s << endl;
    }
    else cout << "impossible" << endl;

    return 0;
}
