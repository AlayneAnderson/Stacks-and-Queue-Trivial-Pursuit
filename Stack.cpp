//Stack implementation

#include"Anderson_A.h"
using namespace std;

stack::stack()
{
	top_index=0;
	head = NULL;
}

stack::~stack()
{
	s_node * temp;
	while(head!=NULL)
	{
		temp= head->next;	
		delete [] head->a_card;
		delete head;
		head= temp;
	}
}


//This function pushes a new card to the top of the stack
//returns one if success
int stack::push(card & to_add)
{
	if(!head)
	{
		top_index=0;
		head= new s_node;
		head->a_card= new card[MAX];
		head->next=NULL;
		head->a_card[top_index].copy(to_add);
		++top_index;
		return 1;
	}else if(top_index<5)
	{
		head->a_card[top_index].copy(to_add);
		++top_index;
		return 1;
	}else
	{
		top_index=0;
		s_node * temp= new s_node;
		temp->a_card= new card[MAX];
		temp->a_card[top_index].copy(to_add);
		++top_index;
		temp->next=head;
		head= temp;
		return 1;
	}
	return 0;

}

//This function deletes the card at the top of the stack,
//and decreases the top index
int stack::pop(card & to_pop)
{
	if(!head)
	return 0;
	else if(top_index >0)
	{
		--top_index;
		head->a_card[top_index].get(to_pop);
		return 1;
	}else if(top_index ==0)
	{
		s_node * temp= head->next;
		temp->a_card[4].get(to_pop);
		delete[] head->a_card;
		delete head;
		head=temp;
		top_index=5;
		return 1;
	}
	return 0;
}

//Displays the question in the card at the top of the stack
int stack::peek()
{
	if(!head)
		return 0;
	else if(top_index >0)
	{
		head->a_card[top_index-1].display_q();
		return 1;
	}
	s_node * temp= head->next;
	if(temp!=NULL)
	{
		temp->a_card[4].display_q();
		return 1;
	}
	return 0;
}

//This function displays all the cards in the stack
int stack::display_all()
{
	int current= top_index;
	for(s_node * temp= head; temp !=NULL; temp=temp->next)
	{
		for(int i=current; i>0; --i)
		{
			temp->a_card[i-1].display_q();
			temp->a_card[i-1].display_a();
		}
		current=5;
	}
	return 1;
}
