/*
** Light.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:04:41 2017 Vacca_J
** Last update Sun Apr 09 01:04:43 2017 Vacca_J
*/


#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "AScene.hpp"

class Light : public AScene {
public:
    explicit Light(Position const &pos, float incX = 0, float incY = 0);
    ~Light();
    Light &operator=(const Light &obj);
    Light(Light const &obj);
    void reset(void);
};

#else

class Light;

#endif
