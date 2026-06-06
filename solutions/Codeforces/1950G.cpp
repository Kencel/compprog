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
    vector<pair<string, string>> songs;
    for(int i=0; i < n; i++){
        string genre, writer;
        cin >> genre >> writer;
        songs.pb(mp(genre, writer));
    }

    vector<vi> adj(n);
    for(int i=0; i < n; i++){
        for(int j=i + 1; j < n; j++){
            if(songs[i].first == songs[j].first || songs[i].second == songs[j].second){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    int keep = 1;
    for(int i=0; i < n; i++){
        int curr_keep = 1;
        deque<pi> q;
        set<int> seen;
        q.pb(mp(i, 1));
        while(!q.empty()){
            int curr, depth; 
            tie(curr, depth) = q[0];
            q.pop_front();
            if(seen.contains(curr)) continue;
            seen.insert(curr);
            for(auto i : adj[curr]){
                q.pb(mp(i, depth + 1));
            }
            curr_keep = max(curr_keep, depth);
        }
        keep = max(keep, curr_keep);
    }

    cout << (n - keep) << br;
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