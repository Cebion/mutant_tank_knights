PREFIX  = /mnt/utmp/mtanks
EXE = mtanks
RM = rm -f
INSTALL_PROG = install -m 755 -s
STRIP=$(CXX:%g++=%strip)

# Add SDL dependency
LDFLAGS +=-lSDL_gfx -lSDL_image -lSDL_mixer $(shell sdl-config --libs)
CFLAGS +=$(shell sdl-config --cflags) -g

# Define targets
SRCS=$(shell echo *.c)
OBJS=$(SRCS:%.c=%.o)

all : $(EXE)

.c.o:
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $*.c -o $*.o 
.cpp.o:
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $*.cpp -o $*.o 

$(EXE) : $(OBJS)
	$(CXX) $(OBJS) -o $(EXE) $(LDFLAGS)
#	$(STRIP) $(EXE)

install : $(EXE)
	$(INSTALL_PROG) $(EXE) $(PREFIX)/bin

uninstall :
	$(RM) $(PREFIX)/bin/$(EXE)

clean :
	$(RM) $(OBJS) $(EXE)

.PHONY:clean install uninstall all
