/*
** Camera.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:04:01 2017 Vacca_J
** Last update Sun Apr 09 01:04:02 2017 Vacca_J
*/


#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "AScene.hpp"

class Camera : public AScene {
public:
    explicit Camera(Position const &pos, float incX = 0, float incY = 0);
    ~Camera();
    Camera &operator=(const Camera &obj);
    Camera(Camera const &camera);
    void reset(void);
};

#else

class Camera;

#endif
