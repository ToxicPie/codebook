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
        randint rand(0, 1LL << 60);
        const vector<ll> MODS = {2, 7, 21673, 26497, 22621, 21817, 28393, 26821, 30181, 65537, 977680993, 971939533, 970479637, 998244353, 1000000007, 1041012121, 1000000000039, 2748779069441, 1000000000000037, 1945555039024054273};
        for(int i = 1; i <= count; i++) {
            _sqrt::Mod ans, test;
            ans.MOD = MODS[i % MODS.size()];
            ans = rand();
            test = ans * ans;
            _sqrt::Mod ret =  _sqrt::sqrt(test);
            if(ret * ret != test) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "input a = " << (ll)test << ", ";
                ss << "input p = " << test.MOD << ", ";
                ss << "expected " << (ll)ans << " or " << (ll)-ans << ", ";
                ss << "found " << (ll)ret << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
