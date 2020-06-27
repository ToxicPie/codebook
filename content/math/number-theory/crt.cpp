ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	auto [x, y, g] = extgcd(m, n);
	assert((a - b) % g == 0);  // no solution
	x = (x * (b - a) / g) % (n / g) * m + a;
	return x < 0 ? x + m * n / g : x;
}
