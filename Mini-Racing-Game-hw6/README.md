Mini Racing Game
	
	This program implements a mini racing game for 2 players. The players move along their separate roads by tossing a dice. If a player ends up on a penalty point, they take 2 steps backward. The first player to reach or pass the finish line wins the game.

Instructions : 

Before running the program, ensure you have watched the video that shows the playing of the game for a better understanding.

Implementation Details : 

1 - The game area is represented by a 15x30 2D array.
2 - Each element in the array represents an item in the game, such as player positions, finish lines, and penalty points.
3 - There are 3 penalty points for Player 1 and 6 penalty points for Player 2.
4 - The positions of penalty points:
	* Player 1: (1, 14), (7, 28), (13, 14)
	* Player 2: (3, 10), (3, 18), (5, 26), (10, 26), (11, 10), (11, 18)
5 - The finish line positions: Player 1 (2, 1) and Player 2 (4, 3).
6 - Initial player positions: Player 1 (1, 1) and Player 2 (3, 3).

Functions :

- void printMap(): Prints the game area with different colors for better visualization.
- int dice(): Returns a random integer in the range [1,6] for dice tossing.
- int startGame(): Decides, according to dice numbers, and returns the number of the player who will start the game.

Running the Game :

	$ make