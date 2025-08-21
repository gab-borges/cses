#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define N 1123
#define M 1123

int n, m;
int mat[N][M];

void dfs(int i, int j) {
	if (i >= n || j >= m || i < 0 || j < 0) return;
	if (mat[i][j] != 1) return;

	mat[i][j] = 2;

	dfs(i+1, j);
	dfs(i, j+1);
	dfs(i-1, j);
	dfs(i, j-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			mat[i][j] = c == '#' ? 0 : 1;
		}
	}

	ll ans = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) ans++;
			
			dfs(i, j);
		}
	}

	cout << ans << '\n';

	return 0;
}
