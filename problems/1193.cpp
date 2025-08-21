#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define N 1123
#define M 1123

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> mat(n);
	ii start, end;

	for (int i = 0; i < n; i++) {
		cin >> mat[i];
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'A') start = {i, j};
			else if (mat[i][j] == 'B') end = {i, j};
		}
	}

	vector<vector<char>> parent(n, vector<char>(m, ' '));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<ii> q;

	q.push(start);
	visited[start.first][start.second] = true;

	int dr[4] = {1, -1, 0, 0};
	int dc[4] = {0, 0, 1, -1};
	string move_char = "DURL";

	int ok = 0;

	while (!q.empty()) {
		ii atual = q.front();
		q.pop();

		if (atual == end) {
			ok = 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int iN = atual.first + dr[i];
			int jN = atual.second + dc[i];

			if (iN < 0 || jN < 0 || iN >= n || jN >= m) continue;
			if (mat[iN][jN] == '#' || visited[iN][jN]) continue;


			parent[iN][jN] = move_char[i];

			visited[iN][jN] = true;
			q.push({iN, jN});
		}
	}

	if (!ok) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	string path = "";
	ii atual = end;

	while (atual != start) {
		char step = parent[atual.first][atual.second];
		path += step;

		int idx = move_char.find(step);
		atual.first -= dr[idx];
		atual.second -= dc[idx];
	}
	reverse(path.begin(), path.end());

	cout << path.size() << '\n';
	cout << path << '\n';

	return 0;
}
