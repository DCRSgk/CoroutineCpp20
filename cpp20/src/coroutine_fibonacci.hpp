#include "generator.hpp"

Generator fibonacci() {
    co_yield 0;
    co_yield 1;

    int a = 0;
    int b = 1;
    while (true) {
        co_yield a + b;
        b = a + b;
        a = b - a;
    }
}