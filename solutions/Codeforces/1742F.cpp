#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pi pair<int, int>

#define mp make_pair
#define pb push_back
#define br "\n"

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    map<char, ll> s, t;
    ll len_s = 1, len_t = 1;
    s['a']++;
    t['a']++;
    for(int i=0; i < n; i++){
        ll q, k;
        string x;
        cin >> q >> k >> x;
        map<char, ll>* curr;
        if(q == 1){
            curr = &s;
        } else {
            curr = &t;
        }
        for(char c : x){
            (*curr)[c] += k;
            if (curr == &s){
                len_s += k; 
            } else {
                len_t += k;
            }
        }
        
        if(t['a'] != len_t || (s['a'] == len_s && t['a'] > s['a'])){
            cout << "YES" << br;
            continue;
        }
        cout << "NO" << br;

    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

}