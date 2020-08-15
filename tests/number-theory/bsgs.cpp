#include "../utils.hpp"

#include <utility>
#include <sstream>
#include <vector>
#include <unordered_map>


using namespace std;

using ll = long long;

namespace _bsgs {
    #include <math/number-theory/modular.cpp>
    #include <math/number-theory/bsgs.cpp>
}

namespace math {
    using _bsgs::Mod, _bsgs::MOD;

    void bsgs_test(int count) {
        const vector<ll> MODS = {2, 7, 21673, 26497, 22621, 21817, 28393, 26821, 30181, 65537, 977680993, 971939533, 970479637, 998244353, 1000000007, 1041012121, 1000000000039, 2748779069441, 1000000000000037, 1945555039024054273};
        for(int i = 1; i <= count; i++) {
            MOD = MODS[i % MODS.size()];
            Mod base = randint(1, MOD - 1)();

            ll l, r, ans;
            if(MOD <= 1e7) {
                l = 1, r = MOD - 1;
                ans = randint(l, r)();
            } else {
                ll sz = randint(1, 1e7 - 1)();
                l = randint(1, MOD - 1 - sz)();
                r = l + sz;
                ans = randint(l, r)();
            }

            Mod test = base ^ ans;
            ll ret = _bsgs::bsgs(base, test, l, r);
            if((base ^ ret) != test) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "modulus = " << MOD << ", ";
                ss << "input a = " << (ll)base << ", ";
                ss << "input b = " << (ll)test << ", ";
                ss << "expected " << (ll)ans << ", ";
                ss << "found " << (ll)ret << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
