/*
** AScene.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:03:41 2017 Vacca_J
** Last update Sun Apr 09 01:03:56 2017 Vacca_J
*/


#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include "AData.hpp"

class AScene : public AData {
public:
    virtual ~AScene () {};

    float getIncX() const;
    virtual void setIncX(float incX);

    float getIncY() const;
    virtual void setIncY(float incY);

    virtual void reset(void) = 0;


protected:
    float _incX;
    float _incY;
};

#else

class AScene;

#endif
