ull next_permutation(ull x) {
	ull c = __builtin_ctzll(x), r = x + (1 << c);
	return (r ^ x) >> (c + 2) | r;
}
// iterate over all (proper) subsets of bitset s
void subsets(ull s) {
	for (ull x = s; x; ) { --x &= s; /* do stuff */ }
}
// generate all subset sums (e.g. x[9] = x[8] + x[1])
void sums(vector<int>& x) {
	int n = x.size();
	for (int b = 0; b < n; b++)
		for (int i = 0; i < (1 << n); i++)
			if (i & 1 << b) x[i] += x[i ^ (1 << b)];
}
