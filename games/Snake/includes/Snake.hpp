//
// Snake.hpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/games/Snake/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 00:04:32 2017 Ethan Kerdelhue
// Last update Sun Apr  9 23:05:29 2017 Romain Fagnola
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <unistd.h>

#include "IGame.hpp"
#include "Cube.hpp"
#include "Sphere.hpp"
#include "Text.hpp"
#include "Audio.hpp"
#include "Model3D.hpp"
#include "Protocol.hpp"

class Snake : public IGame {

  enum direction
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

public:
  Snake();
  ~Snake();
  Snake(const Snake &obj);
  Snake &operator=(const Snake &obj);

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

  virtual void popMicro();

  virtual void setDirection(Snake::direction const &dir);
  virtual Snake::direction getDirection();

  virtual void setKarcadeModeTrue();

  void whereIAm();

private:
  direction _direction;
  Text *_pscore;
  int _score;
  int _frameRate;
  std::string _gameName;
  std::vector <AData *> _data;
  Cube * _bonus;
  Cube * _gameover;
  std::vector <std::string> _sprite;
  std::vector <std::string> _music;
  std::vector <std::string> _model;
  Cube *_head;
  unsigned int _firstCell;
  int _feedNumber;
  Audio *_mainAudio;
  int _it;
  bool _loose;
  bool _isKarkade = false;
  // ScoreManager _scoreManager;
};

#endif /* !SNAKE_HPP */
