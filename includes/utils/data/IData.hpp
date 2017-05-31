/*
** IData.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:04:28 2017 Vacca_J
** Last update Sun Apr 09 01:04:30 2017 Vacca_J
*/


#ifndef IDATA_HPP_
#define IDATA_HPP_

#include "Position.hpp"
#include "Texture.hpp"

enum class DataType {
    Sphere,
    Cube,
    Camera,
    Light,
    Music,
    Text
};

class IData {

public:
    virtual ~IData () {};

    virtual DataType const &getShape() const = 0;
    virtual void setShape(DataType const &shape) = 0;

    virtual Position const &getPosition() const = 0;
    virtual void setPosition(Position const &position) = 0;
    virtual void reset(void) = 0;


};

#else

class IData;
enum class DataType;


#endif /* !IDATA_HPP_ */
