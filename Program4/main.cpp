//Ryan Bornhorst
//CS163
//Program4
//Main for program 4
//handles all of the prompts for the program



#include "tree_head.h"
//constant ints
const int CONCEPT = 20;
const int DATA_STRUCT = 30;
const int ADVANT = 50;
const int DISADVANT = 50;
//prototypes for main only
int menu();
bool again();
bool menu_again();

int main()
{
char concept[CONCEPT];//variables for arguments
char data_s[DATA_STRUCT];
char advant[ADVANT];
char disadvant[DISADVANT];
programs a_program[20];//array of programs
BST a_BST;//BST
node *root = NULL;
int i = 0;

int input = 0;

do
{//while you want to be in the menu

	input = menu();

	if(input == 0)
	{//input info
	do
	{//while there is more info
		cout<<"\nEnter a concept: ";
		cin.get(concept,CONCEPT,'\n');
		cin.ignore(100,'\n');
		cout<<"\nEnter a data struct: ";
		cin.get(data_s,DATA_STRUCT,'\n');
		cin.ignore(100,'\n');
		cout<<"\nAdvantages: ";
		cin.get(advant,ADVANT,'\n');
		cin.ignore(100,'\n');
		cout<<"\nDisadvantages: ";
		cin.get(disadvant,DISADVANT,'\n');
		cin.ignore(100,'\n');
		a_program[i].read(concept,data_s,advant,disadvant);//read the info
		a_BST.insert(root,a_program[i]);//insert into the tree
		++i;//increment counter
	}while(again());
	}
	else if(input == 1)
	{//display the tree sorted
		cout<<"\nThis is the content of the BST "
    		    <<"in SORTED ORDER.";
	
		if(!a_BST.display(root))
			cout<<"\nThe tree is EMPTY."<<endl;
	}
	else if(input == 2)
	{//display a specific concept

		char find[20];
		cout<<"\nEnter a concept that you would like to find: ";
		cin.get(find,100,'\n');
		cin.ignore(100,'\n');
		cout<<"\nThese are the nodes in the tree that match your search."<<endl;
		if(!a_BST.retrieve(root,find))
			cout<<"That concept is not in the list."<<endl;
		cout<<endl;
	}
	else if(input == 3)
	{//delete a specific concept
		char del[20];
		cout<<"\nEnter a concept to delete: ";
		cin.get(del,100,'\n');
		cin.ignore(100,'\n');
		a_BST.remove_conc(root,del);
		if(a_BST.retrieve_con(root,del))
			cout<<"The first instance "
			    <<"of that concept was"
			    <<" deleted but there "
			    <<"are more concepts "
			    <<"that match your "
			    <<"search in the tree."
			    <<" \nDelete the rest by"
			    <<" choosing option 3 "
			    <<"from the menu and "
			    <<"typing in "
			    <<del<<" again."<<endl;
	}
	else if(input == 4)
	{//delete a specific data struct
		char del2[20];
		cout<<"\nEnter a data struct to delete: ";
		cin.get(del2,100,'\n');
		cin.ignore(100,'\n');
		a_BST.remove_data_s(root,del2);
		if(a_BST.retrieve_ds(root,del2))
			cout<<"The first instance "
			    <<"of that data "
			    <<"structure was "
			    <<"deleted but there "
			    <<"are more concepts "
			    <<"that match your "
			    <<"search in the tree."
			    <<"  \nDelete the rest "
			    <<"by choosing option "
			    <<"4 from the menu and"
			    <<" typing in "
			    <<del2<<" again."<<endl;
			
	}	
	else if(input == 5)
	{//show the trees height
		int height = a_BST.height(root);
		if(height == 0)
			cout<<"The tree is EMPTY."<<endl;
		cout<<"\nThe height is: "<<height<<endl;
	}
	else if(input == 6)
		return 0;//exit the program
}while(menu_again());


return 0;
}



//function that asks user if they want to stay
//in the menu
bool menu_again()
{
	char menu = 'z';
	while(!(menu == 'y' || menu == 'Y' || menu == 'n' || menu == 'N'))
	{
		cout<<"Would you like to go back to the menu? (y or n)";
		cin>>menu;
		cin.ignore(100,'\n');
	}
	if(menu == 'y' || menu == 'Y')
		return true;
	else
		return false;
}



//function that asks user if they want to 
//do something again
bool again()
{
	char again = 'z';
	while(!(again == 'y' || again == 'Y' || again == 'n' || again == 'N'))
	{
		cout<<"Go again? (y or n)";
		cin>>again;
		cin.ignore(100,'\n');
	}
	if(again == 'y' ||again == 'Y')
		return true;
	else 
		return false;
}



//funciton that display a menu to user 
//and asks the user to select an option
int menu()
{

int choice = 0;
cout<<"\nChoose an option from the menu."
    <<"\nType in a corresponding number."
    <<"\n0. Add items into the tree."
    <<"\n1. Display the BST in sorted order."
    <<"\n2. Search for an item in the tree."
    <<"\n3. Delete an item by concept."
    <<"\n4. Delete an item by data structure."
    <<"\n5. Find the height of the tree."
    <<"\n6. Leave the menu.";
	cout<<endl;
    cin>>choice;
    cin.ignore(100,'\n');
	return choice;//return user choice
}
