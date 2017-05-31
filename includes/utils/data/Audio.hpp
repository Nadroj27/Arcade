/*
** Audio.hpp for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/includes/utils/data
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun Apr 09 01:03:45 2017 Vacca_J
** Last update Sun Apr 09 01:03:55 2017 Vacca_J
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "AData.hpp"

class Audio: public AData {

public:
    explicit Audio (std::string const & audio, unsigned int intensity = 100, bool repeat = false);
    ~Audio ();
    Audio(const Audio &obj);
    Audio    &operator=(const Audio &obj);

    std::string const &getAudio() const;
    void setAudio(std::string const &audio);

    bool getRepeat() const;
    void setRepeat(bool repeat);

    unsigned int getIntensity() const;
    void setIntensity(unsigned int intensity);

    void reset(void);

private:
    std::string _audio;
    unsigned int _intensity;
    bool _repeat;

};

#else

class Audio;

#endif /* !AUDIO_HPP_ */
