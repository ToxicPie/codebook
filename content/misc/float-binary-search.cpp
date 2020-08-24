union di { double d; ll i; };
bool check(double);
// binary search in [L, R) with relative error 2^-eps
double binary_search(double L, double R, int eps) {
	di l = {L}, r = {R};
	while ((r.i - l.i) > (1LL << (52 - eps))) {
		di m = {.i = (l.i + r.i) >> 1};
		if (check(m.d)) l = m;
		else r = m;
	}
	return l.d;
}
