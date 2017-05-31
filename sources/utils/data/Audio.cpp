/*
** Audio.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:17:00 2017 Vacca_J
// Last update Sun Apr  9 23:08:22 2017 Romain Fagnola
*/

#include "Audio.hpp"

Audio::Audio (std::string const & audio, unsigned int intensity, bool repeat) {
  this->_audio = audio;
  this->_intensity = intensity;
  this->_repeat = repeat;
  this->_shape = DataType::Music;
  this->_position = Position();
}

Audio::~Audio () {

}

Audio::Audio(const Audio &obj) {
  this->_audio = obj._audio;
  this->_repeat = obj._repeat;
  this->_intensity = obj._intensity;
  this->_shape = obj._shape;
  this->_position = obj._position;
}

Audio    &Audio::operator=(const Audio &obj) {
  this->_audio = obj._audio;
  this->_repeat = obj._repeat;
  this->_intensity = obj._intensity;
  this->_shape = obj._shape;
  this->_position = obj._position;
  return *this;
}


std::string const &Audio::getAudio() const {
  return this->_audio;
}

void Audio::setAudio(std::string const &audio) {
  this->_audio = audio;
}


bool Audio::getRepeat() const {
  return this->_repeat;
}

void Audio::setRepeat(bool repeat) {
  this->_repeat = repeat;
}

unsigned int Audio::getIntensity() const
{
  return (this->_intensity);
}
void Audio::setIntensity(unsigned int intensity)
{
  this->_intensity = intensity;
}

void Audio::reset(void)
{
  this->_audio = "";
  this->_repeat = false;
  this->_intensity = 0;
  this->_position = Position();
}
