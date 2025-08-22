#include <iostream>

using namespace std;

int bad(int n) {
  if ( n == 0 )
    return 0;
  else
    return bad(n / 3 + 1 ) + n - 1;
}

int main() {
  cout << "Result of bad(3) =" << bad(3) << endl;
  return 0;
}
