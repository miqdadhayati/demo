#include <iostream>
#include <random>
#include <string>
using namespace std;

enum sign {ROCK, PAPER, SCISSOR, UNKNOWN};
enum outcome {DRAW, WIN, LOSS, NORESULT};

/*
    The following function is straigt forward, it takes in the sign of user
    and computer and returns the results (notice the return type)
*/
outcome result(sign user, sign comp){
    if (user == comp) {
        return DRAW;
    }
    if (user == ROCK) {
        if (comp == SCISSOR) {
            return WIN;
        } else {
            return LOSS;
        }
    }
    if (user == PAPER) {
        if (comp == ROCK) {
            return WIN;
        } else {
            return LOSS;
        }
    }
    if (user == SCISSOR) {
        if (comp == PAPER) {
            return WIN;
        } else {
            return LOSS;
        }
    }
    return NORESULT;
}


/*
    The following  is a simple 1-1 mapping of a string "r", "p", and"s" to their
    crosponding enum sign. Notice I have left the argument empty! It must a constant
    string passed by refference {The reason is explained in the video lecture}
*/
sign string_to_sign(const string &s){
    if(s == "r") return ROCK;
    if(s == "p") return PAPER;
    if(s == "s") return SCISSOR;
    return UNKNOWN;

}

/*
    The following is another 1-1 mapping but this time from a sign to string
    You are REQURED to use a switch statment here
*/
string sign_to_string(sign move){
    switch(move){
        case ROCK: return "r";
        case PAPER: return "p";
        case SCISSOR: return "s";
    }

}

/*
    This is just an output producing function.
    Depending upon user input, computer sign (found using the random function) , and the outcome of the match
    this function will print out a line such as "You: s | Computer: p --> You win!"  
    You are expected to use a swtich statement here
*/
void interface(sign user, sign comp, outcome final){
    cout << "You: " << sign_to_string(user) << endl;
    cout << "Computer: " << sign_to_string(comp) << endl;
    switch(final){
        case DRAW: cout << "It's a draw!" << endl; break;
        case WIN: cout << "You win!" << endl; break;
        case LOSS: cout << "You lose!" << endl; break;
        default: cout << "No result" << endl; break;
    }

}

int main(/*some arguments here if you are taking input from command line*/) {
    /*
        You need to check if there are enough number of values passed at the command line
        if not you need to tell the input format
    */

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);
    /*
        Now you can generate a random number like:
            int random = dist(gen); 
        This will produce a random number between 0 and 2 (both inclusive)
    */

    // A loop over here to combine all elements.
    string input;
    while (true) {
        cout << "Enter your move (r/p/s)";
        cin >> input;
        sign user_sign = string_to_sign(input);
        if (user_sign == UNKNOWN) {
            cout << "Invalid input! Please enter r, p, or s." << endl;
            continue;
        }
        int random = dist(gen);
        sign comp_sign = static_cast<sign>(random);
        outcome match_result = result(user_sign, comp_sign);
        interface(user_sign, comp_sign, match_result);
    }

    return 0;
}
