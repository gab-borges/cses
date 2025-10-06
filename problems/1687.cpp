#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAX_N 212345
#define LOG 18

int n, q;
int parent[MAX_N];
int up[MAX_N][LOG];

void build() {
    parent[0] = -1;

	for (int i = 0; i < n; i++)
		up[i][0] = parent[i];
	
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
		    up[i][j] = up[i][j-1] == -1 ? -1 : up[up[i][j-1]][j-1];
		}
	}
}

int solve(int x, int k) {
	int node = x;

	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			 node = up[node][i];
             if (node == -1) return node;
		}
	}

	return node+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	
	for (int i = 1; i < n; i++) {
		cin >> parent[i];
        parent[i]--;
    }
	
	build();
	
	while(q--) {
		int x, k;
		cin >> x >> k;
		x--;

		cout << solve(x,k) << '\n';
	}

	return 0;
}
