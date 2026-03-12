//还可以用DAG做
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  1e4 + 10;
ll R[N], pre[N];
ll dp[N][505];
struct Order{
    ll l, r, w;
    bool operator < (const Order& o) const {
        return r < o.r;
    }
}ord[N];
void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll s, e, w;
        cin >> s >> e >> w;
        ord[i] = {s, e, w};
        R[i] = e;
    }
    sort(ord, ord + n);
    for (int i = 0; i < n; i++) {
        R[i] = ord[i].r;
    }
    for (int i = 0; i < n; i++) {
        int id = upper_bound(R, R + n, ord[i].l) - R - 1;//找到第一个严格小于自己开始时间的
        pre[i] = id;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i > 0) dp[i][j] = dp[i-1][j];//不选
            ll val = ord[i].w;//选
            if(pre[i] != -1) val += dp[pre[i]][j-1];
            dp[i][j] = max(dp[i][j], val);
        }
    }
    cout << dp[n-1][k] << '\n';
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
