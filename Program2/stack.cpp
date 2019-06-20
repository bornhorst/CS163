//Ryan Bornhorst
#include "stack.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

order::order()
{
	desc = NULL;
	barcode = 0;
	manufacture = NULL;
	quantity = 0;
}
order::~order()
{
	delete [] desc;

	
	delete [] manufacture;
			
}
int order::create_entry(char descrip[],char manu[],int bar, int quant)
{
	//figure this out
	desc = new char[strlen(descrip)+1];
	manufacture = new char[strlen(manu)+1];
	barcode = bar;
	quantity = quant;
	strcpy(desc,descrip);
	strcpy(manufacture,manu);		
	
}

int order::copy_entry(const order & new_order)
{
	if(!(new_order.desc || new_order.manufacture))
	{
		cout<<"There was an error."<<endl;
		return 0;	
	}
	if(new_order.desc)
	{
		desc = new char[strlen(new_order.desc)+1];
		strcpy(desc,new_order.desc);
	}
	if(new_order.manufacture)
	{
		manufacture = new char[strlen(new_order.manufacture)+1];
		strcpy(manufacture,new_order.manufacture);
	}
	barcode = new_order.barcode;
	quantity = new_order.quantity;	


}

int order::display()const
{
	cout<<"Description: "<<desc;
	cout<<"\nBarcode: "<<barcode;
	cout<<"\nManufacturer: "<<manufacture;
	cout<<"\nQuantity: "<<quantity<<endl;


}
bool again()
{
	char again = 'y';
	cout<<"Add again? (y or n)";
	cin>>again;cin.ignore(100,'\n');
	if(again == 'y' || again == 'Y')
		return true;
	else
		return false;
}
stack::stack()
{
	head = NULL;
	top_index = 0;
}
stack::~stack()
{

	while(head)
	{
		node*temp = head;
		head = head->next;
		delete temp;
	}
}
int stack::push(const order & to_add)
{
	
	if(!head)
	{
		head = new node;
		head->orders = new order[MAX];
		head ->next = NULL;
		top_index = 0;
	}
	if(top_index == MAX)
	{
		node*temp = head;
		head = new node;
		head ->orders = new order[MAX];
		head->next = temp;
		top_index = 0;
	}
	if(head->orders[top_index].copy_entry(to_add))
		++top_index;
	else
		return 0;
	return 1;
}
int stack::display_all()const
{
	if(!head)
		return 0;
	node*current = head;
	while(current)
	{
	int t = top_index;
		for(int i = t-1;i>=0;--i)
		{
		current->orders[i].display();
		}
		current = current->next;
		t = 5;

	}
	return 1;
}
	
