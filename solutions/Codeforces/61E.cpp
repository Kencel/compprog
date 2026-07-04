#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

const int INF = 2e9;

struct fenwick{
    vll ar;
    fenwick(vll &_ar): ar(sz(_ar), 0){
        for(int i=0; i < sz(ar); i++){
            ar[i] += _ar[i];
            int j = i | (i + 1);
            if(j < ar.size())
                ar[j] += ar[i];
        }
    }
    ll sum(int i){
        ll res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1)
            res += ar[i];
        return res;
    }
    ll sum(int i, int j){ return sum(j) - sum(i - 1); }
    void add(int i, ll val){
        for(; i < sz(ar); i |= i + 1)
            ar[i] += val;
    }
    ll get(int i){
        ll res = ar[i];
        if(i){
            int lca = (i & (i+1)) - 1;
            for(--i; i != lca; i = (i & (i + 1)) - 1)
                res -= ar[i];
        }
        return res;
    }
    void set(int i, int val){ add(i, -get(i) + val); }
};

/*
currently we can find
for each j
number of i 
such that i < j, ai > aj
call it xj

now find
for each k
sum of xj
for each j such that
j < k, aj > ak

use coord comp then fenwick
query sum of xj for all greater
point update xj
*/

bool tc = false;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    set<int> values;
    for(int i=0; i < n; i++){
        cin >> a[i];
        values.insert(a[i]);
    }
    ordered_multiset order;
    map<int, int> idx;
    int temp = 0;
    for(int x : values){
        idx[x] = temp;
        temp++;
    }
    vll count(sz(idx));
    fenwick *fw = new fenwick(count);
    ll ans = 0;
    for(int i=0; i < n; i++){
        if(idx[a[i]] < sz(idx) - 1){
            ans += fw->sum(idx[a[i]] + 1, sz(idx) - 1);
        }
        fw->add(idx[a[i]], order.order_of_key({a[i], INF}));
        order.insert({a[i], i});
    }
    cout << ans;
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