#include "coroutine_fibonacci.hpp"
#include "normal_fibonacci.hpp"
#include "../src/util/io_util.hpp"

int main()
{
    auto generator = fibonacci();
    auto fib = Fibonacci();
    for (int i = 0; i < 10; ++i)
    {
        if (generator.has_next())
        {
            debug("generator --> ",generator.next());
            debug("normal --> ",fib.next());
        } else
        {
            break;
        }
    }
    return 0;
}
