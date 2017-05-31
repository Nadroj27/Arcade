/*
** Cube.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:04:11 2017 Vacca_J
** Last update Sun Apr 09 01:04:14 2017 Vacca_J
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "AVisual.hpp"

class Cube : public AVisual {
public:
    explicit Cube(Position const &pos, Position const &size, Texture const &text = Texture(), unsigned int zIndex = 0, unsigned int id = 0);
    ~Cube();
    Cube &operator=(const Cube &obj);
    Cube(Cube const &obj);

    Position const &getSize() const;
    void setSize(Position const &size);
    bool operator==(Cube const &cube) const;
    bool inLine(double a, double new_a, double size) const;

    void reset(void);

protected:
    Position _size;
};

#else

class Cube;

#endif
