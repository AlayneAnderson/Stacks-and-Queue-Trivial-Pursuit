//Queue implementation
#include"Anderson_A.h"
using namespace std;

queue::queue()
{
	rear = NULL;
}

queue::~queue()
{
	if(rear)
	{
		q_node * head=rear->next;
		rear->next=NULL;
		while(head!=NULL)
		{
			delete head;
			head= head->next;
		}
	}
}

//This function adds a new card which name is to_add as the argument
//in the rear of the queue and returns one if it is successful
int queue::enqueue(card & to_add)
{
	if(rear==NULL)
	{
		rear = new q_node;
		rear->a_card.copy(to_add);
		rear->next=rear;
		return 1;
	}
	
	q_node *temp= new q_node;
	temp->a_card.copy(to_add);
	temp->next=rear->next;
	rear->next=temp;
	rear=temp;
	return 1;
}

//This function deletes a card in the start of the queue and copies the deleted card 
//to the outside by calling the get function from the card class
int queue::dequeue(card & to_delete)
{
	if(rear)
	{
		if(rear->next==rear)
		{
			rear->a_card.get(to_delete);
			delete rear;
			rear=NULL;
			return 1;
		}
		
		q_node * temp= rear->next;
		temp->a_card.get(to_delete);
		rear->next=temp->next;
		delete temp;
		return 1;
	}
	return 0;
}

//this function displays all the cards in the queue
int queue::display_all()
{
	if(!rear)
		return 0;
	else if(rear->next==rear)
	{
		rear->a_card.display_q();
		rear->a_card.display_a();
		return 1;
	}
	
	q_node * temp=rear->next;
	while(temp!=rear)
	{
		temp->a_card.display_q();
		temp->a_card.display_a();
		temp=temp->next;
	}
	rear->a_card.display_q();
	rear->a_card.display_a();
	return 1;
}

//this function displays the question inthe first card 
//returns 1 if success
int queue::display_question()
{
	if(rear)
	{
		rear->next->a_card.display_q();
		return 1;
	}
	else
	return 0;
}	
