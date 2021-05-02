/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenUpdate
*/

#include "GameScreen.hpp"

static const size_t FADE_SPEED = 16;

void GameScreen::updateSprites()
{
    if (_bgClock.getElapsedTime().asMilliseconds() > 100) {
        if (_playerRect.left >= 325) {
            _playerRect.left = 0;
        } else {
            _playerRect.left += 65;
        }
        _playerSprite.setTextureRect(_playerRect);
        updateBackground();
        _bgClock.restart();
    }
    if (_groundClock.getElapsedTime().asMilliseconds() > 350) {
        _groundRect.left = (_groundRect.left + 1920) % 3840;
        _groundSprite.setTextureRect(_groundRect);
        _groundClock.restart();

    }
}

GameConstants::SCREEN_RETURN GameScreen::updateBananas()
{
    if (_bananas.size() <= 5) {
        return (GameConstants::CHANGE_TO_CREDITS);
    }
    if (_nbBananas <= 30) {
        _nbBananas += 1;
        for (size_t i = 0; i < NB_BANANAS; ++i) {
            size_t future_y = _bananas[i].getPosition().y + random() % 100;
            _bananas[i].setPosition(_bananas[i].getPosition().x,
                future_y > FLOOR_LEVEL - 50 ? 0 : future_y);
        }
    } else {
        if (_bananas.size() <= 100) {
            sf::Color color = _fadeRectangle.getFillColor();
            _fadeRectangle.setFillColor(sf::Color(color.r, color.g, color.b,
                color.a + FADE_SPEED > 255 ? 255 : color.a + FADE_SPEED));
        }
        for (size_t i = 0; i < _bananas.size(); ++i) {
            size_t future_y = _bananas[i].getPosition().y + random() % 100;
            if (future_y > FLOOR_LEVEL - 50) {
                _bananas.erase(_bananas.begin() + i);
            } else {
                _bananas[i].setPosition(_bananas[i].getPosition().x,
                    future_y > FLOOR_LEVEL - 50 ? 0 : future_y);
            }
        }
    }
    return (GameConstants::DO_NOTHING);
}

void GameScreen::updateMovements()
{
    // Gravity & get the jump back
    if (canGoDown()) {
        if (_playerSprite.getPosition().y + _playerRect.height + 25 >= FLOOR_LEVEL) {
            _playerSprite.setPosition(sf::Vector2f(_playerSprite.getPosition().x,
                FLOOR_LEVEL - _playerRect.height));
        } else {
            _playerSprite.setPosition(sf::Vector2f(_playerSprite.getPosition().x,
                _playerSprite.getPosition().y + 25));
        }
    } else {
        _hasJump = true;
        _jumpHigh = 0;
    }

    // Moving on x
    if (_leftInput) {
        _playerSprite.setPosition(_playerSprite.getPosition().x - 15,
            _playerSprite.getPosition().y);
        _playerRect.top = 144;
    }
    if (_rightInput) {
        _playerSprite.setPosition(_playerSprite.getPosition().x + 15,
            _playerSprite.getPosition().y);
        _playerRect.top = 0;
    }

    // Jumping
    if (_upInput && _hasJump) {
        _hasJump = false;
    }
    if (_hasJump == false)
        jumpManagement();

}

void GameScreen::restartPlayer()
{
    _deathCount += 1;
    _deathClock.restart();
    _playerSprite.setPosition(sf::Vector2f(20, FLOOR_LEVEL - _playerRect.height));
}

void GameScreen::updateTexts()
{
    // Clock
    if ((_leftInput || _rightInput || _upInput) &&
    _chronoClock.getElapsedTime().asSeconds() < 0)
        _chronoClock.restart();
    setString(getChronoFormat(_chronoClock.getElapsedTime().asSeconds()),
        _chronoText, sf::Vector2f(20, 20), sf::Color::White);

    // Death
    setString("x " + std::to_string(_deathCount), _deathText,
        sf::Vector2f(1800, 20), sf::Color::White);

    // Level
    setString(_currentMap == 0 ? "Tutorial" :
        "Level " + std::to_string(int(_currentMap)),
        _levelText, sf::Vector2f(20, 60), sf::Color::White);

    // Tutorial
    setString("> SWITCH", _tutorialText1,
        sf::Vector2f(170, 410), sf::Color::White);
    setString("> RESTART", _tutorialText2,
        sf::Vector2f(1080, 355), sf::Color::White);
}


void GameScreen::updateBackground()
{
    if (_currentBackground > 51) {
        _backgroundRect.left = 0;
        _backgroundRect.top = 0;
        _currentBackground = 14;
    }
    size_t frame = 52 - _currentBackground;
    size_t x = 1200 * frame % 8;
    size_t y = (850) * frame / 8;
    _currentBackground += 1;
    _backgroundRect.left = x;
    _backgroundRect.top = y;
    _sBackground.setTextureRect(_backgroundRect);
}