//
// LoadController.cpp for  in /Users/ethankerdelhue/Documents/shared/cpp_arcade/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed Mar 15 09:49:47 2017 Ethan Kerdelhue
// Last update Sun Apr  9 23:07:34 2017 Romain Fagnola
//

#include "LoadController.hpp"

LoadController::LoadController()
{

}

LoadController::~LoadController()
{

}

LoadController::LoadController(const LoadController &obj)
{
  (void) obj;
}

LoadController &LoadController::operator=(const LoadController &obj)
{
  (void) obj;
  return (*this);
}

std::vector <std::string> LoadController::readDirectory(const std::string& path, const std::string& startingLib)
{
  std::vector <std::string> result;
  dirent* de;
  DIR* folder;
  folder = opendir(path.empty() ? "." : path.c_str());
  if (folder)
    {
      while (true)
	{
	  de = readdir(folder);
	  if (de == NULL)
	    break;
	  if (de->d_type != DT_DIR && std::string(de->d_name).substr(std::string(de->d_name).find_last_of(".") + 1) == "so") {
	    if ((path + std::string(de->d_name)) != (startingLib)) {
	      result.push_back(path + std::string(de->d_name));
	    } else if ((path + std::string(de->d_name)) == (startingLib)){
	      result.push_back(path + std::string(de->d_name));
	      std::reverse(result.begin(), result.end());
	    } else {
	      result.push_back(path + std::string(de->d_name));
	      std::reverse(result.begin(), result.end());
	    }
	  }
	}
      closedir(folder);
    }
  return result;
}
