/*
** Model3D.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:32 2017 Vacca_J
** Last update Sun Apr 09 01:16:33 2017 Vacca_J
*/


#include "Model3D.hpp"

Model3D::Model3D (std::string const &object, Position const &position , Position const &_scale, Position const &_rotation) {
  (void) object;
  (void) position;
  (void) _scale;
  (void) _rotation;
}

Model3D::~Model3D () {

}

Model3D::Model3D(const Model3D &obj) {
  (void) obj;
}

Model3D &Model3D::operator=(const Model3D &obj) {
  (void) obj;
  return (*this);
}

void Model3D::setObject(std::string const &object) {
  (void) object;
}

std::string const &Model3D::getObject(void) const {
  std::string *tmp = new std::string("");
  return (*tmp);
}

void Model3D::setScale(Position const &scale) {
  (void) scale;
}

void Model3D::setScaleX(double x) {
  (void) x;
}
void Model3D::setScaleY(double y) {
  (void) y;
}
void Model3D::setScaleZ(double z) {
  (void) z;
}

Position const &Model3D::getScale(void) const {
  Position *tmp = new Position();
  return (*tmp);
}

void Model3D::setPosition(Position const &position) {
  (void) position;
}

void Model3D::setPositionX(double x) {
  (void) x;
}

void Model3D::setPositionY(double y) {
  (void) y;
}

void Model3D::setPositionZ(double z) {
  (void) z;
}

Position const &Model3D::getPosition(void) const {
  Position *tmp = new Position();
  return (*tmp);
}

void Model3D::setRotation(Position const &rotation) {
  (void) rotation;
}

void Model3D::setRotationX(double x) {
  (void) x;
}

void Model3D::setRotationY(double y) {
  (void) y;
}

void Model3D::setRotationZ(double z) {
  (void) z;
}

Position const &Model3D::getRotation(void) const {
  Position *tmp = new Position();
  return (*tmp);
}
