#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e7 + 7;
long long b[maxn], c[maxn];
long long delivery(int n, int k, int l, int a[]) {
    for(int i = 1; i <= n; i++) {
        b[i] = min(l, a[i - 1] * 2);
        if (i > k)
            b[i] += b[i - k];
    }
 
    long long ans = b[n];
 
    for(int i = n; i >= 1; i--) {
        c[i] = min(l, (l - a[i - 1]) * 2);
        if (i + k <= n)
            c[i] += c[i + k];
        ans = min(ans, b[i - 1] + c[i]);
    }
    return ans;
}
