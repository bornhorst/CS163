//main program

#include "candidate.h"

const int NAME = 50;
const int THOUGHT = 100;
const int VIEW = 100;

bool again();

int main()
{
candidate a_candidate;
list a_list;
char a_name[NAME];
char a_thought[THOUGHT];
char a_view[VIEW];
int a_rank = 0;
do
{
cout<<"\nEnter candidate name: ";
cin.get(a_name,NAME,'\n');
cin.ignore(100,'\n');
cout<<"\nEnter the candidates views: ";
cin.get(a_view,VIEW,'\n');
cin.ignore(100,'\n');
cout<<"\nEnter the candidates poll position: ";
cin>>a_rank;
cin.ignore(100,'\n');
cout<<"\nEnter your thoughts: ";
cin.get(a_thought,THOUGHT,'\n');
cin.ignore(100,'\n');

a_candidate.read(a_name,a_rank,a_thought,a_view);
a_list.build(a_candidate);
}while(again());

cout<<"\nHere is the list......."<<endl;
a_list.display();

return 0;

}

bool again()
{
	char again = 'z';
while(!(again == 'Y' || again =='y' || again =='n' ||again == 'N'))
{
	cout<<"Would you like to go again? (Y or N)";
	cin>>again;
	cin.ignore(100,'\n');
}
if(again == 'y' || again == 'Y')
	return true;
else 
	return false;
}
	
