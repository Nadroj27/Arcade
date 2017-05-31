/*
** Model3D.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:06:25 2017 Vacca_J
** Last update Sun Apr 09 01:06:26 2017 Vacca_J
*/

#ifndef MODEL3D_HPP_
#define MODEL3D_HPP_

#include <string>

#include "Position.hpp"

class Model3D {

public:
    Model3D (std::string const &object = "", Position const &position = Position(), Position const &_scale = Position(1, 1, 1), Position const &_rotation = Position());
    ~Model3D ();
    Model3D(const Model3D &obj);
    Model3D    &operator=(const Model3D &obj);

    void setObject(std::string const &object);
    std::string const &getObject(void) const;

    void setScale(Position const &scale);
    void setScaleX(double x);
    void setScaleY(double y);
    void setScaleZ(double z);
    Position const &getScale(void) const;

    void setPosition(Position const &position);
    void setPositionX(double x);
    void setPositionY(double y);
    void setPositionZ(double z);
    Position const &getPosition(void) const;

    void setRotation(Position const &rotation);
    void setRotationX(double x);
    void setRotationY(double y);
    void setRotationZ(double z);
    Position const &getRotation(void) const;

private:
    std::string _object;
    Position _scale;
    Position _position;
    Position _rotation;

};

#else

class Model3D;

#endif /*MODEL3D_HPP_*/
