/*
** AVisual.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:54 2017 Vacca_J
** Last update Sun Apr 09 01:16:54 2017 Vacca_J
*/


#include "AVisual.hpp"

Texture const &AVisual::getTexture() const {
  return this->_texture;
}

void AVisual::setTexture(Texture const &texture) {
  this->_texture = texture;
}

void AVisual::setRotation(int rotation) {
  (void) rotation;
}

unsigned int AVisual::getZIndex() const {
  return this->_zIndex;
}

void AVisual::setZIndex(unsigned int zIndex) {
  this->_zIndex = zIndex;
}

unsigned int AVisual::getId() const {
  return (this->_id);
}

void AVisual::setId(unsigned int id) {
  this->_id = id;
}
