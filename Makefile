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
		ViewEvent.cpp
GAME= game.cpp Hero.cpp Character.cpp EventRefresh.cpp Star.cpp
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

Box.o: Box.h Position.h
Character.o: EventOut.h Event.h LogManager.h Manager.h Object.h Position.h
Character.o: Sprite.h Frame.h Box.h ObjectList.h ObjectListIterator.h
Character.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Character.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Character.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Character.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Character.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Character.o: /usr/include/sys/types.h /usr/include/machine/types.h
Character.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Character.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Character.h
Character.o: EventCollision.h /usr/include/stdlib.h
Character.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
Character.o: WorldManager.h GraphicsManager.h /usr/include/curses.h
Character.o: /usr/include/ncurses_dll.h /usr/include/unctrl.h EventStep.h
Character.o: EventRefresh.h
Clock.o: Clock.h /usr/include/time.h /usr/include/_ansi.h
Clock.o: /usr/include/newlib.h /usr/include/sys/config.h
Clock.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Clock.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Clock.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Clock.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Clock.o: /usr/include/sys/types.h /usr/include/machine/types.h
Event.o: Event.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h Sprite.h
EventCollision.o: Frame.h Box.h LogManager.h Manager.h ObjectList.h
EventCollision.o: ObjectListIterator.h /usr/include/stdio.h
EventCollision.o: /usr/include/_ansi.h /usr/include/newlib.h
EventCollision.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
EventCollision.o: /usr/include/sys/features.h /usr/include/sys/reent.h
EventCollision.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
EventCollision.o: /usr/include/machine/_default_types.h
EventCollision.o: /usr/include/sys/lock.h /usr/include/sys/types.h
EventCollision.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
EventCollision.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
EventCollision.o: /usr/include/bits/wordsize.h
EventKeyboard.o: EventKeyboard.h Event.h LogManager.h Manager.h Object.h
EventKeyboard.o: Position.h Sprite.h Frame.h Box.h ObjectList.h
EventKeyboard.o: ObjectListIterator.h /usr/include/stdio.h
EventKeyboard.o: /usr/include/_ansi.h /usr/include/newlib.h
EventKeyboard.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
EventKeyboard.o: /usr/include/sys/features.h /usr/include/sys/reent.h
EventKeyboard.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
EventKeyboard.o: /usr/include/machine/_default_types.h
EventKeyboard.o: /usr/include/sys/lock.h /usr/include/sys/types.h
EventKeyboard.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
EventKeyboard.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
EventKeyboard.o: /usr/include/bits/wordsize.h
EventMouse.o: EventMouse.h Event.h
EventOut.o: EventOut.h Event.h
EventRefresh.o: EventRefresh.h Event.h Object.h Position.h Sprite.h Frame.h
EventRefresh.o: Box.h
EventStep.o: EventStep.h Event.h
Frame.o: Frame.h
GameManager.o: GameManager.h Manager.h Object.h Position.h Event.h Sprite.h
GameManager.o: Frame.h Box.h ObjectList.h ObjectListIterator.h
GameManager.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
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
GameManager.o: /usr/include/unctrl.h InputManager.h ResourceManager.h
GameManager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
GameManager.o: /usr/include/stdlib.h /usr/include/machine/stdlib.h
GameManager.o: /usr/include/alloca.h
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
GraphicsManager.o: Manager.h Object.h Position.h Event.h Sprite.h Frame.h
GraphicsManager.o: Box.h ObjectList.h ObjectListIterator.h LogManager.h
GraphicsManager.o: Utility.h
Hero.o: EventStep.h Event.h Hero.h EventKeyboard.h Object.h Position.h
Hero.o: Sprite.h Frame.h Box.h EventCollision.h EventMouse.h GameManager.h
Hero.o: Manager.h ObjectList.h ObjectListIterator.h /usr/include/time.h
Hero.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Hero.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Hero.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Hero.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Hero.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Hero.o: /usr/include/sys/types.h /usr/include/machine/types.h
Hero.o: GraphicsManager.h /usr/include/curses.h /usr/include/ncurses_dll.h
Hero.o: /usr/include/stdio.h /usr/include/sys/stdio.h
Hero.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Hero.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h LogManager.h
Hero.o: WorldManager.h EventRefresh.h Character.h ResourceManager.h
InputManager.o: InputManager.h Manager.h Object.h Position.h Event.h Sprite.h
InputManager.o: Frame.h Box.h ObjectList.h ObjectListIterator.h
InputManager.o: GraphicsManager.h /usr/include/curses.h
InputManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
InputManager.o: /usr/include/_ansi.h /usr/include/newlib.h
InputManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
InputManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
InputManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
InputManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
InputManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
InputManager.o: /usr/include/unctrl.h EventKeyboard.h EventMouse.h
InputManager.o: LogManager.h
LogManager.o: LogManager.h Manager.h Object.h Position.h Event.h Sprite.h
LogManager.o: Frame.h Box.h ObjectList.h ObjectListIterator.h
LogManager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
LogManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
LogManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
LogManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
LogManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Utility.h
Manager.o: Manager.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
Manager.o: ObjectList.h ObjectListIterator.h /usr/include/stdio.h
Manager.o: /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/types.h /usr/include/machine/types.h
Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Object.o: Object.h Position.h Event.h Sprite.h Frame.h Box.h WorldManager.h
Object.o: Manager.h ObjectList.h ObjectListIterator.h LogManager.h
Object.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Object.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Object.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Object.o: /usr/include/sys/types.h /usr/include/machine/types.h
Object.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Object.o: /usr/include/stdint.h /usr/include/bits/wordsize.h EventStep.h
Object.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
Object.o: EventMouse.h EventKeyboard.h InputManager.h GraphicsManager.h
Object.o: /usr/include/curses.h /usr/include/ncurses_dll.h
Object.o: /usr/include/unctrl.h /usr/include/math.h
ObjectList.o: ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ObjectList.o: ObjectListIterator.h LogManager.h Manager.h
ObjectList.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
ObjectList.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ObjectList.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ObjectList.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ObjectList.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ObjectList.o: /usr/include/sys/types.h /usr/include/machine/types.h
ObjectList.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
ObjectList.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h Sprite.h Frame.h Box.h /usr/include/stdio.h
ObjectListIterator.o: /usr/include/_ansi.h /usr/include/newlib.h
ObjectListIterator.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ObjectListIterator.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ObjectListIterator.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ObjectListIterator.o: /usr/include/machine/_default_types.h
ObjectListIterator.o: /usr/include/sys/lock.h /usr/include/sys/types.h
ObjectListIterator.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ObjectListIterator.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
ObjectListIterator.o: /usr/include/bits/wordsize.h
Position.o: Position.h LogManager.h Manager.h Object.h Event.h Sprite.h
Position.o: Frame.h Box.h ObjectList.h ObjectListIterator.h
Position.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Position.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Position.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Position.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Position.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Position.o: /usr/include/sys/types.h /usr/include/machine/types.h
Position.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Position.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ResourceManager.o: GraphicsManager.h /usr/include/curses.h
ResourceManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
ResourceManager.o: /usr/include/_ansi.h /usr/include/newlib.h
ResourceManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ResourceManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ResourceManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ResourceManager.o: /usr/include/machine/_default_types.h
ResourceManager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
ResourceManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ResourceManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
ResourceManager.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
ResourceManager.o: Manager.h Object.h Position.h Event.h Sprite.h Frame.h
ResourceManager.o: Box.h ObjectList.h ObjectListIterator.h LogManager.h
ResourceManager.o: ResourceManager.h /usr/include/stdlib.h
ResourceManager.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
Sprite.o: Sprite.h Frame.h GraphicsManager.h /usr/include/curses.h
Sprite.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Sprite.o: /usr/include/_ansi.h /usr/include/newlib.h
Sprite.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Sprite.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Sprite.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Sprite.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Sprite.o: /usr/include/sys/types.h /usr/include/machine/types.h
Sprite.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Sprite.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Sprite.o: /usr/include/unctrl.h Manager.h Object.h Position.h Event.h Box.h
Sprite.o: ObjectList.h ObjectListIterator.h
Star.o: EventOut.h Event.h GraphicsManager.h /usr/include/curses.h
Star.o: /usr/include/ncurses_dll.h /usr/include/stdio.h /usr/include/_ansi.h
Star.o: /usr/include/newlib.h /usr/include/sys/config.h
Star.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Star.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Star.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Star.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Star.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Star.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Star.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h Manager.h Object.h
Star.o: Position.h Sprite.h Frame.h Box.h ObjectList.h ObjectListIterator.h
Star.o: LogManager.h Star.h /usr/include/Stdlib.h
Star.o: /usr/include/machine/stdlib.h /usr/include/alloca.h WorldManager.h
Utility.o: Position.h Box.h Object.h Event.h Sprite.h Frame.h WorldManager.h
Utility.o: Manager.h ObjectList.h ObjectListIterator.h /usr/include/time.h
Utility.o: /usr/include/_ansi.h /usr/include/newlib.h
Utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Utility.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
Utility.o: /usr/include/machine/types.h /usr/include/stdio.h
Utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ViewEvent.o: ViewEvent.h Event.h
ViewObject.o: ViewObject.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ViewObject.o: Utility.h ViewEvent.h
WorldManager.o: WorldManager.h Manager.h Object.h Position.h Event.h Sprite.h
WorldManager.o: Frame.h Box.h ObjectList.h ObjectListIterator.h LogManager.h
WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h
WorldManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Utility.h
WorldManager.o: EventCollision.h GraphicsManager.h /usr/include/curses.h
WorldManager.o: /usr/include/ncurses_dll.h /usr/include/unctrl.h EventOut.h
WorldManager.o: ViewObject.h
game.o: Clock.h /usr/include/time.h /usr/include/_ansi.h
game.o: /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
game.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
game.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
game.o: /usr/include/sys/lock.h /usr/include/machine/time.h
game.o: /usr/include/sys/types.h /usr/include/machine/types.h LogManager.h
game.o: Manager.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
game.o: ObjectList.h ObjectListIterator.h /usr/include/stdio.h
game.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
game.o: /usr/include/stdint.h /usr/include/bits/wordsize.h GameManager.h
game.o: WorldManager.h Hero.h EventKeyboard.h EventCollision.h EventMouse.h
game.o: Character.h Star.h ResourceManager.h /usr/include/unistd.h
game.o: /usr/include/sys/unistd.h
