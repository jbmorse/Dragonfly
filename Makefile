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
		EventView.cpp
GAME= game.cpp Saucer.cpp Hero.cpp Bullet.cpp Explosion.cpp Points.cpp Star.cpp GameOver.cpp GameStart.cpp Laser.cpp
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
Bullet.o: Bullet.h EventCollision.h Event.h Object.h Position.h Sprite.h
Bullet.o: Frame.h Box.h EventOut.h LogManager.h Manager.h ObjectList.h
Bullet.o: ObjectListIterator.h /usr/include/stdio.h /usr/include/_ansi.h
Bullet.o: /usr/include/newlib.h /usr/include/sys/config.h
Bullet.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Bullet.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Bullet.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Bullet.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Bullet.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Bullet.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Bullet.o: /usr/include/bits/wordsize.h ResourceManager.h WorldManager.h
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
EventNuke.o: EventNuke.h Event.h Object.h Position.h Sprite.h Frame.h Box.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
EventView.o: EventView.h Event.h
Explosion.o: EventStep.h Event.h Explosion.h Object.h Position.h Sprite.h
Explosion.o: Frame.h Box.h ResourceManager.h Manager.h ObjectList.h
Explosion.o: ObjectListIterator.h GraphicsManager.h /usr/include/curses.h
Explosion.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Explosion.o: /usr/include/_ansi.h /usr/include/newlib.h
Explosion.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Explosion.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Explosion.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Explosion.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Explosion.o: /usr/include/sys/types.h /usr/include/machine/types.h
Explosion.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Explosion.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Explosion.o: /usr/include/unctrl.h LogManager.h WorldManager.h
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
GameOver.o: EventStep.h Event.h GameManager.h Manager.h Object.h Position.h
GameOver.o: Sprite.h Frame.h Box.h ObjectList.h ObjectListIterator.h
GameOver.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
GameOver.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GameOver.o: /usr/include/sys/features.h /usr/include/sys/reent.h
GameOver.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
GameOver.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameOver.o: /usr/include/machine/time.h /usr/include/sys/types.h
GameOver.o: /usr/include/machine/types.h GameOver.h ViewObject.h LogManager.h
GameOver.o: /usr/include/stdio.h /usr/include/sys/stdio.h
GameOver.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
GameOver.o: /usr/include/bits/wordsize.h ResourceManager.h WorldManager.h
GameStart.o: EventKeyboard.h Event.h GameManager.h Manager.h Object.h
GameStart.o: Position.h Sprite.h Frame.h Box.h ObjectList.h
GameStart.o: ObjectListIterator.h /usr/include/time.h /usr/include/_ansi.h
GameStart.o: /usr/include/newlib.h /usr/include/sys/config.h
GameStart.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
GameStart.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GameStart.o: /usr/include/machine/_types.h
GameStart.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameStart.o: /usr/include/machine/time.h /usr/include/sys/types.h
GameStart.o: /usr/include/machine/types.h GameStart.h ViewObject.h
GameStart.o: GraphicsManager.h /usr/include/curses.h
GameStart.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
GameStart.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
GameStart.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
GameStart.o: /usr/include/unctrl.h Hero.h LogManager.h Points.h
GameStart.o: ResourceManager.h Saucer.h EventCollision.h WorldManager.h
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
Hero.o: Bullet.h EventCollision.h Event.h Object.h Position.h Sprite.h
Hero.o: Frame.h Box.h EventNuke.h EventStep.h EventView.h Explosion.h
Hero.o: ResourceManager.h Manager.h ObjectList.h ObjectListIterator.h Hero.h
Hero.o: EventKeyboard.h GameManager.h /usr/include/time.h
Hero.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Hero.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Hero.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Hero.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Hero.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Hero.o: /usr/include/sys/types.h /usr/include/machine/types.h GameOver.h
Hero.o: ViewObject.h GraphicsManager.h /usr/include/curses.h
Hero.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Hero.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Hero.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Hero.o: /usr/include/unctrl.h Laser.h LogManager.h WorldManager.h
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
Laser.o: EventStep.h Event.h GraphicsManager.h /usr/include/curses.h
Laser.o: /usr/include/ncurses_dll.h /usr/include/stdio.h /usr/include/_ansi.h
Laser.o: /usr/include/newlib.h /usr/include/sys/config.h
Laser.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Laser.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Laser.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Laser.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Laser.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Laser.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Laser.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h Manager.h
Laser.o: Object.h Position.h Sprite.h Frame.h Box.h ObjectList.h
Laser.o: ObjectListIterator.h Laser.h EventCollision.h LogManager.h
Laser.o: ResourceManager.h WorldManager.h
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
Points.o: EventStep.h Event.h GraphicsManager.h /usr/include/curses.h
Points.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Points.o: /usr/include/_ansi.h /usr/include/newlib.h
Points.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Points.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Points.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Points.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Points.o: /usr/include/sys/types.h /usr/include/machine/types.h
Points.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Points.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Points.o: /usr/include/unctrl.h Manager.h Object.h Position.h Sprite.h
Points.o: Frame.h Box.h ObjectList.h ObjectListIterator.h Points.h
Points.o: ViewObject.h
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
Saucer.o: EventNuke.h Event.h Object.h Position.h Sprite.h Frame.h Box.h
Saucer.o: EventOut.h EventView.h Explosion.h ResourceManager.h Manager.h
Saucer.o: ObjectList.h ObjectListIterator.h LogManager.h /usr/include/stdio.h
Saucer.o: /usr/include/_ansi.h /usr/include/newlib.h
Saucer.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Saucer.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Saucer.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Saucer.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Saucer.o: /usr/include/sys/types.h /usr/include/machine/types.h
Saucer.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Saucer.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Points.h
Saucer.o: ViewObject.h Saucer.h EventCollision.h /usr/include/stdlib.h
Saucer.o: /usr/include/machine/stdlib.h /usr/include/alloca.h WorldManager.h
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
Star.o: LogManager.h ResourceManager.h Star.h /usr/include/Stdlib.h
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
ViewObject.o: ViewObject.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ViewObject.o: Utility.h EventView.h GraphicsManager.h /usr/include/curses.h
ViewObject.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
ViewObject.o: /usr/include/_ansi.h /usr/include/newlib.h
ViewObject.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ViewObject.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ViewObject.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ViewObject.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ViewObject.o: /usr/include/sys/types.h /usr/include/machine/types.h
ViewObject.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
ViewObject.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ViewObject.o: /usr/include/unctrl.h Manager.h ObjectList.h
ViewObject.o: ObjectListIterator.h WorldManager.h
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
game.o: GameManager.h Manager.h Object.h Position.h Event.h Sprite.h Frame.h
game.o: Box.h ObjectList.h ObjectListIterator.h /usr/include/time.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
game.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
game.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
game.o: /usr/include/sys/lock.h /usr/include/machine/time.h
game.o: /usr/include/sys/types.h /usr/include/machine/types.h Gamestart.h
game.o: ViewObject.h GraphicsManager.h /usr/include/curses.h
game.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
game.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
game.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
game.o: /usr/include/unctrl.h LogManager.h ResourceManager.h Star.h
game.o: /usr/include/stdlib.h /usr/include/machine/stdlib.h
game.o: /usr/include/alloca.h Utility.h
