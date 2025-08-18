#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define MAXN 212345

ll BIT[MAXN];

void update(int x, int val) {
    for(++x; x<MAXN; x+=(x&-x))
        BIT[x]+=val;
}

ll query(int x) {
    ll sum = 0;
    for(++x; x>0; x-=(x&-x))
        sum += BIT[x];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vi x(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        update(i, x[i]);
    }

    while(q--) {
        int t; cin >> t;
        
        if (t == 1) {
            int k, u; cin >> k >> u;
            update(k, u - x[k]);
            x[k] = u;
        }
        else {
            int a, b; cin >> a >> b;
            cout << query(b) - query(a-1) << '\n';
        }
    }

    return 0;
}