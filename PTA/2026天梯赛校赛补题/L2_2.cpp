#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  1e5 + 10;
int S[N],T[N];
int deg[N];
vector<int> id;
vector<int> adj[N];
void dfs(int u, int fa, int odd, int even) {
    deg[u] = deg[fa] + 1;
    if (deg[u] & 1) {
        if (odd) S[u] = (S[u] + 1) % 2;
    } else {
        if (even) S[u] = (S[u] + 1) % 2;
    }
    if (S[u] != T[u]) {
        if (deg[u] & 1) {
            odd = (odd + 1) % 2;
            id.push_back(u);
        } else {
            even = (even + 1) % 2;
            id.push_back(u);
        }
    }
    for (auto v : adj[u] ) {
        if (v == fa) {
            continue;
        }
        dfs(v, u, odd, even);
    }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    deg[0] = 0;
    dfs(1, 0, 0, 0);
    int k = id.size();
    cout << k << "\n";
    if (k == 0) {
        cout << "\n";
        return ;
    }
    sort(id.begin(), id.end());
    for (int i = 0; i < k; i++) {
        cout << id[i];
        if (i != k - 1) cout << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
