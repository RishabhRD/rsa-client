#include <iostream>
#include "Encryptor.h"
#include <asio.hpp>

using asio::ip::tcp;
using namespace std;

int main(int argc, char** argv){
  try {
    if (argc != 2) {
      std::cerr << "Usage: client <ip>" << std::endl;
      return 1;
    }

    asio::io_context io;
    tcp::resolver resolver(io);
    asio::ip::address ip = asio::ip::address::from_string(argv[1]);
    tcp::endpoint ep (ip, 8080);
    std::vector<tcp::endpoint> endPoints = {ep};
    tcp::socket socket(io);
    asio::connect(socket, endPoints);
    string data;
    PublicKey publicKey;
    size_t len = asio::read(socket, asio::buffer(&publicKey, sizeof(publicKey)));
    cout<<"Public key: "<<publicKey.m<<" "<<publicKey.r<<endl;
    Encryptor encryptor(publicKey);
    for (;;) {
      std::cout<<"Enter string: ";
      cin>>data;
      auto cipherText = encryptor.encryptString(data);
      asio::write(socket, asio::buffer(cipherText));
    }
  }catch(std::exception& e){
    std::cerr << e.what() << std::endl;
  }
}
