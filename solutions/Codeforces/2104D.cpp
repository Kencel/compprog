#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

const int MAXN = 1e7;
vector<ll> primes, prime_pfix = {0};
vector<bool> np(MAXN);

void sieve(){
    for(int i=2; i < MAXN; i++){
        if(np[i]) continue;
        primes.pb(i);
        prime_pfix.pb(prime_pfix[sz(prime_pfix) - 1] + primes[sz(primes) - 1]);
        for(int curr = i * 2; curr < MAXN; curr += i){
            np[curr] = true;
        }
    }
}

bool tc = true;
void solve(){
    int n;
    cin >> n;
    vll a(n), pfix = {0};
    for(int i=0; i < n; i++) cin >> a[i];
    sort(all(a));
    for(int i=n - 1; i > -1; i--) pfix.pb(pfix[n - i - 1] + a[i]);
    int l = -1, r = n + 1, m;
    while(r - l > 1){
        m = (l + r) / 2;
        int max_primes = upper_bound(all(prime_pfix), pfix[m]) - prime_pfix.begin() - 1;
        if(max_primes < m){
            r = m;
        } else {
            l = m;
        }
    }
    cout << (n - l) << br;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();

    if(!tc){
        solve();
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}