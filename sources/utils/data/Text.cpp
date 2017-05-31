/*
** Text.cpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/sources/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:16:23 2017 Vacca_J
// Last update Sun Apr  9 23:09:07 2017 Romain Fagnola
*/


#include        "Text.hpp"

Text::Text (std::string const &text, unsigned int size, Position const &pos, unsigned int zIndex)
{
  this->_text = text;
  this->_shape = DataType::Text;
  this->_position = pos;
  this->_texture = Texture();
  this->_align = Align::LEFT;
  this->_zIndex = zIndex;
  this->_size = size;
}

Text::~Text ()
{

}

Text::Text(const Text &obj)
{
  this->_text = obj._text;
  this->_shape = obj._shape;
  this->_position = obj._position;
  this->_texture = obj._texture;
  this->_align = obj._align;
  this->_zIndex = obj._zIndex;
  this->_size = obj._size;
}

Text    &Text::operator=(const Text &obj)
{
  this->_text = obj._text;
  this->_shape = obj._shape;
  this->_position = obj._position;
  this->_texture = obj._texture;
  this->_zIndex = obj._zIndex;
  this->_align = obj._align;
  this->_size = obj._size;
  return *this;
}

std::string const &Text::getText() const
{
  return this->_text;
}

void Text::setText(std::string const &text)
{
  this->_text = text;
}

Text::Align const &Text::getAlign() const
{
  return (this->_align);
}

void Text::setAlign(Text::Align const &align)
{
  this->_align = align;
}

unsigned int Text::getSize() const
{
  return (this->_size);
}

void Text::setSize(unsigned int size)
{
  this->_size = size;
}

void Text::reset(void)
{
  this->_text = "";
  this->_position = Position();
  this->_texture = Texture();
  this->_align = Align::LEFT;
  this->_zIndex = 0;
  this->_size = 0;
}
