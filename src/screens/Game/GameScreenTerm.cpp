/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenTerm
*/

#include "GameScreen.hpp"

void GameScreen::initTerminal()
{
    _terminalLayer.setSize(sf::Vector2f(1920, 1080));
    _terminalLayer.setPosition(sf::Vector2f(0, 0));
    _terminalLayer.setFillColor(sf::Color(0, 0, 0, 150));
    _isTerminal = false;
    _termInput.setCharacterSize(25);
    _currentInput = std::string("> ");
    _termFont.loadFromFile("assets/termFont.ttf");
    _termInput.setFont(_termFont);

}

void GameScreen::switchBlocks()
{
    for (auto it = _maps[_currentMap].blocks.begin(); it != _maps[_currentMap].blocks.end(); it++) {
        switch(it->get()->getColor()) {
            case RED:
                it->get()->changeMode(N_RED);
                break;
            case N_RED:
                it->get()->changeMode(RED);
                break;
            case BLUE:
                it->get()->changeMode(N_BLUE);
                break;
            case N_BLUE:
                it->get()->changeMode(BLUE);
                break;
            default:
                break;
        }
    }
}

GameConstants::SCREEN_RETURN GameScreen::terminalEventUpdate(sf::RenderWindow &window)
{
    while (window.pollEvent(_event)) {
        if (_event.type == sf::Event::TextEntered) {
            if (_event.text.unicode == 8) {
                if (_currentInput.size() > 2) {
                    _currentInput.erase(_currentInput.size() - 1, 1);
                    _termInput.setString(_currentInput);
                    continue;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == false)
                _typeSound.play();
            _currentInput += _event.text.unicode;
            if (!_endTerminalInput) {
                continue;
            }
            if (_currentInput.find("switch") != std::string::npos) {
                switchBlocks();
                _currentInput = std::string("> ");
            } else if (_currentInput.find("banana") != std::string::npos) {
                _isRainingBananas = true;
                _currentInput = std::string("> ");
            } else if (_currentInput.find("restart") != std::string::npos) {
                restartPlayer();
                _currentInput = std::string("> ");
            }
            _termInput.setString(_currentInput);
        }
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN GameScreen::terminalLogicUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
    if (_playerRect.top == 144)
        _playerRect.top = 432;
    if (_playerRect.top == 0)
        _playerRect.top = 288;

    if (_endTerminalInput) {
        _isTermSound = false;
        if (!_isTermSound) {
            _validSound.play();
            _isEndTermSound = false;
        }
        _currentInput = "> ";
        _termInput.setString(_currentInput);
        _isTerminal = false;

        _playerRect.top = _playerRect.top == 432 * 144;
    }
    setString(_currentInput, _termInput,
        sf::Vector2f(100, 150), sf::Color::Green);
    return (GameConstants::DO_NOTHING);
}

void GameScreen::drawTerminal(sf::RenderWindow &window)
{
    window.draw(_terminalLayer);
    window.draw(_termInput);
}
