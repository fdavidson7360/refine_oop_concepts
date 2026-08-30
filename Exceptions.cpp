// ===== Example 1: Exceptions project
// You are making a program to manage user names.
// A valid username needs to be minimum 4, maximum 20 characters long.
// Create a program to take a string as input, check its length and output "Valid" if the name is valid, or "Invalid", if it is not.

#include <iostream>
using namespace std;

int main() {
   string name;
   cin >> name;
   try {
      if (name.size() < 4 || name.size() > 21)
      {
         throw 99;
      }
      else
      {
         cout << "Valid" << endl;
      }
   }
   catch(int x) {
      cout << "Invalid" << endl;
   }
   
   return 0;
}

// ===== End of Example 1: Exceptions project

// More on Exceptions
// You are making a digital menu, which takes a number as user input, and outputs the corresponding menu item.
//
// However, the users can input anything, even numbers that are not present in the menu.
//
// Handle wrong user input, by throwing an exception with code 404 and outputting "404 - not found", if it is out of the range of the given menu.

#include <iostream>
using namespace std;

int main() {
    string menu[] = {"fruits", "chicken", "fish", "cake"};
    try {
        int x;
        cin >> x;
        //your code goes here
        int length = sizeof(menu) / sizeof(menu[0]);
        if(x < 0 || x >= length)
        {
            throw 404;
        }
        cout << menu[x] << endl;
        
    }
    catch(...) {
        //and here
        cout << "404 - not found" << endl;
        
    }
}



