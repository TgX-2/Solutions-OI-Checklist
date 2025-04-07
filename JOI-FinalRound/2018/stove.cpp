const int maxn = 1e5 + 7;
int n, k, a[maxn];
vector<int> val;


void process() {
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        if (i != 1) val.pb(a[i] - a[i - 1] - 1);
    }
    sort(all(val), greater<int>());
    int ans = a[n] - a[1] + 1;
    FOR(i, 0, k - 2) ans -= val[i];
    cout << ans;
}
