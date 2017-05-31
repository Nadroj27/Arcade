/*
** AScene.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:17:05 2017 Vacca_J
// Last update Sun Apr  9 23:08:16 2017 Romain Fagnola
*/


#include "AScene.hpp"

float AScene::getIncX() const
{
  return (this->_incX);
}

void AScene::setIncX(float incX)
{
  this->_incX = incX;
}

float AScene::getIncY() const
{
  return (this->_incY);
}

void AScene::setIncY(float incY)
{
  this->_incY = incY;
}
