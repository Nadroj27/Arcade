/*
** Light.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:37 2017 Vacca_J
// Last update Sun Apr  9 23:08:50 2017 Romain Fagnola
*/

#include "Light.hpp"

Light::Light(Position const &pos, float incX, float incY)
{
  this->_incX = incX;
  this->_incY = incY;
  this->_position = pos;
  this->_shape = DataType::Light;
}

Light::~Light()
{

}

Light &Light::operator=(const Light &obj)
{
  this->_incX = obj._incX;
  this->_incY = obj._incY;
  this->_position = obj._position;
  this->_shape = obj._shape;
  return *this;
}

Light::Light(Light const &obj)
{
  this->_incX = obj._incX;
  this->_incY = obj._incY;
  this->_position = obj._position;
  this->_shape = obj._shape;
}

void Light::reset(void)
{
  this->_incX = 0;
  this->_incY = 0;
  this->_position = Position();
}
