const int maxn = 2e5 + 7;
int n, q, s, t, a[maxn], d[maxn];

int f(int id) {
    return -d[id] * (d[id] > 0 ? s : t);
}

void process() {
    cin >> n >> q >> s >> t;
    int ans = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        if (i > 0) {
            d[i] = a[i] - a[i - 1];
            ans += f(i);
        }
    }

    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        ans -= f(l);
        d[l] += x;
        ans += f(l);
        
        if (r < n) {
            ans -= f(r + 1);
            d[r + 1] -= x;
            ans += f(r + 1);
        }

        cout << ans __ ;
    }
}
