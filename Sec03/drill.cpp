#include "../std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to: ";
  string first_name;
  cin >> first_name;
  int age{-1};
  cout << "Enter the age of the person: ";
  cin >> age;
  if (!(0 < age && age < 110))
  {
    simple_error("You're kidding!");
  }
  cout << "Enter the name of the friend: ";
  string friend_name;
  cin >> friend_name;
  char gender{0};
  while (!(gender == 'm' || gender == 'f'))
  {
    cout << "gender ['m' or 'f'] : ";
    cin >> gender;
  }
  cout << "Dear " << first_name << "," << endl;
  cout << endl;
  cout << "   How are you? I'm fine. I miss you." << endl;
  cout << "I am not employed now." << endl;
  cout << "Have you seen " << friend_name << " lately?" << endl;
  string him_her = (gender == 'm' ? "him" : "her");
  cout << "If you see " << him_her << ", please ask " << him_her << " to call me." << endl;
  cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
  if (age < 12)
  {
    cout << "Next year you will be " << age + 1 << "." << endl;
  }
  else if (age == 17)
  {
    cout << "Next year you will be able to vote." << endl;
  }
  else if (age >= 70)
  {
    cout << "I hope you're enjoying retirement." << endl;
  }
  cout << "\nYours sincerely,\n\n"
       << "Kazune Takahashi" << endl;
}