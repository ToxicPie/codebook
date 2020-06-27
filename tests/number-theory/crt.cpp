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
        randint rand(0, 1e9);
        for(int i = 1; i <= count; i++) {
            ll a, b, m, n;
            do {
                m = rand();
                n = rand();
                a = rand();
                b = rand();
            } while((a - b) % __gcd(m, n) != 0);
            ll x = _crt::crt(a, m, b, n);
            if(!(x % m == (a % m) && x % n == (b % n))) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "a = " << a << ", ";
                ss << "m = " << m << ", ";
                ss << "b = " << b << ", ";
                ss << "n = " << n << ", ";
                ss << "x = " << x << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
