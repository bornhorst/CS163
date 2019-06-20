//Ryan Bornhorst
//CS163 Program 2
//This .cpp file containes all of the functions that implement the linear linked list
//the stack and the queue.

#include <iostream>
#include <cctype>
#include <cstring>
#include "list.h"
using namespace std;


//constructor for an item in the warehouse
item::item()
{
	descr = NULL;
	manu = NULL;
	bar = 0;
	quan = 0;
}



//destructor for an item in the warehouse
item::~item()
{
	delete [] descr;
	
	delete [] manu;
	
}



//This function reads in an item from the warehouse
int item::read_in(warehouse & get_data)
{
	
	if(descr)
		delete [] descr;//if these already exist we need to delete them
	if(manu)
		delete [] manu;	
	descr = new char[strlen(get_data.descrip)+1];//create dynamic arrays of items
	strcpy(descr,get_data.descrip);//copy the data
	manu = new char[strlen(get_data.manu)+1];
	strcpy(manu,get_data.manu);
	bar = get_data.bar;
	quan = get_data.quant;
	return 1;
}



//This function hard copies items that were read in from the user
//if there are no items then it will return 0
//else it will hard copy and return true
int item::copy_data(const item & new_item)
{
	if(!(new_item.descr || new_item.manu))
		return 0;//if no items return 0
	if(new_item.descr)
	{
		descr = new char[strlen(new_item.descr)+1];
		strcpy(descr,new_item.descr);//hard copy the data
	}
	if(new_item.manu)
	{
		manu = new char[strlen(new_item.manu)+1];
		strcpy(manu,new_item.manu);
	}
	bar = new_item.bar;
	quan = new_item.quan;
	return 1;//everything worked
}



//Function that displays items in the warehouse
void item::display()
{
	cout<<"Item Description: "<<descr;
	cout<<"\nManufacturer: "<<manu;
	cout<<"\nBarcode: "<<bar;
	cout<<"\nQuantity: "<<quan<<endl;	

}



//Constructor for the LLL	
list::list()
{
	//initialize head and tail
	head = NULL;
	tail = NULL;
}



//Destructor for the LLL
list::~list()
{
	while(head)//delete the list
	{
		node*temp = head;
		head = head->next;
		delete temp;
	}
	head =tail = NULL;//set head to NULL
}



//Function that creates the LLL from the data
//stored in the warehouse
//Returns false if the data was not able to be copied from
//the warehouse
int list::create_list(const item & to_add)
{
        node*temp = new node;//create new node
	bool success = temp->data.copy_data(to_add);//copy the data
	if(success)//if copy was successfull
	{	
	if(!head)
	{//head is null, we need a new node
		head = tail = temp;
		tail->next = NULL;
	}
	else
	{//we need to add new items to the list
		tail->next = temp;
		tail = tail->next;
		tail->next = NULL;
	
	}
	}
	else
	{//if unsuccessful we need to delete our node
		delete temp;
		return 0;//did not work
	}
	return success;//True if successful
}



//Function that displays all of the data in the
//LLL
//Returns 0 if list is empty
int list::display_all()
{
	if(!head)//no list
		return 0;
	node*current = head;//current point to head
	while(current)
	{
		current ->data.display();//display the list
		current = current ->next;
	}
	return 1;//there was a list
}



//Function that finds if an item exists in the list
//If it exists then we return the number associated 
//with the item
//if the list is empty then we return 30

int list::compare(char item[])
{
	node*current = head;
	int count = 0;
	if(!head)//nothing in the list
		return 30;
	while(current)
	{
		if(strcmp(item,current->data.item1())==0)//does it exist?
			return count;//return number associated with item
		current = current->next;
		++count;//increment
	}
	if(!current)
		return 20;
}



//Constructor for the queue	
queue::queue()
{
	rear = NULL;
}



//Destructor for the queue
queue::~queue()
{
	if(!rear)
		return;
	q_node*temp = rear->next;
	rear->next = NULL;//turn CLL into LLL
	while(temp)
	{
		q_node*current = temp;
		temp =temp->next;
		delete current;//delete the list
	}
	
}



//Funciton that builds the queue
//Utilizes a CLL to build the queue
//If data could not be copied then return 
//0
int queue::enqueue(order & add)
{
	if(!rear)
	{//Nothing in list, need to make s node
		rear = new q_node;
		if(!rear ->q_order.copy_entry(add))
			return 0;
		rear->next = rear;
	}
	else
	{//list is hear, need to add to the list
		q_node*temp = rear->next;
		rear->next = new q_node;
		rear = rear->next;
		if(!rear->q_order.copy_entry(add))
			return 0;//copy the data
		rear->next = temp;
	}
	return 1;
}



//Function that removes an item from teh queue
//Return 0 if there is nothing to remove
//else success
int queue::dequeue()
{
	if(!rear)
		return 0;//no list
	if(rear->next == rear)
	{//only 1 item in the list
		delete rear;
		rear = NULL;
	}
	else
	{//more that 1 item in the list
		q_node*temp = rear->next;
		rear->next = temp->next;
		delete temp;
	}
	return 1;//success
}



//Funciton that peeks at the first item in the queue
//Return 0 if there is no list
int queue::peek()
{
	if(!rear)//no list
		return 0;
	q_node*temp = rear->next;//peek at front
	temp->q_order.display();
	return 1;
}



//Function that displays all of the items in a queue
//Return 0 if there is nothing to display
int queue::display_all()const
{
	if(!rear)
		return 0;//nothing in queue
	q_node*temp = rear->next;
        rear->q_order.display();	
	while(temp != rear)
	{//display the items in the queue

		temp->q_order.display();
		temp = temp->next;
	}	
	return 1;//success
	
}



//Constructor for an order
order::order()
{//set data to initial values
	desc = NULL;
	barcode = 0;
	manufacture = NULL;
	quantity = 0;
}



//Destructor for an order
order::~order()
{
//delete dynamic arrays
	if(desc)
		delete [] desc;

	if(manufacture)
		delete [] manufacture;
			
}



//Function that creates an order from the warehouse
//based on the users input
int order::create_entry(char descrip[],char manu[],int bar, int quant)
{
	if(desc)//if these already exist we need to delete
		delete [] desc;
	if(manufacture)
		delete [] manufacture;
	desc = new char[strlen(descrip)+1];//copy the data
	manufacture = new char[strlen(manu)+1];
	barcode = bar;
	quantity = quant;
	strcpy(desc,descrip);
	strcpy(manufacture,manu);		
	return 1;	
}



//Funciton that hard copies the data for an order
int order::copy_entry(const order & new_order)
{
	if(!(new_order.desc || new_order.manufacture))
	{//if there is no data to copy
		return 0;	
	}
	if(new_order.desc)
	{//hard copy the data
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
	return 1;//success

}



//Function taht displays all of the items in an order
int order::display()const
{
	cout<<"Description: "<<desc;
	cout<<"\nBarcode: "<<barcode;
	cout<<"\nManufacturer: "<<manufacture;
	cout<<"\nQuantity: "<<quantity<<endl<<endl;
	return 1;	

}



//Constructor for the stack
stack::stack()
{
	head = NULL;//ititialize data members
	top_index = 0;
}



//Destructor for the stack
stack::~stack()
{
//Delete nodes and arrays within the stack
	while(head)
	{
		s_node*temp = head;
		head = head->next;
		delete[] temp->orders;
		delete temp;
	}
}



//Funciton that allows an item to be added onto
//the stack
int stack::push(const order & to_add)
{
	
	if(!head)//no items in the stack yet
	{
		head = new s_node;
		head->orders = new order[MAX];//place item in stack
		head ->next = NULL;
		top_index = 0;//reset top index
	}
	else if(top_index == MAX)//stack node is full
	{
		s_node*temp = head;
		head = new s_node;//add a new node
		head ->orders = new order[MAX];//add order to top
		head->next = temp;
		top_index = 0;//reset top index
	}
	if(head->orders[top_index].copy_entry(to_add))//copy the data to the stack
		++top_index;//increment the index within the stack
	else
		return 0;//not successful
	return 1;//success
}



//Function that peeks at the top of the stack
int stack::peek()
{
	if(!head)
		return 0;
	head->orders[top_index-1].display();	
	return 1;
}


//Function that displays all of the items within a stack
int stack::display_all()const
{
	if(!head)
		return 0;//nothing in the stack
	s_node*current = head;
	
	while(current)
	{//traverse through stack
	int t = top_index;
		for(int i = t-1;i>=0;--i)
		{
		current->orders[i].display();//display items within the arrays
		}
		current = current->next;
		t = 5;//reset the index

	}
	return 1;
}
	
