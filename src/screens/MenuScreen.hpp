/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** MenuScreen
*/
#include "ISCreen.hpp"

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

class MenuScreen : public ISCreen {
  public:
    MenuScreen();
    ~MenuScreen();
    GameConstants::SCREEN_RETURN    eventUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN    logicUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN    displayUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN    optionEventUpdate(sf::RenderWindow &window);
    GameConstants::SCREEN_RETURN    optionLogicUpdate(sf::RenderWindow &window);
    GameConstants::SCREEN_RETURN    optionDisplayUpdate(sf::RenderWindow &window);
    GameConstants::SCREEN_RETURN    playButtonManager(sf::RenderWindow &window);
    GameConstants::SCREEN_RETURN    quitButtonManager(sf::RenderWindow &window);
    GameConstants::SCREEN_RETURN    optionButtonManager(sf::RenderWindow &window);
    GameConstants::SCREEN_RETURN    returnMenuButtonManager();
    GameConstants::SCREEN_RETURN    volumeDownButtonManager();
    GameConstants::SCREEN_RETURN    cutVolumeButtonManager();
    GameConstants::SCREEN_RETURN    volumeUpButtonManager();
    GameConstants::SCREEN_RETURN    creditsButtonManager();
    void                            linkSpriteTexture(sf::Sprite &sprite, sf::Texture &texture, std::string const asset);

  private:
		sf::Event                       _event;
    sf::Vector2i                    _pMouse;

    // fade out
    double                          _opacity = 0;
    int                             _fadeOutProgress = 651;
    sf::RectangleShape              _rectShape;

    // all menus textures and sprites
    sf::Texture                     _menuTexture;
    sf::Sprite                      _menuSprite;
    sf::Texture                     _playTexture;
    sf::Sprite                      _playSprite;
    sf::Texture                     _quitTexture;
    sf::Sprite                      _quitSprite;

    //option Textures and sprites
    sf::Texture                     _optionTexture;
    sf::Sprite                      _optionSprite;
    sf::Texture                     _returnMenuTexture;
    sf::Sprite                      _returnMenuSprite;
    sf::Texture                     _volumeDownTexture;
    sf::Sprite                      _volumeDownSprite;
    sf::Texture                     _volumeUpTexture;
    sf::Sprite                      _volumeUpSprite;
    sf::Texture                     _cutVolumeTexture;
    sf::Sprite                      _cutVolumeSprite;
    sf::Texture                     _creditsTexture;
    sf::Sprite                      _creditsSprite;
    sf::RectangleShape              _backgroundOptionBar;
    sf::RectangleShape              _optionBar;
    sf::Clock                       _optionClock;

    // states when mouse is on button
    sf::Texture                     _cutVolume2Texture;
    sf::Texture                     _play2Texture;
    sf::Texture                     _quit2Texture;
    sf::Texture                     _play3Texture;
    sf::Texture                     _quit3Texture;
    sf::Texture                     _option2Texture;
    sf::Texture                     _option3Texture;
    int                             statePlay;
    int                             stateQuit;
    int                             stateOption;
    bool                            _ispressed;
    bool                            _isOption;

    // menus sounds
    bool                            _isMuted;
    bool                            _isMusic;
    float                           _volume;
    sf::Sound                       _playSound;
    sf::Sound                       _mouseSound;
    sf::Sound                       _selectSound;
    sf::Music                       *_menuMusic;
};

#endif /* !MENUSCREEN_HPP_ */
