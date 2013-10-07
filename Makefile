#
# Makefile for development of game using Dragonfly
#
# 'make' to build executable
# 'make depend' to generate new dependency list
# 'make clean' to remove all constructed files
#
# Variables of interest:
#   GAMESRC is the source code files for the game being developed
#   GAME is the game main() source
#   DEBUG can be set to -DDEBUG to enable various debug flags
#

CC= g++ 
PLATFORM= -DCYGWIN		# uncomment for cygwin
#PLATFORM= -DMACOS  		# uncomment for macos
LDFLAGS= -lncurses -lrt	# uncomment linux/cygwin
#LDFLAGS= -lncurses 		# uncomment for macos
INCPATH= include		# path to engine includes
ENG= lib/libdragonfly.a		# dragonfly engine
GAMEENG= Manager.cpp LogManager.cpp Utility.cpp Clock.cpp GameManager.cpp \
		Position.cpp Object.cpp ObjectList.cpp ObjectListIterator.cpp Event.cpp \
		EventStep.cpp WorldManager.cpp GraphicsManager.cpp InputManager.cpp \
		EventKeyboard.cpp EventMouse.cpp EventCollision.cpp EventOut.cpp \
		Frame.cpp Sprite.cpp ResourceManager.cpp Box.cpp ViewObject.cpp \
		EventView.cpp SceneGraph.cpp
GAME= game.cpp Saucer.cpp Hero.cpp Bullet.cpp Explosion.cpp Points.cpp Star.cpp GameOver.cpp GameStart.cpp Laser.cpp EventNuke.cpp
EXECUTABLE= game
OBJECTS= $(GAMEENG:.cpp=.o)

all: $(EXECUTABLE) Makefile

$(EXECUTABLE): $(OBJECTS) $(GAME) $(GAMEENG)
	$(CC) $(GAME) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o: 
	$(CC) -c $(DEBUG) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Character.o: Character.h /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Character.o: /usr/include/_ansi.h /usr/include/newlib.h
Character.o: /usr/include/sys/config.h /usr/include/sys/features.h
Character.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Character.o: /usr/include/machine/_types.h
Character.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Character.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
Character.o: EventRefresh.h
EventRefresh.o: EventRefresh.h
Hero.o: Hero.h EventRefresh.h Character.h /usr/include/time.h
Hero.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Hero.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Hero.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Hero.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Hero.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Hero.o: /usr/include/sys/types.h /usr/include/machine/types.h
Star.o: Star.h /usr/include/Stdlib.h /usr/include/machine/ieeefp.h
Star.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Star.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Star.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Star.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Star.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
game.o: Hero.h Character.h Star.h /usr/include/stdio.h /usr/include/_ansi.h
game.o: /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
game.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
game.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
game.o: /usr/include/sys/lock.h /usr/include/sys/types.h
game.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
game.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
game.o: /usr/include/bits/wordsize.h /usr/include/unistd.h
game.o: /usr/include/sys/unistd.h
