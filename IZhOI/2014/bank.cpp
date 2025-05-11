const int maxn = 27;
int n, m, a[maxn], b[maxn];
 
int dp[maxn][(1 << 20)];
 
int f(int id, int s, int mask) {
    if (s > a[id]) return 0;
    if (id > n) 
        return 1;
 
    int &ans = dp[id][mask];
    if (ans != -1) return ans;
    ans = 0;
    if (s == a[id]) return ans = f(id + 1, 0, mask);
    FOR(i, 1, m) if ((mask & (1 << i)) == 0) {
        maxi(ans, f(id, s + b[i], mask | (1 << i)));
    }
    return ans;
}
 
void process() {
    cin >> n >> m;
    FOR(i, 1, n)
        cin >> a[i];
    FOR(i, 1, m)
        cin >> b[i];

    sort(alln(b, m));
    memo(dp, -1);
    cout << (f(1, 0, 0) == 0 ? "NO" : "YES") ;
}
 
