#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	unordered_set<int> set;

	for (int i = 1; i <= n; i++)
		set.insert(i);

	for (int i = 0; i < n - 1; i++) {
		int a;
		cin >> a;
		
		set.erase(a);
	}

	cout << *(set.begin()) << '\n';

	return 0;
}

