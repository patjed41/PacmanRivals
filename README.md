# Pacman Rivals

Group project for the [Software engineering (pol. Inżynieria oprogramowania)](https://usosweb.mimuw.edu.pl/kontroler.php?_action=katalog2/przedmioty/pokazPrzedmiot&prz_kod=1000-214bIOP) course taken in the 2021/2022 summer semester that i participated in.

## Game

### General rules

The game is a variation of the classic Pacman for 2-4 players. The game is played on one computer. The first player to win the specified number of rounds wins the whole game. A single round is won by the first player to score the expected number of points (by collecting coins, killing ghosts and enemies) or the last one alive. Various buffs spawn randomly during the game.

### Maps

There are many different maps that are randomly selected for each round. Every map can appear only once during the game. Some of the maps resemble these from classic Pacman while other maps are a bit crazier.

### Coins

At the beginning of each round there is a coin on every tile that is not a wall. Collecting a coin gives 1 point. Coins do not spawn after beginning of the round.

### Players

Every player controls a pacman of a chosen color. He can be controlled by a keyboard or a controller. Players can also chose their nicknames and controls.

### Ghosts

Pacman dies when he touches a ghost unless he is shielded or in a devouring mode. Ghost spawn at the beginning of the round and do not respawn later. Currently there are 3 types of ghosts:
- `pink` - a ghost that walks randomly
- `yellow` - a ghost that walks left/rigth or up/down until he hits the wall and turns back
- `green` - a ghost that walks the same cycle all the time

### Power ups

Pacman gets a power up when he touches it. Pacman can have only one power up at the same time so if he touches a new power up before expiry of the previous one, the previous one is replaced with the new one. Slow down is the exception to this rule as it is a debuff for other players. Some power ups are passive while the others are usable. Currently there are 9 power ups:
- `spikes` - allows players to place 3 permanent spikes that kill characters
- `slow down` - slows down all other pacmans
- `speed up` - speeds up the pacman
- `bomb` - allows player to place a bomb under his pacman that explodes after 3 seconds and kills characters that are in the area of explosion
- `shield` - saves pacman from everything that could kill him once
- `bullet` - allows pacman to fire a bullet in the direction of walking; the bullet disappears when it hits the wall or another bullet
- `coin multiplier` - increases points received for collecting a coin from 1 to 2
- `walking through walls` - allows pacman to walk through walls and hide behind them
- `gluttony` - sets pacman to devouring mode that allows him to eat ghosts and other pacmans unless they are devouring too

### Points

There are 3 ways to collect points:
- collecting a coin - 1 point
- killing a ghost - 5 points
- killing a player - 10 points

## Technical requirements

1. The game can be played on Linux machine with installed:
- SFML 2.4.2+
- xboxdrv
- CMake 3.10.2+

2. The game displays correctly on monitors with resolution at least 1920x1080.

3. The keyboard can be used by up to 2 players. So 3 players need at least 1 controllor (e.g. PlayStation 4, Xbox One) and 4 players need at least 2 controllers. Game can handle up to 4 controllers so no one has to use the keyboard during the game but it is necessary in the main menu and game lobby.


## Installation

1. Clone the repository.

2. If you don't have `SFML` library installed already, you can use this command:

```
sudo apt-get install libsfml-dev
```

3. To build the game go to the `PacmanRivals` directory and execute:

```
mkdir build && cd build && cmake -D CMAKE_BUILD_TYPE=Release .. && make
```
4. If you want to use controllers, connect them to your PC. You can easily find tips how to do it on Linux.

5. Run the game:
```
./PacmanRivals
```

## More about the project

As it was a university project, there were many requirements apart from coding something.

### Documents

We had to make these documents (in polish) during our work:
- [Vision document](https://github.com/patjed41/PacmanRivals/blob/main/docs/vision_doc.md)
- [Non-functional requirements](https://github.com/patjed41/PacmanRivals/blob/main/docs/wymagania_niefunkcjonalne.md)
- [2 chosen UML diagrams](https://github.com/patjed41/PacmanRivals/tree/main/docs/uml_diagrams)
- [Presentation](https://github.com/patjed41/PacmanRivals/tree/main/docs/prezentation.pptx)

### Testing

Continuous integration with unit testing and code coverage was obligatory. GitHub workflows file is [here](https://github.com/patjed41/PacmanRivals/blob/main/.github/workflows/CI.yml). The tests are [here](https://github.com/patjed41/PacmanRivals/tree/main/tests).

To run the tests you have to build the project in the Debug mode like this:
```
mkdir build && cd build && cmake -D CMAKE_BUILD_TYPE=Debug .. && make
```
To run tests use (in the `build` directory)
```
make test
```
To check code coverage use (in the `build` directory)
```
make ExperimentalCoverage
```

### Techonogies used
- C++
- CMake
- CTest
- SFML

### Tools used
- CLion
- GitHub
- GitHub Actions
- GitHub Issues

### Value

Project got more than max points, teached us a lot and gave us even more fun :)
