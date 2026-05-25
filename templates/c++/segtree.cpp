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

#define all(x) (x.begin(), x.end())
#define sz(x) (int)(x).size()

const ll INF = 1e18;

struct segtree {
    int i, j;
    ll val, temp_val = 0, set_val = 0;
    bool has_set = false;
    segtree *l, *r;
    segtree(vll &ar, int _i, int _j) : i(_i), j(_j) {
        if(i == j) {
            val = ar[i];
            l = r = NULL;
        } else {
            int k = (i + j) >> 1;
            l = new segtree(ar, i, k);
            r = new segtree(ar, k + 1, j);
            val = l->val + r->val;
        }
    }
    void visit() {
        if(has_set){
            val = (ll)(j-i+1) * set_val;
            if (l) {
                l->set_val = r->set_val = set_val;
                l->has_set = r->has_set = true;
                l->temp_val = r->temp_val = 0;
            }
            has_set = false;
        }
        if (temp_val) {
            val += (j-i+1) * temp_val;
            if (l) {
                r->temp_val += temp_val;
                l->temp_val += temp_val;
            }
            temp_val = 0;
        }
    }
    void update(int _i, int _j, ll _new_val) {
        visit();
        if (_i <= i && j <= _j) {
            set_val = _new_val;
            has_set = true;
            temp_val = 0;
            visit();
        } else if (_j < i || j < _i) {
            return;
        } else {
            l->update(_i, _j, _new_val);
            r->update(_i, _j, _new_val);
            val = l->val + r->val;
        }
    }
    void increase(int _i, int _j, ll _inc) {
        visit();
        if (_i <= i && j <= _j) {
            temp_val += _inc;
            visit();
        } else if (_j < i or j < _i) {
            return;
        } else {
            l->increase(_i, _j, _inc);
            r->increase(_i, _j, _inc);
            val = l->val + r->val;
        }
    }
    ll query(int _i, int _j){
        visit();
        if(_i <= i and j <= _j)
            return val;
        else if (_j < i || j < _i)
            return 0;
        else
            return l->query(_i, _j) + r->query(_i, _j);
    }
};

void solve() {
    
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

}