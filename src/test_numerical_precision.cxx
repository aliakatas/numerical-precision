#include "numerical_precision.hpp"

#include <filesystem>
#include <iostream>
#include <iomanip>


int main(int argc, char** argv)
{
   std::cout << "\nStarting " << std::filesystem::path{argv[0]}.stem().string() 
      << "...\n" << std::endl;
#ifdef _DEBUG
   std::cout << " *** This is a debug build ***\n" << std::endl;
#endif
   std::cout << std::setprecision(20);

   std::cout << "Machine precision for float:        " 
      << numerical_precision::get_machine_precision<float>() << std::endl;
   std::cout << "Machine precision for double:       " 
      << numerical_precision::get_machine_precision<double>() <<  std::endl;
   std::cout << "Machine precision for long double:  " 
      << numerical_precision::get_machine_precision<long double>() <<  std::endl;

   if (numerical_precision::running_on_64bit_architecture()) 
   {
      std::cout << "\nRunning on a 64-bit architecture.\n" << std::endl;
   } 
   else 
   {
      std::cout << "\nNot running on a 64-bit architecture.\n" << std::endl;
   }

   std::cout << "Test completed successfully.\n" << std::endl;
   return 0;
}

