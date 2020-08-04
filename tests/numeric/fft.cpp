#include "../utils.hpp"

#include <utility>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <complex>


using namespace std;

using ll = long long;

namespace _fft {
    #include <math/number-theory/modular.cpp>
    #include <numeric/fft.cpp>
}

namespace numeric {
    using is_equal::is_equal;

    ostream& operator<<(ostream& o, const _fft::Mod& m) {
        o << (ll)m;
        return o;
    }

    template<typename T>
    bool check(vector<T>& a, vector<T>& b, vector<T>& ans) {
        // randomized check of the correctness of polynomial multiplication
        // returns if a * b equals ans
        constexpr int CHECKS = 10;

        int n = ans.size();
        a.resize(n);
        b.resize(n);
        randint rand(0, n - 1);
        for(int it = 0; it < CHECKS; it++) {
            int i = rand();
            // calculate expected ans[i]
            T cur = 0;
            for(int j = 0; j <= i; j++) {
                cur += a[j] * b[i - j];
            }

            if(!is_equal(ans[i], cur)) {
                for(T& x : a) cerr << x << ' '; cerr << '\n';
                for(T& x : b) cerr << x << ' '; cerr << '\n';
                for(T& x : ans) cerr << x << ' '; cerr << '\n';
                // fails
                return false;
            }
        }
        // nothing fails
        return true;
    }

    // test fft multiplication
    void fft_test(int count) {
        randint rand_n(1, 2000);
        randint rand_v(-1000, 1000);
        for(int i = 1; i <= count; i++) {
            // generate vectors
            int m = rand_n(), n = rand_n();
            vector<complex<double>> a(m), b(n);
            for(auto &i : a) i = rand_v();
            for(auto &i : b) i = rand_v();
            vector<double> orig_a(m), orig_b(n);
            for(int i = 0; i < m; i++) orig_a[i] = real(a[i]);
            for(int i = 0; i < n; i++) orig_b[i] = real(b[i]);

            // fft multiplication
            int sz = 1 << (1 + __lg(m + n));
            vector<complex<double>> res(sz);
            a.resize(sz); _fft::FFT(a, 0);
            b.resize(sz); _fft::FFT(b, 0);
            for(int i = 0; i < sz; i++) res[i] = a[i] * b[i];
            _fft::FFT(res, 1);

            vector<double> ans(sz);
            for(int i = 0; i < sz; i++) ans[i] = real(res[i]);
            if(!check(orig_a, orig_b, ans)) {
                stringstream ss;
                ss << fixed << setprecision(5);
                ss << "Test case " << i << ": ";
                ss << "n = " << n << ", ";
                ss << "m = " << m << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }

    void ntt_test(int count) {
        constexpr int _MOD = 998244353;
        _fft::Mod primitive_root;
        primitive_root.MOD = _MOD;
        primitive_root = 3;

        randint rand_n(1, 2000);
        randint rand_v(0, _MOD - 1);
        for(int i = 1; i <= count; i++) {
            // generate vectors
            int m = rand_n(), n = rand_n();
            vector<_fft::Mod> a(m), b(n);
            for(auto &i : a) i = rand_v();
            for(auto &i : b) i = rand_v();
            auto orig_a = a, orig_b = b;

            // fft multiplication
            int sz = 1 << (1 + __lg(m + n));
            vector<_fft::Mod> res(sz);
            a.resize(sz, 0); _fft::NTT(a, 0, primitive_root);
            b.resize(sz, 0); _fft::NTT(b, 0, primitive_root);
            for(int i = 0; i < sz; i++) res[i] = a[i] * b[i];
            _fft::NTT(res, 1, primitive_root);

            if(!check(orig_a, orig_b, res)) {
                stringstream ss;
                ss << "Test case " << i << ": ";
                ss << "n = " << n << ", ";
                ss << "m = " << m << "";
                throw wrong_answer_error(ss.str());
            }
        }
    }
}
