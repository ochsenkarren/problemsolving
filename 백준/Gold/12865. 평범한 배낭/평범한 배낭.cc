#include <cstdio>
#include <vector>
using namespace std;
int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<pair<int, int>> W_V(N + 1, {0, 0});
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &W_V[i].first, &W_V[i].second);

	vector<vector<int>> v(N + 1);
	for (int i = 0; i < N + 1; ++i)
		v[i].assign(K + 1, 0);

	for (int j = 1; j <= K; ++j) {
		for (int i = 1; i <= N; ++i) {
			int preK = j - W_V[i].first;
			v[i][j] = v[i - 1][j];
			if (0 <= preK) {
				int choice = v[i - 1][preK] + W_V[i].second;
				if (v[i][j] < choice)
					v[i][j] = choice;
			}
		}
	}
	printf("%d", v[N][K]);
	return 0;
}