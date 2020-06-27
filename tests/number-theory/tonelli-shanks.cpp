#include "../utils.hpp"

#include <utility>
#include <sstream>
#include <vector> 


using namespace std;

using ll = long long;

namespace _sqrt {
    #include <math/number-theory/modular.cpp>
    #include <math/number-theory/tonelli-shanks.cpp>
}

namespace math {
    void sqrt_test(int count) {
        // randint rand(0, INT32_MAX);
        randint rand(0, 1LL << 60);
        const vector<ll> MODS = {2, 7, 21673, 26497, 22621, 21817, 28393, 26821, 30181, 65537, 977680993, 971939533, 970479637, 998244353, 1000000007, 1041012121, 1000000000039, 2748779069441, 1000000000000037, 1945555039024054273};
        for(int i = 1; i <= count; i++) {
            _sqrt::Mod a;
            a.MOD = MODS[i % MODS.size()];
            do {
                a = rand();
            } while(_sqrt::legendre(a) == -1);
            _sqrt::Mod x =  _sqrt::sqrt(a);
            if(!(x * x == a)) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "a = " << (ll)a << ", ";
                ss << "x = " << (ll)x << ", ";
                ss << "p = " << a.MOD << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
