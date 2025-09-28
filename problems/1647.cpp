#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

const int MAX_N = 200'005;
const int LOG = 18;

int A[MAX_N];
int st[MAX_N][LOG];
int n, q;

void build_sparse_table() {
	for (int i = 0; i < n; i++)
		st[i][0] = A[i];

	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i + (1<<j) - 1 < n; i++) {
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int L, int R) {
	 int len = R - L + 1;

	 int k = 31 - __builtin_clz(len);

	 return min(st[L][k], st[R-(1<<k)+1][k]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for (int i = 0; i < n; i++)
		cin >> A[i];
	
	build_sparse_table();

	while(q--) {
		 int a, b;
		 cin >> a >> b;
		 a--; b--;
		 cout << query(a, b) << '\n';
	}

	return 0;
}
