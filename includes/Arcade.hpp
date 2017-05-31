//
// Arcade.hpp for  in /Users/ethankerdelhue/Documents/shared/gambin/cpp_arcade/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat Apr  8 18:42:12 2017 Ethan Kerdelhue
// Last update Sat Apr  8 22:06:43 2017 Ethan Kerdelhue
//

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <vector>
#include <thread>
#include <algorithm>
#include <exception>

#include "IArcadeBridge.hpp"
#include "ScoreManager.hpp"
#include "IGraph.hpp"
#include "ExternLib.hpp"
#include "Exception.hpp"
#include "MenuController.hpp"
#include "LoadController.hpp"

typedef IGame *(*game_ptr)();
typedef IGraph *(*lib_ptr)();

class Arcade: public IArcadeBridge {

public: enum ArcadeState {
  INGAME,
  MENU
};

public:

  Arcade ();
   ~Arcade ();
   Arcade &operator=(const Arcade &obj);

   void Setup(std::string const &startingLib);
   void Start();
   void mainLoop();

   void toggleRunning();

   void prevGraph();
   void nextGraph();

   void prevGame();
   void nextGame();

   void goUp() const;
   void goDown() const;
   void goLeft() const;
   void goRight() const;
   void goForward() const;
   void shoot() const;
   void pressEchap();
   void pressEight();
   void pressNine();

   void setInGameMode();
   void setMenuMode();

   void initCurrentGame();
   void setCurrentGameIndex(int gameIndex);
   void setCurrentGame(game_ptr const &);
   std::vector <game_ptr> getLibGames();

   std::vector<game_ptr> getlibGame() const;
   std::vector<std::string> getNameGame() const;

private:
   Arcade(const Arcade &obj);

   void FillGameVector();
   void FillGraphVector(std::string const &startingLib);

   bool _isRunning;
   int _frameRate;

   IGraph* _currentGraph;
   IGame* _currentGame;
   std::vector<lib_ptr> _libGraph;
   std::vector<game_ptr> _libGame;
   std::vector<std::string> _nameGame;
   std::vector<ScoreManager> _scoreVector;

   MenuController *_menu;

   int _graphIndex;
   int _gameIndex;

   void transfertData() const;

};

#else

class Arcade;

#endif /*ARCADE_HPP_*/
