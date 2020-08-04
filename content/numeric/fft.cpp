template<typename T>
void work(int n, vector<T>& a, vector<T>& rt, bool inv) {
	for (int i = 1, r = 0; i < n; i++) {
		for (int bit = n; !(r & bit); bit >>= 1, r ^= bit);
		if (r > i) swap(a[i], a[r]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		for (int i = 0; i < n; i += len) {
			for (int j = 0; j < len / 2; j++) {
				int pos = n / len * (inv ? len - j : j);
				T u = a[i + j], v = a[i + j + len / 2] * rt[pos];
				a[i + j] = u + v, a[i + j + len / 2] = u - v;
			}
		}
	}
	if (inv) {
		T minv = T(1) / T(n);
		for (T& x : a) x *= minv;
	}
}

void FFT(vector<complex<double>>& a, bool inv) {
	int n = a.size();
	vector<complex<double>> rt(n + 1);
	double arg = acos(-1) * 2 / n;
	for (int i = 0; i <= n; i++)
		rt[i] = { cos(arg * i), sin(arg * i) };
	work(n, a, rt, inv);
}

void NTT(vector<Mod>& a, bool inv, Mod root) {
	int n = a.size();
	vector<Mod> rt(n + 1, 1);
	for (int i = 0; i < n; i++) rt[i + 1] = rt[i] * root;
	work(n, a, rt, inv);
}
