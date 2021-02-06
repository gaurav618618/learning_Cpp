#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age ;
	string name = "Rohan ";
	cout << "Enter your age" << endl;
	cin >> age ;
	age > 18 ? std::cout << name << "is eligible to vote" : std::cout << name << "not eligible to vote";
	return 0;


}
