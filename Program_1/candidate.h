//Ryan Bornhorst
//CS163
//Program 1
//10-14-15


//This file includes of the candidate and list member function protottypes.
//It also manages the linked list node pointer, candidate pointer, and head
//pointer.

#include <iostream>
#include <cctype>
#include <cstring>


class candidate
{

	public:
		candidate();//constructor
		~candidate();//destructor
	//	candidate(const candidate&other);//copy constructor
		bool get_info(char name_in[],char party_in[],char views_in[],char thoughts_in[],int poll);
		
		char display();
		int display(char parties[]);
		int compare_name(char other[]);
		char *get_name(){return name;};//fuction that returns a candidates name

	
		char * name;//pointer to name variable
		char * party;//pointer to party array
		char * views;//pointer to views array
		char * thoughts;//pointer to thoughts variable
		int poll_rank;//pole position
		int num_views;//number of views
		int num_parties;//number of parties
		bool party_compare(char parties[]);
};

struct node//node for linked list
{
	candidate * data;
	node * next;
};

class list
{
	public:
		list();//constructor
		~list();//destructor
		bool add(char name[],char party[],char views[], char thoughts[],int poll);
		bool display_all();
		int display_by_party();
		bool display_party(char parties[]);
		bool update_poll(char names[],int new_pos);
		
	private:
		int size_array;//size of the array
		int num_candidates;//number of candidates
		candidate * candidates;//pointer to candidate class
		void insert(candidate *insert);
		

		node * head;
};
