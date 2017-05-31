/*
** IArcadeBridge.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:07:08 2017 Vacca_J
** Last update Sun Apr 09 01:07:10 2017 Vacca_J
*/

#ifndef IARCADEBRIDGE_HPP_
#define IARCADEBRIDGE_HPP_

class IArcadeBridge {

public:
    IArcadeBridge    &operator=(const IArcadeBridge &obj);

    virtual void prevGraph() = 0;
    virtual void nextGraph() = 0;

    virtual void prevGame() = 0;
    virtual void nextGame() = 0;

    virtual void toggleRunning() = 0;
    virtual void goUp() const = 0;
    virtual void goDown() const = 0;
    virtual void goLeft() const = 0;
    virtual void goRight() const = 0;
    virtual void goForward() const = 0;
    virtual void shoot() const = 0;
    virtual void pressEchap() = 0;
    virtual void pressEight() = 0;
    virtual void pressNine() = 0;
};

#endif /* !IARCADEBRIDGE_HPP_ */
