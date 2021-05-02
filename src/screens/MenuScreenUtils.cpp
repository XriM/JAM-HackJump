/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** MenuScreenUtils
*/

#include <unistd.h>
#include "MenuScreen.hpp"

GameConstants::SCREEN_RETURN MenuScreen::playButtonManager(sf::RenderWindow &window)
{
    if (this->statePlay == 0) {
      // if mouse is in button area change state play
      _mouseSound.play();
      this->statePlay = 1;
      _playSprite.setTexture(_play2Texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      // if click on button play
      _selectSound.play();
      _playSprite.setTexture(_play3Texture);
      this->displayUpdate(window);
      window.display();
      _fadeOutProgress = 650;
      _menuMusic->stop();
      _playSound.play();
      return (GameConstants::DO_NOTHING);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::quitButtonManager(sf::RenderWindow &window)
{
    if (this->stateQuit == 0) {
      // if mouse is in button area change state quit
      _mouseSound.play();
      this->stateQuit = 1;
      _quitSprite.setTexture(_quit2Texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      // if click on button quit
      _selectSound.play();
      _quitSprite.setTexture(_quit3Texture);
      this->displayUpdate(window);
      _menuMusic->stop();
      window.display();
      usleep(500000);
      return (GameConstants::EXIT_GAME);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::optionButtonManager(sf::RenderWindow &window)
{
    //_mouseSound.play();
    if (this->stateOption == 0) {
      // if mouse is in button area change state quit
      _mouseSound.play();
      this->stateOption = 1;
      _optionSprite.setTexture(_option2Texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      _selectSound.play();
      _optionSprite.setTexture(_option3Texture);
      this->displayUpdate(window);
      _isOption = true;
      window.display();
      usleep(500000);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::returnMenuButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      _isOption = false;
      return (GameConstants::CHANGE_TO_MENU);
    }
  return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::volumeDownButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (_volume > 0) {
        _volume -= 1;
        _optionBar.setSize(sf::Vector2f(_volume * 3, 50));
      }
      if (_isMuted == 0) {
        _menuMusic->setVolume(_volume);
        _mouseSound.setVolume(_volume / 2);
        _selectSound.setVolume(_volume / 2);
        _playSound.setVolume(_volume);
      } else {
        _mouseSound.setVolume(0);
        _selectSound.setVolume(0);
        _menuMusic->setVolume(0);
        _playSound.setVolume(0);
      }
      return (GameConstants::DO_NOTHING);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::volumeUpButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (_volume < 100) {
        _volume += 1;
        _optionBar.setSize(sf::Vector2f(_volume * 3, 50));
      }
      if (_isMuted == 0) {
        _menuMusic->setVolume(_volume);
        _mouseSound.setVolume(_volume / 2);
        _selectSound.setVolume(_volume / 2);
        _playSound.setVolume(_volume);
      }
      else {
        _mouseSound.setVolume(0);
        _selectSound.setVolume(0);
        _menuMusic->setVolume(0);
        _playSound.setVolume(0);
      }
      return (GameConstants::DO_NOTHING);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::cutVolumeButtonManager()
{
    printf("%f\n", this->_mouseSound.getVolume());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _optionClock.getElapsedTime().asMilliseconds() > 200) {
      _optionClock.restart();
      if (_isMuted > 0 && _ispressed == 0) {
        _volume = _isMuted;
        _isMuted = 0;
        _cutVolumeSprite.setTexture(_cutVolumeTexture);
        _menuMusic->setVolume(_volume);
        _mouseSound.setVolume(_volume / 2);
        _selectSound.setVolume(_volume / 2);
        _playSound.setVolume(_volume);
        return (GameConstants::DEMUTE_GAME_VOLUME);
      } else if (_isMuted == 0 && _ispressed == 0) {
        _isMuted = _volume;
        _volume = 0;
        _cutVolumeSprite.setTexture(_cutVolume2Texture);
        _menuMusic->setVolume(0);
        _mouseSound.setVolume(0);
        _selectSound.setVolume(0);
        _playSound.setVolume(0);
        return (GameConstants::MUTE_GAME_VOLUME);
      }
      _ispressed = 1;
      return (GameConstants::DO_NOTHING);
    } else
    _ispressed = 0;
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::creditsButtonManager()
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      _isOption = false;
      printf("oui\n");
      return (GameConstants::CHANGE_TO_CREDITS);
    }
  return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::optionEventUpdate(sf::RenderWindow &window)
{
    while (window.pollEvent(_event));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return (GameConstants::EXIT_GAME);
    _pMouse = sf::Mouse::getPosition(window);
    if (_pMouse.x >= 960 - 450 && _pMouse.x <= 960 - 150 && _pMouse.y >= 750 && _pMouse.y <= 850) {
      return (this->returnMenuButtonManager());
    }
    if (_pMouse.x >= 960 + 150 && _pMouse.x <= 960 + 450 && _pMouse.y >= 750 && _pMouse.y <= 850) {
      return (this->creditsButtonManager());
    }
    if (_pMouse.x >= 960 - 300 && _pMouse.x <= 960 - 200 && _pMouse.y >= 600 && _pMouse.y <= 700) {
      return (this->volumeDownButtonManager());
    }
    if (_pMouse.x >= 960 - 50 && _pMouse.x <= 960 + 50 && _pMouse.y >= 750 && _pMouse.y <= 850) {
      return (this->cutVolumeButtonManager());
    }
    if (_pMouse.x >= 960 + 200 && _pMouse.x <= 960 + 300 && _pMouse.y >= 600 && _pMouse.y <= 700) {
      return (this->volumeUpButtonManager());
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::optionLogicUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
  return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::optionDisplayUpdate(sf::RenderWindow &window)
{
    window.draw(_menuSprite);
    window.draw(_returnMenuSprite);
    window.draw(_volumeDownSprite);
    window.draw(_volumeUpSprite);
    window.draw(_cutVolumeSprite);
    window.draw(_creditsSprite);
    window.draw(_backgroundOptionBar);
    window.draw(_optionBar);
    return (GameConstants::DO_NOTHING);
}
