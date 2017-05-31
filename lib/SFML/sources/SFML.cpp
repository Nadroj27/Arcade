//
// SFML.cpp for  in /Users/ethankerdelhue/Documents/shared/arcade_pas_a_nous/ARCADE_GLS/lib/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 21 01:16:17 2017 Ethan Kerdelhue
// Last update Sun Apr  9 21:54:11 2017 Ethan Kerdelhue
//

#include "SFML.hpp"

SFML::SFML()
{
  this->_libName = "lib_arcade_sfml";
  this->_width = 800;
  this->_height = 600;
}

SFML::~SFML()
{
  delete (this->window);
  for (size_t i = 0; i < this->_musics.size(); i++) {
    delete(this->_musics[i]);
  }
}

SFML::SFML(const SFML &obj)
{
  this->_libName = obj._libName;
  this->_bridge = obj._bridge;
}

SFML &SFML::operator=(const SFML &obj)
{
  this->_libName = obj._libName;
  this->_bridge = obj._bridge;
  return (*this);
}

void SFML::InitLib() {
  this->window = new sf::RenderWindow(sf::VideoMode(this->_width, this->_height), "Arcade");
}

std::string const & SFML::getLibName() const {
  return (this->_libName);
}

void SFML::giveData(std::vector <AData *> const &data) {
  if (handleEvent())
    return;
  (void) data;
  this->window->clear();
  for (size_t i = 0; i < data.size(); i++) {
    SFML::handleData(*(data[i]));
  }
  this->window->display();
}

void SFML::giveSprite(std::vector <std::string> const &spriteList) {
  (void) spriteList;
}

void SFML::giveMusic(std::vector <std::string> const &musicList) {
  (void) musicList;
}

void SFML::giveModel3D(std::vector <std::string> const &modelList) {
  (void) modelList;
}

void SFML::setBridge(IArcadeBridge * bridge) {
  this->_bridge = bridge;
}

int SFML::handleEvent() const {
  sf::Event event;
  while (this->window->pollEvent(event))
    {
      switch (event.type) {
          case sf::Event::Closed:
              this->window->close();
              return 1;
          case sf::Event::KeyPressed:
              if (handleKeyPressed(event))
                return 1;
              break;
          default:
              break;
        }
    }
    return 0;
}

int SFML::handleKeyPressed(const sf::Event & event) const {
  switch (event.key.code) {
    case sf::Keyboard::Escape:
      this->pressEchap();
      break;
    case sf::Keyboard::Right:
      this->goRight();
      break;
    case sf::Keyboard::Up:
      this->goUp();
      break;
    case sf::Keyboard::Down:
      this->goDown();
      break;
    case sf::Keyboard::Left:
      this->goLeft();
      break;
    case sf::Keyboard::Num2:
      this->prevGraph();
      return 1;
    case sf::Keyboard::Num3:
      this->nextGraph();
      return 1;
    case sf::Keyboard::Num4:
      this->prevGame();
      break;
    case sf::Keyboard::Num5:
      this->nextGame();
      break;
    case sf::Keyboard::Return:
      this->goForward();
      break;
    case sf::Keyboard::Space:
      this->shoot();
      break;
    case sf::Keyboard::P:
      this->toggleRunning();
      return 1;
    case sf::Keyboard::Num8:
      this->pressEight();
      break;
    case sf::Keyboard::Num9:
      this->pressNine();
    default:
      break;
  }
  return 0;
}

void SFML::handleData(AData const & data) {
  (void)data;
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

void SFML::handleSphere(AData const & data) {
  std::map<std::string, sf::Texture*>::iterator it;
  Sphere const & sphere = dynamic_cast<Sphere const &>(data);
  sf::CircleShape circle;
  circle.setRadius((sphere.getRadius() / 100) * this->_width);
  circle.setPosition((sphere.getPosition().getX() / 100.0) * this->_width, (sphere.getPosition().getY() / 100.0) * this->_height);
  std::string spriteName = sphere.getTexture().getSprite();
  if (!spriteName.empty()) {
    it = this->_spriteMap.find(spriteName);
    if (it != this->_spriteMap.end()) {
      circle.setTexture(it->second);
    } else {
      sf::Texture *texture = new sf::Texture;
      if (texture->loadFromFile(spriteName)) {
        this->_spriteMap[spriteName] = texture;
        circle.setTexture(texture);
      }
      circle.setTexture(texture);
    }
  } else {
    Color const & color = sphere.getTexture().getColor();
    circle.setFillColor(sf::Color(color.getR(), color.getG(), color.getB(), color.getA()));
  }
  this->window->draw(circle);
}

void SFML::handleCube(AData const & data) {
  std::map<std::string, sf::Texture*>::iterator it;
  Cube const & cube = dynamic_cast<Cube const &>(data);
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f((cube.getSize().getX() / 100.0) * this->_width, (cube.getSize().getX() / 100.0) * this->_width));
  rectangle.setPosition((cube.getPosition().getX() / 100.0) * this->_width, (cube.getPosition().getY() / 100.0) * this->_height);
  std::string spriteName = cube.getTexture().getSprite();
  if (!spriteName.empty()) {
    it = this->_spriteMap.find(spriteName);
    if (it != this->_spriteMap.end()) {
      rectangle.setTexture(it->second);
    } else {
      sf::Texture *texture = new sf::Texture;
      if (texture->loadFromFile(spriteName)) {
        this->_spriteMap[spriteName] = texture;
        rectangle.setTexture(texture);
      }
      rectangle.setTexture(texture);
    }
  } else {
    Color const & color = cube.getTexture().getColor();
    rectangle.setFillColor(sf::Color(color.getR(), color.getG(), color.getB(), color.getA()));
  }
  this->window->draw(rectangle);
}

void SFML::handleCamera(AData const & data) {
  (void) data;
}

void SFML::handleLight(AData const & data) {
  (void) data;
}

void SFML::handleMusic(AData const & data) {
  Audio const & audio = dynamic_cast<Audio const &>(data);
  sf::Music *music = new sf::Music();
  if (!music->openFromFile(audio.getAudio()))
    return;
  music->setLoop(audio.getRepeat());
  music->setVolume(audio.getIntensity());
  music->setPosition(audio.getPosition().getX(), audio.getPosition().getY(), audio.getPosition().getZ());
  music->play();
  this->_musics.push_back(music);
}

void SFML::handleText(AData const & data) {
  Text const & text = dynamic_cast<Text const &>(data);
  sf::Font font;
  font.loadFromFile("./assets/ka1.ttf");
  sf::Text txt(text.getText(), font);
  txt.setCharacterSize(30);
  Color const & color = text.getTexture().getColor();
  (void)color;
  sf::FloatRect textRect = txt.getLocalBounds();
  switch (text.getAlign()) {
    case Text::Align::CENTER :
      txt.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
      txt.setPosition(sf::Vector2f((text.getPosition().getX() / 100.0) * this->_width, (text.getPosition().getY() / 100.0) * this->_height));
      break;
    case Text::Align::RIGHT :
      txt.setOrigin(textRect.left + textRect.width, textRect.top  + textRect.height);
      txt.setPosition(sf::Vector2f((text.getPosition().getX() / 100.0) * this->_width, (text.getPosition().getY() / 100.0) * this->_height));
      break;
    case Text::Align::LEFT :
      txt.setPosition(sf::Vector2f((text.getPosition().getX() / 100.0) * this->_width, (text.getPosition().getY() / 100.0) * this->_height));
      break;
  }

  this->window->draw(txt);
}

void SFML::toggleRunning() const {
  this->_bridge->toggleRunning();
}

void SFML::prevGraph() const {
  this->_bridge->prevGraph();
}

void SFML::nextGraph() const {
  this->_bridge->nextGraph();
}

void SFML::prevGame() const {
  this->_bridge->prevGame();
}

void SFML::nextGame() const {
  this->_bridge->nextGame();
}

void SFML::goUp() const {
  this->_bridge->goUp();
}

void SFML::goDown() const {
  this->_bridge->goDown();
}

void SFML::goLeft() const {
  this->_bridge->goLeft();
}

void SFML::goRight() const {
  this->_bridge->goRight();
}

void SFML::goForward() const {
this->_bridge->goForward();
}

void SFML::shoot() const {
this->_bridge->shoot();
}

void SFML::pressEchap() const {
  this->_bridge->pressEchap();
}

void SFML::pressNine() const {
  this->_bridge->pressNine();
}

void SFML::pressEight() const {
  this->_bridge->pressEight();
}

extern "C"
{
  IGraph *Create()
  {
    return new SFML();
  }
}
