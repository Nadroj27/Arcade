/*
** Sphere.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:28 2017 Vacca_J
// Last update Sun Apr  9 23:08:59 2017 Romain Fagnola
*/

#include "Sphere.hpp"

Sphere::Sphere(Position const &pos, float radius, Texture const &text, unsigned int zIndex)
{
  this->_position = pos;
  this->_radius = radius;
  this->_texture = text;
  this->_zIndex = zIndex;
  this->_shape = DataType::Sphere;
}

Sphere::~Sphere()
{

}

Sphere &Sphere::operator=(const Sphere &obj)
{
  this->_position = obj._position;
  this->_radius = obj._radius;
  this->_texture = obj._texture;
  this->_zIndex = obj._zIndex;
  this->_shape = obj._shape;
  return *this;
}

Sphere::Sphere(Sphere const &obj)
{
  this->_position = obj._position;
  this->_radius = obj._radius;
  this->_texture = obj._texture;
  this->_zIndex = obj._zIndex;
  this->_shape = obj._shape;
}

float Sphere::getRadius() const
{
  return this->_radius;
}

void Sphere::setRadius(float radius)
{
  this->_radius = radius;
}

void Sphere::reset(void)
{
  this->_position = Position();
  this->_radius = 0;
  this->_texture = Texture();
  this->_zIndex = 0;
}
