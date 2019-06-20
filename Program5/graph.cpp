//Ryan Bornhorst
//CS163
//Program 5
//graph cpp file

#include "graph.h"


//constructor
friends::friends()
{//set variables to NULL
	name = NULL;
	event = NULL;
	date = 0;
}



//destructor
friends::~friends()
{//deallocate memory
	delete [] name;
	delete [] event;
}



//create an entry for the friends class
int friends::create_entry(char a_name[], char an_event[],int a_date)
{
	if(!a_name || !an_event)
		return 0;
	name = new char[strlen(a_name)+1];
	strcpy(name, a_name);
	event = new char[strlen(an_event)+1];
	strcpy(event, an_event);
	date = a_date;
	return 1;
}



//hard copy the variables for the friends class
int friends::copy_entry(const friends & to_copy)
{
	if(!to_copy.name || !to_copy.event)
		return 0;
	name = new char[strlen(to_copy.name)+1];
	strcpy(name, to_copy.name);
	event = new char[strlen(to_copy.event)+1];
	strcpy(event, to_copy.event);
	date = to_copy.date;
	return 1;
}



//determine if the names match
bool friends::compare(char *match)
{
	if(strcmp(name,match)==0)
		return true;//match
	else 
		return false;//no match
}



//dispay the data for friends class
int friends::display()
{
	cout<<"\nFriend: "<<name;
	cout<<"\nEvent: "<<event;
	cout<<"\nYear: "<<date<<endl;
	return 1;
}



//constructor for the table
table::table(int size)
{
	adjacency_list = new vertex[size];
	for(int i = 0;i<size;++i)//set pointers to NULL
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].events = NULL;
	}
	list_size = size;//initialize size of the list
}



//destructor for the table
table::~table()
{
	for(int i = 0;i<list_size;++i)
	{
		while(adjacency_list[i].head)
		{
			node*temp = adjacency_list[i].head;
			adjacency_list[i].head = adjacency_list[i].head->next;
			delete temp;
			
		}
		delete adjacency_list[i].events;
	
		adjacency_list[i].head=NULL;
		adjacency_list[i].events = NULL;

	}
}



//function that inserts vertexes into the table
int table::insert_vertex(const friends & to_add)
{
	int i = 0;
    	while(adjacency_list[i].events != NULL && i < list_size)
    	{
     		++i;//determine the size of the list
    	}
    	if(i == list_size)
        	return 0;//is the list full
            
    	adjacency_list[i].events = new friends;//create a new friend
    	adjacency_list[i].events->copy_entry(to_add);//copy the data
            
    	return 1;
}



//function that inserts an edge into the list
int table::insert_edge(char*current_vert,char*to_attach)
{
	int pos = find_loc(current_vert);//starting vertex
        int pos2 = find_loc(to_attach);//vertex to attach to
        if(pos == -1 || pos2 == -1)//cant attach
            return 0;
        node*temp = adjacency_list[pos].head;
        adjacency_list[pos].head = new node;//create node
        adjacency_list[pos].head->adjacent=&adjacency_list[pos2];//copy to new location
        adjacency_list[pos].head->next = temp;
	return 1;

}



//function that finds where a friend is located in the list
int table::find_loc(char *key_value)
{
 	for(int i=0;i<list_size;++i)//search list
      	{
            	if(adjacency_list[i].events->compare(key_value))
            	{
                	return i;//return the location
            	}
            
      	}
      	return -1; //not found
}



//function that displays everything in the list
int table::display_all()
{
	for(int i = 0;i<list_size;++i)
	{//iterate through the list

		if(adjacency_list[i].events == NULL)
			return 0;//nothing
		else
		adjacency_list[i].events->display();//display data

	
	}
	return 1;
}



//function that recursively goes through the list
//and displays the data
int table::display_list(node*head)
{
	if(!head)
        	return 0;//nothing
    	head->adjacent->events->display();
    	display_list(head->next);//recursive call
    	return 1;
}



//function that displays a vertexes adjacency list
//if the search term matches
int table::display_adjacent(char * key_value)
{
    
   for(int i = 0;i <list_size;++i)
   {//iterate
       if(!adjacency_list[i].head)
           return 0;//nothing
       if(adjacency_list[i].events->compare(key_value))
       {//if found then display adjacent members
            
           display_list(adjacency_list[i].head);
       }
   }
   return 1;
}

