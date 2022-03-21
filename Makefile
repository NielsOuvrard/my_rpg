##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## un makefile de qualité
##

all:
		@cp ./lib/my/my.h include/my.h
		@gcc -c lib/my/*.c
		@ar rc lib/my/libmy.a *.o
		@cp ./lib/my/libmy.a lib/libmy.a
		@gcc -o my_rpg -g src/*.c -I./include/ -L./lib/my/ -lm -lmy -g3\
		-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
		@chmod 777 my_rpg
		@make clean

clean:
		@rm -f *.o

fclean: clean
		@rm my_rpg
		@rm lib/my/libmy.a
		@rm lib/libmy.a

re:	fclean all

auteur:
	echo $(USER) > auteur

push:
		git add .
		git status
		git commit -m "push automatique"
		git push

.PHONY: all clean fclean re push
# le %p c'est un hexadecimal avec un long
