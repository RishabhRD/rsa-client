#ifndef CHIN_REMAINDER
#define CHIN_REMAINDER

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

class ChinRemainder {
private:
  int x1;
  int x2;

  int m1;
  int m2;

public:
  ChinRemainder(int x1, int x2, int m1, int m2);

  bool parametersSet();

  int256_t calculate();
};

#endif
