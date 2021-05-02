/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** maps
*/

#include "GameScreen.hpp"

void GameScreen::initMap0(struct map_s &map)
{
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 600),
        sf::Vector2f(1100, 600), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 600),
        sf::Vector2f(1300, 600), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 600),
        sf::Vector2f(730, 530), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 70),
        sf::Vector2f(900, 725), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 70),
        sf::Vector2f(1500, 725), N_BLUE, false));
}

void GameScreen::initMap1(struct map_s &map)
{
    map.hiddenChar = "66";
    map.hiddenText.setFont(_termFont);
    setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(525, 805), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 50),
        sf::Vector2f(1670, 370), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(75, 50),
        sf::Vector2f(815, 425), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 1000),
        sf::Vector2f(1210, 410), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(180, 50),
        sf::Vector2f(770, 610), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(500, 780), N_BLUE, false));
}

void GameScreen::initMap2(struct map_s &map)
{
    map.hiddenChar = "65";
    map.hiddenText.setFont(_termFont);
    setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(810, 50), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(180, 800),
        sf::Vector2f(275, 390), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 800),
        sf::Vector2f(1000, 520), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(200, 700),
        sf::Vector2f(1530, 300), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 40),
        sf::Vector2f(1730, 300), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 250),
        sf::Vector2f(820, 120), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 400),
        sf::Vector2f(1530, -100), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(80, 40),
        sf::Vector2f(1245, 425), N_BLUE, false));
}

void GameScreen::initMap3(struct map_s &map)
{
    map.hiddenChar = "78";
    map.hiddenText.setFont(_termFont);
    setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(787, 390), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(40, 800),
        sf::Vector2f(430, 300), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 60),
        sf::Vector2f(290, 410), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 60),
        sf::Vector2f(160, 550), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 60),
        sf::Vector2f(290, 690), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(875, 500), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1140, 325), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1300, 515), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(755, 340), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(515, 690), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1580, 500), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1540, 270), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(690, 155), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1100, 770), RED, true));
}

void GameScreen::initMap4(struct map_s &map)
{
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(670, 700),
        sf::Vector2f(1220, -10), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(680, 700),
        sf::Vector2f(0, -10), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(520, 100),
        sf::Vector2f(690, 160), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(520, 100),
        sf::Vector2f(690, 400), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(520, 100),
        sf::Vector2f(690, 640), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(900, 190), GREY, true));
}

void GameScreen::initMap5(struct map_s &map)
{
    map.hiddenChar = "65";
    map.hiddenText.setFont(_termFont);
    setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(90, 805), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(1820, -10), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(700, 100),
        sf::Vector2f(200, 210), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(700, 100),
        sf::Vector2f(200, 700), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(700, 100),
        sf::Vector2f(200, 445), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(900, 190), GREY, true));
}

void GameScreen::initMap6(struct map_s &map)
{
    map.hiddenChar = "78";
    map.hiddenText.setFont(_termFont);
    setString(map.hiddenChar, map.hiddenText, sf::Vector2f(811, 806),
        sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(1720, 150), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(450, 700), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(650, 600), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(850, 500), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(1050, 400), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(1250, 300), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(1620, 150), N_BLUE, false));
}

void GameScreen::initMap7(struct map_s &map)
{
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 320),
        sf::Vector2f(1720, -20), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 350),
        sf::Vector2f(1720, 550), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(500, 300), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(500, 500), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(500, 700), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(600, 400), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(400, 600), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(200, 25),
        sf::Vector2f(800, 275), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(78, 25),
        sf::Vector2f(1000, 275), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(640, 25),
        sf::Vector2f(1080, 275), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(920, 25),
        sf::Vector2f(800, 550), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 300),
        sf::Vector2f(750, -10), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(750, 200), GREY, true));
}

void GameScreen::initMap8(struct map_s &map)
{
    map.hiddenChar = "65";
    map.hiddenText.setFont(_termFont);
    setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(873, 589), sf::Color(180, 180, 180, 200));

    for (size_t i = 0; i < 6; ++i) {
        map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 550 - i * 100),
            sf::Vector2f(500 + 220 * i, -10), GREY, true));
        map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 2000),
            sf::Vector2f(500 + 220 * i, 700 - 60 * i), GREY, true));
    }
}

void GameScreen::initMap9(__attribute__((unused)) struct map_s &map)
{}