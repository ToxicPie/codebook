// checks if Mod::MOD is prime
bool is_prime() {
	if (MOD <= 1 || MOD % 2 == 0) return MOD == 2;
	// Mod A[] = {2, 7, 61};
	Mod A[] = { 2,325,9375,28178,450775,9780504,1795265022 };
	int s = __builtin_ctzll(MOD - 1), i;
	for (Mod a : A) {
		Mod x = a ^ (MOD >> s);
		for (i = 0; i < s && ll(x + 1) > 2; i++, x *= x);
		if (i && x != -1) return 0;
	}
	return 1;
}
