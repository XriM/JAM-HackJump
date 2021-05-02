/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenUtils
*/

#include "GameScreen.hpp"

void GameScreen::setString(const std::string &value, sf::Text &text,
    const sf::Vector2f &position, const sf::Color &color) {
    text.setString(value);
    text.setPosition(position);
    text.setFillColor(color);
}

std::string GameScreen::getChronoFormat(float sec)
{
    int s = int(sec);
    std::string minutes = "00";
    std::string separator = ":";
    std::string secondes = "00";

    if (s == 0)
        return ("--:--");

    if (sec < 60) {
        secondes = std::to_string(s);
        if (s < 10)
            secondes = "0" + secondes;
    } else {
        minutes = std::to_string(s / 60);
        secondes = std::to_string(s % 60);
        if (s % 60 < 10)
            secondes = "0" + secondes;
    }

    return (minutes + separator + secondes);
}

void GameScreen::linkSpriteTexture(sf::Sprite &sprite, sf::Texture &texture, std::string const asset) {
  if (!texture.loadFromFile(asset)) {
      exit (84);
  }
  sprite.setTexture(texture);
}