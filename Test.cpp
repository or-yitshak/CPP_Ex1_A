/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: or yitshak <Please write your names here>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

bool isPalindrom(string str)
{
	string str2 = str;
	reverse(str2.begin(), str2.end());
	return (str2 == str);
}

TEST_CASE("Good input")
{
	string str1 = mat(9, 7, '@', '-');
	string str2 = mat(13, 5, '@', '-');
	string str3 = mat(3, 5, '$', '+');
	string str4 = mat(1, 1, '#', '&');

	// checks some simple examples.
	CHECK(nospaces(str1) == nospaces("@@@@@@@@@\n"
									 "@-------@\n"
									 "@-@@@@@-@\n"
									 "@-@---@-@\n"
									 "@-@@@@@-@\n"
									 "@-------@\n"
									 "@@@@@@@@@\n"));
	CHECK(nospaces(str2) == nospaces("@@@@@@@@@@@@@\n"
									 "@-----------@\n"
									 "@-@@@@@@@@@-@\n"
									 "@-----------@\n"
									 "@@@@@@@@@@@@@\n"));
	CHECK(nospaces(str3) == nospaces("$$$\n"
									 "$+$\n"
									 "$+$\n"
									 "$+$\n"
									 "$$$\n"));
	CHECK(nospaces(str4) == nospaces("#\n"));

	// checks that the size of the string is right.
	CHECK(nospaces(str1).size() == 9 * 7);
	CHECK(nospaces(str2).size() == 13 * 5);
	CHECK(nospaces(str3).size() == 3 * 5);
	CHECK(nospaces(str4).size() == 1 * 1);

	// checks the number of rows in the string.
	char ch = '\n';
	CHECK(count(str1.begin(), str1.end(), ch) == 7);
	CHECK(count(str2.begin(), str2.end(), ch) == 5);
	CHECK(count(str3.begin(), str3.end(), ch) == 5);
	CHECK(count(str4.begin(), str4.end(), ch) == 1);

	// checks that symbol1 appears more times than symbol2.
	char ch11 = '@';
	char ch12 = '-';
	CHECK(count(str1.begin(), str1.end(), ch11) >= count(str1.begin(), str1.end(), ch12));
	CHECK(count(str2.begin(), str2.end(), ch11) >= count(str2.begin(), str2.end(), ch12));

	char ch31 = '$';
	char ch32 = '+';
	CHECK(count(str3.begin(), str3.end(), ch31) >= count(str3.begin(), str3.end(), ch32));

	char ch41 = '#';
	char ch42 = '&';
	CHECK(count(str4.begin(), str4.end(), ch41) >= count(str4.begin(), str4.end(), ch42));

	// checks if its a palindrom.
	CHECK(isPalindrom(nospaces(str1)) == true);
	CHECK(isPalindrom(nospaces(str2)) == true);
	CHECK(isPalindrom(nospaces(str3)) == true);
	CHECK(isPalindrom(nospaces(str4)) == true);

	string str = "@@@@@@@@@\n"
				 "@-------@\n"
				 "@-@@@@@-@\n"
				 "@-@---@-@\n"
				 "@-@@@@@-@\n"
				 "@-------@\n"
				 "@@@@@@@@@";

	/* Add more test here */
}

TEST_CASE("Bad input")
{
	CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(-7, 5, '$', '%'));
	CHECK_THROWS(mat(0, 5, '$', '%'));
	// CHECK_THROWS(mat(11, 5.5, '$', '%'));
	/* Add more test here */
}

/* Add more test cases here */
TEST_CASE("Random input")
{
	int cols = rand() % 100;
	int rows = rand() % 100;

	if (cols % 2 == 0 || rows % 2 == 0)
	{
		CHECK_THROWS(mat(cols, rows, '$', '%'));
	}

	else
	{
		string str = mat(cols, rows, '$', '%');
		CHECK(nospaces(str).size() == cols * rows);

		char ch = '\n';
		CHECK(count(str.begin(), str.end(), ch) == rows - 1);

		char ch1 = '$';
		char ch2 = '%';
		CHECK(count(str.begin(), str.end(), ch1) >= count(str.begin(), str.end(), ch2));

		CHECK(isPalindrom(nospaces(str)) == true);
	}
}