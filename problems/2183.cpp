#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi X(n);
    for (int i = 0; i < n; i++) cin >> X[i];

    sort(X.begin(), X.end());

    ll res = 1;
    for (int i = 0; i < X.size(); i++) {
        if (X[i] > res) break;

	res += X[i];
    }

    cout << res << '\n';

    return 0;
}
