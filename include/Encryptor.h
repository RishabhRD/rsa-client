#include "types.h"
#include <string>

using std::string;

class Encryptor {
private:
  const PublicKey public_key;

  string text;

public:
  Encryptor(const PublicKey key);

  CryptoString encryptString(string &input);
  CryptoChar encryptChar(char c) const;
};
