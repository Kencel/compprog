#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pi pair<int, int>
#define pb push_back
#define br "\n"
#define all(x) (x.begin(), x.end())
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<set<pi> > ranking(200000);
    vi kindergarten(n);
    vi rating(n);
    multiset<int> max_ratings;
    for(int i=0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        b--;
        ranking[b].insert(make_pair(a, i));
        kindergarten[i] = b;
        rating[i] = a;
    }

    for(int i=0; i < 200000; i++){
        if(!ranking[i].empty())
            max_ratings.insert((*ranking[i].rbegin()).first);
    }

    for(int i=0; i < q; i++){
        int c, d;
        cin >> c >> d;
        c--;
        d--;

        int k = kindergarten[c];
        int r = rating[c];
        kindergarten[c] = d;

        max_ratings.erase(max_ratings.find((*ranking[k].rbegin()).first));
        ranking[k].erase(make_pair(r, c));

        if(!ranking[d].empty()){
            max_ratings.erase(max_ratings.find((*ranking[d].rbegin()).first));
        }
        
        ranking[k].erase(make_pair(r, c));
        ranking[d].insert(make_pair(r, c));

        if(!ranking[k].empty()){
            max_ratings.insert((*ranking[k].rbegin()).first);
        }
        max_ratings.insert((*ranking[d].rbegin()).first);

        cout << *max_ratings.begin() << br;
    }
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