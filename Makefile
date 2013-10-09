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
ENGPATH= Dragonfly_Engine
GAMEENG= Manager.cpp LogManager.cpp Utility.cpp Clock.cpp GameManager.cpp \
		Position.cpp Object.cpp ObjectList.cpp ObjectListIterator.cpp Event.cpp \
		EventStep.cpp WorldManager.cpp GraphicsManager.cpp InputManager.cpp \
		EventKeyboard.cpp EventMouse.cpp EventCollision.cpp EventOut.cpp \
		Frame.cpp Sprite.cpp ResourceManager.cpp Box.cpp ViewObject.cpp \
		EventView.cpp SceneGraph.cpp
GAMESRC= Character.cpp EventRefresh.cpp Hero.cpp Star.cpp BossSkull.cpp Pointstemp.cpp \
		EvilCharacter.cpp
GAME= game.cpp
EXECUTABLE= game
OBJECTS= $(addprefix $(ENGPATH)/, $(GAMEENG:.cpp=.o)) $(GAMESRC:.cpp=.o)
VPATH= $(ENGPATH)

all: $(EXECUTABLE) Makefile

$(EXECUTABLE): $(OBJECTS) $(GAME) $(GAMEENG)
	$(CC) $(GAME) $(OBJECTS) $(LDFLAGS) -I$(ENGPATH) -o $@

.cpp.o: 
	$(CC) -c $(DEBUG) -I$(ENGPATH) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core log.txt Makefile.bak *~

depend: 
	makedepend *.cpp $(ENGPATH)/*.cpp 2> /dev/null

# DO NOT DELETE

BossSkull.o: BossSkull.h /usr/include/Stdlib.h /usr/include/machine/ieeefp.h
BossSkull.o: /usr/include/_ansi.h /usr/include/newlib.h
BossSkull.o: /usr/include/sys/config.h /usr/include/sys/features.h
BossSkull.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
BossSkull.o: /usr/include/machine/_types.h
BossSkull.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
BossSkull.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
BossSkull.o: /usr/include/stdlib.h
Character.o: Character.h /usr/include/stdlib.h EventRefresh.h
EventRefresh.o: EventRefresh.h
Hero.o: Hero.h EventRefresh.h Character.h /usr/include/time.h
Hero.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Hero.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Hero.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Hero.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Hero.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Hero.o: /usr/include/sys/types.h /usr/include/machine/types.h
Hero.o: /usr/include/math.h
Pointstemp.o: Pointstemp.h
Star.o: Star.h /usr/include/Stdlib.h /usr/include/machine/ieeefp.h
Star.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Star.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Star.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Star.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Star.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
game.o: Hero.h Character.h Star.h BossSkull.h Pointstemp.h
game.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
game.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/sys/types.h /usr/include/machine/types.h
game.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
game.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
game.o: /usr/include/unistd.h /usr/include/sys/unistd.h
Dragonfly_Engine/Box.o: Dragonfly_Engine/Box.h Dragonfly_Engine/Position.h
Dragonfly_Engine/Clock.o: Dragonfly_Engine/Clock.h /usr/include/time.h
Dragonfly_Engine/Clock.o: /usr/include/_ansi.h /usr/include/newlib.h
Dragonfly_Engine/Clock.o: /usr/include/sys/config.h
Dragonfly_Engine/Clock.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/Clock.o: /usr/include/sys/features.h
Dragonfly_Engine/Clock.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Dragonfly_Engine/Clock.o: /usr/include/machine/_types.h
Dragonfly_Engine/Clock.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/Clock.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Dragonfly_Engine/Clock.o: /usr/include/sys/types.h
Dragonfly_Engine/Clock.o: /usr/include/machine/types.h
Dragonfly_Engine/Event.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/EventCollision.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/EventCollision.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/EventCollision.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/EventCollision.o: /usr/include/newlib.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/config.h
Dragonfly_Engine/EventCollision.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/features.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/reent.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/_types.h
Dragonfly_Engine/EventCollision.o: /usr/include/machine/_types.h
Dragonfly_Engine/EventCollision.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/lock.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/types.h
Dragonfly_Engine/EventCollision.o: /usr/include/machine/types.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/stdio.h
Dragonfly_Engine/EventCollision.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/EventCollision.o: /usr/include/stdint.h
Dragonfly_Engine/EventCollision.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/EventKeyboard.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/EventKeyboard.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/newlib.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/config.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/features.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/reent.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/_types.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/machine/_types.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/lock.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/types.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/machine/types.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/stdio.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/stdint.h
Dragonfly_Engine/EventKeyboard.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/EventMouse.o: Dragonfly_Engine/EventMouse.h
Dragonfly_Engine/EventMouse.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/EventOut.o: Dragonfly_Engine/EventOut.h
Dragonfly_Engine/EventOut.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/EventStep.o: Dragonfly_Engine/EventStep.h
Dragonfly_Engine/EventStep.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/EventView.o: Dragonfly_Engine/EventView.h
Dragonfly_Engine/EventView.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/Frame.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/GameManager.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/GameManager.o: /usr/include/time.h /usr/include/_ansi.h
Dragonfly_Engine/GameManager.o: /usr/include/newlib.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/config.h
Dragonfly_Engine/GameManager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/features.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/reent.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/_types.h
Dragonfly_Engine/GameManager.o: /usr/include/machine/_types.h
Dragonfly_Engine/GameManager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/lock.h
Dragonfly_Engine/GameManager.o: /usr/include/machine/time.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/types.h
Dragonfly_Engine/GameManager.o: /usr/include/machine/types.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/GameManager.o: /usr/include/stdio.h /usr/include/sys/stdio.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/GameManager.o: /usr/include/stdint.h
Dragonfly_Engine/GameManager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/Clock.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/EventStep.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/GameManager.o: /usr/include/curses.h
Dragonfly_Engine/GameManager.o: /usr/include/ncurses_dll.h
Dragonfly_Engine/GameManager.o: /usr/include/unctrl.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/InputManager.h
Dragonfly_Engine/GameManager.o: Dragonfly_Engine/ResourceManager.h
Dragonfly_Engine/GameManager.o: /usr/include/unistd.h
Dragonfly_Engine/GameManager.o: /usr/include/sys/unistd.h
Dragonfly_Engine/GameManager.o: /usr/include/stdlib.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/EventStep.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/GameManager.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/Frame.h Dragonfly_Engine/Box.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/GameOver.o: /usr/include/time.h /usr/include/_ansi.h
Dragonfly_Engine/GameOver.o: /usr/include/newlib.h /usr/include/sys/config.h
Dragonfly_Engine/GameOver.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/GameOver.o: /usr/include/sys/features.h
Dragonfly_Engine/GameOver.o: /usr/include/sys/reent.h
Dragonfly_Engine/GameOver.o: /usr/include/sys/_types.h
Dragonfly_Engine/GameOver.o: /usr/include/machine/_types.h
Dragonfly_Engine/GameOver.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/GameOver.o: /usr/include/sys/lock.h
Dragonfly_Engine/GameOver.o: /usr/include/machine/time.h
Dragonfly_Engine/GameOver.o: /usr/include/sys/types.h
Dragonfly_Engine/GameOver.o: /usr/include/machine/types.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/GameOver.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/ViewObject.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/GameOver.o: /usr/include/stdio.h /usr/include/sys/stdio.h
Dragonfly_Engine/GameOver.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/GameOver.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/ResourceManager.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/GameOver.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/EventKeyboard.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/GameManager.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/Frame.h Dragonfly_Engine/Box.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/GameStart.o: /usr/include/time.h /usr/include/_ansi.h
Dragonfly_Engine/GameStart.o: /usr/include/newlib.h /usr/include/sys/config.h
Dragonfly_Engine/GameStart.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/features.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/reent.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/_types.h
Dragonfly_Engine/GameStart.o: /usr/include/machine/_types.h
Dragonfly_Engine/GameStart.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/lock.h
Dragonfly_Engine/GameStart.o: /usr/include/machine/time.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/types.h
Dragonfly_Engine/GameStart.o: /usr/include/machine/types.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/GameStart.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/ViewObject.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/GameStart.o: /usr/include/curses.h
Dragonfly_Engine/GameStart.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/stdio.h
Dragonfly_Engine/GameStart.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/GameStart.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/GameStart.o: /usr/include/unctrl.h Hero.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/ResourceManager.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/GameStart.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/curses.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/ncurses_dll.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/newlib.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/config.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/features.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/reent.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/_types.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/machine/_types.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/lock.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/types.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/machine/types.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/stdio.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/stdint.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/GraphicsManager.o: /usr/include/unctrl.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/GraphicsManager.o: Dragonfly_Engine/Utility.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/InputManager.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/InputManager.o: /usr/include/curses.h
Dragonfly_Engine/InputManager.o: /usr/include/ncurses_dll.h
Dragonfly_Engine/InputManager.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/InputManager.o: /usr/include/newlib.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/config.h
Dragonfly_Engine/InputManager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/features.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/reent.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/_types.h
Dragonfly_Engine/InputManager.o: /usr/include/machine/_types.h
Dragonfly_Engine/InputManager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/lock.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/types.h
Dragonfly_Engine/InputManager.o: /usr/include/machine/types.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/stdio.h
Dragonfly_Engine/InputManager.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/InputManager.o: /usr/include/stdint.h
Dragonfly_Engine/InputManager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/InputManager.o: /usr/include/unctrl.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/EventKeyboard.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/EventMouse.h
Dragonfly_Engine/InputManager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/LogManager.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/LogManager.o: /usr/include/newlib.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/config.h
Dragonfly_Engine/LogManager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/features.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/reent.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/_types.h
Dragonfly_Engine/LogManager.o: /usr/include/machine/_types.h
Dragonfly_Engine/LogManager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/lock.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/types.h
Dragonfly_Engine/LogManager.o: /usr/include/machine/types.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/stdio.h
Dragonfly_Engine/LogManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/LogManager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/LogManager.o: Dragonfly_Engine/Utility.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/Frame.h Dragonfly_Engine/Box.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/EventView.h
Dragonfly_Engine/Manager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/Manager.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/Manager.o: /usr/include/newlib.h /usr/include/sys/config.h
Dragonfly_Engine/Manager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/Manager.o: /usr/include/sys/features.h
Dragonfly_Engine/Manager.o: /usr/include/sys/reent.h
Dragonfly_Engine/Manager.o: /usr/include/sys/_types.h
Dragonfly_Engine/Manager.o: /usr/include/machine/_types.h
Dragonfly_Engine/Manager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/Manager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Dragonfly_Engine/Manager.o: /usr/include/machine/types.h
Dragonfly_Engine/Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Dragonfly_Engine/Manager.o: /usr/include/stdint.h
Dragonfly_Engine/Manager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/Event.h Dragonfly_Engine/Sprite.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/Frame.h Dragonfly_Engine/Box.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/LogManager.h /usr/include/stdio.h
Dragonfly_Engine/Object.o: /usr/include/_ansi.h /usr/include/newlib.h
Dragonfly_Engine/Object.o: /usr/include/sys/config.h
Dragonfly_Engine/Object.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/Object.o: /usr/include/sys/features.h
Dragonfly_Engine/Object.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Dragonfly_Engine/Object.o: /usr/include/machine/_types.h
Dragonfly_Engine/Object.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/Object.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Dragonfly_Engine/Object.o: /usr/include/machine/types.h
Dragonfly_Engine/Object.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Dragonfly_Engine/Object.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/EventStep.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/GameManager.h /usr/include/time.h
Dragonfly_Engine/Object.o: /usr/include/machine/time.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/EventMouse.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/EventKeyboard.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/InputManager.h
Dragonfly_Engine/Object.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/Object.o: /usr/include/curses.h /usr/include/ncurses_dll.h
Dragonfly_Engine/Object.o: /usr/include/unctrl.h Dragonfly_Engine/Utility.h
Dragonfly_Engine/Object.o: /usr/include/math.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/ObjectList.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/ObjectList.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/ObjectList.o: /usr/include/newlib.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/config.h
Dragonfly_Engine/ObjectList.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/features.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/reent.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/_types.h
Dragonfly_Engine/ObjectList.o: /usr/include/machine/_types.h
Dragonfly_Engine/ObjectList.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/lock.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/types.h
Dragonfly_Engine/ObjectList.o: /usr/include/machine/types.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/stdio.h
Dragonfly_Engine/ObjectList.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/ObjectList.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/ObjectListIterator.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/stdio.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/_ansi.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/newlib.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/config.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/features.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/reent.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/_types.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/machine/_types.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/lock.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/types.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/machine/types.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/stdio.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/stdint.h
Dragonfly_Engine/ObjectListIterator.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/Frame.h Dragonfly_Engine/Box.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/Position.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/Position.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/Position.o: /usr/include/newlib.h /usr/include/sys/config.h
Dragonfly_Engine/Position.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/Position.o: /usr/include/sys/features.h
Dragonfly_Engine/Position.o: /usr/include/sys/reent.h
Dragonfly_Engine/Position.o: /usr/include/sys/_types.h
Dragonfly_Engine/Position.o: /usr/include/machine/_types.h
Dragonfly_Engine/Position.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/Position.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Dragonfly_Engine/Position.o: /usr/include/machine/types.h
Dragonfly_Engine/Position.o: /usr/include/sys/stdio.h
Dragonfly_Engine/Position.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/Position.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/ResourceManager.o: /usr/include/curses.h
Dragonfly_Engine/ResourceManager.o: /usr/include/ncurses_dll.h
Dragonfly_Engine/ResourceManager.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/ResourceManager.o: /usr/include/newlib.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/config.h
Dragonfly_Engine/ResourceManager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/features.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/reent.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/_types.h
Dragonfly_Engine/ResourceManager.o: /usr/include/machine/_types.h
Dragonfly_Engine/ResourceManager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/lock.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/types.h
Dragonfly_Engine/ResourceManager.o: /usr/include/machine/types.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/stdio.h
Dragonfly_Engine/ResourceManager.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/ResourceManager.o: /usr/include/stdint.h
Dragonfly_Engine/ResourceManager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/ResourceManager.o: /usr/include/unctrl.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/ResourceManager.o: Dragonfly_Engine/ResourceManager.h
Dragonfly_Engine/ResourceManager.o: /usr/include/stdlib.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Utility.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/SceneGraph.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/SceneGraph.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/SceneGraph.o: /usr/include/newlib.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/config.h
Dragonfly_Engine/SceneGraph.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/features.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/reent.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/_types.h
Dragonfly_Engine/SceneGraph.o: /usr/include/machine/_types.h
Dragonfly_Engine/SceneGraph.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/lock.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/types.h
Dragonfly_Engine/SceneGraph.o: /usr/include/machine/types.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/stdio.h
Dragonfly_Engine/SceneGraph.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/SceneGraph.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/Sprite.h Dragonfly_Engine/Frame.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/Sprite.o: /usr/include/curses.h /usr/include/ncurses_dll.h
Dragonfly_Engine/Sprite.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/Sprite.o: /usr/include/newlib.h /usr/include/sys/config.h
Dragonfly_Engine/Sprite.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/Sprite.o: /usr/include/sys/features.h
Dragonfly_Engine/Sprite.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Dragonfly_Engine/Sprite.o: /usr/include/machine/_types.h
Dragonfly_Engine/Sprite.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/Sprite.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Dragonfly_Engine/Sprite.o: /usr/include/machine/types.h
Dragonfly_Engine/Sprite.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Dragonfly_Engine/Sprite.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Dragonfly_Engine/Sprite.o: /usr/include/unctrl.h Dragonfly_Engine/Manager.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/Event.h Dragonfly_Engine/Box.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/Sprite.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/Box.h Dragonfly_Engine/Object.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/Utility.o: Dragonfly_Engine/SceneGraph.h /usr/include/time.h
Dragonfly_Engine/Utility.o: /usr/include/_ansi.h /usr/include/newlib.h
Dragonfly_Engine/Utility.o: /usr/include/sys/config.h
Dragonfly_Engine/Utility.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/Utility.o: /usr/include/sys/features.h
Dragonfly_Engine/Utility.o: /usr/include/sys/reent.h
Dragonfly_Engine/Utility.o: /usr/include/sys/_types.h
Dragonfly_Engine/Utility.o: /usr/include/machine/_types.h
Dragonfly_Engine/Utility.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/Utility.o: /usr/include/sys/lock.h
Dragonfly_Engine/Utility.o: /usr/include/machine/time.h
Dragonfly_Engine/Utility.o: /usr/include/sys/types.h
Dragonfly_Engine/Utility.o: /usr/include/machine/types.h /usr/include/stdio.h
Dragonfly_Engine/Utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Dragonfly_Engine/Utility.o: /usr/include/stdint.h
Dragonfly_Engine/Utility.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/ViewObject.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Utility.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/EventView.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/ViewObject.o: /usr/include/curses.h
Dragonfly_Engine/ViewObject.o: /usr/include/ncurses_dll.h
Dragonfly_Engine/ViewObject.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/ViewObject.o: /usr/include/newlib.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/config.h
Dragonfly_Engine/ViewObject.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/features.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/reent.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/_types.h
Dragonfly_Engine/ViewObject.o: /usr/include/machine/_types.h
Dragonfly_Engine/ViewObject.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/lock.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/types.h
Dragonfly_Engine/ViewObject.o: /usr/include/machine/types.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/stdio.h
Dragonfly_Engine/ViewObject.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Dragonfly_Engine/ViewObject.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/ViewObject.o: /usr/include/unctrl.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/ViewObject.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/WorldManager.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Manager.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Object.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Position.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Event.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Sprite.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Frame.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Box.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/ObjectList.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/ObjectListIterator.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/SceneGraph.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/LogManager.h
Dragonfly_Engine/WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
Dragonfly_Engine/WorldManager.o: /usr/include/newlib.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/config.h
Dragonfly_Engine/WorldManager.o: /usr/include/machine/ieeefp.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/features.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/reent.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/_types.h
Dragonfly_Engine/WorldManager.o: /usr/include/machine/_types.h
Dragonfly_Engine/WorldManager.o: /usr/include/machine/_default_types.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/lock.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/types.h
Dragonfly_Engine/WorldManager.o: /usr/include/machine/types.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/stdio.h
Dragonfly_Engine/WorldManager.o: /usr/include/sys/cdefs.h
Dragonfly_Engine/WorldManager.o: /usr/include/stdint.h
Dragonfly_Engine/WorldManager.o: /usr/include/bits/wordsize.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/Utility.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/EventCollision.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/GraphicsManager.h
Dragonfly_Engine/WorldManager.o: /usr/include/curses.h
Dragonfly_Engine/WorldManager.o: /usr/include/ncurses_dll.h
Dragonfly_Engine/WorldManager.o: /usr/include/unctrl.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/EventOut.h
Dragonfly_Engine/WorldManager.o: Dragonfly_Engine/ViewObject.h
