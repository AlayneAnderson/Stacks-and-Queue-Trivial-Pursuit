//the declaration of a card type class ADT
#include<iostream>
#include<cctype>
#include<fstream>
#include<cstring>

class card
{
	public:
		card();
		~card();
		int add(char * q_source, char * a_source);
		int copy(card & copy_from);
		int get(card & current);
		int display_all();
		int display_q();
		int display_a();
		int check(char * user_answer);
	private:
		char * question; 
		char * answer;
};
