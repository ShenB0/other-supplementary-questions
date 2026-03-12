//接雨水问题，可以利用单调栈优化为O(n^2)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  105;
int a[N][N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {//枚举矩阵上边
        vector<int> c(n, 0);//每次枚举上边清空c
        for (int j = i; j < n; j++) {//枚举矩阵下边
            for (int k = 0; k < n; k++) {//枚举矩阵的竖边
                if (a[j][k] == 0) {
                    c[k] = -INF;
                } else if (c[k] == -INF) {
                    continue;
                } else {
                    c[k] += a[j][k];
                }
            }
            int cur = 0;
            for (int k = 0; k < n; k++) {
                if (c[k] == -INF) {
                    cur = 0;
                    continue;
                }
                cur += c[k];
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << "\n";
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
