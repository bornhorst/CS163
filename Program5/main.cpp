//Ryan Bornhorst
//CS163
//Program5
//main cpp file

#include "graph.h"

const int NAME = 20;
const int EVENT = 50;//const ints for array sizes
bool again();//prototype


//main program
int main()
{
char a_name[NAME];//initiallize variables
char an_event[EVENT];
int a_date = 0;

table a_graph;//table object
friends a_friend;//friend object

cout<<"\nEnter in a friends name and an event that happened in chronological order."<<endl;

do
{//while again

	cout<<"\nEnter a name: ";//take input from user
	cin.get(a_name,NAME,'\n');
	cin.ignore(100,'\n');
	cout<<"\nEnter an event: ";
	cin.get(an_event,EVENT, '\n');
	cin.ignore(100,'\n');
	cout<<"\nEnter the year of the event: ";
	cin>>a_date;
	cin.ignore(100,'\n');
	if(!a_friend.create_entry(a_name,an_event,a_date))//create a friend
		cout<<"\nError creating entry."<<endl;
	if(!a_graph.insert_vertex(a_friend))//insert into table
		cout<<"\nError inserting into the graph."<<endl;
}while(again());

char connected[100];
do
{//while again
	cout<<"Enter two friends that are connected:";
	cin.get(a_name,100,'\n');cin.ignore(100,'\n');
	cin.get(connected,100,'\n');cin.ignore(100,'\n');
	if(!a_graph.insert_edge(a_name, connected))//create an adjacency
		cout<<"\nError making first connection."<<endl;
	if(!a_graph.insert_edge(connected, a_name))//connect both ways
		cout<<"\nError making second connection."<<endl;
}while(again());

cout<<"\nThis is a list of all of your friends and events."<<endl;

a_graph.display_all();//display the table

do
{
	cout<<"Enter a name to see their connections:";
	cin.get(a_name,100,'\n');
	cin.ignore(100,'\n');
	cout<<"\nThese are the connections that "<<a_name<<" has."<<endl;

	a_graph.display_adjacent(a_name);//display friends that are connected
	
}while(again());

return 0;

}



//function that asks user if they want to repeat
bool again()
{
char choice = 'z';
while(!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'))
{
	cout<<"Go again? (Y or N)";
	cin>>choice;
	cin.ignore(100,'\n');
}
if(choice == 'y' || choice == 'Y')
	return true;//repeat
else 
	return false;
}
