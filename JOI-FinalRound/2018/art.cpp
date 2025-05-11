const int maxn = 5e5 + 7;
int n, dp[maxn];
pair<int, int> a[maxn];

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n);

    dp[1] = a[1].se;
    int ans = 0;
    FOR(i, 1, n) 
        maxi(ans, dp[i] = max(a[i].se, dp[i - 1] + a[i].se - a[i].fi + a[i - 1].fi));

    cout << ans;
}
