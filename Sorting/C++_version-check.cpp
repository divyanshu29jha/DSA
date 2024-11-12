#include<iostream>
using namespace std;

int main() {
   if (__cplusplus == 201703L)
      cout << "C++17";
   else if (__cplusplus == 201402L)
      cout << "C++14";
   else if (__cplusplus == 201103L)
      cout << "C++11";
   else if (__cplusplus == 199711L)
      cout << "C++98";
   else
      cout << "pre-standard C++";
}