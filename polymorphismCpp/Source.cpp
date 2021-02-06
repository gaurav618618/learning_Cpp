#include <cstdio>
using namespace std;
struct baseClass {
	const int age = 20;
	int getAge() {
		return age;
	}
	virtual const char* printMessage() const{ //virtual keyword is used so that any derived class can override it 
		return "This is baseClass message";
	}
private:
	int year = 2019;

};

struct derivedClass : baseClass {
	const char* printMessage() const override{ //overrided the baseclass method 
		return "This is derivedClass message";
	}

};

struct BaseClass
{
	virtual const char* printMessage() const = 0; //we cant initiate an object of Base class because it has nothing to use , but we can define printMessage in any derived class
	//The = 0 suffix specifies a pure virtual method u, meaning you can’t instantiate a BaseClass—only derive from it.
};
struct DerivedClass:BaseClass {
	const char* printMessage() const override { //overrided the Baseclass method 
		return "This is DerivedClass message";
	}
};
int main() {
	derivedClass driver;
	printf("%d\n",driver.getAge());// driver.year is not accessible to drived class because its private
	printf("%s\n", driver.printMessage());
	DerivedClass driver2;
	printf("%s\n", driver2.printMessage());
	
}