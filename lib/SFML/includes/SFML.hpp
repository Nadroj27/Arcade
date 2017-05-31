//
// SFML.hpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/lib/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 01:10:53 2017 Ethan Kerdelhue
// Last update Sun Apr  9 21:53:36 2017 Ethan Kerdelhue
//

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>

#include "IGraph.hpp"
#include "IArcadeBridge.hpp"

#include "Cube.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Text.hpp"
#include "Audio.hpp"

class SFML : public IGraph {
private:
  std::string _libName;
  IArcadeBridge* _bridge;
  int _height;
  int _width;
  sf::RenderWindow *window;
  std::map<std::string, sf::Texture *> _spriteMap;
  std::vector<sf::Music *> _musics;

public:
  SFML ();
  virtual ~SFML ();
  SFML(const SFML &obj);
  SFML  &operator=(const SFML &obj);

  virtual void InitLib();
  virtual std::string const & getLibName() const;
  virtual void giveData(std::vector <AData *> const &data);
  virtual void giveSprite(std::vector <std::string> const &spriteList);
  virtual void giveMusic(std::vector <std::string> const &musicList);
  virtual void giveModel3D(std::vector <std::string> const &modelList);

  virtual void setBridge(IArcadeBridge * bridge);

  virtual void handleData(AData const & data);
  virtual void handleSphere(AData const & data);
  virtual void handleCube(AData const & data);
  virtual void handleCamera(AData const & data);
  virtual void handleLight(AData const & data);
  virtual void handleMusic(AData const & data);
  virtual void handleText(AData const & data);

private:
  virtual void toggleRunning() const;
  virtual void prevGraph() const;
  virtual void nextGraph() const;
  virtual void prevGame() const;
  virtual void nextGame() const;
  virtual void goUp() const;
  virtual void goDown() const;
  virtual void goLeft() const;
  virtual void goRight() const;
  virtual void goForward() const;
  virtual void shoot() const;
  virtual void pressEchap() const;
  virtual void pressNine() const;
  virtual void pressEight() const;

  virtual int handleEvent() const;
  virtual int handleKeyPressed(const sf::Event & event) const;
};


#endif /* !SFML_HPP */
