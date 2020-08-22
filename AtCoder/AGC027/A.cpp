/**
 * AGC027 A
 *
 * @date 2020.08.21
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int n, x, a_sum = 0;

  cin >> n;
  cin >> x;

  std::vector<int> a;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a_sum += tmp;
    a.push_back(tmp);
  }

  if (x == a_sum) {
    cout << n << endl;
    return 0;
  }

  std::sort(a.begin(), a.end());

  int cnt = 0, a_sum_2 = 0;
  for (std::vector<int>::iterator itr = a.begin(); itr < a.end(); itr++) {
    a_sum_2 += *itr;
    if (a_sum_2 <= x) {
      cnt++;
    } else {
      break;
    }
  }

  cout << (cnt == n ? n - 1 : cnt) << endl;
  return 0;
}