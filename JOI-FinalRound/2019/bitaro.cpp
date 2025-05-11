const int maxn = 3007;
int n, m, a[maxn][maxn], b[2][maxn][maxn];

void process() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) {
        char x; cin >> x;
        if (x == 'J') a[i][j] = 1;
        else if (x == 'O') a[i][j] = 2;
        else a[i][j] = 3;
    }

    FORD(i, n, 1) FORD(j, m, 1) {
        b[0][i][j] = b[0][i + 1][j] + b[0][i][j + 1] - b[0][i + 1][j + 1];
        b[1][i][j] = b[1][i + 1][j] + b[1][i][j + 1] - b[1][i + 1][j + 1];
        if (a[i][j] == 2) b[0][i][j]++;
        else if (a[i][j] == 3) b[1][i][j]++;
    }
    int ans = 0;
    FOR(i, 1, n) FOR(j, 1, m) if (a[i][j] == 1) {
        ans += (b[0][i][j + 1] - b[0][i + 1][j + 1]) * (b[1][i + 1][j] - b[1][i + 1][j + 1]);
    }

    cout << ans;
}
