#include "tests.hpp"
#include "utils.hpp"



int main() {
    run_test("Extended GCD", math::gcd_test, 2'000'000);
    run_test("Chinese remainder", math::crt_test, 1'000'000);
    run_test("Tonelli-Shanks", math::sqrt_test, 200'000);
    run_test("FFT multiplication", numeric::fft_test, 1000);
    run_test("NTT multiplication", numeric::ntt_test, 1000);
}
