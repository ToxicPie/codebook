// min dp[i] value and its i (smallest one)
pll get_dp(int n);
ll aliens(int n) {
	int l = 0, r = 1000000;
	while (l != r) {
		int m = (l + r) / 2;
		pll res = get_dp(m);
		if (res.S == n) return res.F - m * n;
		if (res.S < n) r = m;
		else l = m + 1;
	}
	l--;
	return get_dp(l).F - l * n;
}
