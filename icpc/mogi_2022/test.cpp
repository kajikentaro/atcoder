#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << 14 << endl;
  string stream = "";
  for (long long i = 0; i < 200000; i++) {
    if (i % 14 == 0) {
      cout << stream;
      stream = "";
    }
    stream = stream + "9";
  }
  cout << endl;
}