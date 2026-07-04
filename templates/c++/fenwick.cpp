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

struct fenwick{
    vll ar;
    fenwick(vll &_ar): ar(sz(_ar), 0){
        for(int i=0; i < sz(ar); i++){
            ar[i] += _ar[i];
            int j = i | (i + 1);
            if(j < sz(ar)){
                ar[j] += ar[i];
            } 
        }
    }
    ll sum(int i){
        ll res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1){
            res += ar[i];
        }
        return res;
    }
    ll sum(int i, int j){ return sum(j) - sum(i - 1); }
    void add(int i, ll val){
        for(; i < sz(ar); i |= i + 1){
            ar[i] += val;
        }
    }
    ll get(int i){
        ll res = ar[i];
        if(i){
            int lca = (i & (i+1)) - 1;
            for(--i; i != lca; i = (i & (i + 1)) - 1){
                res -= ar[i];
            }
        }
        return res;
    }
    void set(int i, int val){ add(i, -get(i) + val); }
    void add(int i, int j, int val){ add(i, val); add(j + 1, -val); }
};

bool tc = true;
void solve() {

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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