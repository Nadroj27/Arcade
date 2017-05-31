//
// Exception.hpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 23:39:57 2017 Ethan Kerdelhue
// Last update Mon Mar 20 23:54:02 2017 Ethan Kerdelhue
//


#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <ostream>
#include <exception>

class Exception : public std::exception
  {
    public:
      Exception(std::string const &reason, std::string const &location):
  _reason(reason + ".\x1B[49m"),
  _location("\x1B[41mError in " + location) {

      } ;
      ~Exception() noexcept {}
      std::string const &getLocation(void) const noexcept {
          return this->_location;
      };
      const char *what(void) const noexcept {
        return this->_reason.c_str();
      };
    protected:
      std::string const _reason;
      std::string const _location;
  };

#endif /* !EXCEPTION_HPP */
