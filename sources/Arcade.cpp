//
// Arcade.cpp for  in /Users/ethankerdelhue/Documents/shared/gambin/cpp_arcade/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed Apr  5 23:59:16 2017 Ethan Kerdelhue
// Last update Sun Apr  9 23:07:00 2017 Romain Fagnola
//

#include "Arcade.hpp"

Arcade::Arcade ()
{
  _isRunning = ArcadeState::MENU;
  _currentGame = 0;
  _currentGraph = 0;
  _gameIndex = 0;
  _graphIndex = 0;
  _frameRate = 30;
}

Arcade::~Arcade()
{

}

void	Arcade::Setup(std::string const &startingLib)
{
  FillGraphVector(startingLib);
  FillGameVector();
}

void	Arcade::Start()
{
  this->_currentGraph = this->_libGraph[0]();
  this->_menu = new MenuController(this);
  this->_menu->InitGame();
  this->_currentGraph->InitLib();
  this->_currentGraph->setBridge(this);
}

std::vector<game_ptr> Arcade::getlibGame() const
{
  return (this->_libGame);
}

void	Arcade::FillGraphVector(std::string const &startingLib)
{
  lib_ptr lptr;
  void *handle;
  void *ptr;
  std::vector<std::string> files;

  files = LoadController::readDirectory("./lib/", startingLib);
  if (files.size() == 0)
    throw Exception("No graphic lib", "Arcade:FillGraphVector");
  for(std::vector<std::string>::iterator it=files.begin() ; it < files.end(); it++ ) {
    handle = (ExternLib((*it).c_str(), RTLD_LAZY)).getLib();
    if (handle == NULL) {
      std::cout << dlerror() << std::endl;
      continue;
    }
    try {
      ptr = dlsym(handle, "Create");
      lptr = (lib_ptr) ptr;
      _libGraph.push_back(lptr);
    } catch (std::exception const & e) {
      std::cerr << "Function Create not found, " << e.what() << std::endl;
    };
  }
}

void	Arcade::FillGameVector()
{
  void *handle;
  void *ptr;
  game_ptr gptr;
  std::vector<std::string> files;

  files = LoadController::readDirectory("./games/", "");
  for (unsigned int i = 0; i < files.size(); i ++)
    this->_nameGame.push_back(files[i]);
  for(std::vector<std::string>::iterator it=files.begin() ; it < files.end(); it++ ) {
    handle = (ExternLib((*it).c_str(), RTLD_LAZY)).getLib();
    if (handle == NULL)
      continue;
    ptr = dlsym(handle, "Create");
    gptr = (game_ptr)ptr;
    _libGame.push_back(gptr);
  }
}

std::vector<std::string> Arcade::getNameGame() const
{
  return (this->_nameGame);
}

void	Arcade::mainLoop()
{
  bool loop = true;
  std::chrono::time_point<std::chrono::system_clock> start, end;

  while (loop) {
    if (this->_isRunning == ArcadeState::INGAME) {
      start = std::chrono::system_clock::now();
      this->transfertData();
      this->_currentGame->play();
      end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed = end - start;
      int x = (1000 / this->_frameRate) - (elapsed.count() / 1000);
      std::this_thread::sleep_for(std::chrono::milliseconds(x));
    } else if (this->_isRunning == ArcadeState::MENU) {
      start = std::chrono::system_clock::now();
      this->transfertData();
      this->_menu->play();
      end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed = end - start;
      int x = (1000 / this->_frameRate) - (elapsed.count() / 1000);
      std::this_thread::sleep_for(std::chrono::milliseconds(x));
    }
  }
}

void	Arcade::toggleRunning()
{

}

void	Arcade::prevGraph()
{
  if (this->_currentGraph)
    delete(this->_currentGraph);
  this->_graphIndex = this->_graphIndex > 0 ? this->_graphIndex - 1 : this->_libGraph.size() - 1;
  this->_currentGraph = this->_libGraph[this->_graphIndex]();
  this->_currentGraph->InitLib();
  this->_currentGraph->setBridge(this);
}

void	Arcade::nextGraph()
{
  if (this->_currentGraph)
    delete(this->_currentGraph);
  this->_graphIndex = this->_graphIndex < (int) (this->_libGraph.size() - 1) ? this->_graphIndex + 1 : 0;
  this->_currentGraph = this->_libGraph[this->_graphIndex]();
  this->_currentGraph->InitLib();
  this->_currentGraph->setBridge(this);
}

void	Arcade::prevGame()
{
  this->_gameIndex = this->_gameIndex > 0 ? this->_gameIndex - 1 : this->_libGame.size() - 1;
  this->_currentGame = this->_libGame[this->_gameIndex]();
  std::cout << this->_gameIndex << std::endl;
  this->_currentGame->InitGame();
}

void	Arcade::nextGame()
{
  this->_gameIndex = this->_gameIndex < (int) (this->_libGame.size() - 1) ? this->_gameIndex + 1 : 0;
  this->_currentGame = this->_libGame[this->_gameIndex]();
  std::cout << this->_gameIndex << std::endl;
  this->_currentGame->InitGame();
}

void	Arcade::goUp() const
{
  if (this->_isRunning == ArcadeState::MENU) {
    this->_menu->goUp();
  } else {
    this->_currentGame->goUp();
  }
}

void	Arcade::goDown() const
{
  if (this->_isRunning == ArcadeState::MENU) {
    this->_menu->goDown();
  } else {
    this->_currentGame->goDown();
  }
}

void	Arcade::goLeft() const
{
  if (this->_isRunning == ArcadeState::MENU) {
    this->_menu->goLeft();
  } else {
    this->_currentGame->goLeft();
  }
}

void	Arcade::goRight() const
{
  if (this->_isRunning == ArcadeState::MENU) {
    this->_menu->goRight();
  } else {
    this->_currentGame->goRight();
  }
}

void	Arcade::goForward() const
{
  if (this->_isRunning == ArcadeState::MENU) {
    this->_menu->goForward();
  } else {
    this->_currentGame->goForward();
  }
}

void	Arcade::shoot() const
{
  if (this->_isRunning == ArcadeState::MENU) {
    this->_menu->shoot();
  } else {
    this->_currentGame->shoot();
  }
}

void	Arcade::pressEchap()
{
  if (this->_isRunning == ArcadeState::INGAME) {
    this->_isRunning = ArcadeState::MENU;
  }
}

void Arcade::pressEight() {
  if (this->_isRunning == ArcadeState::INGAME) {
    delete(this->_currentGame);
    this->_currentGame = this->_libGame[this->_gameIndex]();
    this->_currentGame->InitGame();
  }
}

void Arcade::pressNine() {
  if (this->_isRunning == ArcadeState::INGAME) {
    this->_isRunning = ArcadeState::MENU;
  }
}

void	Arcade::transfertData() const
{
  if (this->_isRunning == ArcadeState::INGAME) {
    std::vector <AData *> values = this->_currentGame->getData();
    std::sort(values.begin(), values.end(), [](AData *a, AData *b ) {
        AVisual *tmp1 = dynamic_cast<AVisual *>(a);
	AVisual *tmp2 = dynamic_cast<AVisual *>(b);
	if (tmp1 == NULL || tmp2 == NULL) {
	  return false;
	}
	return tmp1->getZIndex() < tmp2->getZIndex();
      });
    this->_currentGraph->giveData(values);
  } else if (this->_isRunning == ArcadeState::MENU) {
    std::vector <AData *> values = this->_menu->getData();
    std::sort(values.begin(), values.end(), [](AData *a, AData *b ) {
        AVisual *tmp1 = dynamic_cast<AVisual *>(a);
	AVisual *tmp2 = dynamic_cast<AVisual *>(b);
	if (tmp1 == NULL || tmp2 == NULL) {
	  return false;
	}
	return tmp1->getZIndex() < tmp2->getZIndex();
      });
    this->_currentGraph->giveData(values);
  }
}

Arcade::Arcade(const Arcade &obj)
{
  _isRunning = obj._isRunning;
}

Arcade	&Arcade::operator=(const Arcade &obj)
{
  this->_isRunning = obj._isRunning;
  this->_frameRate = obj._frameRate;
  this->_currentGraph = obj._currentGraph;
  this->_currentGame = obj._currentGame;
  this->_libGraph = obj._libGraph;
  this->_libGame = obj._libGame;
  return (*this);
}

void Arcade::setCurrentGame(game_ptr const &game) {
  this->_currentGame = game();
}

std::vector <game_ptr> Arcade::getLibGames() {
  return (this->_libGame);
}

void Arcade::setInGameMode() {
  this->_isRunning = ArcadeState::INGAME;
}

void Arcade::setMenuMode() {
  this->_isRunning = ArcadeState::MENU;
}

void Arcade::initCurrentGame() {
  this->_currentGame->InitGame();
  this->_frameRate = this->_currentGame->getFrameRatePerSecond();
}

void Arcade::setCurrentGameIndex(int gameIndex) {
  this->_gameIndex = gameIndex;
  if (this->_currentGame)
    delete this->_currentGame;
}
