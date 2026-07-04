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

int MAXN = 1e5 + 5;
vector<bool> possible(MAXN, false);
vector<int> bin;

void backtrack(int curr, int idx){
    if(curr >= MAXN) return;
    if(possible[curr]) return;
    possible[curr] = true;

    for(int i=idx; i < sz(bin); i++){
        backtrack(curr * bin[i], idx);
    }
}

void precompute(){
    for(int i=2; i < (1 << 5); i++){
        string s = bitset<5>(i).to_string();
        bin.pb(stoi(s));
    }
    backtrack(1, 0);
}

bool tc = true;
void solve() {
    int n;
    cin >> n;
    cout << (possible[n] ? "YES" : "NO") << br;
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
    precompute();
    while (t--) {
        solve();
    }

}