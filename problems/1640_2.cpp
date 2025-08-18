#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    
    vector<ii> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int l = 0, r = n - 1;

    while (l < r) {
        ll sum = A[l].first + A[r].first;

        if (sum > x) r--;
        else if (sum < x) l++;
        else {
            cout << A[l].second+1 << " " << A[r].second+1 << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}