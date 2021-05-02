/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** MenuScreen
*/

#include <unistd.h>
#include "MenuScreen.hpp"

MenuScreen::MenuScreen()
{
  // sprites and texture
  this->linkSpriteTexture(_menuSprite, _menuTexture, "assets/fondMenu.png");
  _menuSprite.setPosition(sf::Vector2f(0, 0));
  this->linkSpriteTexture(_playSprite, _playTexture, "assets/playButton1.png");
  _playSprite.setPosition(sf::Vector2f(300, 600));
  this->linkSpriteTexture(_quitSprite, _quitTexture, "assets/quitButton1.png");
  _quitSprite.setPosition(sf::Vector2f(1300, 600));
  this->linkSpriteTexture(_optionSprite, _optionTexture, "assets/optionButton1.png");
  _optionSprite.setPosition(sf::Vector2f(800, 850));
  this->linkSpriteTexture(_creditsSprite, _creditsTexture, "assets/creditsButton.png");
  _creditsSprite.setPosition(sf::Vector2f(GameConstants::WINDOW_X / 2 + 150, 750));
  this->linkSpriteTexture(_returnMenuSprite, _returnMenuTexture, "assets/menubutton.png");
  _returnMenuSprite.setPosition(sf::Vector2f(GameConstants::WINDOW_X / 2 - 450, 750));
  this->linkSpriteTexture(_volumeDownSprite, _volumeDownTexture, "assets/volumeDown.png");
  _volumeDownSprite.setPosition(sf::Vector2f(GameConstants::WINDOW_X / 2 - 300, 600));
  this->linkSpriteTexture(_volumeUpSprite, _volumeUpTexture, "assets/volumeUp.png");
  _volumeUpSprite.setPosition(sf::Vector2f(GameConstants::WINDOW_X / 2 + 200, 600));
  this->linkSpriteTexture(_cutVolumeSprite, _cutVolumeTexture, "assets/cutVolume.png");
  _cutVolumeSprite.setPosition(sf::Vector2f(GameConstants::WINDOW_X / 2 - 50, 750));


  // buttons states textures
  _cutVolume2Texture.loadFromFile("assets/cutVolume2.png");
  _play2Texture.loadFromFile("assets/playButton2.png");
  _quit2Texture.loadFromFile("assets/quitButton2.png");
  _option2Texture.loadFromFile("assets/optionButton2.png");
  _play3Texture.loadFromFile("assets/playButton3.png");
  _quit3Texture.loadFromFile("assets/quitButton3.png");
  _option3Texture.loadFromFile("assets/optionButton3.png");
  this->statePlay = this->stateQuit = this->stateOption = 0;
  _isOption = false;

  // bar of volume
  _volume = 50;
  _isMuted = false;
  _optionBar.setSize(sf::Vector2f(_volume * 3, 50));
  _optionBar.setFillColor(sf::Color::White);
  _optionBar.setPosition(sf::Vector2f(960 - 150, 625));
  _backgroundOptionBar.setSize(sf::Vector2f(320, 70));
  _backgroundOptionBar.setFillColor(sf::Color::Black);
  _backgroundOptionBar.setPosition(sf::Vector2f(960 - 160, 615));


  // fadeout init
  _rectShape.setSize(sf::Vector2f(1920, 1080));
  _rectShape.setFillColor(sf::Color(255, 255, 255, 0));

  //audio init
  _optionClock.restart();
  _menuMusic = new sf::Music();
  _menuMusic->openFromFile("audio/menuMusic.ogg");
  _menuMusic->setLoop(true);
  _menuMusic->setVolume(_volume);
  _menuMusic->play();
  _isMusic = false;
  sf::SoundBuffer *_playBuffer = new sf::SoundBuffer();
  _playBuffer->loadFromFile("audio/startGame.ogg");
  _playSound.setBuffer(*_playBuffer);
  sf::SoundBuffer *_mouseBuffer = new sf::SoundBuffer();
  _mouseBuffer->loadFromFile("audio/mouseSound.ogg");
  _mouseSound.setBuffer(*_mouseBuffer);
  _mouseSound.setVolume(_volume / 2);
  sf::SoundBuffer *_selectBuffer = new sf::SoundBuffer();
  _selectBuffer->loadFromFile("audio/selectSound.ogg");
  _selectSound.setBuffer(*_selectBuffer);
}

MenuScreen::~MenuScreen()
{}

void MenuScreen::linkSpriteTexture(sf::Sprite &sprite, sf::Texture &texture, std::string const asset) {
	if (!texture.loadFromFile(asset)) {
			exit (84);
	}
	sprite.setTexture(texture);
}

GameConstants::SCREEN_RETURN MenuScreen::eventUpdate(sf::RenderWindow &window)
{
  if (_isOption) {
    return (optionEventUpdate(window));
  }
  if (_isMusic == false) {
    _menuMusic->play();
    _isMusic = true;
  }
  while (window.pollEvent(_event));
  // managing the fade out when play is clicked
  if (_fadeOutProgress <= 650 && _fadeOutProgress > 0) {
    _fadeOutProgress -= 1;
    return (GameConstants::DO_NOTHING);
  } else if (_fadeOutProgress <= 0) {
    _playSound.stop();
    _isMusic = false;
    return (GameConstants::CHANGE_TO_GAME);
  }
  _pMouse = sf::Mouse::getPosition(window);

	// event managing (clicks, mouse area, Escape...)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return (GameConstants::EXIT_GAME);
	if (_pMouse.x >= 300 && _pMouse.x <= 600 && _pMouse.y >= 600 && _pMouse.y <= 720) {
			return (this->playButtonManager(window));
	} else if (_pMouse.x >= 1300 && _pMouse.x <= 1600 && _pMouse.y >= 600 && _pMouse.y <= 720) {
			return (this->quitButtonManager(window));
	} else if (_pMouse.x >= 800 && _pMouse.x <= 1100 && _pMouse.y >= 850 && _pMouse.y <= 970) {
			return (this->optionButtonManager(window));
	}
	// if mouse is away of area button, return to basic states
	this->stateQuit = this->statePlay = this->stateOption = 0;
	_playSprite.setTexture(_playTexture);
	_quitSprite.setTexture(_quitTexture);
  _optionSprite.setTexture(_optionTexture);
	return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::logicUpdate(sf::RenderWindow &window)
{
  if (_isOption) {
    return (optionLogicUpdate(window));
  }
	if (_fadeOutProgress <= 650) {
		_opacity += 0.38;
		_rectShape.setFillColor(sf::Color(255, 255, 255, _opacity));
	}
	return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN MenuScreen::displayUpdate(sf::RenderWindow &window)
{
	window.draw(_menuSprite);
  if (!_isOption) {
	  window.draw(_playSprite);
	  window.draw(_quitSprite);
	  window.draw(_optionSprite);
  } else {
    optionDisplayUpdate(window);
  }
	if (_fadeOutProgress <= 650) {
		window.draw(_rectShape);
	}
	return (GameConstants::DO_NOTHING);
}