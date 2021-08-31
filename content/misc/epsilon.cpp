long long rc(double x) { return *(long long*)&x; }
// relative error: 2^-28 ~ 3.7e-9
// absolute error: 1e-8
bool is_equal(double a, double b) {
	return abs(rc(a) - rc(b)) < (1LL << (52 - 24)) ||
		abs(a - b) < 1e-8;
}
