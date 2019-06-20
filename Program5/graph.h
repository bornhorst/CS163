//Ryan Bornhorst
//CS163
//Program5
//graph header file


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class friends
{//class to make a friend
	public:
		friends();//constructor
		~friends();//destructor
		int create_entry(char a_name[],char an_event[],int a_date);
		int copy_entry(const friends & to_copy);//hard copy
		bool compare(char * match);//compare name
		int display();//display data
	private:
		char *name;//data
		char *event;
		int date;
};



//vertex
struct vertex
{//pointers
	friends * events;
	struct node*head;

};

struct node
{//node pointer
	vertex *adjacent;
	node *next;
};

class table
{//table class
	public:
		table(int size = 10);//constructor
		~table();//destructor
		int insert_vertex(const friends & to_add);//create vertex
		int find_loc(char * key_value);//find vertex
		int insert_edge(char *current_vert,char*to_attach);//create edge
		int display_all();//display table
		int display_adjacent(char *key_value);//display adjacencies

		int display_list(node*head);//recursive display		
	private:
		
		vertex *adjacency_list;//pointer to vertex
		int list_size;//size of the list
		
};


#endif
