#ifndef NYMS_H
#define NYMS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

class traits // this is where I store all available traits for nyms
{
	protected:
		const string	hair[6] = {"blue", "red", "yellow", "brown", "grey", "silver"};
		const string	eyes[6] = {"blue", "red", "yellow", "brown", "grey", "silver"};
		const string	skin[4] = {"pale", "brown", "tan", "olive"};
		const string	trait_1[4] = {"thing1", "thing2", "thing3", "thing4"};
		const string	trait_2[4] = {"thing1", "thing2", "thing3", "thing4"};
		const string	trait_3[4] = {"thing1", "thing2", "thing3", "thing4"};
		const string	trait_4[4] = {"thing1", "thing2", "thing3", "thing4"};
	public: 
	// this place contains the functions used to generate a random number which coincides with a trait, 
	//ie. if it lands on 0 for hair the hair colour would be blue.
	// it doesn't quite work yet, i'm probably missing something.
		int		gen_hair(void){
			return ((rand() % 5));
		}
		int		gen_eyes(void){
			return ((rand() % 5));
		}
		int		gen_skin(void){
			return ((rand() % 3));
		}
		int		gen_trait_1(void){
			return ((rand() % 3));
		}
		int		gen_trait_2(void){
			return ((rand() % 3));
		}
		int		gen_trait_3(void){
			return ((rand() % 3));
		}
		int		gen_trait_4(void){
			return ((rand() % 3));
		}
		// retrieve trait, these are used when the uses executes a 'view' command
		// it gets the correct trait from the list. ie. if type = 0 for hair
		// it will return "blue" because that's hair[0].
		string	get_hair(int type){
			return (hair[type]);
		}
		string	get_eyes(int type){
			return (eyes[type]);
		}
		string	get_skin(int type){
			return (skin[type]);
		}
		string	get_trait_1(int type){
			return (trait_1[type]);
		}
		string	get_trait_2(int type){
			return (trait_2[type]);
		}
		string	get_trait_3(int type){
			return (trait_3[type]);
		}
		string	get_trait_4(int type){
			return (trait_4[type]);
		}
};

class nym : public traits
{
private:
	string	_name;
	int		hair; // saves the hair trait in the form of a number, ie. 0 is blue
	int		eyes;
	int		skin;
	int		trait_1;
	int		trait_2;
	int		trait_3;
	int		trait_4;
	traits	traits;
public:
	void set_name(string name){
		// this function allows the user to set a name for their nym.
		_name = name;
	}
	void generate_nym(nym nym){
		// this function generates a new nym using the code mentioned above
		nym.hair = traits.gen_hair();
		nym.eyes = traits.gen_eyes();
		nym.skin = traits.gen_skin();
		nym.trait_1 = traits.gen_trait_1();
		nym.trait_2 = traits.gen_trait_2();
		nym.trait_3 = traits.gen_trait_3();
		nym.trait_4 = traits.gen_trait_4();
	}
	// this returns the traits for real (this is probably why it's dying lmao)
	string get_name(){
		return _name;
	}
	string get_hair(){
		// basically gets the word related to the number, say hair = 0, then
		// this function will return hair[0], which is "blue"
		// this is how all these functions work
		return traits.get_hair(hair);
	}
	string get_eyes(){
		return traits.get_eyes(eyes);
	}
	string get_skin(){
		return traits.get_skin(skin);
	}
	string get_trait_1(){
		return traits.get_trait_1(trait_1);
	}
	string get_trait_2(){
		return traits.get_trait_2(trait_2);
	}
	string get_trait_3(){
		return traits.get_trait_3(trait_3);
	}
	string get_trait_4(){
		return traits.get_trait_4(trait_4);
	}
};

class nyms
{
private:
	nym user_nyms[2];

public:
	nyms();
	void	show_nyms(){
		// this function is supposed to output 
		// the characteristics of the 2 generated starter nyms
		// but it's broken rn bc I suck at coding.
		int i;

		i = 0;
		while (i < 2)
		{
			cout << "Name: " << user_nyms[i].get_name() << endl;
			cout << "Hair colour: " << user_nyms[i].get_hair() << endl;
			cout << "Eye colour: " << user_nyms[i].get_eyes() << endl;
			cout << "skin type: " << user_nyms[i].get_skin() << endl;
			cout << "trait 1: " << user_nyms[i].get_trait_1() << endl;
			cout << "trait 2: " << user_nyms[i].get_trait_2() << endl;
			cout << "trait 3: " << user_nyms[i].get_trait_3() << endl;
			cout << "trait 4: " << user_nyms[i].get_trait_4() << endl;
			i++;
		}
	}
};

#endif