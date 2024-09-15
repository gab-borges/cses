#include <bits/stdc++.h>
using namespace std;

#define N 212345
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;

	int A[N];		

	for (int i = 0; i < n; i++)
		cin >> A[i];

	ll prefix[N];

	prefix[0] = A[0];

	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i-1] + A[i];

	while (q--) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		
		if (a > 0)
			cout << prefix[b] - prefix[a-1] << '\n';

		else
			cout << prefix[b] << '\n';
	}

	return 0;
}

