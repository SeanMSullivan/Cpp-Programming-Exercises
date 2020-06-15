// 
// These are some select exercises for practice from here:
// http://www.stroustrup.com/4thExercises.pdf
//

#include <algorithm>
using std::sort;

#include <chrono>
using std::chrono::seconds;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <iostream>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

#include <mutex>
using std::mutex;
using std::unique_lock;

#include <string>
using std::string;

#include <thread>
using std::thread;
using std::this_thread::sleep_for;

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

void X_5_8()
{
   vector<string> names = {"Kant", "Plato", "Aristotle", "Kierkegard", "Hume"};

   cout << "Unsorted:\n";
   for (const auto name : names)
      cout << name << ' ';

   sort(names.begin(), names.end());

   cout << "\nSorted:\n";
   for (const auto name : names)
      cout << name << ' ';
}

void X_5_9()
{
   ofstream outFile;
   outFile.open("integers.txt");
   if (outFile.is_open())
      for (int i = 0; i < 200; i++)
         outFile << i << " ";
   outFile.close();
}

void X_5_10()
{
   ifstream inFile;
   inFile.open("integers.txt");
   if (inFile.is_open())
      while (!inFile.eof())
      {
         int i;
         inFile >> i;
         cout << i << " ";
      }
   inFile.close();
}

struct Acout
{
   string s;
   mutex &m;
   Acout(string s, mutex &m)
      :s{s}, m{m} {}

   void operator()()
   {
      unique_lock<mutex> lck{m};
      cout << s;
      sleep_for(seconds{1});
   }
};

void X_6_2()
{
   mutex m;
   for (int count = 0; count < 5; count++)
   {
      thread t1 {Acout {"Hello ", m}};
      thread t2 {Acout {"World\n", m}};
      t1.join();
      t2.join();
   }
}

int main()
{
   X_6_2();
}
