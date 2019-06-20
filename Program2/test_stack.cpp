//Ryan Bornhorst
//CS163
//Program 2

//This is the main.cpp of my program.
//It tests the program to make sure that 
//all of the ADTs work properly.

#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

bool again();
int menu();

int main()
{

warehouse house[20];//max items in the warehouse
queue a_queue;//queue object
stack my_stack;//stack object
order an_order;//order object
item an_item;//item object
list a_list;//list object

ifstream fin;//read in from the file
int i = 0;
fin.open("warehouse.dat");
if(fin)
{	
	fin.get(house[i].descrip,100,':');//read in 
	fin.ignore(100,':');//prime pump
	while(!fin.eof() && i <6)//while not end of file
	{
		fin.get(house[i].manu,100,':');
		fin.ignore(100,':');
		
		fin>>house[i].bar;fin.ignore(100,':');
		fin>>house[i].quant;fin.ignore(100,'\n');
		++i;
		
		fin.get(house[i].descrip,100,':');//prime pump for more items
		fin.ignore(100,':');
	}
	fin.close();//close file

	
}

//read in all the items from the warehouse
for(int i = 0;i<6;++i)
{
	an_item.read_in(house[i]);	//read in
	if(!(a_list.create_list(an_item)))//create the list of items
		cout<<"Error with creation."<<endl;
}

	
cout<<"These are the items in the WAREHOUSE."<<endl<<endl;
	if(!(a_list.display_all()))//display the list of items in the warehouse
		cout<<"Can't display list."<<endl;

char item[100];
int amount = 0;

do
{
	cout<<"Enter the item you would like: ";//promp the client
	cin.get(item,100,'\n');cin.ignore(100,'\n');//read in
        int item_num = a_list.compare(item);//compare item to client input
	if(item_num == 30)
		cout<<"No list"<<endl;	
	if(item_num == 20)
	{//the client entered something not in the warehouse
		cout<<"Sorry we dont't carry that."<<endl;
			
	}
	else
	{	//we have a match
		cout<<"We have those.  How many would you like? ";
		cin>>amount;cin.ignore(100,'\n');//read in amount
	}
	
	int new_amount = 0;
	if(amount <= house[item_num].quant && item_num != 20 && item_num != 30)
	{	//if there is stock, add to the queue
		cout<<"We have that many in stock!"<<endl;		
		cout<<"The order has been added to the queue."<<endl;
		new_amount = house[item_num].quant - amount;//keep amount ordered
		house[item_num].quant = new_amount;//update amount
		
		an_order.create_entry(house[item_num].descrip,house[item_num].manu,house[item_num].bar,amount);//update the warehouse
		a_queue.enqueue(an_order);		//add to the queue
	}
	else if(amount > house[item_num].quant && item_num != 20 && item_num != 30)
	{//not in stock... add to the stack
		cout<<"We don't current have that many in stock."<<endl;
		cout<<"The order has been added to the stack."<<endl;
			an_order.create_entry(house[item_num].descrip,house[item_num].manu,house[item_num].bar,amount);//update warehouse
			if(!(my_stack.push(an_order)))//add to the stack
			cout<<"Error with the List."<<endl;
	}
}while(again());//while orders are to be added
	cout<<"THE ITEMS IN THE QUEUE ARE: "<<endl;
	if(!a_queue.display_all())//display the queue
		cout<<"The queue is empty."<<endl;
	cout<<"THE ITEMS IN THE STACK ARE: "<<endl;//display the stack
	if(!my_stack.display_all())
		cout<<"The stack is empty."<<endl;
	char peek = 'y';
	cout<<"Would you like to peek at the top of the queue?"<<endl;
	cin>>peek;
	cin.ignore(100,'\n');
	if(peek == 'y' || peek == 'Y')
	{
		cout<<"THE TOP OF THE QUEUE."<<endl;
		if(!a_queue.peek())//peek at the top of the queue
			cout<<"Nothing to peek at."<<endl;
	}
	do
	{
		char dequeue = 'y';
		cout<<"Would you like to ship out the top of your queue?";
		cin>>dequeue;
		cin.ignore(100,'\n');
		if(dequeue == 'y' || dequeue == 'Y')
		{
			if(!a_queue.dequeue())//dequeue an order
				cout<<"Nothing to dequeue."<<endl;
		}
		cout<<"THIS IS NOW THE QUEUE"<<endl;
		if(!a_queue.display_all())//display queue
			cout<<"The queue is empty."<<endl;
	}while(again());
	char peek2 = 'y';
	cout<<"Would you like to peek at the top of the stack?"<<endl;
	cin>>peek2;
	cin.ignore(100,'\n');
	if(peek2 == 'y' || peek2 == 'Y')
	{
		cout<<"THIS IS THE TOP OF THE STACK."<<endl;
		if(!my_stack.peek())//top of the stack
			cout<<"Nothing to peek at."<<endl;
	}
	
	cout<<"THESE ARE NOW THE CONTENTS OF THE QUEUE."<<endl;
	if(!a_queue.display_all())//final display
		cout<<"There is nothing to display."<<endl;
	cout<<"THESE ARE NOW THE CONTENTS OF THE STACK."<<endl;
	if(!my_stack.display_all())//final display
		cout<<"There is nothing to display."<<endl;

return 0;

}

bool again()
{
	char again = 'y';
	cout<<"Go again? (y or n)";
	cin>>again;cin.ignore(100,'\n');
	if(again == 'y' || again == 'Y')
		return true;
	else 
		return false;
}

