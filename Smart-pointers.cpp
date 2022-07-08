#include <iostream>
#include<memory>
using namespace std;
class SmartPointers
{
public:
	SmartPointers()
	{
		cout << "Constructor Invoked" << endl;
	}
	~SmartPointers()
	{
		cout << "Destructor Invoked" << endl;
	}
	void display()
	{
		cout << "Inside Display method" << endl;
	}
};
int main()
{
	{
		//Block of Unique Pointer
		unique_ptr < SmartPointers > unptr = make_unique<SmartPointers>();
		unptr->display();
		unique_ptr<int> unptr2 = make_unique<int>(25);
		unique_ptr<int> unptr3 = move(unptr2);
		cout << *unptr3 << endl;

	}
	cout << " \n Outside the UniquePointer Scope \n-------------" << endl;

	{
		//Block of Shared Pointer
		shared_ptr<SmartPointers> shrdptr = make_shared<SmartPointers>();
		cout << shrdptr.use_count() << endl;
		{
			shared_ptr<SmartPointers> shrdptr2 = shrdptr;
			cout << shrdptr.use_count() << endl;
		}
		cout << shrdptr.use_count() << endl;
	}
	cout << " \n Outside the SharedPointer Scope \n-------------" << endl;
	{
		weak_ptr<int> wkptr;
		{
			shared_ptr<int>shrdptr = make_shared<int>();
			wkptr = shrdptr;
		}
	}
}

