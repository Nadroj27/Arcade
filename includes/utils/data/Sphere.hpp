/*
** Sphere.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:04:51 2017 Vacca_J
** Last update Sun Apr 09 01:04:51 2017 Vacca_J
*/

#ifndef SPHERE_HPP_
#define SHPERE_HPP_

#include "AVisual.hpp"

class Sphere : public AVisual {
public:
    explicit Sphere(Position const &pos, float radius, Texture const &text = Texture(), unsigned int zIndex = 0);
    ~Sphere();
    Sphere &operator=(const Sphere &obj);
    Sphere(Sphere const &obj);

    float getRadius() const;
    void setRadius(float radius);

    void reset(void);

protected:
    float _radius;
};

#else

class Sphere;

#endif
