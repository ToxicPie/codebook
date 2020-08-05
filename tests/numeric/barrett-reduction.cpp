#include "../utils.hpp"

#include <sstream>


using namespace std;

using ll = long long;

namespace _reduce {
    #include <numeric/barrett-reduction.cpp>
}

namespace numeric {
    void reduction_test(int count) {
        randint rand(2, 1e9);
        // FIXME: only tests for correctness, not speed
        for(int i = 1; i <= count; i++) {
            ll a = rand(), m = rand();
            auto mod_m = _reduce::reduction(m);
            ll ans = a % m;
            ll x = mod_m(a);
            if(x != ans) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "Expected " << ans << ", ";
                ss << "found " << x << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
