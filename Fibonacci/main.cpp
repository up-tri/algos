#include "./../yakishake/unit.hpp"
#include "./../yakishake/debug.hpp"
#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;

using yakishake::unit::LLI;

LLI *memo;
LLI *dic;

LLI fib(LLI i)
{
  if (i <= 2)
    return 1;
  return fib(i - 1) + fib(i - 2);
}

LLI fib_using_memo(LLI i)
{
  if (i <= 2)
    return 1;
  else if (memo[i] != 0)
    return memo[i];
  else
    return fib_using_memo(i - 1) + fib_using_memo(i - 2);
}

LLI fib_directly(LLI n)
{
  dic = (LLI *)malloc(n * sizeof(LLI));
  dic[0] = 1;
  dic[1] = 1;
  for (LLI i = 2; i < n; i++)
  {
    dic[i] = dic[i - 1] + dic[i - 2];
  }
  return dic[n - 1];
}

int main(int argc, char const *argv[])
{
  LLI n = -1, normal_result, memo_result, directly_result;
  while (n < 0)
  {
    cout << "n項目(0 <= n):";
    cin >> n;
  }

  if (n <= 40)
  {
    {
      // normal
      yakishake::debug::Duration<yakishake::debug::unit::MCS> normal_duration("normal");
      normal_result = fib(n);
      cout << "normal: " << normal_result << endl;
    }
    {
      // memo
      yakishake::debug::Duration<yakishake::debug::unit::MCS> memo_duration("memo");
      memo = (LLI *)malloc(n * sizeof(LLI));
      memo_result = fib_using_memo(n);
      cout << "memo: " << memo_result << endl;
    }
  }
  {
    // directly
    yakishake::debug::Duration<yakishake::debug::unit::MCS> directly_duration("directly");
    directly_result = fib_directly(n);
    cout << "directly: " << directly_result << endl;
  }
  return 0;
}
