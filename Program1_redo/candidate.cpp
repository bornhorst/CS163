//cpp file for the candidate

#include "candidate.h"

candidate::candidate()
{
	name = NULL;
	thought = NULL;
	views = NULL;
	rank = 0;
}

candidate::~candidate()
{
	delete [] name;
	delete [] thought;
	delete [] views;
}

int candidate::read(char a_name[], int a_rank,char a_thought[],char a_view[])
{
	name = new char[strlen(a_name)+1];
	strcpy(name, a_name);
	rank = a_rank;
	thought = new char[strlen(a_thought)+1];
	strcpy(thought, a_thought);
	views = new char[strlen(a_view)+1];
}


int candidate::copy(candidate & copy)
{
	name = new char[strlen(copy.name)+1];
	strcpy(name,copy.name);
	thought = new char[strlen(copy.thought)+1];
	strcpy(thought,copy.thought);
	views = new char[strlen(copy.views)+1];
	rank = copy.rank;
	
}

int candidate::display()
{
	cout<<"\nCandidiate: "<<name
	    <<"\nViews: "<<views
            <<"\nRank: "<<rank
	    <<"\nYour Thoughts: "<<thought<<endl;
}

list::list()
{
	head = NULL;
}

list::~list()
{
	while(head)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

int list::build(candidate & to_add)
{
	if(!head)
	{
		head = new node;
		head->data.copy(to_add);
		head->next = NULL;
	}
	else if(!head->next)
	{
		node*temp = new node;
		head->next = temp;
		temp->data.copy(to_add);
		temp->next = NULL;
	}
	else
	{
		node*current = head;
		while(current->next)
		{
			current = current ->next;
		}
		node*temp = new node;
		temp->data.copy(to_add);
		current->next = temp;
		temp->next = NULL;
	}
}

int list::display()
{
	if(!head)
		return 0;
	node*current = head;
	while(current)
	{
		current->data.display();
		current=current->next;
	}
}

