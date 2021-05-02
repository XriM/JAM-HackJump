/*
** EPITECH PROJECT, 2021
**
** File description:
** Block.hpp
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <SFML/Graphics.hpp>
#include <unordered_map>

static const sf::Color COLORS[10] = {
    sf::Color(255, 0, 0),
    sf::Color(165, 0, 0),
    sf::Color(255, 0, 0, 50),
    sf::Color(165, 0, 0, 50),

    sf::Color(0, 0, 255),
    sf::Color(0, 0, 165),
    sf::Color(0, 0, 255, 50),
    sf::Color(0, 0, 165, 50),

    sf::Color(90, 90, 90),
    sf::Color(220, 220, 220)
};

enum WhatColor {
    RED,
    OUT_RED,
    N_RED,
    N_OUT_RED,

    BLUE,
    OUT_BLUE,
    N_BLUE,
    N_OUT_BLUE,

    GREY,
    OUT_GREY
};

class Block {
    public:
        Block(sf::Vector2f size, sf::Vector2f position,
            WhatColor color, bool isActive);
        ~Block();
        const sf::RectangleShape &getShape() { return _shape; };
        const bool &getActive() { return _isActive; };
        const sf::Vector2f &getPosition() { return _position; };
        const sf::Vector2f &getSize() { return _size; };
        const WhatColor &getColor() { return _color; };
        void changeMode(WhatColor newColor);

    private:
        sf::RectangleShape _shape;
        sf::Vector2f _size;
        sf::Vector2f _position;
        WhatColor _color;
        bool _isActive;
};

#endif /* BLOCK_HPP_ */