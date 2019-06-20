//Ryan Bornhorst
//CS163
//Program4

//.cpp file for BST
//handles all of the functions for the
//classes within the header file

#include "tree_head.h"



//Constructor for the program class
programs::programs()
{//set private data to NULL
	concept = NULL;
	data_struct = NULL;
	advantage = NULL;
	disadvantage = NULL;
}



//Destructor for the program class
programs::~programs()
{//delete dynamic arrays
	delete [] concept;
	delete [] data_struct;
	delete [] advantage;
	delete [] disadvantage;
}



//Function that reads in from user and stores the data
int programs::read(char conc[],char data_s[],char advant[],char disadvant[])
{//initialize all variables dynamically

	concept = new char[strlen(conc)+1];
	strcpy(concept,conc);
	data_struct = new char[strlen(data_s)+1];
	strcpy(data_struct,data_s);
	advantage = new char[strlen(advant)+1];
	strcpy(advantage,advant);
	disadvantage = new char[strlen(disadvant)+1];
	strcpy(disadvantage,disadvant);
	return 1;
}



//Function that displays all of the private
//data members
int programs::display()
{//display all variables
	cout<<"\n\nConcept: "<<concept<<endl;
	cout<<"Data Struct: "<<data_struct<<endl;
	cout<<"Advantages: "<<advantage<<endl;
	cout<<"Disadvantages: "<<disadvantage;
	cout<<endl;
}



//Function that hard copies data into the 
//private data members
int programs::copy_data(programs&copy)
{
	if(!(copy.concept || copy.data_struct || copy.advantage || copy.disadvantage))
		return 0;
	concept = new char[strlen(copy.concept)+1];
	strcpy(concept,copy.concept);
	data_struct = new char[strlen(copy.data_struct)+1];
	strcpy(data_struct,copy.data_struct);
	advantage = new char[strlen(copy.advantage)+1];
	strcpy(advantage,copy.advantage);
	disadvantage = new char[strlen(copy.disadvantage)+1];
	strcpy(disadvantage,copy.disadvantage);
	return 1;
}



//function that compares two concept strings
//returns result
int programs::compare(programs&data)
{
	return strcmp(concept,data.concept);
}



//Function that determines if a concept
//matches the user input
int programs::match(char found[])
{
	if(strcmp(concept,found)==0)
		return 1;//match
	else
		return 0;//no match
}



//Function that determines if a data struct
//matches the user input
int programs::match2(char found2[])
{
	if(strcmp(data_struct,found2)==0)
		return 1;//match
	else
		return 0;//no match
}



//Constructor for the BST		
BST::BST()
{//set root to null
	root = NULL;
}



//Destructor for the BST
BST::~BST()
{//delete the tree
	remove_all(root);
}



//Function that inserts the nodes into the
//BST	
void BST::insert(node*&root,programs&copy)
{

if(!root)
{
	root = new node;
	root->data.copy_data(copy);
	root->right = root->left=NULL;
}
else if(root->data.compare(copy)<0)
	insert(root->left,copy);
else
	insert(root->right,copy);
	
}



//Function that displays the nodes of 
//the tree in sorted order
int BST::display(node*root)
{
	if(!root)
		return 0;//nothing to display
	if(root)
	{//sorted order
		display(root->right);
		root->data.display();
		display(root->left);
	}
	return 1;
}



//Function that finds if a concept is
//located within one of the trees nodes
int BST::retrieve(node*root,char found[])
{
	if(!root)
		return 0;//nothign to retrieve
	if(root->data.match(found))
		root->data.display();//display match
	retrieve(root->left,found);
	retrieve(root->right,found);
	return 1;
}


//Function that finds if a concept is 
//located in the tree but does not display
int BST::retrieve_con(node*root,char found[])
{
	if(!root)
		return 0;
	if(root->data.match(found))
		return 1;//there is a match	
	
	retrieve_con(root->left,found);
	
	retrieve_con(root->right,found);
	return 0;
	
}



//Function that finds if a data struct 
//is located in the tree but does not display
int BST::retrieve_ds(node*root,char found[])
{
	if(!root)
		return 0;
	if(root->data.match2(found))
		return 1;//there is a match
	retrieve_ds(root->left,found);
	retrieve_ds(root->right,found);
	return 0;
}



//Function that recursively calles the 
//remove all function	
int BST::remove_all()
{
	return remove_all(root);
}



//Function that removes all nodes from
//the tree
int BST::remove_all(node*&root)
{
	if(!root)
		return 0;//nothing
	remove_all(root->left);
	remove_all(root->right);
	delete root;
	root = NULL;
	return 1;
}



//Function that checks the height of the tree
int BST::height(node*root)
{
	if(!root)
		return 0;//nothing
	return(max(height(root->left),height(root->right))+1);
}



//Function that removes a node from the BST based on
//the concept of that nodes data
int BST::remove_conc(node*&root,char remove[])
{
if(!root)
	return 0;//nothing

if(root->data.match(remove))//data matches the search
{
	
	//case 1... no root
	if(root->left == NULL && root->right == NULL)
	{
		delete root;
		root = NULL;
	}//case 2.. no right child
	else if(root->left == NULL && root->right !=NULL)
	{
		node*temp = root->right;
		delete root;
		root = temp;
	}//case 3.. no left child
	else if(root->left != NULL && root->right == NULL)
	{
		node*temp = root->left;
		delete root;
		root = temp;
	}//case 4 and 5... two children
	else
	{	
		if(root->right->left == NULL)
		{//find inorder successor	
			
			node*temp=root->right->right;
			root->data.copy_data(root->right->data);
			delete root->right;
			root->right = temp;
		}
		else
		{//find inorder successor
			node*current = root->right;
			node*prev = NULL;
			
			while(current->left)
			{
				prev = current;
				current =current->left;
				//travel iteratively
			}
			prev->left=current->right;
			root->data.copy_data(current->data);
			delete current;
		}
	}
return 1;	
}

remove_conc(root->left,remove);
remove_conc(root->right,remove);

}

//Function that removes a node from the BST based on
//the data struct of that nodes data
int BST::remove_data_s(node*&root,char remove2[])
{
if(!root)
	return 0;

if(root->data.match2(remove2))//data matches the search
{
	
	//case 1... no root
	if(root->left == NULL && root->right == NULL)
	{
		delete root;
		root = NULL;
	}//case 2.. no right child
	else if(root->left == NULL && root->right !=NULL)
	{
		node*temp = root->right;
		delete root;
		root = temp;
	}//case 3.. no left child
	else if(root->left != NULL && root->right == NULL)
	{
		node*temp = root->left;
		delete root;
		root = temp;
	}//case 4 and 5... two children
	else
	{	
		if(root->right->left == NULL)
		{//find inorder successor	
		
			node*temp = root->right->right;
			root->data.copy_data(root->right->data);
			delete root->right;
			root->right = temp;
		}
		else
		{//find inorder successor
			node*current = root->right;
			node*prev = NULL;
			
			while(current->left)
			{
				prev = current;
				current =current->left;
				
			}
			prev->left=current->right;
			root->data.copy_data(current->data);
			delete current;
		}
	}
return 1;	
}

remove_data_s(root->left,remove2);
remove_data_s(root->right,remove2);

}			
