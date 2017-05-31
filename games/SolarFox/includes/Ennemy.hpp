/*
** Ennemy.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/games/SolarFox/includes
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:19:04 2017 Vacca_J
** Last update	Sun Apr 09 21:47:20 2017 Ethan Kerdelhue
*/

#ifndef _ENNEMY_HPP_
#define _ENNEMY_HPP_

#include "Cube.hpp"
#include "IGame.hpp"

class Ennemy
{
private:
  Cube *trump;
  int _direction;
  bool where;
  int _frame;
  bool _isFreeze;
public:
  Ennemy(Position, std::vector<AData *> *_data, int);
  ~Ennemy();
  Ennemy(const Ennemy &obj);
  Ennemy &operator=(const Ennemy &obj);
  void  move(int num);
  Cube *getCube();
  void setFrame(int);
  int  getFrame();
  bool getFreeze();
  void setFreeze(bool);
};

#else

class Ennemy;

#endif /* _ENNEMY_HPP_ */
