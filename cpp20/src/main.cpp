#include "generatorTemp.hpp"



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

class Fibonacci {
 public:
  int next() {
    if (a == -1) {
      a = 0;
      b = 1;
      return 0;
    }

    int next = b;
    b = a + b;
    a = b - a;
    return next;
  }

 private:
  int a = -1;
  int b = 0;
};

int main() {
  auto generator = fibonacci();
  auto fib = Fibonacci();
  for (int i = 0; i < 10; ++i) {
    if (generator.has_next()) {
      std::cout << "generator --> " << generator.next() 
      << " "<< "normal --> " << fib.next() << std::endl;
    } else {
      break;
    }
  }
  return 0;
}
