/*
** AVisual.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:03:52 2017 Vacca_J
** Last update Sun Apr 09 01:03:53 2017 Vacca_J
*/

#ifndef VISUAL_HPP_
#define VISUAL_HPP_

#include "AData.hpp"

class AVisual: public AData {

public:
    virtual ~AVisual () {};

    Texture const &getTexture() const;
    virtual void setTexture(Texture const &texture);

    virtual void setRotation(int rotation);

    unsigned int getZIndex() const;
    virtual void setZIndex(unsigned int zIndex);

    unsigned int getId() const;
    virtual void setId(unsigned int id);

    virtual void reset(void) = 0;

protected:
    Texture _texture;
    unsigned int _zIndex;
    unsigned int _id;

};

#else

class AVisual;

#endif /* !VISUAL_HPP_ */
