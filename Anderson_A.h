//class
#include<iostream>
#include<cstring>
#include "card.h"

int const MAX=5;

//The node for the queue class
struct q_node
{
	card a_card;
	q_node * previous;
	q_node * next;
};

//The node for the stack class
struct s_node
{
	card * a_card;
	s_node * next;
};

//The class for the queue data structure 
class queue
{
	public:
		queue();
		~queue();
		int enqueue(card & to_add);
		int dequeue(card & to_delete);
		int display_all();
		int display_question();
	private:
		q_node * rear;
};

//The class for the stack data structure
class stack
{
	public:
		//queue
		stack();
		~stack();
		int push(card & to_push);
		int pop(card & to_pop);
		int peek();
		int display_all();
	private:
		s_node * head;
		int top_index;
};

