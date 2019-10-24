#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int flag = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      cout << x / 2 << '\n';
    } else {
      cout << (x + flag) / 2 << '\n';
      flag *= -1;
    }
  }
  return 0;
}