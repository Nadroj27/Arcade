/*
** Missile.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/games/SolarFox/sources
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:19:23 2017 Vacca_J
** Last update	Sun Apr 09 21:00:52 2017 Ethan Kerdelhue
*/


#include "Missile.hpp"

Missile::Missile(std::vector <AData *> *miss, double x, double y, int flags)
{
  if (flags == 0)
    {
      this->_fireball = new Cube(Position(x, y, 50), Position(5, 5, 5), Texture("./assets/solarfox/fireball.png", Color(255, 255, 255, 255)), 2, 5);
      this->_id = 0;
    }
  else if (flags == 1)
    {
      this->_fireball = new Cube(Position(x, y, 50), Position(5, 5, 5), Texture("./assets/solarfox/laser-horizon.png", Color(255, 255, 255, 255)), 4);
      this->_id = 1;
    }
  else if (flags == 2)
    {
      this->_fireball = new Cube(Position(x, y, 50), Position(5, 5, 5), Texture("./assets/solarfox/laser-horizon.png", Color(255, 255, 255, 255)), 4);
      this->_id = 2;
    }
  else if (flags == 3)
    {
      this->_fireball = new Cube(Position(x, y, 50), Position(5, 5, 5), Texture("./assets/solarfox/laser-vertic.png", Color(255, 255, 255, 255)), 4);
      this->_id = 3;
    }
  else
    {
      this->_fireball = new Cube(Position(x, y, 50), Position(5, 5, 5), Texture("./assets/solarfox/laser-vertic.png", Color(255, 255, 255, 255)), 4);
      this->_id = 4;
    }
  miss->push_back(this->_fireball);
}

Missile::~Missile()
{

}

Missile::Missile(const Missile &obj)
{
  this->_fireball = obj._fireball;
  this->_direction = obj._direction;
}

Missile &Missile::operator=(const Missile &obj)
{
  this->_fireball = obj._fireball;
  this->_direction = obj._direction;
  return(*this);
}

int Missile::getId()
{
  return this->_id;
}

Cube *Missile::getCube() const
{
  return this->_fireball;
}

void Missile::Launchfireball(int dir)
{
  this->_direction = dir;
  if (this->_direction == 0)
    this->_fireball->setPositionY(this->_fireball->getPosition().getY() - 5);
  if (this->_direction == 1)
    this->_fireball->setPositionY(this->_fireball->getPosition().getY() + 5);
  if (this->_direction == 3)
    this->_fireball->setPositionX(this->_fireball->getPosition().getX() - 5);
  if (this->_direction == 2)
    this->_fireball->setPositionX(this->_fireball->getPosition().getX() + 5);
  if (this->_direction == 8)
    this->_fireball->setPositionY(this->_fireball->getPosition().getY() - 5);
}

void Missile::Launch(int dir)
{
  this->_direction = dir;
  if (this->_direction == 0)
    this->_fireball->setPositionY(this->_fireball->getPosition().getY() - 5);
  if (this->_direction == 1)
    this->_fireball->setPositionY(this->_fireball->getPosition().getY() + 5);
  if (this->_direction == 3)
    this->_fireball->setPositionX(this->_fireball->getPosition().getX() - 5);
  if (this->_direction == 2)
    this->_fireball->setPositionX(this->_fireball->getPosition().getX() + 5);
}
