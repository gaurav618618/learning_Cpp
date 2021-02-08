#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Entity is created" << std::endl;
	}
	Entity(const Entity& other) = delete;
	
	~Entity()
	{
		std::cout << "Entity is destroyed" << std::endl;
	}
};

void PrintEnti(const Entity& e1) // if we define the argument as a simple type then new argument type object will be created which we dont want because of space terefore use arg as a reference
{
	//always pass object as a const reference
}

int uniques_shared_ptr()
{
	std::shared_ptr<Entity> sharedCopy = std::shared_ptr<Entity>();
	Entity e1;
	Entity e2 = e1; // we cannot copy this object because the cunstructore is defined is delete if you will see , Just add the definition instead of delete to do anything when anyone copies

	

	{
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(); //we wont be able to copy it like unique_ptr<Entity>  en2= entity; also it will get destroyed out of scope automatically
		std::shared_ptr<Entity> sharedEntity = std::shared_ptr<Entity>();
		sharedCopy = sharedEntity;
	} //entity and sharedEntity will get destroyed automatically destroyed after this scope but sharedCopy will remain as it is because it is a copy.  
	
	return 0;

}

int main()
{
	return 0;
}