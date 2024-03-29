// source: waynedisonitau123

vector<long long> convolution(const vector<int> &a, const vector<int> &b) {
	// Should be able to handle N <= 10^5, C <= 10^4
	int sz = 1;
	while (sz < a.size() + b.size() - 1) sz <<= 1;
	vector<cplx> v(sz);
	for (int i = 0; i < sz; ++i) {
		double re = i < a.size() ? a[i] : 0;
		double im = i < b.size() ? b[i] : 0;
		v[i] = cplx(re, im);
	}
	fft(v, sz);
	for (int i = 0; i <= sz / 2; ++i) {
		int j = (sz - i) & (sz - 1);
		cplx x = (v[i] + v[j].conj()) * (v[i] - v[j].conj()) * cplx(0, -0.25);
		if (j != i) v[j] = (v[j] + v[i].conj()) * (v[j] - v[i].conj()) * cplx(0, -0.25);
		v[i] = x;
	}
	ifft(v, sz);
	vector<long long> c(sz);
	for (int i = 0; i < sz; ++i) c[i] = round(v[i].re);
	return c;
}
vector<int> convolution_mod(const vector<int> &a, const vector<int> &b, int p) {
	int sz = 1;
	while (sz < (int)a.size() + (int)b.size() - 1) sz <<= 1;
	vector<cplx> fa(sz), fb(sz);
	for (int i = 0; i < (int)a.size(); ++i)
		fa[i] = cplx(a[i] & ((1 << 15) - 1), a[i] >> 15);
	for (int i = 0; i < (int)b.size(); ++i)
		fb[i] = cplx(b[i] & ((1 << 15) - 1), b[i] >> 15);
	fft(fa, sz), fft(fb, sz);
	double r = 0.25 / sz;
	cplx r2(0, -1), r3(r, 0), r4(0, -r), r5(0, 1);
	for (int i = 0; i <= (sz >> 1); ++i) {
		int j = (sz - i) & (sz - 1);
		cplx a1 = (fa[i] + fa[j].conj());
		cplx a2 = (fa[i] - fa[j].conj()) * r2;
		cplx b1 = (fb[i] + fb[j].conj()) * r3;
		cplx b2 = (fb[i] - fb[j].conj()) * r4;
		if (i != j) {
			cplx c1 = (fa[j] + fa[i].conj());
			cplx c2 = (fa[j] - fa[i].conj()) * r2;
			cplx d1 = (fb[j] + fb[i].conj()) * r3;
			cplx d2 = (fb[j] - fb[i].conj()) * r4;
			fa[i] = c1 * d1 + c2 * d2 * r5;
			fb[i] = c1 * d2 + c2 * d1;
		}
		fa[j] = a1 * b1 + a2 * b2 * r5;
		fb[j] = a1 * b2 + a2 * b1;
	}
	fft(fa, sz), fft(fb, sz);
	vector<int> res(sz);
	for (int i = 0; i < sz; ++i) {
		long long a = round(fa[i].re);
		long long b = round(fb[i].re);
		long long c = round(fa[i].im);
		res[i] = (a + ((b % p) << 15) + ((c % p) << 30)) % p;
	}
	return res;
}}
