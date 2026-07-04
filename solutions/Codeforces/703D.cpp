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
const int LOGN = 20;

struct query{
    int id, l, r; ll hilbert_index;
    query(int id, int l, int r): id(id), l(l), r(r){
        hilbert_index = hilbert_order(l, r, LOGN, 0);
    }
    ll hilbert_order(int x, int y, int pow, int rotate){
        if(pow == 0) return 0;
        int hpow = 1 << (pow-1);
        int seg = ((x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2));
        seg = (seg + rotate) & 3;
        const int rotate_delta[4] = {3, 0, 0 , 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotate_delta[seg]) & 3;
        ll sub_sq_size = 1ll << (2*pow - 2); 
        ll ans = seg * sub_sq_size;
        ll add = hilbert_order(nx, ny, pow-1, nrot);
        ans += (seg==1 || seg==2) ? add : (sub_sq_size-add-1);
        return ans;
    }
    bool operator<(const query& other) const { return this->hilbert_index < other.hilbert_index; }
};

vi freq;
ll curr = 0;
vll comp, a;

void add(int idx){
    if(freq[comp[idx]] % 2 == 0 && freq[comp[idx]] > 0) curr ^= a[idx];
    freq[comp[idx]]++;
    if(freq[comp[idx]] % 2 == 0) curr ^= a[idx];
}

void remove(int idx){
    if(freq[comp[idx]] % 2 == 0) curr ^= a[idx];
    freq[comp[idx]]--;
    if(freq[comp[idx]] % 2 == 0 && freq[comp[idx]] > 0) curr ^= a[idx];
}

bool tc = false;
void solve() {
    int n, m;
    cin >> n;
    freq.resize(n);
    comp.resize(n);
    a.resize(n);
    vll coords(n);
    for(int i=0; i < n; i++) {
        cin >> a[i];
        coords[i] = a[i];
    }
    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end());
    freq.resize(sz(coords));
    int count = 0;
    for(int i=0; i < n; i++){
        comp[i] = lower_bound(all(coords), a[i]) - coords.begin();
    }
    cin >> m;
    vll ans(m);
    vector<query> queries;
    for(int i=0; i < m; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries.pb({i, l, r});
    }
    sort(all(queries));
    int l = 0, r = -1;
    for(const query &q : queries){
        while(r < q.r) add(++r);
        while(l > q.l) add(--l);
        while(r > q.r) remove(r--);
        while(l < q.l) remove(l++);
        
        ans[q.id] = curr;
    }
    for(int num : ans){
        cout << num << br;
    }
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