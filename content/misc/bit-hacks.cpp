ull next_permutation(ull x) {
	ull c = __builtin_ctzll(x), r = x + (1 << c);
	return (r ^ x) >> (c + 2) | r;
}
// iterate over all (proper) subsets of bitset s
void subsets(ull s) {
	for (ull x = s; x; ) { --x &= s; /* do stuff */ }
}
