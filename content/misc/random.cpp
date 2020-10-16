#include <random>
#include <chrono>

using namespace std;

// most judges and contest environments run linux
// but we should not trust anyone
#ifdef __unix__
	random_device rd;
	mt19937_64 RNG(rd());
#else
	const auto SEED = chrono::high_resolution_clock::now()
			.time_since_epoch().count();
	mt19937_64 RNG(SEED);
#endif

// usage:
// random long long: RNG();
// uniformly random ll in [l, r]:
//   uniform_int_distribution<int> dt(l, r); dt(RNG);
// uniformly random double in [l, r]:
//   uniform_real_distribution<double> dt(l, r); dt(RNG);
