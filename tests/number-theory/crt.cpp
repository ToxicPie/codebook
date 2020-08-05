#include "../utils.hpp"

#include <utility>
#include <sstream>
#include <algorithm>


using namespace std;

using ll = long long;

namespace _crt {
    #include <math/number-theory/extgcd.cpp>
    #include <math/number-theory/crt.cpp>
}

namespace math {
    void crt_test(int count) {
        randint rand_ans(1, 1e18);
        randint rand_mod(1, 1e9);
        for(int i = 1; i <= count; i++) {
            ll ans = rand_ans(), m = rand_mod(), n = rand_mod();
            ll a = ans % m, b = ans % n;
            ll x = _crt::crt(a, m, b, n);
            if(!(x % m == a && x % n == b)) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "a = " << a << ", ";
                ss << "m = " << m << ", ";
                ss << "b = " << b << ", ";
                ss << "n = " << n << "; ";
                ss << "Expected " << ans << ", ";
                ss << "found " << x << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
