##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

OUT = clip

SRCNAMES =	error_handling\
			backrooms\
			display_steps\
			update_clock\
			struct/init_struct\
			struct/init_clock\
			struct/init_sprite\
			struct/init_sound\
			struct/init_texts\
			struct/init_window\
			struct/free_struct\

## DON'T TOUCH BELOW THIS LINE ##

SRCMAIN =	$(SRCNAMES)\
			main\

CC = gcc
CFLAGS = -l csfml-graphics -l csfml-system -l csfml-audio
CPPFLAGS = -I./include/

SRC = $(addsuffix .c, $(addprefix src/, $(SRCMAIN)))
OBJ = $(SRC:.c=.o)

DESTDIR = /usr/local

TEMPFILES =     *~\
                *\#

VGFILES =       vgcore.*

all:	compile install

compile: $(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(OUT)

install: compile
	@sudo mkdir -p $(DESTDIR)/lib/backrooms/
	@sudo cp -r ./* $(DESTDIR)/lib/backrooms/
	@sudo cp $(OUT) $(DESTDIR)/bin
	@echo
	@echo "Installation done :)"
	@echo "You can now launch the game by typing '$(OUT)'"
	@echo "My GitHub : github.com/Happneel"

uninstall:
	@sudo rm -rf $(DESTDIR)/lib/backrooms/
	@sudo rm -f $(DESTDIR)/bin/$(OUT)
	@echo
	@echo "Uninstallation done :)"
	@echo "My GitHub : github.com/Happneel"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(TEMPFILES)
	@$(RM) src/$(TEMPFILES)
	@$(RM) $(VGFILES) src/$(VGFILES)
fclean: clean
	@$(RM) $(OUT)

re: fclean all

.PHONY: all compile clean fclean re
