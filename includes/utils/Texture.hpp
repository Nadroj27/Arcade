/*
** Texture.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:06:45 2017 Vacca_J
** Last update Sun Apr 09 01:06:46 2017 Vacca_J
*/


#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <string>
#include "Color.hpp"
#include "Model3D.hpp"

class Texture {

public:
    Texture (Color const & color = Color());
    Texture (std::string const & sprite, Color const & color = Color(), int rotation = 0, Model3D const &model = Model3D());
    virtual ~Texture ();
    Texture(const Texture &obj);
    Texture    &operator=(const Texture &obj);

    Color const &getColor() const;
    void setColor(Color const &color);

    std::string const &getSprite() const;
    void setSprite(std::string const &sprite);

    int const &getRotation() const;
    void setRotation(int rotation);

    Model3D const &getModel() const;
    void setModel(Model3D const &model);

private:
    Color _color;
    std::string _sprite;
    Model3D _model;
    int _rotation;

};

#else

class Texture;

#endif /* !TEXTURE_HPP_ */
