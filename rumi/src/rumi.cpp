#include <stdio.h>
#include <stdlib.h>
#include <format>
#include <iostream>
#include <sys/reboot.h>

int main()
{
   std::cout << "test" << std::endl;
   reboot(RB_POWER_OFF); // Initiate power off

   return(0);
}
