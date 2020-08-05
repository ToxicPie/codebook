#include "../utils.hpp"

#include <sstream>


using namespace std;

using ll = long long;

namespace _llmul {
    #include <numeric/ll-mul.cpp>
}

namespace numeric {
    void llmul_test(int count) {
        randint rand(2, 1e18);
        for(int i = 1; i <= count; i++) {
            ll m = rand();
            ll a = rand() % m, b = rand() % m;
            ll ans = (__int128)a * (__int128)b % (__int128)m;
            ll x = _llmul::mult(a, b, m);
            if(x != ans) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "a = " << a << ", ";
                ss << "a = " << a << ", ";
                ss << "m = " << m << "; ";
                ss << "Expected " << ans << ", ";
                ss << "found " << x << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
