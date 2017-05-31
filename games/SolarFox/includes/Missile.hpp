/*
** Missile.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/games/SolarFox/includes
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:19:10 2017 Vacca_J
// Last update Sun Apr  9 23:06:01 2017 Romain Fagnola
*/


#ifndef _MISSILE_HPP_
#define _MISSILE_HPP_

#include "Cube.hpp"
#include "IGame.hpp"

class Missile {
  enum direction
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };
private:
  Cube *_fireball;
  int _direction;
  int _id;
public:
  Missile(std::vector <AData *> *miss, double x, double y, int);
  ~Missile();
  Missile(const Missile &obj);
  Missile &operator=(const Missile &obj);
  int getId();
  void Launch(int dir);
  Cube *getCube() const;
  void Launchfireball(int dir);
};

#endif /* !_MISSILE_HPP_ */
