//
// Position.hpp for  in /Users/ethankerdelhue/Documents/shared/gambin/tmp2/cpp_arcade/includes/utils/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sun Apr  9 19:09:43 2017 Ethan Kerdelhue
// Last update Sun Apr  9 19:09:47 2017 Ethan Kerdelhue
//

#ifndef POSITION_HPP_
#define POSITION_HPP_

class Position {

private:
    double _x;
    double _y;
    double _z;

public:
    Position (double const x = 0, double const y = 0, double const z = 0);
    ~Position ();
    Position(const Position &obj);
    Position    &operator=(const Position &obj);
    bool    operator==(const Position &obj) const;

    double getX() const;
    void setX(double const x);

    double getY() const;
    void setY(double const y);

    double getZ() const;
    void setZ(double const z);

};

Position operator+(Position const &a, Position const &b);
Position operator-(Position const &a, Position const &b);
Position operator/(Position const &a, int b);
Position operator*(Position const &a, int b);

#else

class Position;

#endif /* !POSITION_HPP_ */
