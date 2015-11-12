#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


const int CODE_LENGTH = 4;
const int CODE_SPAN = 9; // int 0 - 9


char int_to_char(int x) {
    return x + '0';
}

string generate_code(void) {
    string result = "";
    int i = -1;
    int il = CODE_LENGTH - 1;

    while (i++ < il) {
        result += int_to_char(rand() % (CODE_SPAN + 1));
    }

    return result;
}

void get_correct_misplaced(const string& guess, const string& code, int& correct, int& misplaced) {
    int i = -1;
    int il = code.size() - 1;

    while (i++ < il) {
        if (guess[i] == code[i]) {
            correct += 1;
        } else {
            misplaced += 1;
        }
    }
}

void game_over(int);

void loop(const string& code, int guesses) {
    string guess;
    int correct = 0;
    int misplaced = 0;

    cout << "Enter Code: ";
    cin >> guess;

    get_correct_misplaced(guess, code, correct, misplaced);

    // 45 was to far
    cout << setw(40) << guess;
    cout << setw(15) << correct;
    cout << setw(15) << misplaced;
    cout << setw(0) << '\n';

    if (correct == CODE_LENGTH) {
        game_over(guesses);
    } else {
        loop(code, guesses + 1);
    }
}

void start_game(void) {
    cout
        << "YOUR GUESSES:                                  CORRECT:     MISPLACED:\n"
        << "======================================================================\n";
    loop(generate_code(), 1);
}

void game_over(int guesses) {
    char input;

    cout << "Congratulations, you guessed the code!\n";

    if (guesses == 1) {
        cout << "It only took you 1 guess!\n";
    } else {
        cout << "It only took you " << guesses << " guesses!\n\n";
    }

    cout << "Would you like to play again (Y/N)?: ";
    cin >> input;
    cout << '\n';

    if (input == 'Y' || input == 'y') {
        start_game();
    }
}

void print_instrctions(void) {
    cout
        << "WELCOME TO CODEBREAKER!\n"
        << '\n'
        << "The computer has created the secret code, and your mission is to guess\n"
        << "it! After you register your guesses with the computer, it will respond\n"
        << "with numbers that analyze your guesses: 'CORRECT' signifies the number\n"
        << "of digits that are the correct identity AND in the correct places, and\n"
        << "'MISPLACED' signifies the number of digits that are the correct\n"
        << "identity but NOT in the correct places.  See if you can get all of the\n"
        << "digits correct within twelve guesses!\n"
        << "\n";
}

int main(int argc, char** argv) {
    srand(time(NULL));
    print_instrctions();
    start_game();
    return 0;
}
