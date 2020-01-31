//Alayne Anderson
//CS163 Karla Fant Fall 2019
//main file
#include<fstream>
#include "Anderson_A.h"
using namespace std;

int const SIZE=100;

int main()
{
	//definitions
	ifstream file_in;
	queue object;
	stack a_object;
	card a_card;
	char temp[SIZE];
	char a_temp[SIZE];
	char * question;
	char * answer;

	//Reading in information and putting it into the card class to be
	//used in answering questions
	file_in.open("questions.txt");
	if(!file_in)
	{
		cout<<"Error in opening the questions.txt file"<<endl;
	}
	else
	{
		file_in.getline(temp, SIZE,';');
		file_in.ignore(SIZE,';');
		while(!file_in.eof())
		{
			file_in.getline(a_temp,SIZE,'\n');
			file_in.ignore(SIZE,'\n');
			question= new char[strlen(temp)+1];
			strcpy(question, temp);
			answer= new char[strlen(a_temp)+1];
			strcpy(answer, a_temp);
			a_card.add(question, answer);
			object.enqueue(a_card);
			delete [] question; 
			delete [] answer;
			file_in.getline(temp, SIZE,';');
			file_in.ignore(SIZE,';');
		}
			file_in.close();
	}


//game starts 
	//The game is a question, answer game that can be played. 
	//The user can decide to stop playing the game whenever they would like too though
	char start;
	cout<<"This game is a game to guess the answer to questions"<<endl;
	cout<<"Would you like to begin?"<<endl;
	cin>>start;
	cin.ignore(100,'\n');
	int score =0;	
	card receiver;
	char user_answer[SIZE];
	char response;

	while(toupper(start)=='Y')
	{
	
			object.display_question();
			object.dequeue(receiver);
			if(toupper(response)=='N')
			{
				object.display_question();
				object.dequeue(receiver);
			}else
				a_object.pop(receiver);
		cout<<"Enter your answer:";
		cin.get(user_answer,SIZE,'\n');
		cin.ignore(SIZE,'\n');
		if(receiver.check(user_answer)==1)
		{
			++score;
			cout<<'\n'<<"Your answer is correct"<<endl;
			cout<<"Your score is:"<<score<<endl;
			object.enqueue(receiver);
		}else
		{
		cout<<'\n'<<"Your answer is wrong! Continue quessing."<<endl;
		a_object.push(receiver);
		}
		
	
	cout<<"Would you like to keep playing?"<<endl;
	cin>>start;
	cin.ignore(100,'\n');
	}
	if(score==5)
	{
		cout<<"You win!"<<endl;
		cout<<"Game over!"<<endl;
	}
	return 0;
}
