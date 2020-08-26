#include <iostream>
#include "nyms.hpp"
using namespace std;

//this is where the program starts! it welcomes the user to the program 
// and explains the basic commands. You can change what's between the " " to
// edit the messages it will output. \n stands for newline, which is basically
// the computer way of hitting enter. there's a bunch of special commands like that
// you can google them.
int main(void)
{    
    cout << "Welcome to your nyms!" << endl;
    cout << "The following commands are available to you:\nview - view your nyms\nexit - exit program" << endl;
    cout << "WARNING! All your nyms will be deleted once you write exit." << endl;
    cout << "THIS PROGRAM IS CASE SENSITIVE\n\"VIEW\" WILL NOT BE RECOGNISED BUT \"view\" WILL." << endl;
    nyms(); // this takes you to the cyms.ccp file, where you'll find the more interesting code.
    cout << "Goodbye!" << endl;
    return (0);
    
}
