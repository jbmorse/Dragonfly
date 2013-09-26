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
		EventKeyboard.cpp EventMouse.cpp EventCollision.cpp EventOut.cpp
GAME= game.cpp Hero.cpp
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

Clock.o: Clock.h /usr/include/time.h /usr/include/_ansi.h
Clock.o: /usr/include/newlib.h /usr/include/sys/config.h
Clock.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Clock.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Clock.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Clock.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Clock.o: /usr/include/sys/types.h /usr/include/machine/types.h
Event.o: Event.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
GameManager.o: GameManager.h Manager.h Object.h Position.h Event.h
GameManager.o: ObjectList.h ObjectListIterator.h /usr/include/time.h
GameManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GameManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GameManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
GameManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
GameManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameManager.o: /usr/include/machine/time.h /usr/include/sys/types.h
GameManager.o: /usr/include/machine/types.h LogManager.h /usr/include/stdio.h
GameManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
GameManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Clock.h
GameManager.o: EventStep.h WorldManager.h GraphicsManager.h
GameManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
GameManager.o: /usr/include/unctrl.h InputManager.h /usr/include/unistd.h
GameManager.o: /usr/include/sys/unistd.h
GraphicsManager.o: GraphicsManager.h /usr/include/curses.h
GraphicsManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
GraphicsManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GraphicsManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GraphicsManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
GraphicsManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
GraphicsManager.o: /usr/include/machine/_default_types.h
GraphicsManager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
GraphicsManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
GraphicsManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
GraphicsManager.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
GraphicsManager.o: Manager.h Object.h Position.h Event.h ObjectList.h
GraphicsManager.o: ObjectListIterator.h
InputManager.o: InputManager.h Manager.h Object.h Position.h Event.h
InputManager.o: ObjectList.h ObjectListIterator.h GraphicsManager.h
InputManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
InputManager.o: /usr/include/stdio.h /usr/include/_ansi.h
InputManager.o: /usr/include/newlib.h /usr/include/sys/config.h
InputManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
InputManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
InputManager.o: /usr/include/machine/_types.h
InputManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
InputManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
InputManager.o: /usr/include/unctrl.h EventKeyboard.h EventMouse.h
LogManager.o: LogManager.h Manager.h Object.h Position.h Event.h ObjectList.h
LogManager.o: ObjectListIterator.h /usr/include/stdio.h /usr/include/_ansi.h
LogManager.o: /usr/include/newlib.h /usr/include/sys/config.h
LogManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
LogManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
LogManager.o: /usr/include/machine/_types.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
LogManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Utility.h
Manager.o: Manager.h Object.h Position.h Event.h ObjectList.h
Manager.o: ObjectListIterator.h /usr/include/stdio.h /usr/include/_ansi.h
Manager.o: /usr/include/newlib.h /usr/include/sys/config.h
Manager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Manager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Manager.o: /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/types.h /usr/include/machine/types.h
Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Object.o: Object.h Position.h Event.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h LogManager.h /usr/include/stdio.h
Object.o: /usr/include/_ansi.h /usr/include/newlib.h
Object.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Object.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Object.o: /usr/include/sys/types.h /usr/include/machine/types.h
Object.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Object.o: /usr/include/stdint.h /usr/include/bits/wordsize.h EventStep.h
Object.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
Object.o: EventMouse.h EventKeyboard.h InputManager.h /usr/include/math.h
ObjectList.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
ObjectList.o: LogManager.h Manager.h /usr/include/stdio.h
ObjectList.o: /usr/include/_ansi.h /usr/include/newlib.h
ObjectList.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ObjectList.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ObjectList.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ObjectList.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ObjectList.o: /usr/include/sys/types.h /usr/include/machine/types.h
ObjectList.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
ObjectList.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h /usr/include/stdio.h /usr/include/_ansi.h
ObjectListIterator.o: /usr/include/newlib.h /usr/include/sys/config.h
ObjectListIterator.o: /usr/include/machine/ieeefp.h
ObjectListIterator.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ObjectListIterator.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ObjectListIterator.o: /usr/include/machine/_default_types.h
ObjectListIterator.o: /usr/include/sys/lock.h /usr/include/sys/types.h
ObjectListIterator.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ObjectListIterator.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
ObjectListIterator.o: /usr/include/bits/wordsize.h
Position.o: Position.h LogManager.h Manager.h Object.h Event.h ObjectList.h
Position.o: ObjectListIterator.h /usr/include/stdio.h /usr/include/_ansi.h
Position.o: /usr/include/newlib.h /usr/include/sys/config.h
Position.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Position.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Position.o: /usr/include/machine/_types.h
Position.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Position.o: /usr/include/sys/types.h /usr/include/machine/types.h
Position.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Position.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Utility.o: Position.h /usr/include/time.h /usr/include/_ansi.h
Utility.o: /usr/include/newlib.h /usr/include/sys/config.h
Utility.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Utility.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Utility.o: /usr/include/machine/_types.h
Utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
Utility.o: /usr/include/machine/types.h /usr/include/stdio.h
Utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
WorldManager.o: WorldManager.h Manager.h Object.h Position.h Event.h
WorldManager.o: ObjectList.h ObjectListIterator.h LogManager.h
WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h
WorldManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Utility.h
WorldManager.o: EventCollision.h
game.o: Clock.h /usr/include/time.h /usr/include/_ansi.h
game.o: /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
game.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
game.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
game.o: /usr/include/sys/lock.h /usr/include/machine/time.h
game.o: /usr/include/sys/types.h /usr/include/machine/types.h LogManager.h
game.o: Manager.h Object.h Position.h Event.h ObjectList.h
game.o: ObjectListIterator.h /usr/include/stdio.h /usr/include/sys/stdio.h
game.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
game.o: /usr/include/bits/wordsize.h GameManager.h WorldManager.h
game.o: /usr/include/unistd.h /usr/include/sys/unistd.h
