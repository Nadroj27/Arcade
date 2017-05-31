/*
** ScoreManager.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:07:40 2017 Vacca_J
** Last update Sun Apr 09 01:07:41 2017 Vacca_J
*/


#ifndef SCOREMANAGER_HPP_
#define SCOREMANAGER_HPP_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

struct Score {
        std::string name;
        int score;
};

class ScoreManager {

public:
    explicit ScoreManager (std::string const & gameName, std::string name);
    ~ScoreManager ();

    void pushNewScore(int score);
    int getBestScore() const;
    std::string getBestName() const;
    std::string const &getName() const;
    void setName(std::string const &name);
    std::vector<Score> const &getScoreBoard() const;

private:
    ScoreManager(const ScoreManager &obj);
    ScoreManager    &operator=(const ScoreManager &obj);
    void loadScores();
    bool getLineInfo(std::string line, Score &score);

    std::vector<Score> _scoreBoard;
    std::string _name;
    std::fstream _file;
};

#endif /* !SCOREMANAGER_HPP_ */
