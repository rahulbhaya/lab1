/**
 * File: look-and-say.cpp
 * ----------------------
 * This program prints out the look-and-say
 * sequence, one number every half a second,
 * until the user quits the program.  The
 * one modification is that we retain just the
 * first 15 digits of a number if it's longer
 * than 15 digits, and carry on as if it was the
 * 15-digit number all along.
 */

#include <iostream>
#include "simpio.h"
#include "genlib.h"
#include <windows.h>
#include <sstream>

/**
 * Stalls execution for the specified number
 * of seconds.
 */

void PauseInMilliSeconds(int milliseconds) {
	Sleep(milliseconds);
}

/**
 * Accepts a numeric string, and generates the numeric
 * string that results because we "look" at the number
 * and "say" it out loud.
 *
 * @param string before the initial number, expressed as a string.
 * @return string the converted number, as outlined by the rules of the
 *         look-and-say sequence.
 */

string LookAndSay(string before) 
{
	 
 string output = "";
    char counting = 0;
    int count = 0;
    for (int i = 0; i < before.length(); i++) {
        if (before.at(i) != counting) {
            if (i > 0) {
                output += count;
                output += counting;
            }
            counting = before.at(i);
            count = 1;
        } else {
            count++;
        }
    }
    output += count;
    output += counting;

    return output;
}

/**
 * This program prints out the look-and-say sequence, relying
 * on the LookAndSay function above to continually generate
 * the next number in the sequence from the most recently
 * printed one.
 */

int main() {
	string currentNum = "1";
	while (true) {
		cout << currentNum << endl;
		PauseInMilliSeconds(1000);
		currentNum = LookAndSay(currentNum);
	}
	return 0;
}
