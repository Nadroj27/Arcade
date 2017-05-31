//
// NCURSE.cpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/lib/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 01:16:17 2017 Ethan Kerdelhue
// Last update Sun Apr  9 22:29:34 2017 Ethan Kerdelhue
//

#include "NCURSE.hpp"

NCURSE::NCURSE()
{
  this->_libName = "NCURSE";
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  this->_height = ((w.ws_row * 0.75) / 2) - 2;
  this->_width = w.ws_row - 2;
}

NCURSE::~NCURSE()
{
  endwin();
}

NCURSE::NCURSE(const NCURSE &obj)
{
  this->_libName = obj._libName;
  this->_bridge = obj._bridge;
}

NCURSE &NCURSE::operator=(const NCURSE &obj)
{
  this->_libName = obj._libName;
  this->_bridge = obj._bridge;
  return (*this);
}

void NCURSE::InitLib() {
  WINDOW *w = initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_BLUE, COLOR_BLUE);
  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_CYAN, COLOR_CYAN);
  init_pair(5, COLOR_GREEN, COLOR_GREEN);
  init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(8, COLOR_BLACK, COLOR_BLACK);
  init_pair(9, COLOR_WHITE, COLOR_BLACK);
  init_pair(10, COLOR_BLACK, COLOR_WHITE);
  setColor(Color(255, 255, 255, 255));
  cbreak();
  timeout(-1);
  keypad(stdscr, TRUE);
  curs_set(0);
  nodelay(w, TRUE);
}

std::string const & NCURSE::getLibName() const{
  return (this->_libName);
}

void NCURSE::giveData(std::vector <AData *> const &data) {
  setColor(Color(255, 255, 255, 255));
  int i;
  int j;

  i = 0;
  j = 0;
  attron(COLOR_PAIR(1));
  while (i < this->_width + 2)
    {
      j = 0;
      while (j < this->_height + 2)
	{
	  if (j == 0 || i == 0 || i == this->_width + 1 || j == this->_height + 1)
	    mvprintw(j, i, " ");
	  j++;
	}
      i++;
    }
  attron(COLOR_PAIR(9));
  for (size_t i = 0; i < data.size(); i++) {
    handleData(*(data[i]));
  }
  handleEvent();
}

void NCURSE::giveSprite(std::vector <std::string> const &spriteList) {
  (void) spriteList;
}

void NCURSE::giveMusic(std::vector <std::string> const &musicList) {
  (void) musicList;
}

void NCURSE::giveModel3D(std::vector <std::string> const &modelList) {
  (void) modelList;
}

void NCURSE::setBridge(IArcadeBridge * bridge) {
  this->_bridge = bridge;
}

void NCURSE::handleEvent() const {
  char c = getch();
  (void) c;
  switch (c) {
  case 'p':
    this->toggleRunning();
    break;
  case 27:
    this->pressEchap();
    break;
  case ' ':
    this->shoot();
    break;
  case 10:
    this->goForward();
    break;
  case 4:
    this->goLeft();
    break;
  case 5:
    this->goRight();
    break;
  case 3:
    this->goUp();
    break;
  case 2:
    this->goDown();
    break;
  case 50:
    this->prevGraph();
    return;
  case 51:
    this->nextGraph();
    return;
  case 52:
    this->prevGame();
    return;
  case 53:
    this->nextGame();
  case 57:
    this->pressNine();
  case 56:
    this->pressEight();
    return;
  default:
    break;
  }
}

void NCURSE::setColor(Color const &col)
{
  unsigned char r = col.getR();
  unsigned char g = col.getG();
  unsigned char b = col.getB();

  if (r >= g + 30 && r >= b + 30)
    attron(COLOR_PAIR(3));
  else if (g >= r + 30 && g >= b + 30)
    attron(COLOR_PAIR(5));
  else if (b >= r + 30 && b >= g + 30)
    attron(COLOR_PAIR(2));
  else if (r >= g + 30)
    attron(COLOR_PAIR(7));
  else if (r >= b + 30)
    attron(COLOR_PAIR(6));
  else if (g >= r + 30)
    attron(COLOR_PAIR(7));
  else if (r > 50 && g > 50 && b > 50)
    attron(COLOR_PAIR(1));
  else
    attron(COLOR_PAIR(8));
}

void NCURSE::handleData(AData const & data) {
  refresh();
  switch (data.getShape()) {
  case DataType::Cube :
    handleCube(data);
    break;
  case DataType::Sphere :
    handleSphere(data);
    break;
  case DataType::Text :
    handleText(data);
    break;
  case DataType::Music :
    handleMusic(data);
    break;
  default:
    std::cout << "No DataType recognized" << std::endl;
  }
}

void NCURSE::handleSphere(AData const & data) {
  (void) data;
}

void NCURSE::handleCube(AData const & data) {
  Cube const & cube = dynamic_cast<Cube const &>(data);
  int i;
  int x = (cube.getPosition().getX() / 100.0) * this->_width + 1;
  int y = (cube.getPosition().getY() / 100.0) * this->_height + 1;
  float toXfloat = (cube.getSize().getX() / 100.0) * this->_width;
  float toYfloat = (cube.getSize().getY() / 100.0) * this->_height;
  int toX = x + (toXfloat > (int)toXfloat ? toXfloat + 1 : toXfloat);
  int toY = y + (toYfloat > (int)toYfloat ? toYfloat + 1 : toYfloat);
  this->setColor(cube.getTexture().getColor());
  while (x < toX)
    {
      i = y;
      while (i < toY)
        {
	  mvprintw(i, x, " ");
	  i++;
        }
      x++;
    }
  (void) data;
}

void NCURSE::handleCamera(AData const & data) {
  (void) data;
}

void NCURSE::handleLight(AData const & data) {
  (void) data;
}

void NCURSE::handleMusic(AData const & data) {
  (void) data;
}

void NCURSE::handleText(AData const & data) {
  Text const & text = dynamic_cast<Text const &>(data);
  int x = (text.getPosition().getX() / 100.0) * this->_width + 1;
  int y = (text.getPosition().getY() / 100.0) * this->_height + 1;
  attroff(COLOR_PAIR(8));
  mvprintw(y, x, text.getText().c_str());
}

void NCURSE::toggleRunning() const {
  this->_bridge->toggleRunning();
}

void NCURSE::prevGraph() const {
  this->_bridge->prevGraph();
}

void NCURSE::nextGraph() const {
  this->_bridge->nextGraph();
}

void NCURSE::prevGame() const {
  this->_bridge->prevGame();
}

void NCURSE::nextGame() const {
  this->_bridge->nextGame();
}

void NCURSE::goUp() const {
  this->_bridge->goUp();
}

void NCURSE::goDown() const {
  this->_bridge->goDown();
}

void NCURSE::goLeft() const {
  this->_bridge->goLeft();
}

void NCURSE::goRight() const {
  this->_bridge->goRight();
}

void NCURSE::goForward() const {
  this->_bridge->goForward();
}

void NCURSE::shoot() const {
  this->_bridge->shoot();
}

void NCURSE::pressEchap() const {
  this->_bridge->pressEchap();
}

void NCURSE::pressEight() const {
  this->_bridge->pressEight();
}

void NCURSE::pressNine() const {
  this->_bridge->pressNine();
}

extern "C"
{
  IGraph *Create()
  {
    return new NCURSE();
  }
}
