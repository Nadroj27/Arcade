/*
** ExternLib.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:06:20 2017 Vacca_J
** Last update	Sun Apr 09 21:01:59 2017 Ethan Kerdelhue
*/


#ifndef EXTERNLIB_HPP_
#define EXTERNLIB_HPP_

#include <iostream>
#include <dlfcn.h>
#include "Exception.hpp"

class ExternLib {

public:

    ExternLib (char const * filename, int flags) {
        this->_lib = dlopen(filename, flags);
        if (!this->_lib) {
            try {
                throw Exception(dlerror(), "ExternLib");
            } catch (std::exception const &e){
                _lib = NULL;
                std::cerr << e.what() << std::endl;
            }
        }
    };

    ~ExternLib () {
      
    }

    void *getLib() const {
        return this->_lib;
    }

private:
    void *_lib;

};

#endif /* !EXTERNLIB_HPP_ */
