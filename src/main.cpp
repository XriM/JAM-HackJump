/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** main
*/

#include "Game.hpp"

static void display_usage(void)
{
  printf("\nPlatform game created with SFML.\nUSAGE\n\t./HackJump\nOPTIONS\n\t-h print the usage and quit.\n\n");
}

int main(int ac, char **av)
{
  if (ac == 2 && av[1] == std::string("-h")) {
    display_usage();
    return (0);
  }
  Game game;

  game.run();
}