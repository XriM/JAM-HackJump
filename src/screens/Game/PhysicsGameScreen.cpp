/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** PhysicsGameScreen
*/

#include <cmath>

#include "GameScreen.hpp"

bool GameScreen::canGoDown()
{
    sf::Vector2f l1(_playerSprite.getPosition());
    sf::Vector2f r1(_playerSprite.getPosition().x + _playerRect.width,
        _playerSprite.getPosition().y + _playerRect.height);

    for (auto it = _maps[_currentMap].blocks.begin(); it != _maps[_currentMap].blocks.end(); it++) {
        if (!it->get()->getActive()) {
            continue;
        }
        sf::Vector2f l2(it->get()->getPosition());
        sf::Vector2f r2(it->get()->getPosition() + it->get()->getSize());
        if (l1.x < r2.x && l2.x < r1.x) {
            size_t future_y = _playerSprite.getPosition().y + _playerRect.height + 25;
            if (future_y > it->get()->getPosition().y + it->get()->getSize().y) {
                continue;
            }
            if (future_y > it->get()->getPosition().y && future_y < it->get()->getPosition().y + it->get()->getSize().y) {
                _playerSprite.setPosition(
                    _playerSprite.getPosition().x,
                    it->get()->getPosition().y - _playerRect.height - 1
                );
                return (false);
            }
            return (!(_playerSprite.getPosition().y + _playerRect.height + 25 > it->get()->getPosition().y));
        }
    }
    return (_playerSprite.getPosition().y + _playerRect.height < 850);
}

void GameScreen::jumpManagement(void)
{
    int sign = _leftInput ? -1 : 1;

    if (!_leftInput && !_rightInput)
        sign = 0;
    if (_hasJump == false) {
        if (_jumpHigh != 600) {
            _playerSprite.setPosition(sf::Vector2f(_playerSprite.getPosition().x
                + (0.5 * _jumpHigh / log(_jumpHigh * _jumpHigh) * sign),
                _playerSprite.getPosition().y - 40));
            _jumpHigh += 40;
        }
    } else {
        _jumpHigh = 0;
        _hasJump = true;
    }
}

bool doOverlap(sf::Vector2f l1, sf::Vector2f r1, sf::Vector2f l2, sf::Vector2f r2)
{
    if (l1.x == r1.x || l1.y == r2.y || l2.x == r2.x
        || l2.y == r2.y) {
        return false;
    }
    if (l1.x >= r2.x || l2.x >= r1.x) {
        return false;
    }
    if (l1.y >= r2.y || l2.y >= r1.y) {
        return false;
    }
    return true;
}

bool GameScreen::checkHitboxes()
{
    sf::Vector2f l1(_playerSprite.getPosition());
    sf::Vector2f r1(_playerSprite.getPosition().x + _playerRect.width,
        _playerSprite.getPosition().y + _playerRect.height);

    for (auto it = _maps[_currentMap].blocks.begin(); it != _maps[_currentMap].blocks.end(); it++) {
        if (!it->get()->getActive()) {
            continue;
        }
        sf::Vector2f l2(it->get()->getPosition());
        sf::Vector2f r2(it->get()->getPosition() + it->get()->getSize());
        if (doOverlap(l1, r1, l2, r2)) {
            return (false);
        }
    }
    return (true);
}