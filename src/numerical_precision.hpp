#pragma once
#include <type_traits>

namespace numerical_precision 
{
   /**
    * @brief Returns the numerical precision of the 
    * machine given the (floating point) data type.
    * 
    * @tparam T Supports float, double, long double.
    * @return Numerical precision of the machine for the particular data type.
    */
   template <typename T>
   typename std::enable_if<std::is_floating_point<T>::value, T>::type
   get_machine_precision() 
   {
      T e = static_cast<T>(1.0L);
      while (e + static_cast<T>(1.0L) != static_cast<T>(1.0L))
         e *= static_cast<T>(0.5L);
      return e;
   }

   /**
    * @brief Checks if the current architecture is 64-bit.
    * 
    * @return true if running on a 64-bit architecture, false otherwise.
    */
   inline bool running_on_64bit_architecture() 
   {
      return sizeof(void*) == 8;
   }
}
