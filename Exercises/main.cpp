// 
// These are some select exercises for practice from here:
// http://www.stroustrup.com/4thExercises.pdf
//

#include <iostream>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

#include <string>
using std::string;

class Person
{
public:
   friend ostream &operator<<(ostream &out, Person &person)
   {
      return out << "Name: " << person.name << "\nAge: " << person.age << '\n';
   }

   friend istream &operator>>(istream &in, Person &person)
   {
      return in >> person.name >> person.age;
   }

private:
   string name;
   int age;
};

void main()
{
   // Section X.5
   // X.5[5]
   string name;
   int age;
   cout << "Enter name and age in that order:\n";
   cin >> name >> age;
   cout << "Name: " << name << "\nAge: " << age << '\n';

   Person person;
   cout << "Enter name and age in that order:\n";
   cin >> person;
   cout << person;

   return;
}