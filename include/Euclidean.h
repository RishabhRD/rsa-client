#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

#ifndef EUCLIDEAN_
#define EUCLIDEAN_

class Euclidean {
private:
  Euclidean();
  ~Euclidean();

public:
  static int256_t extendedEuclidean(int256_t a, int256_t b, int256_t *x,
                                    int256_t *s);

  static int256_t euclidean(int256_t a, int256_t b);
};

#endif
