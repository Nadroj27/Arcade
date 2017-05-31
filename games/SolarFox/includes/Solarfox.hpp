//
// Starfox.hpp for  in /home/fagnol_r/Tek_2/CPP/cpp_arcade/games/Starfox/includes
//
// Made by Romain Fagnola
// Login   <fagnol_r@epitech.net>
//
// Started on  Mon Apr  3 17:57:08 2017 Romain Fagnola
// Last update Sun Apr  9 21:00:21 2017 Ethan Kerdelhue
//

#ifndef SOLARFOX_HPP
#define SOLARFOX_HPP

#include <unistd.h>

#include "IGame.hpp"
#include "Cube.hpp"
#include "Sphere.hpp"
#include "Text.hpp"
#include "Audio.hpp"
#include "Ennemy.hpp"
#include "Missile.hpp"
#include "Protocol.hpp"

class Solarfox : public IGame {

public:

  enum direction
    {
      UP = 0,
      DOWN = 1,
      RIGHT = 2,
      LEFT = 3,
      UNKNOWN = 8,
    };

  Solarfox();
  ~Solarfox();
  Solarfox(const Solarfox &obj);
  Solarfox &operator=(const Solarfox &obj);

  virtual void InitGame();
  virtual std::string const &getGameName() const;
  virtual int getFrameRatePerSecond() const;
  virtual std::vector <AData *> const &getData() const;

  virtual std::vector <std::string> const & getSprite() const;
  virtual std::vector <std::string> const & getMusic() const;
  virtual std::vector <std::string> const & getModel3D() const;

  virtual void setScoreManager(ScoreManager *scoreManager);
  virtual void updateNewScore() const;

  virtual void play();
  virtual void getMap();
  virtual void whereIAm();

  virtual void goUp();
  virtual void goDown();
  virtual void goLeft();
  virtual void goRight();
  virtual void goForward();
  virtual void shoot();
  virtual void gameover();
  virtual void moveUp();
  virtual void moveDown();
  virtual void moveLeft();
  virtual void moveRight();

  virtual void setDirection(direction const &dir);
  virtual direction getDirection();

  virtual void trump_shot();
  virtual void Missile_move();
  virtual void erase_trump_missile();
  virtual int hit_trump();
  virtual void erase_fireball();
  virtual int colisionMail();
  virtual void win();
  virtual int colisionMissile();

  virtual void setKarcadeModeTrue();

private:
  direction _direction;
  Text *_pscore;
  int _score;
  int _speed;
  int _frameRate;
  std::string _gameName;
  std::vector <AData *> _data;
  Cube * _gameover;
  std::vector <std::string> _sprite;
  std::vector <std::string> _music;
  std::vector <std::string> _model;
  std::vector <Ennemy*> _ennemy;
  Cube *_head;
  unsigned int _firstCell;
  int _feedNumber;
  Audio *_mainAudio;
  int _it;
  std::vector <Missile*> _miss;
  bool _press;
  unsigned int _endCell;
  bool _win;
  bool _loose;
  bool _isKarkade = false;
};

#else

class Solarfox;

#endif /* SOLARFOX_HPP */
