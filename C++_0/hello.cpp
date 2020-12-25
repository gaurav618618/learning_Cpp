#include <cstdio> 
void testClass(void);
void testStruct(void);
int main() {
	
	testStruct();
	testClass();
	return 0; 
}

void testClass() {
	class PrintYear { //Learning class
		int year; //every thing is private by default in class
	public : // To define public methods
		int addYear() {
			year++;
			return year;
		}
		void setYear(int newYear) {
			year = newYear;
		}
	};
	PrintYear year2;
	year2.setYear(2020);
	printf("%d\n", year2.addYear());
}

void testStruct() {
	struct PodStruct {
		int a;
		char b[256];
		bool c;
	};
	struct PrintYear { //Learning Struct
		bool isDown;
		int em;
		//PrintYear( bool c, int m) { //Constructor
		//	year = 2020;
		//	isDown = c;
		//	em = m;

		//}
		int addYear() {
			year++;
			return year;
		}
		void setYear(int newYear) {
			year = newYear;
		}
	private:// everything is public by default to assign a variable as a private 
		int year;
	};
	PrintYear year1{};
	PodStruct year_nm{11,"Hello",true};
	printf("%s\n", year_nm.b);

}