/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenPause
*/

#include "GameScreen.hpp"

void GameScreen::setVolume(float volume)
{
    _volume = volume;
    _gameMusic->setVolume(volume);
    _termSound.setVolume(volume);
    _typeSound.setVolume(volume);
    _validSound.setVolume(volume);
}

void GameScreen::initPauseMenu()
{
    linkSpriteTexture(_continueButtonSprite, _continueButtonTexture,
        "assets/continuePauseButton.png");
    _continueButtonSprite.setPosition(sf::Vector2f(800, 450));
    linkSpriteTexture(_returnMenuSprite, _returnMenuTexture,
        "assets/menubutton.png");
    _returnMenuSprite.setPosition(sf::Vector2f(800, 600));
    linkSpriteTexture(_quitButtonSprite, _quitButtonTexture,
        "assets/quitPauseButton.png");
    _quitButtonSprite.setPosition(sf::Vector2f(800, 750));
}

GameConstants::SCREEN_RETURN GameScreen::pauseEventUpdate(sf::RenderWindow &window)
{
    _posMouse = sf::Mouse::getPosition(window);

    while (window.pollEvent(_event));
    if (_posMouse.x >= 800 && _posMouse.x <= 1100 && _posMouse.y >= 450 && _posMouse.y <= 550)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _isPause = false;
            return (GameConstants::DO_NOTHING);
        }
    if (_posMouse.x >= 800 && _posMouse.x <= 1100 && _posMouse.y >= 600 && _posMouse.y <= 700)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _isPause = false;
            _gameMusic->pause();
            return (GameConstants::CHANGE_TO_MENU);
        }
    if (_posMouse.x >= 800 && _posMouse.x <= 1100 && _posMouse.y >= 750 && _posMouse.y <= 950)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _isPause = false;
            return (GameConstants::EXIT_GAME);
        }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN GameScreen::pauseLogicUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
    return (GameConstants::DO_NOTHING);
}

void GameScreen::drawPause(sf::RenderWindow &window)
{
    window.draw(_quitButtonSprite);
    window.draw(_continueButtonSprite);
    window.draw(_returnMenuSprite);
}