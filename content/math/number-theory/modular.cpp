template<typename T> struct M {
	static T MOD;
	T v;
	M() : v(0) {}
	M(T x) {
		v = (-MOD <= x && x < MOD) ? x : x % MOD;
		if (v < 0) v += MOD;
	}
	explicit operator T() const { return v; }
	bool operator==(const M& b) const { return v == b.v; }
	bool operator!=(const M& b) const { return v != b.v; }
	M operator-() { return M(-v); }
	M operator+(M b) { return M(v + b.v); }
	M operator-(M b) { return M(v - b.v); }
	M operator*(M b) { return M((__int128)v * b.v % MOD); }
	M operator/(M b) { return *this * (b ^ (MOD - 2)); }
	friend M operator^(M a, ll b) {
		M ans(1);
		for (; b; b >>= 1, a *= a) if (b & 1) ans *= a;
		return ans;
	}
	friend M& operator+=(M& a, M b) { return a = a + b; }
	friend M& operator-=(M& a, M b) { return a = a - b; }
	friend M& operator*=(M& a, M b) { return a = a * b; }
	friend M& operator/=(M& a, M b) { return a = a / b; }
};
using Mod = M<ll>;
template<>ll Mod::MOD = 1000000007;

/* Safe primes
 * 21673, 26497, 22621, 21817, 28393, 26821, 30181, 22093
 * 977680993, 971939533, 970479637, 910870273, 1041012121
 * 741266610070171837, 1110995545625882557
 * NTT prime           | p - 1       | primitive root
 * 65537               | (2^16)      | 3
 * 998244353           | (2^23)*119  | 3
 * 2748779069441       | (2^39)*5    | 3
 * 1945555039024054273 | (2^56)*27   | 5               */
