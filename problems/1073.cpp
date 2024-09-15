#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> K(n);

	for (int i = 0; i < n; i++) {
		cin >> K[i];		
	}

	vector<int> towers(1, K[0]);

	for (int i = 1; i < n; i++) {
		auto obj = upper_bound(towers.begin(), towers.end(), K[i]);

		if (obj == towers.end())
			towers.push_back(K[i]);

		else
			towers[obj-towers.begin()] = K[i];
	}

	cout << towers.size() << '\n';

	return 0;
}

