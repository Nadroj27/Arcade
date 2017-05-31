/*
** main.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:15:46 2017 Vacca_J
// Last update Sun Apr  9 23:07:05 2017 Romain Fagnola
*/


#include "Arcade.hpp"

int main(int const ac, char const * const * const av)
{
  if (ac != 2)
    {
      std::cerr << "Usage: " << av[0] << " [Startup Library]" << std::endl;
      return EXIT_FAILURE;
    }
  srand(time(NULL));
  Arcade arcade;
  arcade.Setup(av[1]);
  arcade.Start();
  arcade.mainLoop();
  return EXIT_SUCCESS;
}
