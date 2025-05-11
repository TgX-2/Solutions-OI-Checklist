void process() {
    int s, n; cin >> s >> n;

    int cur = 1;
    FOR(i, 1, n - 1) {
        cout << i __ ;
        s -= i;
    }
    
    cout << s;
}
