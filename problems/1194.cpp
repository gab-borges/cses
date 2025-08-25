#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define N 1123
#define M 1123

char mat[N][M];
vector<vector<char>> pred(N, vector<char>(M, 'x'));
vector<vi> tempoMonstros(N, vi(M, INT_MAX));
vector<vi> tempoJogador(N, vi(M, INT_MAX));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	
	vector<ii> posicaoMonstros;
	ii posJogador;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];

			if (mat[i][j] == 'M') {
				posicaoMonstros.push_back({i, j});
				tempoMonstros[i][j] = 0;
			}
			else if (mat[i][j] == '#') {
				tempoMonstros[i][j] = -1;
			}
			else if (mat[i][j] == 'A') {
				tempoJogador[i][j] = 0;
				posJogador = {i, j};
			}
		}
	}

	queue<ii> q;

	for (auto monstro : posicaoMonstros)
		q.push(monstro);
	
	while (!q.empty()) {
		int i = q.front().first; int j = q.front().second;
		q.pop();

		if (i < 0 || j < 0 || i >= n || j >= m) continue;
		if (mat[i][j] == '#') continue;

		for (int k = 0; k < 4; k++) {
			int ni=i+dx[k], nj=j+dy[k];

			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (mat[ni][nj] == '#') continue;

			if (tempoMonstros[ni][nj] == INT_MAX) {
				tempoMonstros[ni][nj] = tempoMonstros[i][j] + 1;
				q.push({ni, nj});
			}
		}
	}

	q.push(posJogador);

	int ok = 0;

	map<int, char> map1 = {{0, 'D'}, {1, 'R'}, {2, 'U'}, {3, 'L'}};
	map<char, int> map2;
	map2['D'] = 0;
	map2['R'] = 1;
	map2['U'] = 2;
	map2['L'] = 3;

	ii posFinal;

	while (!q.empty()) {
		int i = q.front().first; int j = q.front().second;
		q.pop();

		if (i < 0 || j < 0 || i >= n || j >= m) continue;
		if (mat[i][j] == '#') continue;

		if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
			ok = 1;
			posFinal = {i, j};
			break;
		}

		int novoTempo = tempoJogador[i][j] + 1;
		for (int k = 0; k < 4; k++) {
			int ni=i+dx[k], nj=j+dy[k];

			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

			if (tempoJogador[ni][nj] != INT_MAX || novoTempo >= tempoMonstros[ni][nj]) continue;

			tempoJogador[ni][nj] = novoTempo;
			pred[ni][nj] = map1[k];
			q.push({ni, nj});
		}
	}

	if (!ok) {
		cout << "NO\n";
		return 0;
	}
	
	ii pos = posFinal;
	string ans = "";

	while (pos != posJogador) {
		int i = pos.first, j = pos.second;
		if (i < 0 || j < 0 || i >= n || j >= m) break;

		char movimento = pred[pos.first][pos.second];
		
		ans.push_back(movimento);
		
		pos.first -= dx[map2[movimento]];
		pos.second -= dy[map2[movimento]];
	}

	reverse(ans.begin(), ans.end());

	cout << "YES\n";
	cout << ans.size() << '\n';
	cout << ans << '\n';

	return 0;
}
