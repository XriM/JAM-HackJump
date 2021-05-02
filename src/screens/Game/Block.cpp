/*
** EPITECH PROJECT, 2021
**
** File description:
** Block.cpp
*/

#include "Block.hpp"

Block::Block(sf::Vector2f size, sf::Vector2f position, WhatColor color, bool isActive)
    : _size(size), _position(position), _color(color), _isActive(isActive)
{
    _shape.setSize(_size);
    _shape.setPosition(_position);
    _shape.setFillColor(COLORS[_color]);

    _shape.setOutlineThickness(-10);
    if (_color == RED)
        _shape.setOutlineColor(COLORS[OUT_RED]);
    if (_color == N_BLUE)
        _shape.setOutlineColor(COLORS[N_OUT_BLUE]);
    if (_color == GREY)
        _shape.setOutlineColor(COLORS[OUT_GREY]);
}

Block::~Block()
{}

void Block::changeMode(WhatColor newColor) {
    _color = newColor;
    _isActive = !_isActive;
    _shape.setFillColor(COLORS[_color]);
    switch(newColor) {
        case RED:
            _shape.setOutlineColor(COLORS[OUT_RED]);
            break;
        case N_RED:
            _shape.setOutlineColor(COLORS[N_OUT_RED]);
            break;
        case BLUE:
            _shape.setOutlineColor(COLORS[OUT_BLUE]);
            break;
        case N_BLUE:
            _shape.setOutlineColor(COLORS[N_OUT_BLUE]);
            break;
        default:
            break;
    }
}