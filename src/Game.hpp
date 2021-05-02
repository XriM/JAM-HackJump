/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "ISCreen.hpp"
#include "GameConstants.hpp"

#include "screens/Game/GameScreen.hpp"
#include "screens/MenuScreen.hpp"
#include "screens/CreditsScreen.hpp"

class Game {
  public:
    Game();
    ~Game();
    void run();

  private:
    bool checkScreenReturnValue(GameConstants::SCREEN_RETURN value);
    GameScreen _gameScreen;
    MenuScreen _menuScreen;
    CreditsScreen _creditsScreen;
    std::unique_ptr<ISCreen> _currentScreen;
    sf::RenderWindow _window;
    sf::Clock clock;
};

#endif /* !GAME_HPP_ */
