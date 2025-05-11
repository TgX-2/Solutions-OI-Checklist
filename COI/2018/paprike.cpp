const int maxn = 1e5 + 7;
int n, k, a[maxn];
vector<int> g[maxn];

int ans = 0, dp[maxn];
void dfs(int u, int pre = -1) {
    dp[u] = a[u];

    vi vec;

    for(int v : g[u]) if (v != pre) {
        dfs(v, u);
        vec.pb(dp[v]);
        dp[u] += dp[v];
    }

    if (dp[u] > k) {
        sort(all(vec));
        int sum = a[u];

        for(int x : vec) {
            if (sum + x > k) { 
                ans++;
                dp[u] -= x;
            } else sum += x;
        }
    }
}

void process() {
    cin >> n >> k;
    FOR(i, 1, n) 
        cin >> a[i];

    FOR(i, 2, n) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1); cout << ans;
}
