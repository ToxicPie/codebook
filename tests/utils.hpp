#include <chrono>
#include <exception>
#include <functional>
#include <iostream>
#include <random>
#include <stdexcept>



struct timer {
    std::chrono::time_point<std::chrono::steady_clock> start;
    timer();
    void reset();
    long get();
};

struct randint {
    std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<long long> rnd_val;
    randint() = delete;
    randint(long long l, long long r);
    long long operator()();
};

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

void run_test(std::string name, test_func test, int count);
