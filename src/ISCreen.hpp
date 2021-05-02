/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** ISCreen
*/

#ifndef ISCREEN_HPP_
#define ISCREEN_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "GameConstants.hpp"
class ISCreen {
  public:
    ~ISCreen() = default;
    virtual GameConstants::SCREEN_RETURN eventUpdate(sf::RenderWindow &window) = 0;
    virtual GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window) = 0;
    virtual GameConstants::SCREEN_RETURN displayUpdate(sf::RenderWindow &window) = 0;
};

#endif /* !ISCREEN_HPP_ */
