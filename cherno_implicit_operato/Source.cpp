#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    explicit Entity(const std::string& name)
        :m_Name(name), m_Age(-1) {}
    Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}
    int operator+(int value)
    {
        m_Age += value;
    }
};

void PrintEntity(const Entity& entity)
{
}

int main()
{
    PrintEntity(std::string("Cherno")); //will not work with simple char array we have to change the type because custructor need a std::string
    PrintEntity(Entity("Cherno")); //above line give error because the string cinstructor is now explicit so we will have create an objec like this only
    PrintEntity(22); //this works fine because value 22 can be converted into Entity through age constructor
    Entity a("cherno");
    Entity b = 22;
    std::cout << b + 22; //since we have difined a function with operator we can use this operator to our use

     std::cin.get();

}