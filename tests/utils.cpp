#include "utils.hpp"


timer::timer() { reset(); }
void timer::reset() {
    start = std::chrono::steady_clock::now();
}
long timer::get() {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        now - start
    ).count();
}

randint::randint(long long l, long long r) : dev(), rng(dev()), rnd_val(l, r) {}
long long randint::operator()() {
    return rnd_val(rng);
}

wrong_answer_error::wrong_answer_error(const std::string& what_arg)
    : std::runtime_error(what_arg) {}

assertion_error::assertion_error(const std::string& what_arg)
    : std::runtime_error(what_arg) {}

void assert(const bool& val) {
    if(!val) throw assertion_error(
        "something unexpected happened in the templates"
    );
}

void run_test(std::string name, test_func test, int count) {
    std::cout << "Running test for ";
    std::cout << "\033[34m\033[1m" << name << "\033[0m ... ";
    try {
        timer test_timer;
        test(count);
        auto time_used = test_timer.get();
        std::cout << "\033[32mAccepted: \033[0m";
        std::cout << count << " cases, ";
        std::cout << time_used << "ms\n";
    } catch(wrong_answer_error& e) {
        std::cout << "\033[31mWrong Answer: \033[0m";
        std::cout << e.what() << "\n";
    } catch(assertion_error& e) {
        std::cout << "\033[33mAssertion Error: \033[0m";
        std::cout << e.what() << "\n";
    }
}
