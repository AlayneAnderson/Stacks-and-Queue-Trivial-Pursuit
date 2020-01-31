//card class implementation
#include"card.h"
using namespace std;

card::card()
{
	question = NULL;
	answer= NULL;
}

card::~card()
{
	delete [] question;
	delete [] answer;
	question= NULL;
	answer = NULL;
}

//To add a card to the data structure
int card::add(char * q_source, char * a_source)
{
	if(q_source)
	{
		question= new char[strlen(q_source)+1];
		strcpy(question, q_source);
	}
	if(a_source)
	{
		answer= new char[strlen(a_source)+1];
		strcpy(answer, a_source);
	}
	return 1;
}

//This is a function to copy the question and answer from another card
//to the current card
int card::copy(card & copy_from)
{
	if(copy_from.question)
	{
		question= new char[strlen(copy_from.question)+1];
		strcpy(question, copy_from.question);
	}
	if(copy_from.answer)
	{
		answer=new char[strlen(copy_from.answer)+1];
		strcpy(answer, copy_from.answer);
	}
	return 1;
}

//This function gets a card and passes it to the queue data structure
int card::get(card & current)
{
	current.question= new char[strlen(question)+1];
	strcpy(current.question, question);
	current.answer= new char[strlen(answer)+1];
	strcpy(current.answer, answer);
	return 1;
}

//will display both the question and the answer
int card::display_all()
{
	if(display_q()==1 && display_a()==1)
	{
	display_q();
	display_a();
	return 1;
	}
	else
	return 0;
}
//displays the question in a card
int card::display_q()
{
	if(question)
	{
		cout<<"The question is:"<<question<<endl;
		return 1;
	}
	return 0;
}

//this will display the answer to a card
int card::display_a()
{
	if(answer)
	{
		cout<<"The answer is:"<<answer<<endl;
		return 1;
	}
	return 0;
}

//this function checks the answer from the user
int card::check(char * user_answer)
{
	if(answer !=NULL)
	{
		if(strcmp(user_answer,answer)==0)
			return 1;
		else
			return 0;
	}
}
