#include "nyms.hpp" 
// ^ this is a header file, usually you use it to declare functions
// but not the implementation, that's found elsewhere. But rn,
// it's full of implementations for overview's sake.
#include <string.h>
using namespace std; // this is so I don't have to keep writing std::
                        //every time I want to use a function from std

nyms::nyms(void) // this is the main function! it waits for input
{
	string command;
	int i;

	i = 0;
    cout << "First let's name your first nyms.\n";
    cout << "Name nym 1:\n";
    getline(cin, command);
    user_nyms[0].set_name(command);
    cout << "Name nym 2:\n";
    getline(cin, command);
    user_nyms[1].set_name(command);
    user_nyms[0].generate_nym(user_nyms[0]);
    user_nyms[1].generate_nym(user_nyms[1]);
	cout << "Please enter your command now:" << endl;
    cin >> command; // this is where it waits and gets the input
    while (command.compare("exit") != 0) //as long as the user doesn't write exit, the program will keep going.
    {   
        if (command.compare("view") == 0) // if the user wrote view, this will happen, we'll put the nyms view function here
        {
			cout << "view which nymphs you have" << endl;
            show_nyms();
        }
        else if (command.compare("generate") == 0) // ditto for generating
        {
            cout << "generate new nym?" << endl;
        }
        else // all other input is invalid and will remind the user what commands exist
        {
            cout << "Sorry, that command does not exist." << endl;
            cout << "Write: view to view your nyms, generate to create new ones or exit to leave" << endl;
        }
        cout << "Anything else?" << endl;
        cin >> command; // this part allows the loop to keep listening for input.
    }
}
