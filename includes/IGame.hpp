//
// IGame.hpp for  in /Users/ethankerdelhue/Documents/shared/gambin/tmp2/cpp_arcade/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sun Apr  9 19:11:58 2017 Ethan Kerdelhue
// Last update Sun Apr  9 19:12:00 2017 Ethan Kerdelhue
//

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
#include <iostream>

#include "ScoreManager.hpp"
#include "AVisual.hpp"

class IGame {

public:
    virtual ~IGame() {};
    virtual void InitGame() = 0;
    virtual std::string const &getGameName() const = 0;
    virtual int getFrameRatePerSecond() const = 0;
    virtual std::vector <AData *> const &getData() const = 0;

    virtual std::vector <std::string> const & getSprite() const = 0;
    virtual std::vector <std::string> const & getMusic() const = 0;
    virtual std::vector <std::string> const & getModel3D() const = 0;

    virtual void setScoreManager(ScoreManager *scoreManager) = 0;
    virtual void updateNewScore() const = 0;

    virtual void play() = 0;
    virtual void getMap() = 0;
    virtual void whereIAm() = 0;

    virtual void goUp() = 0;
    virtual void goDown() = 0;
    virtual void goLeft() = 0;
    virtual void goRight() = 0;
    virtual void goForward() = 0;
    virtual void shoot() = 0;

protected:

};

#else

class IGame;

#endif /* !IGAME_HPP_ */
