using ull = unsigned long long;
using ll = long long;
using ld = long double;
// returns a * b % M
ull mult(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
