#include <cstdio>
struct college
{
	char name[20];
};

struct timeRef {
	int year = 2019;
	void setYear(int ye) {
	
		year = ye;
	}
	int getYear() {
		return year;
	}
};


void printName(college* arrayC)
{
	printf("%s\n", arrayC->name);// printing 1st element only with the help of pointer
	printf("%s\n", arrayC[1].name);// using bracket notation to use every element in array
}

void addYear(timeRef& clock)// use reference whenever we to point a variable to a single object it will not change throughout
{
	clock.setYear(clock.getYear() + 1);
}

void memberOfpointer(void);
void testArray(void);
void testString(void);
void testingRef(void);

int main() {
	
	//memberOfpointer();
	//testArray();
	//testString();
	testingRef();
	return 0;
}

void testingRef() {
	timeRef clock;
	printf("current year is : %d\n", clock.getYear());
	addYear(clock);
	printf("current year is : %d\n", clock.getYear());

}

void testString() {

	char lower[] = "abcd?";
	char upper[] = "ABCD?";
	char* upper_ptr = &upper[0]; // upper_ptr here is equivalent to upper because they both point to 1st element in upper array
	*(lower + 4) = 'e';
	*(upper_ptr + 4) = 'E';
	printf("upper arra :%s\n", upper);
	printf("upper arra :%s\n", lower);

}

void testArray() {
	
	int arrayM[]{ 3,6,8,9,10 };
	int (*elem)[5] = &arrayM; //we cant store address of an array to int *arra; because both are of different type pointer but every element address of arra is not stored in elem it just 1st one
	int* sndElm = arrayM+2; //storing address of 3rd element in array arraM (arrayM points to address of 1st element )
	printf("%p\n", &arrayM);
	printf("%d\n", *elem[0]); // Both 27 and 28 lines are same but 2nd element of array is not elem[1]
	printf("%p\n", sndElm);
	college mellon[] = { "ycce","rcoem","raisoni" };
	printName(mellon);
}

void memberOfpointer() {
	struct testMop
	{
		int year;
		void setYear(int ye) {
			year = ye;
		}
	};
	int getIs{};
	int* getIsAddr; //initializing pointer
	getIsAddr = &getIs;
	printf("%d\n", getIs);
	printf("%p\n", getIsAddr);//%p to print pointers on screen
	printf("%d\n", *getIsAddr); // * is used to dereference a pointer

	testMop year1;
	testMop* year2 = &year1;
	// testMop* year3; cannot just print it like thid because pointer are used to reference somthing. 
	// year3->setYear(2022); this will give us error initializing without a refernce
	year2->year = 2010;
	printf("value of year1 : %d",year1.year);
	printf("value of year1 : %d", (*year2).year);//alternative of above line


}