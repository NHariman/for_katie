#ifndef NYMS_H
#define NYMS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdio.h>

# define AVERAGE	0
# define P_AQUA		1
# define F_AQUA		2
# define P_AVI		3
# define F_AVI		4
# define P_REP		6
# define F_REP		7
# define P_FUR		8
# define F_FUR		9

using namespace std;

class traits // this is where I store all available traits for nyms
{
	protected:
		const string	variant[9] = {"Average", "Partial Aquatic", "Full Aquatic", "Partial Avian", "Full Avian", "Partial Reptilian", "Full Repltilian", "Partial Furry", "Full Furry"};
		const string	hair[6] = {"blue", "red", "yellow", "brown", "grey", "silver"};
		const string	eyes[6] = {"blue", "red", "yellow", "brown", "grey", "silver"};
		const string	skin[4] = {"pale", "brown", "tan", "olive"};
		const string	ear_type[10] = {"None", "Average", "Webbed", "Holes", "Cat", "Dog", "Rabbit (S)", "Rabbit (L)", "Bear", "Mouse"};
		const string	nose_type[4] = {"None", "Average", "Cat", "Dog"};
		const string	wing_type[4] = {"None", "Bird", "Bat", "Insect"};
		const string	tail_type[8] = {"None", "Feathers", "Lizard", "Cat", "Dog", "Rabbit", "Bear", "Mouse"};
	public: 
	// this place contains the functions used to generate a random number which coincides with a trait, 
	//ie. if it lands on 0 for hair the hair colour would be blue.
		int		gen_variant(void){
			int i;
			
			i = rand() % ((*(&variant + 1) - variant) - 1);
			return (i);
		}
		int		gen_hair(){
			int i;

			i = rand() % ((*(&hair + 1) - hair) - 1);
			return (i);
		}
		int		gen_eyes(){
			int i;

			i = rand() % ((*(&eyes + 1) - eyes) - 1);
			return (i);
		}
		int		gen_skin(){
			int i;

			i = rand() % ((*(&skin + 1) - skin) - 1);
			return (i);
		}
		int		gen_ear_type(int var){
			int i;
			if (var == P_FUR || var == F_FUR) // if variant is Partial or Full Furry, start at the 4th position of the array (cat ears)
				i = (rand() % 6) + 3; // generates a random trait based on furry range
			else if (var == F_REP || var == P_REP) // if variant is FULL/PARTIAL REPTILIAN, only one option is available.
				i = 3;
			else if (var == F_AQUA || P_AQUA)
				i = (rand() % 2) + 1; // range between webbed or average ears
			else
				i = 1; // everyone else gets boring default ears
			return (i);
		}
		int		gen_nose_type(int var){
			int i;
			if (var == P_FUR || var == F_FUR)
				i = (rand() % 2) + 2;
			else if (var == F_REP || var == P_REP) // if variant is FULL/PARTIAL REPTILIAN, only one option is available.
				i = 0;
			else if (var == F_AQUA || P_AQUA)
				i = 0; // range between webbed or average ears
			else
				i = 1; // everyone else gets boring default ears
			
			return (i);
		}
		int		gen_wing_type(){
			int i;

			i = rand() % ((*(&wing_type + 1) - wing_type) - 1); // uses whole range for now because only avians can get here.
			// fun fact! there's now a chance for avians to be born without wings :) to remove that, add + 1 right in front of the ;
			return (i);
		}
		int		gen_tail_type(int var){
			int i;
			if (var == P_AVI || var == F_AVI)
				i = 1; // only one option rn.
			else if (var == P_REP || var == F_REP)
				i = 2; // also only one option rn.
			else
				i = (rand() % 5) + 3; // everyone else is a furry nym
			// all nyms except for average and aquatic can have tails. the range once again depends on the var.
			return (i);
		}
		// retrieve trait, these are used when the uses executes a 'view' command
		// it gets the correct trait from the list. ie. if type = 0 for hair
		// it will return "blue" because that's hair[0].
		string	get_variant(int type){
			return (variant[type]);
		}
		string	get_hair(int type){
			return (hair[type]);
		}
		string	get_eyes(int type){
			return (eyes[type]);
		}
		string	get_skin(int type){
			return (skin[type]);
		}
		string	get_ear_type(int type){
			return (ear_type[type]);
		}
		string	get_nose_type(int type){
			return (nose_type[type]);
		}
		string	get_wing_type(int type){
			return (wing_type[type]);
		}
		string	get_tail_type(int type){
			return (tail_type[type]);
		}
};

class nym : public traits
{
private:
	string	_name;
	int		variant;
	int		hair; // saves the hair trait in the form of a number, ie. 0 is blue
	int		eyes;
	int		skin;
	int		ear_type;
	int		nose_type;
	int		wing_type;
	int		tail_type;
	traits	traits;
public:
	void set_name(string name){
		// this function allows the user to set a name for their nym.
		_name = name;
	}
	void generate_nym(){
		// this function generates a new nym using the code mentioned above.
		// first it generates a variant, and then based on this variant, other characteristics are generated.
		variant = traits.gen_variant();
		hair = traits.gen_hair();
		eyes = traits.gen_eyes();
		skin = traits.gen_skin();
		ear_type = traits.gen_ear_type(variant);
		nose_type = traits.gen_nose_type(variant);
		if (variant == P_AVI || variant == F_AVI)
			wing_type = traits.gen_wing_type();
		if (variant > F_AQUA)
			tail_type = traits.gen_tail_type(variant);
	}
	int		_variant(){
		return variant;
	}
	// this returns the traits for real (this is probably why it's dying lmao)
	string get_name(){
		return _name;
	}
	string get_variant(){
		return traits.get_variant(variant);
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
	string get_ear_type(){
		return traits.get_ear_type(ear_type);
	}
	string get_nose_type(){
		return traits.get_nose_type(nose_type);
	}
	string get_wing_type(){
		return traits.get_wing_type(wing_type);
	}
	string get_tail_type(){
		return traits.get_tail_type(tail_type);
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
		int i;

		i = 0;
		while (i < (*(&user_nyms + 1) - user_nyms))
		{
			cout << "Name: " << user_nyms[i].get_name() << endl;
			cout << "Variant: " << user_nyms[i].get_variant() << endl;
			cout << "Hair colour: " << user_nyms[i].get_hair() << endl;
			cout << "Eye colour: " << user_nyms[i].get_eyes() << endl;
			cout << "skin type: " << user_nyms[i].get_skin() << endl;
			cout << "Ear type: " << user_nyms[i].get_ear_type() << endl;
			cout << "Nose type: " << user_nyms[i].get_nose_type() << endl;
			if (user_nyms[i]._variant() == P_AVI || user_nyms[i]._variant() == F_AVI)
				cout << "Wing type: " << user_nyms[i].get_wing_type() << endl;
			if (user_nyms[i]._variant() > 2)
				cout << "Tail type: " << user_nyms[i].get_tail_type() << endl;
			cout << endl;
			i++;
		}
	}
};

#endif