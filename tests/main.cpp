#include "tests.hpp"
#include "utils.hpp"



int main() {
    init();

    run_test("Extended GCD", math::gcd_test, 2'000'000);
    run_test("Chinese remainder", math::crt_test, 2'000'000);
    run_test("Tonelli-Shanks", math::sqrt_test, 200'000);
    run_test("long long multiplication", numeric::llmul_test, 10'000'000);
    run_test("Barrett Reduction", numeric::reduction_test, 10'000'000);
    run_test("FFT multiplication", numeric::fft_test, 1000);
    run_test("NTT multiplication", numeric::ntt_test, 1000);
}
