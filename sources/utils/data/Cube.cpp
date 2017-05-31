/*
** Cube.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:44 2017 Vacca_J
// Last update Sun Apr  9 23:08:42 2017 Romain Fagnola
*/


#include "Cube.hpp"

Cube::Cube(Position const &pos, Position const &size, Texture const &text, unsigned int zIndex, unsigned int id)
{
  this->_size = size;
  this->_position = pos;
  this->_texture = text;
  this->_zIndex = zIndex;
  this->_shape = DataType::Cube;
  this->_id = id;
}

Cube::~Cube()
{

}

Cube &Cube::operator=(const Cube &obj)
{
  this->_size = obj._size;
  this->_position = obj._position;
  this->_texture = obj._texture;
  this->_zIndex = obj._zIndex;
  this->_shape = obj._shape;
  return *this;
}

Cube::Cube(Cube const &obj)
{
  this->_size = obj._size;
  this->_position = obj._position;
  this->_texture = obj._texture;
  this->_zIndex = obj._zIndex;
  this->_shape = obj._shape;
}

Position const &Cube::getSize() const
{
  return this->_size;
}

void Cube::setSize(Position const &size)
{
  this->_size = size;
}

void Cube::reset(void) {
  this->_size = 0;
  this->_position = Position();
  this->_texture = Texture();
  this->_zIndex = 0;
}

bool Cube::inLine(double a, double new_a, double size) const
{
  return (a >= new_a && a <= new_a + size);
}

bool Cube::operator==(Cube const &cube) const
{
  bool xIn = inLine(cube.getPosition().getX(), this->getPosition().getX(), this->getSize().getX())
    || inLine(this->getPosition().getX(), cube.getPosition().getX(), cube.getSize().getX());

  bool yIn = inLine(cube.getPosition().getY(), this->getPosition().getY(), this->getSize().getY())
    || inLine(this->getPosition().getY(), cube.getPosition().getY(), cube.getSize().getY());

  bool zIn = inLine(cube.getPosition().getZ(), this->getPosition().getZ(), this->getSize().getZ())
    || inLine(this->getPosition().getZ(), cube.getPosition().getZ(), cube.getSize().getZ());

  return (xIn && yIn && zIn);
}
