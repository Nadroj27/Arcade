//
// LoadController.hpp for  in /Users/ethankerdelhue/Documents/shared/cpp_arcade/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed Mar 15 09:47:57 2017 Ethan Kerdelhue
// Last update Sun Apr  9 21:02:36 2017 Ethan Kerdelhue
//

#ifndef LoadController_HPP
# define LoadController_HPP

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>

class LoadController {
  private:

  public:
    LoadController ();
    virtual ~LoadController ();
    LoadController(const LoadController &obj);
    LoadController  &operator=(const LoadController &obj);

    static std::vector <std::string> readDirectory(std::string const &path, std::string const &startingLib);

};

#endif /* !LoadController_HPP */
