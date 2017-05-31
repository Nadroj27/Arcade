/*
** AData.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:17:09 2017 Vacca_J
// Last update Sun Apr  9 23:08:08 2017 Romain Fagnola
*/


#include "AData.hpp"

DataType const &AData::getShape() const {
  return this->_shape;
}

void AData::setShape(DataType const &shape) {
  this->_shape = shape;
}

Position const &AData::getPosition() const {
  return this->_position;
}

void AData::setPosition(Position const &position) {
  this->_position = position;
}

void AData::setPositionX(double const x) {
  this->_position.setX(x);
}

void AData::setPositionY(double const y) {
  this->_position.setY(y);
}

void AData::setPositionZ(double const z) {
  this->_position.setZ(z);
}
