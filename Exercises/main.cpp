// 
// These are some select exercises for practice from here:
// http://www.stroustrup.com/4thExercises.pdf
//

#include <algorithm>
using std::sort;

#include <iostream>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;


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

void X_5_5()
{
   // Section X.5
   // X.5[5]
   string name;
   int age;
   cout << "Enter name and age in that order:\n";
   cin >> name >> age;
   cout << "Name: " << name << "\nAge: " << age << '\n';
}

void X_5_6()
{
   Person person;
   cout << "Enter name and age in that order:\n";
   cin >> person;
   cout << person;
}

void X_5_7()
{
   vector<int> nums = {5, 9, -1, 200, 0};

   cout << "Unsorted:\n";
   for (const auto num : nums)
      cout << num << ' ';

   sort(nums.begin(), nums.end());

   cout << "\nSorted:\n";
   for (const auto num : nums)
      cout << num << ' ';
}


void main()
{
   X_5_6();
}