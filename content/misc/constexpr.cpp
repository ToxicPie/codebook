// constexpr array example
constexpr array<int, 100> fibonacci {
	[] {
		array<int, 100> a{};
		a[0] = a[1] = 1;
		for (int i = 2; i < 100; i++)
			a[i] = (a[i - 1] + a[i - 2]) % 420;
		return a;
	}()
};
static_assert(fibonacci[9] == 55, "CE");

// some default limits in g++ (7.x - trunk):
// constexpr recursion depth: 512
// constexpr loop iteration (per function): 262144
// constexpr operation count (per function): 33554432
// template recursion depth: 900 (g++ might segfault)
// use recursion / unrolling / TMP for more calculations.

// WARNING:
//   g++ 10 has a bug that incorrectly rejects some usages
//   g++ 11 has it fixed, and g++ 7.x - 9.x work fine
// "for constexpr"
template<typename F, typename INT, INT... S>
constexpr void
for_constexpr(integer_sequence<INT, S...>, F&& func) {
	int _[] = { (func(integral_constant<INT, S>{}), 0)... };
}

// example usage
template<typename ...T>
void print_tuple(tuple<T...> t) {
	for_constexpr(
		make_index_sequence<sizeof...(T)>{},
		[&](auto index) { cout << get<index>(t) << ' '; }
	);
	cout << '\n';
}
