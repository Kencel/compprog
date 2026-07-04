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

const ll INF = 1e18;

struct range{
    int l, r, id;
    bool operator<(const range& other) const {
        if(this->r == other.r) return this->l > other.r;
        return this->r < other.r;
    }
};

bool tc = false;
void solve() {
    int n;
    ordered_multiset sup_o, sub_o;
    vi sup(n), sub(n);
    vector<range> ranges;
    for(int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        ranges.pb({x, y, i});
    }
    sort(all(ranges));
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