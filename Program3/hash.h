//Ryan Bornhorst

//File that contains all of the prototypes for classes
//and all class implementations.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

//Constants for the struct
const int PERSON = 30;
const int DATE = 10;
const int CONTENT = 50;
const int KEYWORD = 30;
const int HASH = 30;


//Struct that stores a single posts data
struct post_data
{
	char person[PERSON];
	char date[DATE];
	char content[CONTENT];
	char hashword[HASH];
	int views;
};


//Functions that all the struct to read in data
void read(post_data & new_data);//read in post
void write(post_data & to_write);//write to file
void read_hash(post_data & new_hash);//read in hash
bool again();//while again
bool again2();
bool again3();


//Struct for a node for the hashtag list
struct h_node
{
	char *hash;
	h_node*next;
};

//Class that manages all the data for a single post
class post
{
	public:
		post();
		~post();
		int copy(post & to_copy);//copy data
		int create_hashlist(char *hash_w);//make hashtag list
		int display_hash();//display hashtag list
		int display();//display post	

	private:
		char *pers;//private data members
		char *dates;
		char *cont;
		h_node*head;
		h_node*tail;
		int view;
};


//Struct that manages a node for the list of posts
struct node
{
	post data;
	node*next;
};

//Class that manages the data for a list of posts
class list
{
	public:
		list();
		~list();
		int create(post & to_add);//create list of post	
		int display_all();//display list
	private:
		node*head;//private data members
		node*tail;
};


//Class that manages the data for the hashtable
class table
{
	public:
		table(int size = 17);
		~table();
		int insert(char *key,post & to_add);//create table
		int hash_fun(char *key)const;//hash function
		int display_all();//display table
		int retrieve(char*key);//find location in table
	private:
		node**hash;//private data members
		int hash_size;
};


