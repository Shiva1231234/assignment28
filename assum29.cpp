Q=1
/*


#include <iostream>
using namespace std;
 
class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)
    {  real = r;   imag = i; }
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
};
 
ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag << endl;
    return out;
}
 
istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.imag;
    return in;
}
 
int main()
{
   Complex c1;
   cin >> c1;
   cout << "The complex object is ";
   cout << c1;
   return 0;
}*/
Q=2
/*
#include <iostream>    // using IO functions
#include <string>      // using string
using namespace std;
 
class Circle {
private:
   double radius;      // Data member (Variable)
   string color;       // Data member (Variable)
 
public:
   // Constructor with default values for data members
   Circle(double r = 1.0, string c = "red") {
      radius = r;
      color = c;
   }
 
   double getRadius() {  // Member function (Getter)
      return radius;
   }
 
   string getColor() {   // Member function (Getter)
      return color;
   }
 
   double getArea() {    // Member function
      return radius*radius*3.1416;
   }
};   // need to end the class declaration with a semi-colon
 
// Test driver function
int main() {
   // Construct a Circle instance
   Circle c1(1.2, "blue");
   cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()
        << " Color=" << c1.getColor() << endl;
 
   // Construct another Circle instance
   Circle c2(3.4); // default color
   cout << "Radius=" << c2.getRadius() << " Area=" << c2.getArea()
        << " Color=" << c2.getColor() << endl;
 
   // Construct a Circle instance using default no-arg constructor
   Circle c3;      // default radius and color
   cout << "Radius=" << c3.getRadius() << " Area=" << c3.getArea()
        << " Color=" << c3.getColor() << endl;
   return 0;
}*/
Q=3
/*
#include <iostream>
using namespace std;
  
// Driver Method
int main()
{
    int intArray[1024];
    for (int i = 0, j = 0; i < 1024; i++) {
        intArray[i] = j++;
    }
  
    // 512
    cout << intArray[512] << endl;
  
    // 257
    cout << 257 [intArray] << endl;
  
    // pointer to the middle of the array
    int* midArray = &intArray[512];
  
    // 256
    cout << midArray[-256] << endl;
  
    // unpredictable, may crash
    cout << intArray[-256] << endl;
}*/
Q=4
/*
/ for a specific class
#include<iostream>
#include<stdlib.h>
 
using namespace std;
class student
{
    string name;
    int age;
public:
    student()
    {
        cout<< "Constructor is called\n" ;
    }
    student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout<< "Name:" << name << endl;
        cout<< "Age:" << age << endl;
    }
    void * operator new(size_t size)
    {
        cout<< "Overloading new operator with size: " << size << endl;
        void * p = ::operator new(size);
        //void * p = malloc(size); will also work fine
     
        return p;
    }
 
    void operator delete(void * p)
    {
        cout<< "Overloading delete operator " << endl;
        free(p);
    }
};
 
int main()
{
    student * p = new student("Yash", 24);
 
    p->display();
    delete p;
}*/
Q=5
/*

// CPP program to demonstrate
// Overloading new and delete operator
// for a specific class
#include<iostream>
#include<stdlib.h>
 
using namespace std;
class student
{
    string name;
    int age;
public:
    student()
    {
        cout<< "Constructor is called\n" ;
    }
    student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout<< "Name:" << name << endl;
        cout<< "Age:" << age << endl;
    }
    void * operator new(size_t size)
    {
        cout<< "Overloading new operator with size: " << size << endl;
        void * p = ::operator new(size);
        //void * p = malloc(size); will also work fine
     
        return p;
    }
 
    void operator delete(void * p)
    {
        cout<< "Overloading delete operator " << endl;
        free(p);
    }
};
 
int main()
{
    student * p = new student("Yash", 24);
 
    p->display();
    delete p;
}*/
Q=6
/*

// C++ program for Assignment Operator overloading
#include <iostream>
using namespace std;
  
class Complex {
private:
    int real, img; // real, imaginary
  
public:
    // Parameterized Constructor
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }
  
    // This is automatically called
    // when '=' operator is
    // used between C1 and C2.
  
    void operator=(const Complex& C)
    {
        real = C.real;
        img = C.img;
    }
  
    // function to print
    void print() { cout << real << "+i" << img << endl; }
};
  
int main()
{
    // Assigning by overloading constructor
    Complex C1(2, 3), C2(4, 6);
    
    cout << "BEFORE OVERLOADING ASSIGNMENT OPERATOR"<< endl;
    cout << "C1 complex number: ";
    
    C1.print();    
    
    cout << "C2 complex number: ";
    
    C2.print();     
    
    // overloading assignment operator to copy values
    C1 = C2;
    
    cout << "AFTER OVERLOADING ASSIGNMENT OPERATOR" << endl;
    cout << "C1 complex number: ";
    
    C1.print();    
    
    cout << "C2 complex number: ";
    
    C2.print();
    
    return 0;
}*/
Q=7
/*
#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents): m_cents{cents} {}

    // Overload -Cents as a member function
    Cents operator-() const;

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
Cents Cents::operator-() const
{
    return -m_cents; // since return type is a Cents, this does an implicit conversion from int to Cents using the Cents(int) constructor
}

int main()
{
    const Cents nickle{ 5 };
    std::cout << "A nickle of debt is worth " << (-nickle).getCents() << " cents\n";

    return 0;
}*/
Q=8
/*
#include <iostream>
using namespace std;
  
// Comma class
class comma {
    int x, y;
  
public:
    // Default Constructor
    comma() {}
  
    // Parameterized Constructor
    comma(int X, int Y)
    {
        x = X;
        y = Y;
    }
  
    // Function to display the value
    void display()
    {
        cout << "x=" << x << " ";
        cout << "y=" << y << " ";
    }
  
    comma operator+(comma ob2);
    comma operator, (comma ob2);
};
  
// Function to overload the + operator
comma comma::operator+(comma ob2)
{
    comma temp;
  
    // Update the value temp
    temp.x = ob2.x + x;
    temp.y = ob2.y + y;
  
    // Return the value temp
    return temp;
}
  
// Function to overload the, operator
comma comma::operator, (comma ob2)
{
    comma temp;
  
    // Update the value temp
    temp.x = ob2.x;
    temp.y = ob2.y;
  
    // Print the value
    cout << "x=" << ob2.x << " "
         << "y=" << ob2.y << endl;
  
    // Return the value temp
    return temp;
}
  
// Driver code
int main()
{
    // Initialize objects
    comma ob1(10, 20), ob2(5, 30), ob3(1, 1);
  
    ob1.display();
    ob2.display();
    ob3.display();
  
    cout << endl;
  
    ob1 = (ob2 + ob2, ob1, ob3);
  
    // Displays the value of
    // ob3 (Rightmost expression)
    ob1.display();
  
    return 0;
}*/
Q=9
/*
/* The Point class Implementation file (Point.cpp) */
#include "Point.h"
#include <iostream>
using namespace std;
 
// Constructor - The default values are specified in the declaration
Point::Point(int x, int y) : x(x), y(y) { }
 
// Getters
int Point::getX() const { return x; }
int Point::getY() const { return y; }
 
// Setters
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }
 
// Public Functions
void Point::setXY(int x, int y) { this->x = x; this->y = y; }
 
void Point::print() const {
   cout << "Point @ (" << x << "," << y << ")";
}*/
Q=10
/*
// defining the constructor within the class
 
#include <iostream>
using namespace std;
 
class student {
    int rno;
    char name[10];
    double fee;
 
public:
    student()
    {
        cout << "Enter the RollNo:";
        cin >> rno;
        cout << "Enter the Name:";
        cin >> name;
        cout << "Enter the Fee:";
        cin >> fee;
    }
 
    void display()
    {
        cout << endl << rno << "\t" << name << "\t" << fee;
    }
};
 
int main()
{
    student s; // constructor gets called automatically when
               // we create the object of the class
    s.display();
 
    return 0;
}*/
Q=11
/*
#include <iostream>
using namespace std;

class sample
{
	private:
		int a;
	public:
		int b;
		void init(int a)
		{this->a = a;}
		void display()
		{cout<<"a: "<<a<<endl;}
};

int main()
{
	//pointer to an object declaration
	sample *sam = new sample();
	
	cout<<"Using * and . Operators\n";
	//value assignment to a and back
	(*sam).init(100);
	(*sam).b=200;
	
	//printing the values
	(*sam).display();
	cout<<"b: "<<(*sam).b<<endl;
	
	cout<<"Using Arrow Operator (->)\n";
	//value assignment to a and back
	sam->init(100);
	sam->b=200;
	
	//printing the values
	sam->display();
	cout<<"b: "<<sam->b<<endl;	
	
	return 0;			
}*/