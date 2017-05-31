/*
** Text.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:04:57 2017 Vacca_J
** Last update Sun Apr 09 01:05:00 2017 Vacca_J
*/


#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "AVisual.hpp"

class Text : public AVisual {
public:
    enum Align
    {
        CENTER,
        LEFT,
        RIGHT
    };

    explicit Text (std::string const &text, unsigned int size, Position const &pos = Position(), unsigned int zIndex = 0);
    ~Text ();
    Text(const Text &obj);
    Text    &operator=(const Text &obj);
    std::string const &getText() const;
    void setText(std::string const &text);
    Align const &getAlign() const;
    void setAlign(Align const &align);
    unsigned int getSize() const;
    void setSize(unsigned int size);
    void reset(void);

protected:
    std::string _text;
    Align _align;
    unsigned int _size;

};

#else

class Test;

#endif
