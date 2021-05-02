/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreen
*/

#include "GameScreen.hpp"

GameScreen::GameScreen()
{
    srandom(time(NULL));
    _isPause = false;

    initTerminal();
    initPauseMenu();
    initPlayer();

    // Banana
    _bananaClock.restart();
    _isRainingBananas = false;
    _nbBananas = 0;
    linkSpriteTexture(_bananaSprite, _bananaTexture, "assets/banana.png");
    for (size_t i = 0; i < NB_BANANAS; ++i) {
        sf::Sprite newBanana(_bananaSprite);
        newBanana.setPosition(sf::Vector2f(random() % 1920, 0));
        newBanana.setScale(sf::Vector2f(0.2, 0.2));
        _bananas.push_back(newBanana);
    }
    _fadeRectangle.setSize(sf::Vector2f(1920, 1080));
    _fadeRectangle.setPosition(sf::Vector2f(0, 0));
    _fadeRectangle.setFillColor(sf::Color(0, 0, 0, 0));

    // Game Music
    _gameMusic = new sf::Music();
    _gameMusic->openFromFile("audio/gameMusic.ogg");
    _gameMusic->setLoop(true);
    _volume = 50;
    _isTermSound = false;
    _isEndTermSound = false;
    _gameMusic->setVolume(_volume);
    sf::SoundBuffer *_termBuffer = new sf::SoundBuffer();
    _termBuffer->loadFromFile("audio/terminalSound.ogg");
    _termSound.setBuffer(*_termBuffer);
    sf::SoundBuffer *_typeBuffer = new sf::SoundBuffer();
    _typeBuffer->loadFromFile("audio/typeSound.ogg");
    _typeSound.setBuffer(*_typeBuffer);
    sf::SoundBuffer *_validBuffer = new sf::SoundBuffer();
    _validBuffer->loadFromFile("audio/endTerminalSound.ogg");
    _validSound.setBuffer(*_validBuffer);

    // Chrono
    _fontBis.loadFromFile("assets/graff.ttf");
    _levelText.setFont(_fontBis);
    _chronoText.setFont(_fontBis);

    // Death
    linkSpriteTexture(_deathSprite, _deathTexture, "assets/death.png");
    _deathSprite.setPosition(sf::Vector2f(1745, 10));
    _deathText.setFont(_fontBis);

    // Tutorial
    linkSpriteTexture(_tutorialSprite, _tutorialTexture, "assets/tKey.png");
    _tutorialSprite.setPosition(sf::Vector2f(250, 450));
    _tutorialText1.setFont(_termFont);
    _tutorialText2.setFont(_termFont);

    initInputs();
    initMaps();

    _groundTexture.loadFromFile("assets/ground.png");
    _groundRect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1920, 1080));
    _groundSprite.setTexture(_groundTexture);
    _groundSprite.setTextureRect(_groundRect);
    _groundSprite.setPosition(sf::Vector2f(0, 0));
    _groundClock.restart();

    initBackground();
}

GameScreen::~GameScreen()
{}

GameConstants::SCREEN_RETURN GameScreen::eventUpdate(sf::RenderWindow &window)
{
    _terminalInput = sf::Keyboard::isKeyPressed(sf::Keyboard::T);
    _endTerminalInput = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    _pauseInput = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
        return (GameConstants::EXIT_GAME);
    }
    if (_isTerminal) {
        return (terminalEventUpdate(window));
    }
    if (_isPause) {
        return (pauseEventUpdate(window));
    }
    _leftInput = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    _rightInput = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    _upInput = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    while (window.pollEvent(_event));

    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN GameScreen::logicUpdate(sf::RenderWindow &window)
{
    sf::Vector2f stkPosition = _playerSprite.getPosition();

    if (!_calledOnce) {
        _gameMusic->play();
        _chronoClock.restart();
        _calledOnce = true;
    }
    updateSprites();

    if (_terminalInput) {
        if (!_isTermSound) {
            _termSound.play();
            _isTermSound = true;
        }
        _isTerminal = true;
        _terminalInput = false;
    }
    if (_isTerminal) {
        return (terminalLogicUpdate(window));
    }

    if (_pauseInput) {
        _isPause = true;
    }
    if (_isPause) {
        return (pauseLogicUpdate(window));
    }

    updateMovements();
    if (_playerSprite.getPosition().x < -30) {
        if (_currentMap == 0) {
            printf("\n--- À demain ---\n\n");
            return (GameConstants::EXIT_GAME);
        } else {
            _currentMap -= 1;
            _playerSprite.setPosition(sf::Vector2f(1920, _playerSprite.getPosition().y));
        }
    } else if (_playerSprite.getPosition().x > 1950 && _currentMap < NB_MAPS - 1) {
        _playerSprite.setPosition(sf::Vector2f(0, _playerSprite.getPosition().y));
        _currentMap += 1;
    }

    if (!checkHitboxes()) {
        _playerSprite.setPosition(stkPosition);
    }

    updateTexts();

    if (_isRainingBananas && _bananaClock.getElapsedTime().asMilliseconds() > 80) {
        if (updateBananas() == GameConstants::CHANGE_TO_CREDITS) {
            return (GameConstants::CHANGE_TO_CREDITS);
        }
        _bananaClock.restart();
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN GameScreen::displayUpdate(sf::RenderWindow &window)
{
    window.draw(_sBackground);
    if (_isRainingBananas) {
        for (size_t i = 0; i < _bananas.size(); ++i) {
            window.draw(_bananas[i]);
        }
    }

    if (_currentMap == 0) {
        window.draw(_tutorialText1);
        window.draw(_tutorialText2);
        window.draw(_tutorialSprite);
    }

    window.draw(_maps[_currentMap].hiddenText);
    for (auto it = _maps[_currentMap].blocks.begin(); it != _maps[_currentMap].blocks.end(); it++)
        window.draw(it->get()->getShape());
    window.draw(_groundSprite);
    if (_isTerminal) {
        drawTerminal(window);
    }
    window.draw(_playerSprite);
    window.draw(_chronoText);
    window.draw(_deathText);
    window.draw(_deathSprite);
    window.draw(_levelText);
    if (_isPause) {
        drawPause(window);
    }
    window.draw(_fadeRectangle);
    return (GameConstants::DO_NOTHING);
}