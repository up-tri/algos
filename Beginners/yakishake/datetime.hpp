#include <chrono>
#include <string>
#include <ctime>

namespace yakishake
{
  namespace datetime
  {
    std::string now(std::string format)
    {
      const char *format_char = format.c_str();
      char buf[128];
      std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
      std::time_t time = std::chrono::system_clock::to_time_t(now);
      std::strftime(buf, sizeof(buf), format_char, std::localtime(&time));
      return buf;
    }
  } // namespace datetime
} // namespace yakishake
