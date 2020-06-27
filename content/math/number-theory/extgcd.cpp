tuple<ll, ll, ll> extgcd(ll a, ll b) {
	if (b == 0) return { 1, 0, a };
	else {
		auto [p, q, g] = extgcd(b, a % b);
		return { q, p - q * (a / b), g };
	}
}
