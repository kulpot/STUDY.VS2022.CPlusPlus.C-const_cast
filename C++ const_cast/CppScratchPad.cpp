#include <iostream>
using std::cout;
using std::endl;

//----------------------- C++ const_cast ------------------------------------------------------------------
//ref link:https://www.youtube.com/watch?v=SJ7ZTpNydTk&list=PLRwVmtr-pp070AKU7G71q8XyCRttsWIvi&index=5&t=1s

/*
* const_cast allows you to remove the const definition of the object.
* You can use this thing when you should pass an regular object to a function but your object is a const object. The function will not accept the const object.
*/

class Cow {
public:
	void saySomething() { cout << "waaa" << endl; }
};

void f(Cow* c)		//none-const pointer
{
	c->saySomething();
}

void main()
{
	const Cow* c = new Cow;
	//f(c);			//error: f function is not const
	//Cow* c2 = c;		//error: c is not const
	Cow* c2 = const_cast<Cow*>(c);
	f(const_cast<Cow*>(c));

	delete c;
}
































//------------------------- const pointers -----------------------------------------------------------------
//ref link:https://www.youtube.com/watch?v=BimM1lLeZg8&list=PLRwVmtr-pp070AKU7G71q8XyCRttsWIvi&index=2&t=1s

//class Cow
//{
//	int mooCount;
//public:
//	Cow() { mooCount = 0; }
//	void moo() { cout << mooCount++ << endl; }
//	void saySomething() const { cout << "Hello" << endl; }
//};
//
//void main()
//{
//	Cow* c = new Cow;
//	//const Cow* constCow = c;
//	//Cow* const constCow = c;		//pointer itself is const
//	//constCow = new Cow;		// error cant modify const constCow
//	const Cow* const constCow = c;		// the object and the pointer is const
//	c->moo();
//	//constCow->moo();		// error cant modify const Cow*	, solution: Cow* const constCow = c;
//	delete c;
//}



































//------------------ C++ const functions (const correctness) --------------------------
//ref link:https://www.youtube.com/watch?v=ehJKvbbe9hk

//const int MY_INT = 5;

//class Cow
//{
//	int mooCount;
//	//const int mooCount;
//
//public:
//	Cow() { mooCount = 0; }
//	//void moo() { cout << mooCount++ << endl; }		//none-const func	, modifies int mooCount;
//	//void saySomething() { cout << "Hello" << endl; }	// none modify int mooCount;
//	
//	//void moo() const { cout << mooCount++ << endl; }		//error: const cant modify mooCount to mooCount++
//	void moo() const { cout << mooCount << endl; }			
//	void saySomething() const { cout << "Hello" << endl; }
//};
//
//void main()
//{
//	//Cow c;
//	const Cow c;
//	c.moo();
//	c.moo();
//	c.saySomething();
//	c.moo();
//
//	//cout << MY_INT << endl;
//}