/*
** Position.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:09 2017 Vacca_J
** Last update	Sun Apr 09 19:10:38 2017 Ethan Kerdelhue
*/


#include "Position.hpp"

Position::Position (double const x, double const y, double const z) {
  this->_x = x;
  this->_y = y;
  this->_z = z;
};

Position::~Position () {

};

Position::Position(const Position &obj) {
  this->_x = obj._x;
  this->_y = obj._y;
  this->_z = obj._z;
};

Position    &Position::operator=(const Position &obj) {
  this->_x = obj._x;
  this->_y = obj._y;
  this->_z = obj._z;
  return *this;
};

double Position::getX() const {
  return this->_x;
};
void Position::setX(double const x) {
  this->_x = x;
};

double Position::getY() const {
  return this->_y;
};
void Position::setY(double const y){
  this->_y = y;
};

double Position::getZ() const {
  return this->_z;
};
void Position::setZ(double const z){
  this->_z = z;
};

Position operator+(Position const &a, Position const &b)
{
  Position tmp(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
  return (tmp);
}

Position operator-(Position const &a, Position const &b)
{
  Position tmp(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
  return (tmp);
}

Position operator/(Position const &a, int b)
{
  Position tmp(a.getX() / b, a.getY() / b, a.getZ() / b);
  return (tmp);
}

Position operator*(Position const &a, int b)
{
  Position tmp(a.getX() * b, a.getY() * b, a.getZ() * b);
  return (tmp);
}
