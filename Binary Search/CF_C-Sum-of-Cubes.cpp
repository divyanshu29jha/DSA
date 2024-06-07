#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for (ll i = 0; i < n; i++)

void solve(){
    ll x;
    cin >> x;
    for (ll i = 1; i <= 1e4; i++){
        if (x - i * i * i <= 0)
            continue;
        ll f = x - i * i * i;
        ll l = 1;
        ll r = 1e4;
        while (l <= r){
            ll m = l + (r - l) / 2;
            if(m * m * m == f){
                cout << "YES"<< "\n";
                return;
            }
            else if(m * m * m < f){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }

    cout << "NO"<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}