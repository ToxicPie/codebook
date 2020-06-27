#include "tests.hpp"
#include "utils.hpp"



int main() {
    run_test("Extended GCD", math::gcd_test, 1'000'000);
    run_test("Chinese remainder", math::crt_test, 500'000);
    run_test("Tonelli-Shanks", math::sqrt_test, 100'000);
}
