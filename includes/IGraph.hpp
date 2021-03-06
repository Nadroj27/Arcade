//
// IGraph.hpp for  in /Users/ethankerdelhue/Documents/shared/gambin/tmp2/cpp_arcade/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sun Apr  9 21:48:36 2017 Ethan Kerdelhue
// Last update Sun Apr  9 21:48:38 2017 Ethan Kerdelhue
//

#ifndef IGRAPH_HPP_
#define IGRAPH_HPP_

#include <vector>

#include "IGame.hpp"
#include "IArcadeBridge.hpp"

class IGraph {

public:
    virtual ~IGraph() {};
    virtual void InitLib() = 0;
    virtual std::string const & getLibName() const = 0;
    virtual void giveData(std::vector <AData *> const &data) = 0;
    virtual void giveSprite(std::vector <std::string> const &spriteList) = 0;
    virtual void giveMusic(std::vector <std::string> const &musicList) = 0;
    virtual void giveModel3D(std::vector <std::string> const &modelList) = 0;

    virtual void setBridge(IArcadeBridge * bridge) = 0;

    virtual void handleData(AData const & data) = 0;
    virtual void handleSphere(AData const & data) = 0;
    virtual void handleCube(AData const & data) = 0;
    virtual void handleCamera(AData const & data) = 0;
    virtual void handleLight(AData const & data) = 0;
    virtual void handleMusic(AData const & data) = 0;
    virtual void handleText(AData const & data) = 0;

private:
    virtual void toggleRunning() const = 0;
    virtual void prevGraph() const = 0;
    virtual void nextGraph() const = 0;
    virtual void prevGame() const = 0;
    virtual void nextGame() const = 0;
    virtual void goUp() const = 0;
    virtual void goDown() const = 0;
    virtual void goLeft() const = 0;
    virtual void goRight() const = 0;
    virtual void goForward() const = 0;
    virtual void shoot() const = 0;
    virtual void pressEchap() const = 0;
    virtual void pressEight() const = 0;
    virtual void pressNine() const = 0;
};

#else

class IGraph;

#endif /* !IGRAPH_HPP_ */
