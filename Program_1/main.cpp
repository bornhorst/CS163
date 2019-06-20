//Ryan Bornhorst
//CS163
//Project 1
//10-14-15


//This is the main.cpp file for the program.  This file handles all of the testing of the
//class candidate and the linked list ADT.  All of the prompts happen in this file as well
//as all of the error handling.

#include <iostream>
#include <cctype>
#include <cstring>
#include "candidate.h"

using namespace std;


void get_can(char name[],char party[], char views[],char thoughts[],int& poll);
int can_menu();
int main()
{
	const int SIZE = 100;
	char name[SIZE];//variable for name
	int poll = 0;//variable for poll position
	char party[SIZE];//variable for party
	char thoughts[SIZE];//variable for thoughts
	char views[SIZE];//variable for views
	candidate new_candidate;//candidate object
	list new_list;//list object

	int user_input = 0;
char repeat = 'y';
while(repeat == 'y' || repeat == 'Y')
{//continue until user is done adding candidates
	user_input = can_menu();
	if(user_input == 1)
	{//add new candidate
		get_can(name, party,views,thoughts,poll);
	      	if(!new_list.add(name,party,views,thoughts,poll))
			cout<<"Problem with function.";
	}
	else if(user_input == 2)//display all candidates
	{
		if(!new_list.display_all())
			cout<<"No list.";
	}
	else if(user_input == 3)//display in alphabetical order
	{
		if(!new_list.display_by_party())
			cout<<"No list.";
	}
	else if(user_input == 4)//find candidates by party
	{
		char parties[20];
		cout<<"Enter party that you are looking for: ";
		cin.get(parties,100,'\n');
		cin.ignore(100,'\n');
		if(!new_list.display_party(parties))
			cout<<"No List.";
	}
	else if(user_input == 5)//update poll
	{
		char cannie[20];
		int pos = 0;
		cout<<"Enter candidates name: ";
		cin.get(cannie,100, '\n');
		cin.ignore(100, '\n');
		cout<<"\nEnter new postion: ";
		cin>>pos;
		cin.ignore(100, '\n');
		new_list.update_poll(cannie,pos);
	}
	cout<<"Would you like to go back to the menu? (y or n)";
	cin>>repeat;
	cin.ignore(100,'\n');
	if(repeat == 'n' || repeat == 'N')
		return 0;
}

return 0;
}


//function that brings up a menu for inputting candidates
//a way to test the ADT
//returns input from user
int can_menu()
{
	int user_input = 0;
	cout<<"\nWelcome"<<endl;
	cout<<"Choose an option from the list."<<endl;
	cout<<"Enter the corresponding number."<<endl;
	cout<<"1. Add a Candidate"<<endl;
	cout<<"2. Display All Candidates"<<endl;
	cout<<"3. Display All Candidates Alphabetically"<<endl;
	cout<<"4. Display Candidates by Party"<<endl;
	cout<<"5. Update Candidate Poll Position"<<endl;
	cout<<"6. Exit"<<endl;
	cin>>user_input;
	cin.ignore(100, '\n');
	return user_input;
}



//function that prompts the user for information
//allowing us to test the ADT
void get_can(char name[],char party[],char views[],char thoughts[],int& poll)
{
	int view_num = 0;
	char more_views = 'y';
	cout<< "Enter name: ";//prompt user for information
	cin.get(name, 100, '\n');
	cin.ignore(100, '\n');
	cout<<"Enter party: ";
	cin.get(party, 100,'\n');
	cin.ignore(100, '\n');
	cout<<"Enter Poll Position: ";
	cin>>poll;
	cin.ignore(100,'\n');
	while(more_views == 'y' || more_views == 'Y')
	{
		if(view_num < 5)
		{//allow multiple views
			
			cout<<"Enter views: ";
			cin.get(views, 100, '\n');
			cin.ignore(100, '\n');
			
			++view_num;
			
			cout<<"Enter more views? (y or n)";
			cin>>more_views;
			cin.ignore(100,'\n');
		}
		else
		{
			cout<<"No more than 5 views please."<<endl;
			more_views = 'n';
		}
	}
	cout<<"Enter thoughts: ";
	cin.get(thoughts, 100, '\n');
	cin.ignore(100, '\n');
	

}



