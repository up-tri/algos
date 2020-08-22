/**
 * ABC042 D
 * 
 * @date 2020.07.18
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int height;
int width;
int vertinal_constraint;   // a
int horizontal_constraint; // b

std::vector<std::vector<long long>> comb(int n, int r)
{
  std::vector<std::vector<long long>> v(n + 1, std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++)
  {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++)
  {
    for (int k = 1; k < j; k++)
    {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main(int argc, char const *argv[])
{
  cin >> height;
  cin >> width;
  cin >> vertinal_constraint;
  cin >> horizontal_constraint;

  // 全数計算
  height + width;

  return 0;
}