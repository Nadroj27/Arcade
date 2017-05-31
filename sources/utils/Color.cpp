/*
** Color.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:18 2017 Vacca_J
// Last update Sun Apr  9 23:07:27 2017 Romain Fagnola
*/


#include "Color.hpp"

Color::Color (unsigned char const x, unsigned char const y, unsigned char const z, unsigned char const a) {
  this->_r = x;
  this->_g = y;
  this->_b = z;
  this->_a = a;
};

Color::~Color () {

};

Color::Color(const Color &obj) {
  this->_r = obj._r;
  this->_g = obj._g;
  this->_b = obj._b;
  this->_a = obj._a;
};

Color    &Color::operator=(const Color &obj) {
  this->_r = obj._r;
  this->_g = obj._g;
  this->_b = obj._b;
  this->_a = obj._a;
  return *this;
};

unsigned char Color::getR() const {
  return this->_r;
};
void Color::setR(unsigned char const r) {
  this->_r = r;
};

unsigned char Color::getG() const {
  return this->_g;
};
void Color::setG(unsigned char const g){
  this->_g = g;
};

unsigned char Color::getB() const {
  return this->_b;
};
void Color::setB(unsigned char const b){
  this->_b = b;
};

unsigned char Color::getA() const {
  return this->_a;
};
void Color::setA(unsigned char const a){
  this->_a = a;
};
