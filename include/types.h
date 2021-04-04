#pragma once
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
typedef std::vector<int256_t> CryptoString;
typedef int256_t CryptoChar;

typedef struct {
  int256_t s;
  int256_t p;
  int256_t q;
} PrivateKey;

typedef struct {
  int256_t r;
  int256_t m;
} PublicKey;
