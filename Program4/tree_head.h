//Ryan Bornhorst
//CS163
//Program4
//header file for the binary search tree
//handles all of the member functions for classes
//and all of the private data members for the
//classes

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


//class that keeps track of the data for the concepts
//and data structures
class programs
{

	public: 
		programs();
		~programs();
		int read(char conc[],char data_s[],char advant[],char disadvant[]);//read from user
		int copy_data(programs &copy);//hard copy data
		int compare(programs &data);//compare data
		int display();//display data
		int match(char found[]);//find a match
		int match2(char found2[]);
		char*get_con(){return concept;}	//return concept	
	private:
		char *concept;//private data
		char *data_struct;
		char *advantage;
		char *disadvantage;
};

struct node
{//node for the BST
	programs data;
	node*left;//left and right pointer
	node*right;
};


//class for the BST data and member functions
class BST
{
	public:
	BST();//constructor
	~BST();//destructor
	void insert(node*&root,programs&copy);//insert into the tree
	int height(node*root);//find height just for fun
	int display(node*root);//display tree
	int retrieve(node*root,char found[]);//find and display
	int retrieve_con(node*root,char found[]);
	int retrieve_ds(node*root,char found[]);
	int remove_all();//delete the tree
	int remove_conc(node*&root,char remove[]);//find and delete concept	
	int remove_data_s(node*&root,char remove2[]);
	private:
	int remove_all(node*&root);//delete tree
	node*root;	
};

