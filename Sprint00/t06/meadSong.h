#pragma once
#include <iostream>
#include <string>

using namespace std;

// 99 bottles of mead on the wall, 99 bottles of mead.
// Take one down and pass it around, 98 bottles of mead on the wall.

// 1 bottle of mead on the wall, 1 bottle of mead.
// Take it down and pass it around, no more bottles of mead on the wall.

// No more bottles of mead on the wall, no more bottles of mead.
// Go to the store and buy some more, 99 bottles of mead on the wall.

void setupStrings(string& bottle, string& where, string& take_one);
void printPoem(string& bottle, string& where, string& take_one, int num);
