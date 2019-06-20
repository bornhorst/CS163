//Ryan Bornhorst
//CS163
//10-14-15



//This file manages all of the candidate class member functions as well as
//all of the list member functions.

#include <iostream>
#include <cctype>
#include <cstring>
#include "candidate.h"

using namespace std;

//constructor
//initiallizes all private variables in candidate class
candidate::candidate()
{
	name = NULL;
        party = NULL;

	views = NULL;
	num_views = 0;
	num_parties = 0;
	thoughts = NULL;
	poll_rank = 0;

}



//copy constructor
//copies everything from the constructor
/*candidate::candidate(const candidate&other)
{
	name = other.name;
	poll_rank = other.poll_rank;
	party = new char*[10];
	views = new char*[10];
	num_views = other.num_views;
	num_parties = other.num_parties;
	thoughts = other.thoughts;
	for(int i = 0; i < num_parties;++i)
	{
		party[i] = new char[strlen(other.party[i])];
		strcpy(party[i],other.party[i]);
	}

	
	for(int i = 0;i<num_views;++i)
	{
		views[i] = new char[strlen(other.views[i])];
		strcpy(views[i],other.views[i]);
	}
}

*/
//destructor
//deallocates memory from dynamic arrays
candidate::~candidate()
{
	delete name;
	delete party;
	delete thoughts;
	delete views;
}

bool candidate::get_info(char name_in[],char party_in[],char views_in[],char thoughts_in[],int poll)
{
		if(name_in == NULL || party_in == NULL || views_in == NULL || thoughts_in == NULL)
			return false;	
		//deep copy all of candidate
		//data
		name = new char[strlen(name_in)+1];
		strcpy(name, name_in);

		party = new char[strlen(party_in)+1];
		strcpy(party,party_in);
			
	
		
		views = new char[strlen(views_in)+1];
		strcpy(views, views_in);
		
		
		

		thoughts = new char[strlen(thoughts_in)+1];
		strcpy(thoughts, thoughts_in);
		poll_rank = poll;

	return true;
}



//function that displays the information of the candidate
//if the argument matches the party of the candidate
//takes a char array as an argument
//returns false if it doesn't work... true otherwise
int candidate::display(char parties[])
{       
	if(party_compare(parties)==false)
		return 0;
	if(party_compare(parties) == true)
		display();//parties match
	return 1;
}



//function that compares candidate parties with a party
//input from the user 
bool candidate::party_compare(char parties[])
{
	
	
		if(strcmp(party,parties)==0)
			return true;//parties match
		else
			return false;
	
	
	
}



//function that displays all of the candidates info
char candidate::display()
{
	cout<<"Name:  ";
	for(int i = 0;name[i] != '\0';++i)
		cout<<name[i];
	cout<<endl;
	cout<<"Party:  ";
	for(int i = 0;party[i] != '\0';++i)
		cout<<party[i];
	cout<<endl;
	cout<<"Poll Position:  "<<poll_rank<<endl;
	cout<<"Views:  "<<endl;
	cout<<"------"<<endl;
	for(int i = 0;views[i] != '\0'; ++i)
	{
		cout<<views[i];
	}
	cout<<endl;
	cout<<"Your Thoughts:  "<<endl;
	cout<<"--------------"<<endl;
	for(int i = 0;thoughts[i] != '\0'; ++i)
		cout<<thoughts[i];
	cout<<endl;
	
}



//functino that compares the names of candidates
//returns an integer value
int candidate::compare_name(char other[])
{
	return strcmp(name,other);//check name for match
}



//constructor
//initializes all private variables
list::list()
{
	size_array = 30;
	candidates = new candidate[size_array];
	num_candidates = 0;
	head = NULL;
}


//destructor
//deallocates dynamic memory
list::~list()
{
	delete [] candidates;
	while(head != NULL)
	{	
		node * temp = head;
		head = head -> next;
		delete temp;
	}
}



//function that reads in a new arrival to the candidate
//list from the user
bool list::add(char name[],char party[],char views[],char thoughts[],int poll)
{
	
       	if(!candidates[num_candidates].get_info(name,party,views,thoughts,poll))
		return false;
	
	
	++num_candidates;
	return true;
	
	
	
}


//function that displays everything in the list
bool list::display_all()
{
	if(num_candidates == 0)
		return false;//nothing in list
	for(int i = 0; i < num_candidates; ++i)
		candidates[i].display();
	return true;
}


//function that displays candidates that fall into
//a particular party
bool list::display_party(char parties[])
{
	if(num_candidates == 0)
		return false;

	for(int i = 0;i<num_candidates;++i)
	{
		candidates[i].display(parties);
		cout<<endl;
	
	}
	
	return true;
}



//function that displays the candidates in the list
//organized by candidate name
int list::display_by_party()
{
    	
	if(head != NULL)
	{
		while(head != NULL)
		{
			node*temp = head;
			head = head -> next;
			delete head;
		}
	}
	for(int i = 0; i < num_candidates;++i)
	{	
		insert(new candidate(candidates[i]));
	}
	node * current = head;
	while(current != NULL)
	{
		cout<<current ->data->display();
		current = current -> next;
	}
	return 1;
}

//function that updates a candidates postion in the polls
//takes in a name and compares it. Then it updates the
//candidates poll position.
bool list::update_poll(char names[],int new_pos)
{
	node* current = head;
	while(current)
	{
		if(strcmp(current->data->name,names) ==0)
		current->data->poll_rank = new_pos;
		current = current->next;
	}
}
	
//function that build the list of candidates.  places
//the first candidate at the head of the list, then 
//compares the newly entered candidates to determine 
//what order they should go within the list.
void list::insert(candidate *insert)
{
	if(head == NULL)//time to make list
	{
		head = new node;
		head->data = insert;
		head->next = NULL;
	}
	else
	{//time to add to list
		node*current = head;
		node*previous = current;
		//add in sorted order
		while(current != NULL && current -> data->compare_name(insert->get_name())<= 0)
		{
			previous = current;
			current = current->next;
		}
		if(current == NULL)//add to end
		{
			current = new node;
			current ->data = insert;
			current ->next = NULL;
			previous ->next = current;
		}
		else if(current == head)//add a new head
		{
			head = new node;
			head ->data = insert;
			head ->next = current;
		}
		else
		{//add in front of current
			previous ->next = new node;
			previous ->next->data = insert;
			previous->next->next = current;
		}
	}
}
