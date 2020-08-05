int legendre(Mod a) {
	if (a == 0) return 0;
	return (a ^ ((a.MOD - 1) / 2)) == 1 ? 1 : -1;
}
Mod sqrt(Mod a) {
	assert(legendre(a) != -1);  // no solution
	ll p = a.MOD, s = p - 1;
	if (a == 0) return 0;
	if (p == 2) return 1;
	if (p % 4 == 3) return a ^ ((p + 1) / 4);
	int r, m;
	for (r = 0; !(s & 1); r++) s >>= 1;
	Mod n = 2;
	while (legendre(n) != -1) n += 1;
	Mod x = a ^ ((s + 1) / 2), b = a ^ s, g = n ^ s;
	while (b != 1) {
		Mod t = b;
		for (m = 0; t != 1; m++) t *= t;
		Mod gs = g ^ (1LL << (r - m - 1));
		g = gs * gs, x *= gs, b *= g, r = m;
	}
	return x;
}
