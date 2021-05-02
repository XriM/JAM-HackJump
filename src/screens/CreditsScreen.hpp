/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** CreditsScreen
*/

#include "ISCreen.hpp"

#ifndef CREDITSSCREEN_HPP_
#define CREDITSSCREEN_HPP_

class CreditsScreen : public ISCreen {
  public:
    CreditsScreen();
    ~CreditsScreen();

    GameConstants::SCREEN_RETURN eventUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN displayUpdate(sf::RenderWindow &window) override;

  private:
    void setString(const std::string &value,
    sf::Text &text, const sf::Vector2f &position, const sf::Color &color);
    sf::Text _text;
    sf::Font _textFont;

    sf::Text _chetrit;
    sf::Font _chetritFont;

    sf::Text _axel;
    sf::Font _axelFont;

    sf::Text _lucas;
    sf::Font _lucasFont;

    sf::Text _maxime;
    sf::Font _maximeFont;

    sf::Text _sean;
    sf::Font _seanFont;

    size_t y;
};

#endif /* !CREDITSSCREEN_HPP_ */
