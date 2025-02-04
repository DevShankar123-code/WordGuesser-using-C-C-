# WordGuesser-using-C-C-
The Word Guesser game is a simple console-based game where the player has to guess a hidden word by suggesting letters within a certain number of attempts. The game is inspired by the classic "Hangman" game. The primary objective is to guess the word before running out of allowed attempts.

Features:
Word Selection:

The game selects a word randomly from a predefined list of words.

The selected word is hidden from the player, and only its length is displayed as a series of underscores.

Guessing Letters:

The player inputs one letter at a time.

If the guessed letter is in the word, all occurrences of that letter are revealed in their respective positions.

If the guessed letter is not in the word, the number of remaining attempts decreases.

Tracking Progress:

The game displays the current state of the word with correctly guessed letters revealed and remaining letters as underscores.

The game also displays the number of remaining attempts and the letters that have already been guessed.

Winning and Losing:

The player wins if they guess all the letters in the word before running out of attempts.

The player loses if they run out of attempts before guessing the word.

After the game ends, the player is informed whether they won or lost, and the correct word is revealed.

Implementation Outline:
Define Constants:

Define constants for the maximum number of attempts and the list of words.

Initialize Game Variables:

Initialize variables for the selected word, guessed letters, remaining attempts, etc.

Game Loop:

Continuously prompt the player to guess a letter.

Update the game state based on the guessed letter.

Check for win/loss conditions and break the loop if the game ends.

Display Functions:

Functions to display the current state of the word, remaining attempts, and guessed letters.

End of Game:

Display the result (win/loss) and the correct word.

Optionally, ask the player if they want to play again.
