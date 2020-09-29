CC	=	g++
CFLAGS	=	-W	-Wall	-ansi	-std=c++11	-g
LIBS	=
LDFLAGS	=
INCLUDES	=
EXEC	=	main
SRC	=	main.cpp
OBJ	=	$(SRC:.c=.o)

all:	$(EXEC)
main:	$(OBJ)
	$(CC)	$(CFLAGS)	$(INCLUDES)	-o	$@	$^	$(LIBS)	$(LDFLAGS)
%.o:	%.c
	$(CC)	$(CFLAGS)	-o	$@	-c	$<
clean:
	rm	-rf	*.o	*~
mrproper:	clean
	rm	-rf	$(EXEC)