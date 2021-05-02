/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** constants
*/

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <iostream>

namespace GameConstants {
	static const size_t WINDOW_X = 1920;
	static const size_t WINDOW_Y = 1080;

	enum SCREEN_RETURN {
		CHANGE_TO_GAME,
		CHANGE_TO_MENU,
		EXIT_GAME,
		CHANGE_TO_CREDITS,
		DO_NOTHING,
		MUTE_GAME_VOLUME,
		DEMUTE_GAME_VOLUME
	};
}

#endif /* !CONSTANTS_H_ */
