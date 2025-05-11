const int maxn = 1e6 + 7;
int n, a[maxn];
vector<int> pos[maxn];

void process() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }

    int ans = n;
    FORD(i, n, 1) {
        if (len(pos[a[i]]) and pos[a[i]].back() == i) pos[a[i]].pop_back();
        if (len(pos[a[i] + 1])) {
            pos[a[i] + 1].pop_back();
            ans--;
        }

    }

    cout << ans;
}
