//Ryan Bornhorst
//CS 163
//Program 2

//This is the .h file for my program.  It contains
//the list, stack, and queue data members.
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct warehouse
{//a struct for a warehouse, creates arrays for the items
	char descrip[100];
	char manu[100];
	int bar;
	int quant;
};




class item//class for each item in the warehouse
{
	public:
		item();
		~item();
		int read_in(warehouse & get_data);//read in from client
		int copy_data(const item & new_dept);//copy data
		void display();//display items
		char *item1(){return descr;};//return item description
		
	private:
		char *descr;//data members for item
		char *manu;
		int bar;
		int quan;
};




struct node
{//node for an item object
	
	item data;
	node*next;
};



class list
{//class for creating a list of items
	public:
		list();
		~list();
		int create_list(const item & to_add);//create list
		int display_all();//display list
		int compare(char item[]);//compare items in list
		int copy_list(const list & copy);
		

	private:
		node*head;//list data members
		node*tail;//head and tail pointers
	
};




class order//class for an order of items
{
	public:
		order();
		~order();
		int copy_entry(const order & new_order);//copy order
		int create_entry(char *,char*, int,int);//create order
		int display()const;//display order
	private:
		char *desc;
		int barcode;//order data members
		char *manufacture;
		int quantity;
};


struct s_node
{	
	//node pointer for an order
	order* orders;
	s_node *next;
};
const int MAX = 5;//size of the array in the stack


//a stack class
class stack
{
	public:
		stack();
		~stack();
		int display_all()const;//display items in the stack
		int push(const order & to_add);//add to the stack
		int peek();//peek at top of stack
		
	private:
		s_node *head;
		int top_index;//data members for the stack
};		


struct q_node
{
	//node for the queue
	order q_order;
	q_node*next;
};

class queue
{//the queue class
	public:
		queue();
		~queue();
		int enqueue(order & add);//enqueue
		int dequeue();//dequeue
		int peek();//peek
		int display_all()const;//show all
	private:
		q_node*rear;//data member for queue
	
};
