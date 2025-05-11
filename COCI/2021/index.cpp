template<typename T>
class FastSegTree {
private: 
    vector<vector<T>> seg;
    int n;

public:
    FastSegTree(const vector<T> &a) :
        n(len(a)), seg(len(a) << 1, vector<T>()) {
        FOR(i, 0, n - 1)
            seg[i + n].pb(a[i]);
        FORD(id, n - 1, 1) {
            merge(all(seg[id << 1]), all(seg[id << 1 | 1]), back_inserter(seg[id]));
        }
    }

    int get(int l, int r, T val) {
        int ans = 0;
        for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ans += seg[l].end() - lower_bound(all(seg[l]), val);
                l++;
            } 
            if (r & 1) {
                r--;
                ans += seg[r].end() - lower_bound(all(seg[r]), val);
            }
        }
        return ans;
    }

    int query(int u, int v) {
        int l = 0, r = (v - u + 1);
        int ans = intmin;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if (get(u, v, mid) >= mid) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};


int n, q;
void process() {
    cin >> n >> q;
    vector<int> a(n);
    FOR(i, 0, n - 1)
        cin >> a[i];

    FastSegTree<int> segtree(a);
    while(q--) {
        int l, r; cin >> l >> r;
        cout << segtree.query(l - 1, r - 1) __ ;
    }
}
