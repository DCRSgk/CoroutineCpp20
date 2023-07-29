#include "coroutine_fibonacci.hpp"
#include "normal_fibonacci.hpp"

int main() {
    auto generator = fibonacci();
    auto fib = Fibonacci();
    for (int i = 0; i < 10; ++i) {
        if (generator.has_next()) {
            std::cout << "generator --> " << generator.next() << " "
                      << "normal --> " << fib.next() << std::endl;
        } else {
            break;
        }
    }
    return 0;
}
