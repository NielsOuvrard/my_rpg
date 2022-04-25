##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## un makefile de qualité spécial RPG
##

SRC = 	src/*.c \
		src/create/*.c \
		src/editor/*.c \
		src/inventory/*.c \
		src/level1/*.c \
		src/npc/*c

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

BINARY = my_rpg

LIB = -I./include/ -L./lib/my/ -lm -lmy

all:
		@cp ./lib/my/my.h include/my.h
		@gcc -c lib/my/*.c
		@ar rc lib/my/libmy.a *.o
		@cp ./lib/my/libmy.a lib/libmy.a
		@gcc -o $(BINARY) -g $(SRC) $(LIB) -g3 $(CSFML)
		@chmod 777 $(BINARY)
		@make clean

clean:
		rm -f *.o

fclean: clean
		rm $(BINARY)
		rm lib/my/libmy.a
		rm lib/libmy.a

re:	fclean all

auteur:
		@echo $(USER) > auteur

push:
		@git add .
		@git status
		@git commit -m "push automatique"
		@git push

mac_del:
		rm -Rf *.dSYM
		rm -Rf .vscode
		rm -Rf .DS_Store

vg_del:
		rm vgcore.*

fm_push:
		make fclean
		make mac_del
		make push

.PHONY: all clean fclean re push mac_del vg_del fm_push
