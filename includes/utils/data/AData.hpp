/*
** AData.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:03:31 2017 Vacca_J
** Last update Sun Apr 09 01:03:57 2017 Vacca_J
*/

#ifndef ADATA_HPP_
#define ADATA_HPP_

#include "IData.hpp"

class AData : public IData {

public:
    virtual ~AData () {};

    DataType const &getShape() const;
    virtual void setShape(DataType const &shape);

    Position const &getPosition() const;
    virtual void setPosition(Position const &position);

    virtual void setPositionX(double const x);
    virtual void setPositionY(double const y);
    virtual void setPositionZ(double const z);

    virtual void reset(void) = 0;

protected:
    DataType _shape;
    Position _position;

};

#else

class AData;

#endif /* !ADATA_HPP_ */
