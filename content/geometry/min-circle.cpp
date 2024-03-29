// source: waynedisonitau123

pt center(const pt &a, const pt &b, const pt &c) {
	pt p0 = b - a, p1 = c - a;
	double c1 = abs2(p0) * 0.5, c2 = abs2(p1) * 0.5;
	double d = cross(p0, p1);
	double x = a.x + (c1 * p1.y - c2 * p0.y) / d;
	double y = a.y + (c2 * p0.x - c1 * p1.x) / d;
	return pt(x, y);
}

pair<double, double> solve(vector<pt> &p) {
	shuffle(p.begin(), p.end(), RNG);
	double r = 0.0;
	pt cent;
	for (int i = 0; i < p.size(); ++i) {
		if (abs2(cent - p[i]) <= r) continue;
		cent = p[i];
		r = 0.0;
		for (int j = 0; j < i; ++j) {
			if (abs2(cent - p[j]) <= r) continue;
			cent = (p[i] + p[j]) / 2;
			r = abs2(p[j] - cent);
			for (int k = 0; k < j; ++k) {
				if (abs2(cent - p[k]) <= r) continue;
				cent = center(p[i], p[j], p[k]);
				r = abs2(p[k] - cent);
			}
		}
	}
	return {cent, sqrt(r)};
}
