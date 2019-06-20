//Ryan Bornhorst

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class order
{
	public:
		order();
		~order();
		int copy_entry(const order & new_order);
		int create_entry(char *,char*, int,int);
		int display()const;
	private:
		char *desc;
		int barcode;
		char *manufacture;
		int quantity;
};


struct node
{	
	order *orders;
	node *next;
};
const int MAX = 5;
class stack
{
	public:
		stack();
		~stack();
		int display_all()const;
		int peek(order & at_top);
		int push(const order & to_add);
		int pop();
		
	private:
		node *head;
		int top_index;
};		



