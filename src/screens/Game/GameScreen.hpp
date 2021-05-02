/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreen
*/

#ifndef GAMESCREEN_HPP_
#define GAMESCREEN_HPP_

#include <memory>
#include <string>
#include <iostream>

#include "../../ISCreen.hpp"
#include "Block.hpp"

class GameScreen : public ISCreen {
    public:
        GameScreen();
        ~GameScreen();
        bool checkHitboxes(void);
        void animPlayer(void);
        std::string getChronoFormat(float seconds);

        GameConstants::SCREEN_RETURN eventUpdate(sf::RenderWindow &window) override;
        GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window) override;
        GameConstants::SCREEN_RETURN displayUpdate(sf::RenderWindow &window) override;

        void linkSpriteTexture(sf::Sprite &sprite, sf::Texture &texture,
            std::string const asset);
        void setVolume(float volume);
    private:
        static const size_t FLOOR_LEVEL = 850;

        sf::Event _event;
        sf::Font _fontBis;

        sf::Text _levelText;

        void initInputs();

        void updateSprites();
        void updateMovements();
        void updateTexts();

        // Tutorial
        sf::Text _tutorialText1;
        sf::Text _tutorialText2;
        sf::Sprite _tutorialSprite;
        sf::Texture _tutorialTexture;

        // Game Music
        sf::Music   *_gameMusic;
        sf::Sound   _termSound;
        sf::Sound   _typeSound;
        sf::Sound   _validSound;
        float   _volume;
        bool    _isTermSound;
        bool    _isEndTermSound;

        // Bananas
        bool _isRainingBananas;
        static const size_t NB_BANANAS = 150;
        GameConstants::SCREEN_RETURN updateBananas();
        sf::Sprite _bananaSprite;
        std::vector<sf::Sprite> _bananas;
        sf::Texture _bananaTexture;
        sf::Clock _bananaClock;
        size_t _nbBananas;
        sf::RectangleShape _fadeRectangle;

        // Death
        int _deathCount;
        sf::Sprite _deathSprite;
        sf::Texture _deathTexture;
        sf::Text _deathText;
        sf::Clock _deathClock;

        // Chrono
        sf::Clock _chronoClock;
        sf::Text _chronoText;
        bool _calledOnce;

        // Player
        void initPlayer();
        void restartPlayer();
        sf::Sprite _playerSprite;
        sf::Texture _playerTexture;
        sf::IntRect _playerRect;

        // Utils
        void setString(const std::string &value, sf::Text &text,
            const sf::Vector2f &position, const sf::Color &color);

        // Background
        void initBackground();
        sf::IntRect _backgroundRect;
        sf::Texture _background;
        sf::Sprite _sBackground;
        size_t _currentBackground;
        void updateBackground();
        sf::Clock _bgClock;

        //Ground
        sf::Texture _groundTexture;
        sf::Sprite _groundSprite;
        sf::IntRect _groundRect;
        sf::Clock _groundClock;

        // Moving
        bool _rightInput;
        bool _leftInput;

        // Jumping
        void jumpManagement(void);
        bool canGoDown();
        int _jumpHigh;
        bool _hasJump;
        bool _upInput;

        // Pause menu
        void initPauseMenu();
        bool _pauseInput;
        bool _isPause;

        sf::RectangleShape _blackSquare;
        sf::Vector2i _posMouse;

        sf::Texture _continueButtonTexture;
        sf::Sprite _continueButtonSprite;
        sf::Texture _returnMenuTexture;
        sf::Sprite _returnMenuSprite;
        sf::Texture _quitButtonTexture;
        sf::Sprite _quitButtonSprite;

        GameConstants::SCREEN_RETURN pauseLogicUpdate(sf::RenderWindow &window);
        GameConstants::SCREEN_RETURN pauseEventUpdate(sf::RenderWindow &window);
        void drawPause(sf::RenderWindow &window);

        // Terminal mode
        void initTerminal();
        bool _terminalInput;
        bool _endTerminalInput;
        bool _isTerminal;
        sf::RectangleShape _terminalLayer;
        sf::Text _termInput;
        std::string _currentInput;
        sf::Font _termFont;
        GameConstants::SCREEN_RETURN terminalEventUpdate(sf::RenderWindow &window);
        GameConstants::SCREEN_RETURN terminalLogicUpdate(sf::RenderWindow &window);
        void drawTerminal(sf::RenderWindow &window);

        // Blocks
        void initMaps();
        void switchBlocks();

        // Maps
        #define NB_MAPS 10
        size_t _currentMap;
        struct map_s {
            std::vector<std::shared_ptr<Block>> blocks;
            sf::Text hiddenText;
            std::string hiddenChar;
        } _maps[NB_MAPS];

        void initMap0(struct map_s &map);
        void initMap1(struct map_s &map);
        void initMap2(struct map_s &map);
        void initMap3(struct map_s &map);
        void initMap4(struct map_s &map);
        void initMap5(struct map_s &map);
        void initMap6(struct map_s &map);
        void initMap7(struct map_s &map);
        void initMap8(struct map_s &map);
        void initMap9(struct map_s &map);

        void (GameScreen:: *mapFuncs[NB_MAPS])(struct map_s &map) = {
            &GameScreen::initMap0,
            &GameScreen::initMap1,
            &GameScreen::initMap2,
            &GameScreen::initMap3,
            &GameScreen::initMap4,
            &GameScreen::initMap5,
            &GameScreen::initMap6,
            &GameScreen::initMap7,
            &GameScreen::initMap8,
            &GameScreen::initMap9,
        };
};

#endif /* !GameSCREEN_HPP_ */
