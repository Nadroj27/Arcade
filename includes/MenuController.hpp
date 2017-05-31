//
// MenuController.hpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/games/Snake/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 00:04:32 2017 Ethan Kerdelhue
// Last update Sun Apr  9 21:02:41 2017 Ethan Kerdelhue
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Arcade.hpp"
#include "IGame.hpp"
#include "Cube.hpp"
#include "Text.hpp"
#include "Audio.hpp"

class MenuController : public IGame {

public:
  MenuController(Arcade * main);
  ~MenuController();
  MenuController(const MenuController &obj);
  MenuController &operator=(const MenuController &obj);

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
  virtual void pressEchap();
  virtual void pressEight();
  virtual void pressNine();

private:
  int _frameRate;
  std::string _gameName;
  std::vector <AData *> _data;
  int _it;
  Arcade *_main;
  std::vector <std::string> _sprite;
  std::vector <std::string> _music;
  std::vector <std::string> _model;
  int _lib;
  int _flags;
  int _size;
  bool _score;
  int _repere;
  int _i;
};

#else

class MenuController;

#endif /* !SNAKE_HPP */
