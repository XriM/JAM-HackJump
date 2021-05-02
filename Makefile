##
## EPITECH PROJECT, 2021
## any
## File description:
## Makefile
##

CXX	?=		g++

# Binaries
NAME = HackJump

# Flags
CXXFLAGS +=	-std=c++17 -W -Wall -Wextra -g # -Werror
CPPFLAGS += 	-I src/ -I include/
LDLIBS +=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC =	src/main.cpp							\
		src/Game.cpp							\
		\
		src/screens/Game/GameScreen.cpp			\
		src/screens/Game/GameScreenPause.cpp	\
		src/screens/Game/GameScreenTerm.cpp		\
		src/screens/Game/GameScreenUpdates.cpp	\
		src/screens/Game/GameScreenUtils.cpp	\
		src/screens/Game/InitGameScreen.cpp		\
		src/screens/Game/PhysicsGameScreen.cpp	\
		src/screens/Game/Block.cpp				\
		src/screens/Game/maps.cpp				\
		\
		src/screens/MenuScreen.cpp				\
		src/screens/MenuScreenUtils.cpp			\
		\
		src/screens/CreditsScreen.cpp			\

# Object files
OBJ =		$(SRC:.cpp=.o)

# Rules
all:		$(NAME)

$(NAME):	$(OBJ) $(OBJM)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

debug:		CFLAGS += $(DEBUG)
debug:		fclean $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME) $(NAME_TEST)

re:			fclean all

.PHONY:		all test tests_run cov debug clean fclean re
