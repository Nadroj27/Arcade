//
// Snake.cpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/games/Snake/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 00:05:59 2017 Ethan Kerdelhue
// Last update Sun Apr  9 23:31:26 2017 Ethan Kerdelhue
//

#include "Snake.hpp"

Snake::Snake()
{
  this->_frameRate = 60;
  this->_gameName = "Snake";
  this->_feedNumber = 0;
  this->_score = 0;
  this->_direction = RIGHT;
  this->_it = 0;
  this->_loose = false;
}

Snake::~Snake()
{

}

Snake::Snake(const Snake &obj)
{
  this->_frameRate = obj._frameRate;
  this->_gameName = obj._gameName;
  this->_data = obj._data;
  this->_sprite = obj._sprite;
  //this->_scoreManager = obj._scoreManager;
}

Snake &Snake::operator=(const Snake &obj)
{
  this->_frameRate = obj._frameRate;
  this->_gameName = obj._gameName;
  this->_data = obj._data;
  this->_sprite = obj._sprite;
  // this->_scoreManager = obj._scoreManager;
  return (*this);
}

void Snake::InitGame() {
  AData *bg = new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture(Color(0, 0, 0, 255)), 0);
  this->_head = new Cube(Position(50, 50, 50), Position(5, 5, 5), Texture("./assets/snake/sprite-melanchon.png", Color(255, 255, 0, 0)), 2);
  Cube *bonus = new Cube(Position(20, 20, 20), Position(5, 5, 5), Texture("./assets/snake/sprite-micro.png", Color(255, 255, 255, 255)), 1);
  this->_gameover = new Cube(Position(0, 0, 0), Position(100, 100, 100), Texture("./assets/snake/sprite-gameover.png", Color(255, 255, 255, 255)), 3);
  Text *score = new Text("SCORE", 36, Position(42, 5, 50), 8);
  this->_pscore = new Text(std::to_string(this->_score), 36, Position(55, 5, 30), 8);
  score->setTexture(Texture(Color(255, 255, 255, 255)));
  _pscore->setTexture(Texture(Color(255, 255, 255, 255)));
  score->setAlign(Text::CENTER);
  _pscore->setAlign(Text::CENTER);
  this->_mainAudio = new Audio("./assets/hypocrites.ogg", 100, true);
  this->_bonus = bonus;
  this->_data.push_back(bonus);
  this->_data.push_back(bg);
  this->_data.push_back(score);
  this->_data.push_back(_pscore);
  this->_mainAudio->setPositionX(-500);
  this->_mainAudio->setPositionY(0);
  this->_mainAudio->setPositionZ(0);
  this->_data.push_back(this->_mainAudio);
  this->_data.push_back(this->_head);
  this->_data.push_back(new Cube(Position(this->_head->getPosition().getX() -5, this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(this->_head->getPosition().getX() -10, this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2));
  this->_data.push_back(new Cube(Position(this->_head->getPosition().getX() -15, this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2));

}

std::string const &Snake::getGameName() const {
  return (this->_gameName);
}

int Snake::getFrameRatePerSecond() const {
  return (this->_frameRate);
}

std::vector <AData *> const &Snake::getData() const {
  return (this->_data);
}

std::vector <std::string> const & Snake::getSprite() const {
  return (this->_sprite);
}

std::vector <std::string> const & Snake::getMusic() const {
  return (this->_music);
}

std::vector <std::string> const & Snake::getModel3D() const {
  return (this->_model);
}

void Snake::setScoreManager(ScoreManager *scoreManager) {
  (void) scoreManager;
}

void Snake::updateNewScore() const {

}


void Snake::play() {
  if (this->_loose == false)
    {
      if (this->_isKarkade == false) {
	for (size_t i = 0; i < this->_data.size(); i++) {
	  if (this->_mainAudio == this->_data[i]) {
	    this->_data.erase(this->_data.begin() + i);
	  }
	  if (this->_head == this->_data[i]) {
	    this->_firstCell = i + 1;
	  }
	}
	if (this->_it == 6) {
	  if (this->_direction == UP)
	    moveUp();
	  else if (this->_direction == DOWN)
	    moveDown();
	  else if (this->_direction == LEFT)
	    moveLeft();
	  else if (this->_direction == RIGHT)
	    moveRight();
	  gameover();
	  this->_it = 0;
	}
	this->_it += 1;

      } else {
	for (size_t i = 0; i < this->_data.size(); i++) {
	  if (this->_mainAudio == this->_data[i]) {
	    this->_data.erase(this->_data.begin() + i);
	  }
	  if (this->_head == this->_data[i]) {
	    this->_firstCell = i + 1;
	  }
	}
        if (this->_direction == UP)
          moveUp();
        else if (this->_direction == DOWN)
          moveDown();
        else if (this->_direction == LEFT)
          moveLeft();
        else if (this->_direction == RIGHT)
          moveRight();
        gameover();
      }
    }
}


void Snake::gameover()
{
  if (this->_head->getPosition().getX() >= 100 || this->_head->getPosition().getX() <= -1 || this->_head->getPosition().getY() <= -4 || this->_head->getPosition().getY() >= 100) {
    this->_loose = true;
    this->_data.push_back(this->_gameover);
  }
  for(unsigned int i = this->_firstCell; i != this->_data.size(); i++)
    {
      if (this->_head->getPosition().getX() == this->_data[i]->getPosition().getX() && this->_head->getPosition().getY() == this->_data[i]->getPosition().getY())
	{
	  this->_data.push_back(this->_gameover);
	  this->_loose = true;
	}
    }
  //touche 8 pour restart
}
// FONCTION CONTROLL SNAKE

void Snake::popMicro() // ENCAPSULER LA FONCTION RAND !!!!
{
  double new_posx;
  double new_posy;

  new_posx = (double)(rand() % 9 + 1) * 10;
  new_posy = (double)(rand() % 9 + 1) * 10;
  for (unsigned int i = this->_firstCell - 1; i < this->_data.size(); i++)
    {
      if (this->_data[i]->getPosition().getX() == new_posx && this->_data[i]->getPosition().getY() == new_posy)
	{
          new_posx = ((double)(rand() % 9 + 1)) * 10;
          new_posy = ((double)(rand() % 9 + 1)) * 10;
          i = this->_firstCell;
	}
    }
  this->_bonus->setPositionY(new_posy);
  this->_bonus->setPositionX(new_posx);
}

void Snake::moveUp()
{
  if (this->getDirection() != DOWN)
    {
      setDirection(UP);
      Position headPos = this->_head->getPosition();
      if (this->_bonus->getPosition().getX() == headPos.getX() && this->_bonus->getPosition().getY() == headPos.getY()) {
        if (this->_data.size() != this->_firstCell)
          this->_data.push_back(new Cube(Position(this->_head->getPosition().getX(), this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
        else
          this->_data.push_back(new Cube(Position(this->_data.back()->getPosition().getX(), this->_data.back()->getPosition().getY(), this->_data.back()->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
        this->_feedNumber += 1;
        this->_score = this->_score + 1;
        this->_pscore->setText(std::to_string(this->_score));
	popMicro();
      }
      for(int unsigned i = this->_data.size() - 1; i >= this->_firstCell; i--){
	if (i == this->_firstCell)
	  {
	    this->_data[i]->setPositionY(this->_head->getPosition().getY());
	    this->_data[i]->setPositionX(this->_head->getPosition().getX());
	  }
	else
	  {
	    this->_data[i]->setPositionY(this->_data[i - 1]->getPosition().getY());
	    this->_data[i]->setPositionX(this->_data[i - 1]->getPosition().getX());
	  }
      }
      this->_head->setPositionY(this->_head->getPosition().getY() - 5);
    }
}

void Snake::moveDown()
{
  if (this->getDirection() != UP)
    {
      setDirection(DOWN);
      Position headPos = this->_head->getPosition();
      if (this->_bonus->getPosition().getX() == headPos.getX() && this->_bonus->getPosition().getY() == headPos.getY()) {
	if (this->_data.size() != this->_firstCell)
	  this->_data.push_back(new Cube(Position(this->_head->getPosition().getX(), this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2 , 6));
	else
	  this->_data.push_back(new Cube(Position(this->_data.back()->getPosition().getX(), this->_data.back()->getPosition().getY(), this->_data.back()->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
	this->_feedNumber += 1;
	this->_score = this->_score + 1;
	this->_pscore->setText(std::to_string(this->_score));
	popMicro();
      }
      for(int unsigned i = this->_data.size() - 1; i >= this->_firstCell; i--){
	if (i == this->_firstCell)
	  {
	    this->_data[i]->setPositionY(this->_head->getPosition().getY());
	    this->_data[i]->setPositionX(this->_head->getPosition().getX());
	  }
	else
	  {
	    this->_data[i]->setPositionY(this->_data[i - 1]->getPosition().getY());
	    this->_data[i]->setPositionX(this->_data[i - 1]->getPosition().getX());
	  }
      }
      this->_head->setPositionY(this->_head->getPosition().getY() + 5);
    }
}

void Snake::moveLeft()
{
  if (this->getDirection() != RIGHT)
    {
      setDirection(LEFT);
      Position headPos = this->_head->getPosition();
      if (this->_bonus->getPosition().getX() == headPos.getX() && this->_bonus->getPosition().getY() == headPos.getY()) {
	if (this->_data.size() != this->_firstCell)
	  this->_data.push_back(new Cube(Position(this->_head->getPosition().getX(), this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
	else
	  this->_data.push_back(new Cube(Position(this->_data.back()->getPosition().getX(), this->_data.back()->getPosition().getY(), this->_data.back()->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
	this->_feedNumber += 1;
	this->_score = this->_score + 1;
	this->_pscore->setText(std::to_string(this->_score));
	popMicro();
      }
      for(int unsigned i = this->_data.size() - 1; i >= this->_firstCell; i--){
	if (i == this->_firstCell)
	  {
	    this->_data[i]->setPositionX(this->_head->getPosition().getX());
	    this->_data[i]->setPositionY(this->_head->getPosition().getY());
	  }
	else
	  {
	    this->_data[i]->setPositionY(this->_data[i - 1]->getPosition().getY());
	    this->_data[i]->setPositionX(this->_data[i - 1]->getPosition().getX());
	  }
      }
      this->_head->setPositionX(this->_head->getPosition().getX() - 5);
    }
}

void Snake::moveRight()
{
  if (this->getDirection() != LEFT)
    {
      setDirection(RIGHT);
      Position headPos = this->_head->getPosition();
      if (this->_bonus->getPosition().getX() == headPos.getX() && this->_bonus->getPosition().getY() == headPos.getY()) {
	if (this->_data.size() != this->_firstCell)
	  this->_data.push_back(new Cube(Position(this->_head->getPosition().getX(), this->_head->getPosition().getY(), this->_head->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
	else
	  this->_data.push_back(new Cube(Position(this->_data.back()->getPosition().getX(), this->_data.back()->getPosition().getY(), this->_data.back()->getPosition().getZ()), Position(5,5,5), Texture("./assets/snake/sprite-marinelepen.png", Color(255, 255, 255, 255)), 2, 6));
	this->_feedNumber += 1;
	this->_score = this->_score + 1;
	this->_pscore->setText(std::to_string(this->_score));
	popMicro();
      }
      for(int unsigned i = this->_data.size() - 1; i >= this->_firstCell;i--){
	if (i == this->_firstCell)
	  {
	    this->_data[i]->setPositionX(this->_head->getPosition().getX());
	    this->_data[i]->setPositionY(this->_head->getPosition().getY());
	  }
	else
	  {
	    this->_data[i]->setPositionX(this->_data[i-1]->getPosition().getX());
	    this->_data[i]->setPositionY(this->_data[i-1]->getPosition().getY());
	  }
      }
      this->_head->setPositionX(this->_head->getPosition().getX() + 5);
    }
}

void Snake::goUp() {
  if (this->getDirection() != DOWN && this->getDirection() != UP)
    setDirection(UP);
}

void Snake::goDown() {
  if (this->getDirection() != DOWN && this->getDirection() != UP)
    setDirection(DOWN);
}

Snake::direction Snake::getDirection()
{
  return (this->_direction);
}

void Snake::setDirection(Snake::direction const &dir)
{
  this->_direction = dir;
}

void Snake::goLeft() {
  if (this->getDirection() != LEFT && this->getDirection() != RIGHT)
    setDirection(LEFT);
}

void Snake::goRight() {
  if (this->getDirection() != LEFT && this->getDirection() != RIGHT)
    setDirection(RIGHT);
}

void Snake::goForward() {
  std::cout << "Go forward" << std::endl;
}

void Snake::shoot() {

}

void Snake::setKarcadeModeTrue() {
  this->_isKarkade = true;
}

void Snake::whereIAm() {
  arcade::WhereAmI *wai;

  wai = reinterpret_cast<struct arcade::WhereAmI*>(new char[sizeof(struct arcade::WhereAmI)
							    + sizeof(arcade::Position)]);
  wai->position->x = this->_head->getPosition().getX() / 5;
  wai->position->y = this->_head->getPosition().getY() / 5;
  wai->lenght = 1;
  wai->type = arcade::CommandType::WHERE_AM_I;
  write(1, wai, sizeof(struct arcade::WhereAmI) + sizeof(struct arcade::Position));
}

void Snake::getMap() {
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
	    case 6:
	      map->tile[x + (y * 20)] = arcade::TileType::POWERUP;
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
    return new Snake();
  }

  void secondswitch(Snake &snake, arcade::CommandType input)
  {
    switch ((uint16_t) input)
    {
      case 4:
         snake.goLeft();
         break;
      case 5:
         snake.goRight();
         break;
      case 6:
         snake.goForward();
         break;
      case 7:
         snake.shoot();
         break;
      case 9:
       snake.play();
         break;
      default:
        break;
    }
  }

  void theswitch(Snake &snake, arcade::CommandType input)
  {
    switch ((uint16_t)input)
    {
    case 0:
      snake.whereIAm();
       break;
    case 1:
       snake.getMap();
       break;
    case 2:
       snake.goUp();
       break;
    case 3:
       snake.goDown();
       break;
    default:
      secondswitch(snake, input);
      break;
    }
  }

  void Play()
  {
    Snake snake;
    snake.setKarcadeModeTrue();
    snake.InitGame();
    arcade::CommandType input;

    while (read(0, &input, sizeof(arcade::CommandType)))
    {
      theswitch(snake, input);
    }
  }
}
