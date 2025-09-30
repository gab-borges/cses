#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define MAX_N 212345
#define MAX_LOG 18

int up[MAX_N][MAX_LOG];
int parent[MAX_N];
int n, q;

void build() {
    parent[0] = -1;
    for (int i = 0; i < n; i++)
        up[i][0] = parent[i];

    for (int j = 1; j < MAX_LOG; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[i][j-1] == -1 ? -1 : up[up[i][j-1]][j-1];
        }
    }
}

int solve(int x, int k) {
    int node = x;

    for (int j = 0; j < MAX_LOG; j++)
        if (k & (1 << j)) {
            node = up[node][j];
            if (node == -1) return -1;
        }

    return node+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
    }

    build();

    while(q--) {
        int x, k; cin >> x >> k;
        x--;
        cout << solve(x,k) << '\n';
    }

    return 0;
}
