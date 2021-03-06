CC	=	g++
CFLAGS	=	-W	-Wall	-ansi	-std=c++11	-g
LIBS	=
LDFLAGS	= `sdl2-config --cflags --libs`
INCLUDES	= graphic.hpp commun.hpp logic.hpp player.hpp events.hpp
EXEC	=	main
SRC	=	main.cpp graphic.cpp logic.cpp player.cpp events.cpp
OBJ	=	$(SRC:.cpp=.o)

all:	$(EXEC)
main:	$(OBJ)
	$(CC)	$(CFLAGS)	$(INCLUDES)	-o	$@	$^	$(LIBS)	$(LDFLAGS)
%.o:	%.c
	$(CC)	$(CFLAGS)	-o	$@	-c	$<
clean:
	rm	-rf	*.o	*~
rmall:	clean
	rm	-rf	$(EXEC)