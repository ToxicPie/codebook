#include "../utils.hpp"

#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

using ll = long long;

namespace _gcd {
    #include <math/number-theory/extgcd.cpp>
}

namespace math {
    void gcd_test(int count) {
        randint rand(0, 1e9);
        for(int i = 1; i <= count; i++) {
            int a, b;
            a = rand();
            b = rand();
            auto [x, y, g] = _gcd::extgcd(a, b);
            if(!((ll)x * a + (ll)y * b == g && g == __gcd(a, b))) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "a = " << a << ", ";
                ss << "b = " << b << ", ";
                ss << "x = " << x << ", ";
                ss << "y = " << y << ", ";
                ss << "g = " << g << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
