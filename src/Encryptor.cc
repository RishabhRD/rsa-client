#include "Encryptor.h"
#include "types.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace boost::multiprecision;
using std::string;

Encryptor::Encryptor(const PublicKey key) : text(""), public_key(key){};

CryptoString Encryptor::encryptString(string &input) {
  CryptoString str;

  int256_t tmp;
  int it;
  for (it = 0; it < input.length(); it++) {
    tmp = powm((int256_t)input.at(it), public_key.r, public_key.m);
    str.push_back(tmp);
  }

  return str;
}

CryptoChar Encryptor::encryptChar(char c) const {
  CryptoChar res = powm((CryptoChar)c, public_key.r, public_key.m);
  return res.convert_to<int>();
}
