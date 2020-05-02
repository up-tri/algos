#include "datetime.hpp"
#include <iostream>
#include <chrono>

namespace yakishake
{
  namespace debug
  {
    namespace unit
    {
      typedef std::chrono::system_clock::time_point timestamp;
      typedef std::chrono::microseconds MCS;
      typedef std::chrono::milliseconds MLS;
      typedef std::chrono::seconds SS;

    } // namespace unit

    template <typename TIME_UNIT>
    class Duration
    {
    public:
      Duration(const std::string &name = "Debug") : debug_name(name)
      {
        if (typeid(TIME_UNIT) == typeid(yakishake::debug::unit::MCS))
        {
          time_unit_str = "microsec";
        }
        else if (typeid(TIME_UNIT) == typeid(yakishake::debug::unit::MLS))
        {
          time_unit_str = "ms";
        }
        else if (typeid(TIME_UNIT) == typeid(yakishake::debug::unit::SS))
        {
          time_unit_str = "s";
        }
        start = now();
      }
      ~Duration()
      {
        end = now();
        std::cout << "[DEBUG " << yakishake::datetime::now("%Y-%m-%d %H:%M:%S") << "] " << debug_name << ": " << diff() << "[" << time_unit_str << "]" << std::endl;
      }

    private:
      yakishake::debug::unit::timestamp start;
      yakishake::debug::unit::timestamp end;
      std::string time_unit_str;
      std::string debug_name;

      long long diff()
      {
        return std::chrono::duration_cast<TIME_UNIT>(end - start).count();
      }

      yakishake::debug::unit::timestamp now()
      {
        return std::chrono::system_clock::now();
      }
    };
  } // namespace debug
} // namespace yakishake