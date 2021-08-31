// source: min-25

using i64 = long long;
using Matrix = vector< vector<int> >;

vector<int> linear_recurrence_mod(const vector<int>& terms, const int mod) {
	const int N = terms.size() / 2;
	Matrix A(N, vector<int>(N + 1));
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N + 1; ++x)
			if ((A[y][x] = terms[x + y] % mod) < 0) A[y][x] += mod;
	int r = 0;
	for (int x = 0; x < N; ++x, ++r) {
		for (int y = x + 1; y < N; ++y) {
			while (A[y][x] > 0) {
				if (A[y][x] < A[x][x] || A[x][x] == 0) {
					for (int x2 = x; x2 < N + 1; ++x2) swap(A[x][x2], A[y][x2]);
				}
				int mq = mod - A[y][x] / A[x][x];
				for (int x2 = x; x2 < N + 1; ++x2) A[y][x2] = (A[y][x2] + i64(mq) * A[x][x2]) % mod;
			}
		}
		if (A[x][x] == 0) break;
	}
	vector<int> f(r + 1); f[0] = 1;
	for (int x = r - 1; x >= 0; --x) if (A[x][x]) {
		int g = __gcd(mod, A[x][x]); assert(A[x][r] % g == 0);
		int mc = (mod - i64(A[x][r] / g) * mod_inv(A[x][x] / g, mod / g) % mod) % mod;
		f[r - x] = mc;
		for (int y = x - 1; y >= 0; --y) A[y][r] = (A[y][r] + i64(mc) * A[y][x]) % mod;
	}
	return f;
}
