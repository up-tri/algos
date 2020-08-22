/**
 * ABC042 B
 * 
 * @date 2020.05.02
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
  int n;
  int l;
  std::cin >> n;
  std::cin >> l;
  std::vector<std::string> dic = {};
  for (int i = 0; i < n; i++)
  {
    std::string in;
    std::cin >> in;
    dic.push_back(in);
  }
  std::sort(dic.begin(), dic.end());

  for (std::vector<std::string>::iterator item = dic.begin(); item != dic.end(); item++)
  {
    std::cout << *item;
  }
  std::cout << endl;

  return 0;
}