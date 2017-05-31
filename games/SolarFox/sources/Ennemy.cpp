/*
** Ennemy.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/games/SolarFox/sources
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:19:17 2017 Vacca_J
** Last update	Sun Apr 09 21:00:30 2017 Ethan Kerdelhue
*/


#include "Ennemy.hpp"

Ennemy::Ennemy(Position pos, std::vector <AData *> *_data, int number)
{
  switch (number) {
  case 0:
    trump = new Cube(pos, Position(5, 5, 5), Texture("./assets/solarfox/trump_bas.png", Color(255, 255, 255, 255)), 3, 3);
    _direction = 0;
    break;
  case 1:
    trump = new Cube (pos, Position(5, 5, 5), Texture("./assets/solarfox/trump_haut.png", Color(255, 255, 255, 255)), 3, 3);
    _direction = 1;
    break;
  case 2:
    trump = new Cube (pos, Position(5, 5, 5), Texture("./assets/solarfox/trump_gauche.png", Color(255, 255, 255, 255)), 3, 3);
    _direction = 2;
    break;
  case 3:
    trump = new Cube (pos, Position(5, 5, 5), Texture("./assets/solarfox/trump_droite.png", Color(255, 255, 255, 255)), 3, 3);
    _direction = 3;
    break;
  default:
    break;
  }
  _data->push_back(trump);
  this->where = true;
  this->_frame = rand() % 30 + 1;
  this->_isFreeze = false;
}

Ennemy::~Ennemy()
{

}

Ennemy::Ennemy(const Ennemy &obj)
{
  this->trump = obj.trump;
  this->_direction = obj._direction;
}

Ennemy  &Ennemy::operator=(const Ennemy &obj)
{
  this->trump = obj.trump;
  this->_direction = obj._direction;
  return (*this);
}

void Ennemy::setFrame(int frame)
{
  this->_frame = frame;
}

int Ennemy::getFrame()
{
  return this->_frame;
}

Cube  *Ennemy::getCube()
{
  return (this->trump);
}

void Ennemy::setFreeze(bool freeze)
{
  this->_isFreeze = freeze;
}

bool Ennemy::getFreeze()
{
  return (this->_isFreeze);
}

void  Ennemy::move(int num)
{
  switch (num) {
  case 0:
    if (this->_isFreeze == false)
      {
	if (this->where == true)
	  {
	    this->trump->setPositionX(this->trump->getPosition().getX() + 5);
	    if (this->trump->getPosition().getX() == 80)
	      this->where = false;
	  }
	else if (this->where == false)
	  {
	    this->trump->setPositionX(this->trump->getPosition().getX() - 5);
	    if (this->trump->getPosition().getX() == 10)
	      this->where = true;
	  }
      }
    break;
  case 1:
    if (this->_isFreeze == false)
      {
	if (this->where == true)
	  {
	    this->trump->setPositionX(this->trump->getPosition().getX() - 5);
	    if (this->trump->getPosition().getX() == 10)
	      this->where = false;
	  }
	else if (this->where == false)
	  {
	    this->trump->setPositionX(this->trump->getPosition().getX() + 5);
	    if (this->trump->getPosition().getX() == 80)
	      this->where = true;
	  }
      }
    break;
  case 2:
    if (this->_isFreeze == false)
      {
	if (this->where == true)
	  {
	    this->trump->setPositionY(this->trump->getPosition().getY() + 5);
	    if (this->trump->getPosition().getY() == 80)
	      this->where = false;
	  }
	else if (this->where == false)
	  {
	    this->trump->setPositionY(this->trump->getPosition().getY() - 5);
	    if (this->trump->getPosition().getY() == 10)
	      this->where = true;
	  }
      }
    break;
  case 3:
    if (this->_isFreeze == false)
      {
	if (this->where == true)
	  {
	    this->trump->setPositionY(this->trump->getPosition().getY() - 5);
	    if (this->trump->getPosition().getY() == 10)
	      this->where = false;
	  }
	else if (this->where == false)
	  {
	    this->trump->setPositionY(this->trump->getPosition().getY() + 5);
	    if (this->trump->getPosition().getY() == 80)
	      this->where = true;
	  }
      }
    break;
  default:
    break;
  }
}
