/*
** Texture.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:03 2017 Vacca_J
// Last update Sun Apr  9 23:07:59 2017 Romain Fagnola
*/


#include "Texture.hpp"

Texture::Texture (Color const & color) {
  this->_color = color;
  this->_sprite = "";
}

Texture::Texture (std::string const & sprite, Color const & color, int rotation, Model3D const &model) {
  this->_color = color;
  this->_sprite = sprite;
  (void) model;
  (void) rotation;
}

Texture::~Texture () {

}

Texture::Texture(const Texture &obj) {
  this->_color = obj._color;
  this->_sprite = obj._sprite;
}

Texture    &Texture::operator=(const Texture &obj) {
  this->_color = obj._color;
  this->_sprite = obj._sprite;
  return *this;
}


Color const &Texture::getColor() const {
  return this->_color;
}

void Texture::setColor(Color const &color) {
  this->_color = color;
}


std::string const &Texture::getSprite() const {
  return this->_sprite;
}

void Texture::setSprite(std::string const &sprite) {
  this->_sprite = sprite;
}
