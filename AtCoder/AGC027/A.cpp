/**
 * AGC027 A
 * 
 * @date 2020.08.21
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */

// やりかけ

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
  int n, x, a_sum = 0;

  cin >> n;
  cin >> x;

  std::vector<int> a;

  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    a_sum += tmp;
    a.push_back(tmp);
  }

  if (a_sum < x)
  {
    cout << (n - 1) << endl;
    return 0;
  }
  else if (x == a_sum)
  {
    cout << n << endl;
    return 0;
  }

  std::sort(a.begin(), a.end());

  int cnt = 0;
  for (std::vector<int>::iterator itr = a.begin(); itr < a.end(); itr++)
  {
    if (x - *itr >= 0)
    {
      cnt++;
      x -= *itr;
    }
    else
    {
      break;
    }
  }

  cout << cnt << endl;
  return 0;
}