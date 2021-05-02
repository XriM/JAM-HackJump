/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** CreditsScreen
*/

#include "CreditsScreen.hpp"

CreditsScreen::CreditsScreen()
{
    y = 0;

    _text.setCharacterSize(70);
    _textFont.loadFromFile("assets/creditsFont.ttf");
    _text.setFont(_textFont);

    _chetrit.setCharacterSize(40);
    _chetritFont.loadFromFile("assets/creditsFont.ttf");
    _chetrit.setFont(_chetritFont);

    _axel.setCharacterSize(40);
    _axelFont.loadFromFile("assets/creditsFont.ttf");
    _axel.setFont(_axelFont);

    _lucas.setCharacterSize(40);
    _lucasFont.loadFromFile("assets/creditsFont.ttf");
    _lucas.setFont(_lucasFont);

    _maxime.setCharacterSize(40);
    _maximeFont.loadFromFile("assets/creditsFont.ttf");
    _maxime.setFont(_maximeFont);

    _sean.setCharacterSize(40);
    _seanFont.loadFromFile("assets/creditsFont.ttf");
    _sean.setFont(_seanFont);

}

CreditsScreen::~CreditsScreen()
{
}

void CreditsScreen::setString(const std::string &value, sf::Text &text, const sf::Vector2f &position, const sf::Color &color) {
    text.setString(value);
    text.setPosition(position);
    text.setFillColor(color);
}

GameConstants::SCREEN_RETURN CreditsScreen::eventUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return (GameConstants::EXIT_GAME);
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN CreditsScreen::logicUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
    setString("Thanks For Playing!",
    _text, sf::Vector2f(150, 100 - y * 3), sf::Color::Green);

    setString("Alexandre Chetrit:\nBoucle de jeu\nIScreen\ntableaux\nblocs & collisions\nbonus\nbackground matrix",
    _chetrit, sf::Vector2f(150, 300 - y * 3), sf::Color::White);

    setString("Axel Karcher:\nDA\nblocs & collisions\nsprite personnage + idle\nsons\ntableaux\nbonus",
    _axel, sf::Vector2f(150, 800 - y * 3), sf::Color::White);

    setString("Lucas Bernard:\nGenerique\nmenu options\nfix sons\nmenu principal\nbonus",
    _lucas, sf::Vector2f(150, 1300 - y * 3), sf::Color::White);

    setString("Maxime Sarres:\nSons\nmenu principal\nfade out de lancement\nfix des sons\nmenu option\nbonus",
    _maxime, sf::Vector2f(150, 1800 - y * 3), sf::Color::White);

    setString("Sean Morton:\nAnimation sol\nbackground matrix\nsprite personnage + idle\ngenerique\nreadme/-h",
    _sean, sf::Vector2f(150, 2300 - y * 3), sf::Color::White);

    y += 1;
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN CreditsScreen::displayUpdate(sf::RenderWindow &window)
{
    window.draw(_text);
    window.draw(_chetrit);
    window.draw(_axel);
    window.draw(_lucas);
    window.draw(_maxime);
    window.draw(_sean);

    return (GameConstants::DO_NOTHING);
}