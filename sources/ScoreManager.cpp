//
// ScoreManager.cpp for  in /Users/ethankerdelhue/Documents/shared/gambin/cpp_arcade/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat Apr  8 20:44:26 2017 Ethan Kerdelhue
// Last update Sun Apr  9 21:06:56 2017 Ethan Kerdelhue
//

#include "ScoreManager.hpp"


ScoreManager::ScoreManager (std::string const & gameName, std::string name) {
  this->_name = name;
  (void) gameName;
}

ScoreManager::~ScoreManager () {

}

void ScoreManager::pushNewScore(int score) {
  (void) score;
}

int ScoreManager::getBestScore() const {
  return (1);
}

std::string ScoreManager::getBestName() const {
  return (this->_name);
}

std::string const &ScoreManager::getName() const {
  return (this->_name);
}

void ScoreManager::setName(std::string const &name) {
  (void) name;
}

std::vector<Score> const &ScoreManager::getScoreBoard() const {
  return (this->_scoreBoard);
}
