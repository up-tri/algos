/**
 * ABC042 A
 * 
 * @date 2020.05.02
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
  int count = 0;
  int in;
  for (int i = 0; i < 3; i++)
  {
    std::cin >> in;
    if (in == 5)
      count += 1;
    if (in == 7)
      count += 10;
  }
  std::cout << (count == 12 ? "YES" : "NO") << endl;

  return 0;
}