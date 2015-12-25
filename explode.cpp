/**
 * File: explode.cpp
 * ------------------
 */

#include <cassert>
#include <iostream>
#include "genlib.h"
#include "vector.h"

/**
 * Accepts the specified string (str) and breaks it
 * up into smaller tokens, using the specified delimiter (delim)
 * as the separator.
 */

Vector<string> Explode(string s, char d) 
{
	Vector <string> full;
	string temp;
	s.append(1,d);
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==d)
		{
			full.add(temp);
			temp="";
			
		}
		else
		{
			temp.append(1,s[i]);
		}
	}
	return full;
}

/**
 * Type: testCase
 * The testCase is a small record of information about a
 * potential use case for Explode.  The numComponents field
 * stores the expected length of the explosion, and first and
 * last record the strings we expect to see at the front and
 * back.
 */

struct testCase {
	string str;
	char delimiter;
	int numComponents;
	string first;
	string last;
};

static testCase testCases[] = {	
{"171.64.64.131", '.', 4, "171", "131"},
{"happy birthday", ' ', 2, "happy", "birthday"},
{"happy birthday", 'a', 3, "h", "y"},
{"happy birthday", '$', 1, "happy birthday", "happy birthday"},
{"yoyyyoyoyo", 'o', 5, "y", ""},
{"yoyyyoyoyoy", 'o', 5, "y", "y"},
};

/**
 * Returns true if and only if the specified
 * test case works out.
 *
 * @param testCase test a testCase containing parameters that,
 *        when passed to Explode, should generate a Vector
 *        with testComponents, such that test.first is in the
 *        0th slot, and test.last is in the last one.
 * @return bool true if and only if the test passes, and false otherwise.
 */

bool TestCasePasses(testCase& test) {
	Vector<string> explosion = Explode(test.str, test.delimiter);
	return 
	    explosion.size() == test.numComponents &&
		explosion[0] == test.first &&
		explosion[explosion.size() - 1] == test.last;
}

/**
 * This type of program is what's called a unit test, which
 * means it's sole purpose is to aggresively test a piece of code
 * to verify that it works as expected in a variety of situation,
 * including unusual but technically valid ones.
 */

int main() {
	int numErrors = 0;
	for (int i = 0; i < sizeof(testCases)/sizeof(*testCases); i++) {
		testCase& test = testCases[i];
		if (!TestCasePasses(test)) {
			numErrors++;
			cout << "Test failed while exploding \"" << test.str << "\" " <<
			"around '" << test.delimiter << "' as a delimiter." << endl;
			
		}
	}
	
	if (numErrors == 0) {
		cout << "All tests passed.  Congratulations!!" << endl;
	}
	return 0;
}

