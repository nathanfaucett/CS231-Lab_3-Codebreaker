For this lab assignment, you will be implementing a simple game called “Codebreaker,” derived from other similar games which have long been played on paper.  In this game, the computer randomly generates a secret numeric code.  Depending on the level of difficulty you specify in the program, this code can be either three or four digits in length, composed of digits ranging either from one through six or one through nine.  The player's task is to guess all of the digits of the code, in the correct order, in the least possible number of guesses.  The attached file, "Lab03_skeleton.cpp", represents a partial implementation that you can use as a starting point.

In response to each of the player's guesses, the computer provides clues which can help the player to crack the code through a process of deduction.  The computer checks the digits guessed by the player, compares each of them to every one of the digits in the secret code, and determines whether each digit in the player's guess is of the correct identity and in the correct place (these are the “correct” digits), or whether each digit is of the correct identity but is not in the correct place (these are the “misplaced” digits).  With each guess, it counts the number of “correct” and “misplaced” digits, and prints these totals to the screen, alongside the player's guess, in ordered columns.  The player can use this information to determine which digits need to be exchanged or replaced, until the player's guess exactly matches the secret code.  The computer then prints a message of congratulations, along with the total number of guesses it took the player to crack the code.

This lab assignment is worth 100 points and is due by the end of the day on Friday, October 16th.  Your output should resemble the following (in this example, the secret code is 2426):
```bash
WELCOME TO CODEBREAKER!

The computer has created the secret code, and your mission is to guess
it! After you register your guesses with the computer, it will respond
with numbers that analyze your guesses: 'CORRECT' signifies the number
of digits that are the correct identity AND in the correct places, and
'MISPLACED' signifies the number of digits that are the correct
identity but NOT in the correct places.  See if you can get all of the
digits correct within twelve guesses!

YOUR GUESSES:                                  CORRECT:     MISPLACED:
======================================================================
Enter Code: 1234
                                    1234              0              2
Enter Code: 2134
                                    2134              1              1
Enter Code: 2314
                                    2314              1              1
Enter Code: 2431
                                    2431              2              0
Enter Code: 2442
                                    2442              2              1
Enter Code: 2424
                                    2424              3              0
Enter Code: 2425
                                    2425              3              0
Enter Code: 2421
                                    2421              3              0
Enter Code: 2426

Congratulations, you guessed the code!
It only took you 9 guess(es)!

Would you like to play again (Y/N)?
```

A few tips and hints to get you started:

Your program should define constants to specify the length (the number of digits, initially three) and the span (the maximum digit, initially six) of the secret code.  Suggested names are CODE_LENGTH and CODE_SPAN.  Once your game is working, you should be able to increase the code length from three to four, and the range of digits from six to nine, simply by changing the value of these constants.  To make the constants accessible to your functions, you may define them in the global scope (that is, place your definitions immediately before your function prototypes, outside any of your function definitions).
Your program should use strings for both the secret code and the player's guesses. Recall that you can access the individual characters within strings by subscripting them; for example, if you want to return the second digit in the string code, use code[1] (remember that the elements are numbered starting from zero, not from one).
Your program should use a function to generate the secret code, and another function to get the player's guesses.  Both functions should return the codes as strings.  The function which gets the player's guesses should also validate the user's input: it should check the length of each guess (to make sure it matches the length specified in CODE_LENGTH), and it should check each digit to make sure it is within the range specified in CODE_SPAN (for example, if the range is from one to six, the player should not be able to make a guess which includes the digits seven, eight, or nine).  If the player's input fails the validation check, the function should continue to prompt the player to guess again until a valid code is received (you will find a while loop useful for this).
Your game should continue to prompt the player for guesses until the player guesses correctly.  Then, after printing a message of congratulations and the number of guesses made by the player, it should allow the player to start a new game.  At the start of each new game, it should select a different secret code and reset the guess counter.  At the start of each round (guess) of the game, it should reset the counters for the number of “correct” and “misplaced” digits, since these numbers will be different with every guess.  Get your program to the point where it can play a single game first, and then add the ability to start a new game.
You may find it useful to convert an int value into the corresponding char value, so it can be compared with the user's input or printed to the screen as a character.  One way to do this is to add the int value to the character '0'.  For example, to check whether the player's guesses are within the range one to six, use '0' + CODE_SPAN to get the character '6', which is the upper limit of each character in the player's guess.
To align your program's output neatly into columns, use the setw output manipulator we have discussed in class (your program must #include the <iomanip> library).  Use a width of 45 for the player's guess, and a width of 15 for the “correct” and “misplaced” digits (see the sample output for an example).
To generate random numbers within a specific range, use the random number generator code given in the “Rock, Paper, Scissors” exercise, and add the following randint() function definitions, which allows you to specify either a max value or a min and max value.  Don't forget to add the corresponding function prototypes!
```c++
// RANDOM NUMBER GENERATOR ( >= MIN && < MAX )

int randint(int min, int max) {

     return ( randint( max - min ) + min );

} // End randint()

// RANDOM NUMBER GENERATOR ( < MAX )

int randint(int max) {

     return ( rand() % max );

} // End randint()
```
