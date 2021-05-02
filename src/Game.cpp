/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** Game
*/

#include <unistd.h>
#include <iostream>
#include <unistd.h>

#include "Game.hpp"

Game::Game() : _window(sf::VideoMode(GameConstants::WINDOW_X, GameConstants::WINDOW_Y),
  "HackJump", sf::Style::Fullscreen)
{
  _window.setFramerateLimit(60);
  _window.setVerticalSyncEnabled(true);
  _currentScreen = std::make_unique<MenuScreen>(_menuScreen);
  clock.restart();
}

Game::~Game()
{}

bool Game::checkScreenReturnValue(GameConstants::SCREEN_RETURN value)
{
  if (value == GameConstants::SCREEN_RETURN::EXIT_GAME) {
    this->_window.close();
    return (true);
  } else if (value == GameConstants::SCREEN_RETURN::CHANGE_TO_GAME) {
    _currentScreen = std::make_unique<GameScreen>(_gameScreen);
  } else if (value == GameConstants::SCREEN_RETURN::CHANGE_TO_MENU) {
    _currentScreen = std::make_unique<MenuScreen>(_menuScreen);
  } else if (value == GameConstants::SCREEN_RETURN::CHANGE_TO_CREDITS) {
    _currentScreen = std::make_unique<CreditsScreen>(_creditsScreen);
  } else if (value == GameConstants::SCREEN_RETURN::MUTE_GAME_VOLUME) {
    _gameScreen.setVolume(0);
  } else if (value == GameConstants::SCREEN_RETURN::DEMUTE_GAME_VOLUME) {
    _gameScreen.setVolume(50);
  }
  return (false);
}


void Game::run()
{
  while (_window.isOpen()) {
      if (clock.getElapsedTime().asMilliseconds() > 17) {
        _window.clear();
        if (checkScreenReturnValue(_currentScreen->eventUpdate(_window))) {
          break;
        }
        if (checkScreenReturnValue(_currentScreen->logicUpdate(_window))) {
          break;
        }
        if (checkScreenReturnValue(_currentScreen->displayUpdate(_window))) {
          break;
        }
        _window.display();
        clock.restart();
      }
  }
}