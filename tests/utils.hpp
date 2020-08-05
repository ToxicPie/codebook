#include <chrono>
#include <complex>
#include <exception>
#include <functional>
#include <iostream>
#include <random>
#include <stdexcept>
#include <type_traits>



// global prng
// std::random_device is pretty platform-dependent so we don't use it here
extern std::mt19937_64 global_rng;

// useful structs
struct timer {
    std::chrono::time_point<std::chrono::steady_clock> start;
    timer();
    void reset();
    long get();
};

struct randint {
    std::uniform_int_distribution<long long> rnd_val;
    randint() = delete;
    randint(long long l, long long r);
    long long operator()();
};

// is_equal functions: check if two values x and y are equal
// for floating points / std::complex<floating point>s:
//     returns true if error between x and y is small enough
// for other types / classes with ==: returns x == y
// for all other types: unsupported
namespace is_equal {
    template<typename T>
    constexpr T _abs(const T& x) {
        return x < 0 ? -x : x;
    }

    template<typename T>
    constexpr std::enable_if_t<std::is_floating_point_v<T>, bool>
    is_equal(const T& x, const T& y) {
        constexpr T EPS = 1e-6;
        T error_base = std::max(_abs(x), _abs(y));
        error_base = std::max(error_base, T(1));
        return _abs(x - y) / error_base < EPS;
    }

    template<typename T>
    constexpr std::enable_if_t<std::is_floating_point_v<T>, bool>
    is_equal(const std::complex<T>& x, const std::complex<T>& y) {
        constexpr T EPS = 1e-6;
        T error_base = std::max(abs(x), abs(y));
        error_base = std::max(error_base, T(1));
        return abs(x - y) < EPS;
    }

    template<typename T, typename U>
    constexpr bool is_equal(const T& x, const U& y) {
        return x == y;
    }
}

// exception classes
struct wrong_answer_error : public std::runtime_error {
    wrong_answer_error(const std::string& what_arg);
};

struct assertion_error : public std::runtime_error {
    assertion_error(const std::string& what_arg);
};

// custom assert that throws
void assert(const bool& val);

// test function type
using test_func = std::function<void(int)>;

// runs a test with given name and iterations
void run_test(std::string name, test_func test, int count);

// initializes stuff
void init();

// util functions
template<typename T>
void shuffle(std::vector<T>& v);
