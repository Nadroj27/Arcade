//
// MenuController.cpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/games/MenuController/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 00:05:59 2017 Ethan Kerdelhue
// Last update Sun Apr  9 23:07:11 2017 Romain Fagnola
//

#include "MenuController.hpp"

MenuController::MenuController(Arcade *main)
{
  this->_frameRate = 60;
  this->_gameName = "Menu";
  this->_main = main;
  this->_lib = 0;
  this->_flags = 1;
  this->_size = 27;
  this->_score = false;
  this->_repere = 0;
  this->_i = 1;
}

MenuController::~MenuController()
{

}

MenuController::MenuController(const MenuController &obj)
{
  this->_frameRate = obj._frameRate;
  this->_gameName = obj._gameName;
  this->_data = obj._data;
  this->_sprite = obj._sprite;
}

MenuController &MenuController::operator=(const MenuController &obj)
{
  this->_frameRate = obj._frameRate;
  this->_gameName = obj._gameName;
  this->_data = obj._data;
  this->_sprite = obj._sprite;
  return (*this);
}

void MenuController::InitGame() {
  int size = 30;
  AData *bg = new Cube(Position(0, -30, 0), Position(100 , 100, 0), Texture("./assets/menu/menu.png", Color(255,255,0,0)), 0);

  this->_data.push_back(bg);
  for (unsigned int a = 0; a < this->_main->getNameGame().size(); a++)
    {
      Text *score = new Text(this->_main->getNameGame()[a], 36, Position(50, size, 50), 2);
      score->setTexture(Texture(Color(0, 0, 0, 0)));
      score->setAlign(Text::CENTER);
      this->_data.push_back(score);
      size += 10;
    }
  Text *score = new Text("Score", 36, Position(50, size, 50));
  score->setTexture(Texture(Color(0, 0, 0, 0)));
  score->setAlign(Text::CENTER);
  this->_data.push_back(score);
  this->_data.push_back(new Cube(Position(90, 10, 5), Position(5,5,5), Texture("./assets/menu/flag.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(90, 20, 5), Position(5,5,5), Texture("./assets/menu/flag.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(0, 10, 5), Position(5,5,5), Texture("./assets/menu/sprite-melanchon.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(0, 20, 5), Position(5,5,5), Texture("./assets/menu/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(0, this->_size, 5), Position(5,5,5), Texture("./assets/menu/cartman.png", Color(255, 255, 255, 255)), 2));
  this->_repere = (this->_data.size() - 1);
}

std::string const &MenuController::getGameName() const {
  return (this->_gameName);
}

void MenuController::setScoreManager(ScoreManager *scoreManager) {
  (void) scoreManager;
}

void MenuController::whereIAm() {

}

int MenuController::getFrameRatePerSecond() const {
  return (this->_frameRate);
}

std::vector <AData *> const &MenuController::getData() const {
  return (this->_data);
}

std::vector <std::string> const & MenuController::getSprite() const {
  return (_sprite);
}

std::vector <std::string> const & MenuController::getMusic() const {
  return (_music);
}

std::vector <std::string> const & MenuController::getModel3D() const {
  return (_model);
}

void MenuController::updateNewScore() const {

}

void MenuController::play() {
  if (this->_score == false)
    {
      if (_flags == 1)
	{
	  int i = rand() % 3 + 1;
	  if (i == 1)
	    this->_data[this->_data.size() - (2)]->setPositionX(this->_data[this->_data.size() - (2)]->getPosition().getX() + 0.5);
	  else if (i <= 2)
	    this->_data[this->_data.size() - (3)]->setPositionX(this->_data[this->_data.size() - (3)]->getPosition().getX() + 0.5);
	  if (this->_data[this->_data.size() - (2)]->getPosition().getX() == 90 && this->_flags == 1)
	    {
	      Text *bscore = new Text("Marine Presidente", 36, Position(50, 10, 50));
	      bscore->setTexture(Texture(Color(0, 0, 0, 0)));
	      bscore->setAlign(Text::CENTER);
	      this->_data.push_back(bscore);
	      this->_flags = 2;
	    }
	  else if (this->_data[this->_data.size() - (3)]->getPosition().getX() == 90 && this->_flags == 1)
	    {
	      Text *ascore = new Text("Melenchon President", 36, Position(50, 10, 50));
	      ascore->setTexture(Texture(Color(0, 0, 0, 0)));
	      ascore->setAlign(Text::CENTER);
	      this->_data.push_back(ascore);
	      this->_flags = 2;
	    }
	}
    }
}


void MenuController::gameover()
{

}

void MenuController::getMap() {

}

void MenuController::moveUp()
{

}

void MenuController::moveDown()
{

}

void MenuController::moveLeft()
{

}

void MenuController::moveRight()
{

}

void MenuController::goUp() {
  int i = this->_data.size() - this->_flags;
  if (this->_data[i]->getPosition().getY() != 27)
    {
      this->_data[i]->setPositionY(this->_data[i]->getPosition().getY() - 10);
      if (this->_lib == 0);
      else if (this->_data[i]->getPosition().getY() == ((unsigned int)this->_size) + ((this->_main->getNameGame().size() - 1) * 10));
      else
	this->_lib -= 1;
    }
}

void MenuController::goDown() {
  int i = this->_data.size() - this->_flags;
  if (this->_data[i]->getPosition().getY() != ((unsigned int)this->_size) + ((this->_main->getNameGame().size()) * 10))
    {
      this->_data[i]->setPositionY(this->_data[i]->getPosition().getY() + 10);
      if ((unsigned int)this->_lib == this->_main->getNameGame().size() - 1)
	this->_score = true;
      else
	this->_lib += 1;
    }
}

void MenuController::goLeft() {
  if (this->_i == 0)
    {
      this->_data.erase(this->_data.end() - 1);
      this->_i = 1;
    }
  this->_score = false;
}

void MenuController::goRight() {

}

void MenuController::goForward() {
  if (this->_score == false) {
    this->_main->setCurrentGame(this->_main->getLibGames()[this->_lib]);
    this->_main->setInGameMode();
    this->_main->initCurrentGame();
  }
  if (this->_score == true && this->_i != 0)
    {
      this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture(Color(0, 0, 0, 255)), 8));
      this->_i = 0;
    }
}

void MenuController::shoot() {

}

void MenuController::pressEchap() {

}

void MenuController::pressEight() {

}
void MenuController::pressNine() {

}
