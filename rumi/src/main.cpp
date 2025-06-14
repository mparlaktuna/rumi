#include <stdio.h>
#include <stdlib.h>
#include <format>
#include <iostream>
#include <sys/reboot.h>
#include "rumi.hpp"

using namespace RUMI;
int main()
{
   Rumi rumi;

   std::cout << "test" << std::endl;
   reboot(RB_POWER_OFF); // Initiate power off

   return(0);
}
