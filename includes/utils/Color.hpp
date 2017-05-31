/*
** Color.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:06:15 2017 Vacca_J
** Last update Sun Apr 09 01:06:16 2017 Vacca_J
*/


#ifndef COLOR_HPP_
#define COLOR_HPP_

class Color {

private:
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
    unsigned char _a;

public:
    Color (unsigned char const r = 0, unsigned char const g = 0, unsigned char const b = 0, unsigned char const a = 0);
    ~Color ();
    Color(const Color &obj);
    Color    &operator=(const Color &obj);

    unsigned char getR() const;
    void setR(unsigned char const r);

    unsigned char getG() const;
    void setG(unsigned char const g);

    unsigned char getB() const;
    void setB(unsigned char const b);

    unsigned char getA() const;
    void setA(unsigned char const a);

    void setRGBA(unsigned char const x, unsigned char const y, unsigned char const z, unsigned char const a);

};

#else

class Color;

#endif /* !COLOR_HPP_ */
