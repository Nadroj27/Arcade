//
// Starfox.cpp for  in /home/fagnol_r/Tek_2/CPP/cpp_arcade/games/Starfox/sources
//
// Made by Romain Fagnola
// Login   <fagnol_r@epitech.net>
//
// Started on  Mon Apr  3 17:56:20 2017 Romain Fagnola
// Last update Sun Apr  9 23:31:47 2017 Ethan Kerdelhue
//

#include "Solarfox.hpp"

Solarfox::Solarfox()
{
  this->_frameRate = 60;
  this->_gameName = "Solarfox";
  this->_feedNumber = 0;
  this->_score = 0;
  this->_direction = UNKNOWN;
  this->_press = false;
  this->_speed = 5;
  this->_win = false;
  this->_loose = false;
  this->_it = 0;
}

Solarfox::~Solarfox()
{

}

Solarfox::Solarfox(const Solarfox &obj)
{
  this->_frameRate = obj._frameRate;
  this->_gameName = obj._gameName;
  this->_data = obj._data;
  this->_sprite = obj._sprite;
}

Solarfox &Solarfox::operator=(const Solarfox &obj)
{
  this->_frameRate = obj._frameRate;
  this->_gameName = obj._gameName;
  this->_data = obj._data;
  this->_sprite = obj._sprite;
  return (*this);
}

void Solarfox::InitGame() {
  AData *bg = new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture(Color(25, 25, 25, 255)), 0);
  this->_head = new Cube(Position(45, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/hilarie.png", Color(255, 255, 0, 0)), 3);

  this->_ennemy.push_back(new Ennemy(Position(45, 0, 50), &this->_data, UP));
  this->_ennemy.push_back(new Ennemy(Position(45, 90, 50), &this->_data, DOWN));
  this->_ennemy.push_back(new Ennemy(Position(0, 45, 50), &this->_data, LEFT));
  this->_ennemy.push_back(new Ennemy(Position(90, 45, 50), &this->_data, RIGHT));
  this->_mainAudio = new Audio("./assets/americanfuckyeah.ogg", 100, true);
  this->_data.push_back(bg);
  this->_mainAudio->setPositionX(-500);
  this->_mainAudio->setPositionY(0);
  this->_mainAudio->setPositionZ(0);

  this->_data.push_back(this->_mainAudio);
  this->_data.push_back(this->_head);

  this->_firstCell = 6;
  this->_data.push_back(new Cube(Position(45, 10, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(50, 10, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(40, 10, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(35, 15, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(40, 15, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(45, 15, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(50, 15, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(55, 15, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(45, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(50, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(40, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(35, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(55, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(30, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(60, 20, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));


  this->_data.push_back(new Cube(Position(45, 80, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(50, 80, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(40, 80, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(35, 75, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(40, 75, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(45, 75, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(50, 75, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(55, 75, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(45, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(50, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(40, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(35, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(55, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(30, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(60, 70, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));


  this->_data.push_back(new Cube(Position(10, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(10, 40, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(10, 50, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(15, 35, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(15, 40, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(15, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(15, 50, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(15, 55, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(20, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(20, 50, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(20, 40, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(20, 35, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(20, 55, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(20, 60, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(20, 30, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));


  this->_data.push_back(new Cube(Position(80, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(80, 40, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(80, 50, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(75, 35, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(75, 40, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(75, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(75, 50, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(75, 55, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_data.push_back(new Cube(Position(70, 45, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(70, 50, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(70, 40, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(70, 35, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(70, 55, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(70, 60, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(70, 30, 50), Position(5, 5, 5), Texture("./assets/solarfox/mail.png", Color(255, 255, 255, 255)), 2));

  this->_endCell = (this->_data.size() - 1);
}

std::string const &Solarfox::getGameName() const {
  return (this->_gameName);
}

int Solarfox::getFrameRatePerSecond() const {
  return (this->_frameRate);
}

std::vector <AData *> const &Solarfox::getData() const {
  return (this->_data);
}

std::vector <std::string> const & Solarfox::getSprite() const {
  return (this->_sprite);
}

std::vector <std::string> const & Solarfox::getMusic() const {
  return (this->_music);
}

std::vector <std::string> const & Solarfox::getModel3D() const {
  return (this->_model);
}

void Solarfox::setScoreManager(ScoreManager *scoreManager) {
  (void) scoreManager;
}

void Solarfox::updateNewScore() const {

}

void Solarfox::play() {
  for (size_t i = 0; i < this->_data.size(); i++) {
    if (this->_mainAudio == this->_data[i]) {
      this->_data.erase(this->_data.begin() + i);
    }
  }
  if (this->_win == false && this->_loose == false)
    {
      if (this->_isKarkade == false) {
	if (this->_it == 6) {
	  for (size_t i = 0; i < this->_data.size(); i++) {
	    if (this->_head == this->_data[i]) {
	      this->_firstCell = i + 1;
	    }
	  }
	  gameover();
	  if (this->_endCell - 6 == 0)
	    win();
	  for (int i = 0; i != 4; i++)
	    this->_ennemy[i]->move(i);
	  if (this->_ennemy[0]->getFrame() == 0)
	    {
	      this->trump_shot();
	      this->_ennemy[0]->setFrame((rand() % 30 + 1));
	      for (unsigned int a = 0; a < this->_ennemy.size(); a++)
		if (this->_ennemy[a]->getFreeze() == true)
		  this->_ennemy[a]->setFreeze(false);
	    }
	  if (this->_miss.size() > 0)
	    this->Missile_move();
	  this->_ennemy[0]->setFrame(this->_ennemy[0]->getFrame() - 1);
	  erase_trump_missile();
	  hit_trump();
	  if (this->_it % 6 == 0)
	    erase_fireball();
	  if (this->_direction != UNKNOWN)
	    {
	      if (this->_direction == UP)
		moveUp();
	      else if (this->_direction == DOWN)
		moveDown();
	      else if (this->_direction == LEFT)
		moveLeft();
	      else if (this->_direction == RIGHT)
		moveRight();
	    }
	  this->_it = 0;
	}
	this->_it += 1;
      } else {
	for (size_t i = 0; i < this->_data.size(); i++) {
	  if (this->_head == this->_data[i]) {
	    this->_firstCell = i + 1;
	  }
	}
	gameover();
	if (this->_endCell - 6 == 0)
	  win();
	for (int i = 0; i != 4; i++)
	  this->_ennemy[i]->move(i);
	if (this->_ennemy[0]->getFrame() == 0)
	  {
	    this->trump_shot();
	    this->_ennemy[0]->setFrame((rand() % 30 + 1));
	    for (unsigned int a = 0; a < this->_ennemy.size(); a++)
	      if (this->_ennemy[a]->getFreeze() == true)
		this->_ennemy[a]->setFreeze(false);
	  }
	if (this->_miss.size() > 0)
	  this->Missile_move();
	this->_ennemy[0]->setFrame(this->_ennemy[0]->getFrame() - 1);
	erase_trump_missile();
	if (this->_direction != UNKNOWN)
	  {
	    if (this->_direction == UP)
	      moveUp();
	    else if (this->_direction == DOWN)
	      moveDown();
	    else if (this->_direction == LEFT)
	      moveLeft();
	    else if (this->_direction == RIGHT)
	      moveRight();
	  }
      }
    }
}

void Solarfox::win()
{
  std::cout << "You win !" << std::endl;
  this->_win = true;
  this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/solarfox/hillary_win.jpg", Color(255, 255, 255, 255)), 6));
}

void Solarfox::gameover()
{
  for (unsigned int i = 0; i < this->_miss.size(); i++)
    {
      if (this->_miss[i]->getId() == 1 || this->_miss[i]->getId() == 2 || this->_miss[i]->getId() == 3 || this->_miss[i]->getId() == 4)
	{
	  if (this->_miss[i]->getCube()->getPosition().getX() == this->_head->getPosition().getX() && this->_miss[i]->getCube()->getPosition().getY() == this->_head->getPosition().getY())
	    {
	      this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/solarfox/trump_win.png", Color(255, 255, 255, 255)), 6));
	      this->_loose = true;
	    }
	}
    }
}

int Solarfox::colisionMail()
{
  for (unsigned int i = 0; i < this->_miss.size(); i++)
    {
      if (this->_miss[i]->getId() == 0)
	{
	  for (unsigned int j = this->_firstCell; j < this->_endCell; j++)
	    {
	      if (this->_miss[i]->getCube()->getPosition().getX() == this->_data[j]->getPosition().getX() && this->_miss[i]->getCube()->getPosition().getY() == this->_data[j]->getPosition().getY())
		{
		  this->_data.erase(this->_data.begin() + j);
		  this->_endCell -= 1;
		  return 1;
		}
	    }
	}
    }
  return 0;
}

int Solarfox::hit_trump()
{
  for (unsigned int i = 0; i < this->_ennemy.size(); i++)
    {
      for (unsigned int a = 0; a < this->_miss.size(); a++)
	{
	  if (this->_miss[a]->getId() == 0)
	    {
	      if (this->_ennemy[i]->getCube()->getPosition().getX() == this->_miss[a]->getCube()->getPosition().getX() &&
		  this->_ennemy[i]->getCube()->getPosition().getY() == this->_miss[a]->getCube()->getPosition().getY())
		{
		  this->_ennemy[i]->setFreeze(true);
		  return (1);
		}
	    }
	}
    }
  return (0);
}

void Solarfox::Missile_move()
{
  for (unsigned int i = 0; i != this->_miss.size(); i++)
    {
      if (this->_miss[i]->getId() == 1)
	this->_miss[i]->Launch(3);
      if (this->_miss[i]->getId() == 2)
	this->_miss[i]->Launch(2);
      if (this->_miss[i]->getId() == 3)
	this->_miss[i]->Launch(0);
      if(this->_miss[i]->getId() == 4)
	this->_miss[i]->Launch(1);
    }
}

void Solarfox::trump_shot() {
  int i = rand() % 4;
  if (i == 0)
    this->_miss.push_back(new Missile(&this->_data, this->_ennemy[i]->getCube()->getPosition().getX(), this->_ennemy[i]->getCube()->getPosition().getY(), 4));
  else if (i == 1)
    this->_miss.push_back(new Missile(&this->_data, this->_ennemy[i]->getCube()->getPosition().getX(), this->_ennemy[i]->getCube()->getPosition().getY(), 3));
  else if (i == 2)
    this->_miss.push_back(new Missile(&this->_data, this->_ennemy[i]->getCube()->getPosition().getX(), this->_ennemy[i]->getCube()->getPosition().getY(), 2));
  else if (i == 3)
    this->_miss.push_back(new Missile(&this->_data, this->_ennemy[i]->getCube()->getPosition().getX(), this->_ennemy[i]->getCube()->getPosition().getY(), 1));
}

void Solarfox::erase_fireball()
{
  for (unsigned int i = 0; i < this->_miss.size(); i++)
    {
      if (this->_miss[i]->getId() == 0)
	{
	  for (unsigned a = 0; a < this->_data.size(); a++)
	    {
	      if (this->_data[a] == this->_miss[i]->getCube())
		this->_data.erase(this->_data.begin() + a);
	    }
	  this->_miss.erase(this->_miss.begin() + i);
	}
    }
}


int Solarfox::colisionMissile()
{
  for (unsigned int i = 0; i < this->_miss.size(); i++)
    {
      if (this->_miss[i]->getId() == 0)
	{
	  for (unsigned int j = 0; j < this->_miss.size(); j++)
	    {
	      if (this->_miss[j]->getId() == 1 || this->_miss[j]->getId() == 2 || this->_miss[j]->getId() == 3 || this->_miss[j]->getId() == 4)
		{
		  if (this->_miss[i]->getCube()->getPosition().getX() == this->_miss[j]->getCube()->getPosition().getX() && this->_miss[i]->getCube()->getPosition().getY() == this->_miss[j]->getCube()->getPosition().getY())
		    {
		      for (unsigned int k = this->_firstCell; k < this->_data.size(); k++)
			{
			  if (*((Cube *)this->_data[k]) == *(this->_miss[j]->getCube()))
			    {
			      this->_data.erase(this->_data.begin() + k);
			    }
			}
		      this->_miss.erase(this->_miss.begin() + j);
		      return(1);
		    }
		}
	    }
	}
    }
  return(0);
}

void Solarfox::erase_trump_missile()
{
  for(unsigned int i = 0; i < this->_miss.size(); i++)
    {
      if (this->_miss[i]->getId() == 1 || this->_miss[i]->getId() == 2 || this->_miss[i]->getId() == 3 || this->_miss[i]->getId() == 4)
	{
	  if (this->_miss[i]->getCube()->getPosition().getX() > 100 || this->_miss[i]->getCube()->getPosition().getY() > 100 || this->_miss[i]->getCube()->getPosition().getX() < 0 || this->_miss[i]->getCube()->getPosition().getY() < 0)
	    {
	      for (unsigned int a = 0; a < this->_data.size(); a++)
		{
		  if (this->_data[a] == this->_miss[i]->getCube())
		    this->_data.erase(this->_data.begin() + a);
		}
	      this->_miss.erase(this->_miss.begin() + i);
	    }
	}
    }
}

void Solarfox::moveUp()
{
  setDirection(UP);
  if (this->_head->getPosition().getY() >= 15)
    this->_head->setPositionY(this->_head->getPosition().getY() - this->_speed);
  else
    {
      this->_loose = true;
      this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/solarfox/trump_win.png", Color(255, 255, 255, 255)), 6));
    }
}

void Solarfox::moveDown()
{
  setDirection(DOWN);
  if (this->_head->getPosition().getY() <= 75)
    this->_head->setPositionY(this->_head->getPosition().getY() + this->_speed);
  else
    {
      this->_loose = true;
      this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/solarfox/trump_win.png", Color(255, 255, 255, 255)), 6));
    }
}

void Solarfox::moveLeft()
{
  setDirection(LEFT);
  if (this->_head->getPosition().getX() >= 15)
    this->_head->setPositionX(this->_head->getPosition().getX() - this->_speed);
  else
    {
      this->_loose = true;
      this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/solarfox/trump_win.png", Color(255, 255, 255, 255)), 6));
    }
}

void Solarfox::moveRight()
{
  setDirection(RIGHT);
  if (this->_head->getPosition().getX() <= 75)
    this->_head->setPositionX(this->_head->getPosition().getX() + this->_speed);
  else
    {
      this->_loose = true;
      this->_data.push_back(new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/solarfox/trump_win.png", Color(255, 255, 255, 255)), 6));
    }
}

void Solarfox::goUp() {
  if (this->_isKarkade == false) {
    if (this->getDirection() != DOWN)
      setDirection(UP);
  } else {
    setDirection(UP);
  }
}

void Solarfox::goDown() {
  if (this->_isKarkade == false) {
    if (this->getDirection() != UP)
      setDirection(DOWN);
  } else {
    setDirection(DOWN);
  }
}

Solarfox::direction Solarfox::getDirection()
{
  return (this->_direction);
}

void Solarfox::setDirection(Solarfox::direction const &dir)
{
  this->_direction = dir;
}

void Solarfox::goLeft() {
  if (this->_isKarkade == false) {
    if (this->getDirection() != RIGHT)
      setDirection(LEFT);
  } else {
    setDirection(LEFT);
  }
}

void Solarfox::goRight() {
  if (this->_isKarkade == false) {
    if (this->getDirection() != LEFT)
      setDirection(RIGHT);
  } else {
    setDirection(RIGHT);
  }
}

void Solarfox::goForward() {
  if (this->_press == false)
    {
      this->_speed = 10;
      this->_press = true;
    }
  else
    {
      this->_speed = 5;
      this->_press = false;
    }
}

void Solarfox::shoot() {
  if (this->_isKarkade == false) {
    this->_miss.push_back(new Missile(&this->_data, this->_head->getPosition().getX(), this->_head->getPosition().getY(), 0));
    unsigned int i = this->_miss.size();
    this->_miss[i - 1]->Launchfireball(this->getDirection());
    if (colisionMail() == 1)
      return;
    else if (colisionMissile() == 1)
      return;
    else if (hit_trump() == 1)
      return;
    else
      {
	this->_miss[i - 1]->Launchfireball(this->getDirection());
	if (colisionMail() == 1)
	  return;
	else if (colisionMissile() == 1)
	  return;
	else if (hit_trump() == 1)
	  return;
	else
	  {
	    this->_miss[i - 1]->Launchfireball(this->getDirection());
	    if (colisionMail() == 1)
	      return;
	    else if (colisionMissile() == 1)
	      return;
	    else if (hit_trump() == 1)
	      return;
	  }
      }
  } else {
    Cube *tmp = new Cube(Position(this->_head->getPosition().getX(), this->_head->getPosition().getY(), 50), Position(5, 5, 5), Texture("./assets/solarfox/fireball.png", Color(255, 255, 255, 255)), 2, 5);
    this->_data.push_back(tmp);
    if (this->_direction == 0)
      tmp->setPositionY(tmp->getPosition().getY() -  5);
    if (this->_direction == 1)
      tmp->setPositionY(tmp->getPosition().getY() +  5);
    if (this->_direction == 3)
      tmp->setPositionX(tmp->getPosition().getX() -  5);
    if (this->_direction == 2)
      tmp->setPositionX(tmp->getPosition().getX() +  5);
    else {
      tmp->setPositionX(tmp->getPosition().getY() +  5);
    }
  }
}

void Solarfox::setKarcadeModeTrue() {
  this->_isKarkade = true;
}

void Solarfox::whereIAm() {
  arcade::WhereAmI *wai;

  wai = reinterpret_cast<struct arcade::WhereAmI*>(new char[sizeof(struct arcade::WhereAmI)
							    + sizeof(arcade::Position)]);
  wai->position->x = this->_head->getPosition().getX() / 5;
  wai->position->y = this->_head->getPosition().getY() / 5;
  wai->lenght = 1;
  wai->type = arcade::CommandType::WHERE_AM_I;
  write(1, wai, sizeof(struct arcade::WhereAmI) + sizeof(struct arcade::Position));
}

void Solarfox::getMap() {
  arcade::GetMap *map;
  Cube *cube1;
  int y, x;

  y = 0;
  x = 0;
  (void) cube1;
  map = reinterpret_cast<struct arcade::GetMap*>(new char[sizeof(struct arcade::GetMap) + sizeof(arcade::TileType) * (20 * 20)]);
  map->type = arcade::CommandType::GET_MAP;
  map->width = 20;
  map->height = 20;
  while (y < 20) {
    while (x < 20) {
      for (size_t k = 0; k < this->_data.size(); k++) {
        if (this->_data[k]->getShape() == DataType::Cube) {
          cube1 = dynamic_cast<Cube *>(this->_data[k]);
          if (cube1->getPosition().getX() == x * 5 && cube1->getPosition().getY() == y * 5) {
            switch (cube1->getId()) {
	    case 0:
	      map->tile[x + y * 20] = arcade::TileType::EMPTY;
	      break;
	    case 5:
	      map->tile[x + (y * 20)] = arcade::TileType::MY_SHOOT;
	      break;
	    }
          }
        }
      }
      x++;
    }
    x = 0;
    y++;
  }
  write(1, map, sizeof(struct arcade::GetMap) + sizeof(arcade::TileType) * (20 * 20));
}

extern "C"
{
  IGame *Create()
  {
    return new Solarfox();
  }

  void secondswitch(Solarfox &solarfox, arcade::CommandType input)
  {
    switch ((uint16_t)input)
    {
    case 4:
solarfox.goLeft();
break;
    case 5:
solarfox.goRight();
break;
    case 6:
solarfox.goForward();
break;
    case 7:
solarfox.shoot();
break;
    case 9:
solarfox.play();
break;
    default:
break;
    }
  }

  void theswitch(Solarfox &solarfox, arcade::CommandType input)
  {
        switch ((uint16_t)input)
        {
        case 0:
    solarfox.whereIAm();
    break;
        case 1:
    solarfox.getMap();
    break;
        case 2:
    solarfox.goUp();
    break;
        case 3:
    solarfox.goDown();
    break;
    default:
        secondswitch(solarfox, input);
        break;
    }
  }

  void Play()
  {
    Solarfox solarfox;
    solarfox.setKarcadeModeTrue();
    solarfox.InitGame();
    arcade::CommandType input;
    while (read(0, &input, sizeof(arcade::CommandType)))
    {
      theswitch(solarfox, input);
    }
  }
}
