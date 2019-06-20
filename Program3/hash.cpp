//Ryan Bornhorst
//Program 3
//CS163

//This file contains all of my function implementations
//for program 3
#include "hash.h"



//This function reads in a new post from user
void read(post_data & new_data)
{
	cout<<"\nName of the person who wrote the post: ";	       cin.get(new_data.person,PERSON,'\n');
	cin.ignore(100,'\n');
	cout<<"\nDate of post: ";
	cin.get(new_data.date,DATE,'\n');
	cin.ignore(100,'\n');
	cout<<"\nThe content of the post: ";
	cin.get(new_data.content,CONTENT,'\n');
	cin.ignore(100,'\n');
	cout<<"\nNumber of views the post has: ";
	cin>>new_data.views;
	cin.ignore(100,'\n');
}



//This function reads in a hashtag from the user
void read_hash(post_data & new_hash)
{
	cout<<"\nEnter a hashtag for this post: ";
	cin.get(new_hash.hashword,HASH,'\n');
	cin.ignore(100,'\n');
}



//This function writes data to an external file
void write(post_data & to_write)
{

	ofstream f_out;//name filestream
	f_out.open("post.dat");//open
	if(f_out)
	{//write data to the file
		f_out<<to_write.person<<':'
		     <<to_write.date<<':'
		     <<to_write.content<<':'
		     <<to_write.views
		     <<endl;
		f_out.close();
	}
}



//Function that asks the user if they want to add
//another hashtag
bool again()
{
	char again = 'y';
	cout<<"\nEnter another hashtag? (y or n) ";
	cin>>again;
	cin.ignore(100,'\n');
	if(again == 'y' || again == 'Y')
		return true;
	else
		return false;
}



//Funciton that asks the user if they want to make another post
bool again2()
{
	char again2 = 'y';
	cout<<"\nMake another post? (y or n) ";
	cin>>again2;
	cin.ignore(100,'\n');
	if(again2 == 'y' ||again2 == 'Y')
		return true;
	else 	
		return false;
}



//Function that asks user if they want to search
//another hashtag
bool again3()
{
	char again3 = 'y';
	cout<<"\nSearch for another hashtag? (y or n) ";
	cin>>again3;
	cin.ignore(100,'\n');
	if(again3 == 'y' || again3 == 'Y')
		return true;
	else 
		return false;
}




//Constructor for post class
post::post()
{
	post_data post;//create struct
	ifstream fin;
	fin.open("post.dat");//open file
	if(fin)
	{
		fin.get(post.person,100,':');
		fin.ignore(100,':');//prime pump
			
		fin.get(post.date,100,':');
		fin.ignore(100,':');//read in from file
			
		fin.get(post.content,100,':');
		fin.ignore(100,':');
			
		fin>>post.views;
		fin.ignore(100,'\n');

		fin.close();//close file
	}
	//hardcopy the data members	
	pers = new char[strlen(post.person)+1];
	strcpy(pers,post.person);
	dates = new char[strlen(post.date)+1];
	strcpy(dates,post.date);
	cont = new char[strlen(post.content)+1];
	strcpy(cont,post.content);
	view = post.views;
	head = tail = NULL;//set head to NULL
}


//Destructor for post class			
post::~post()
{

		delete [] pers;//deallocate memory
		pers = NULL;
		delete [] dates;
		dates = NULL;
		delete [] cont;
		cont = NULL;
		while(head)//deallocate list of hashtags
		{
			h_node*temp = head;
			head = head->next;
			delete temp;
		}
		head =tail = NULL;
}



//Deep copies data into the post class data members
int post::copy(post & to_copy)
{
	if(!(to_copy.pers || to_copy.dates || to_copy.cont))
		return 0;
	if(to_copy.pers)//hardcopy all of the datamembers
	{
		pers = new char[strlen(to_copy.pers)+1];
		strcpy(pers,to_copy.pers);
	}
	if(to_copy.dates)
	{
		dates = new char[strlen(to_copy.dates)+1];
		strcpy(dates,to_copy.dates);
	}
	if(to_copy.cont)
	{
		cont = new char[strlen(to_copy.cont)+1];
		strcpy(cont,to_copy.cont);
	}
	view = to_copy.view;
	return 1;
}



//Function that displays the post data		
int post::display()
{
	if(!pers || !dates || !cont)
		return 0;
	cout<<"\nPerson: "<<pers;//display post data
	cout<<"\nDate: "<<dates;
	cout<<"\nContent: "<<cont;
	cout<<"\nNumber of views: "<<view;
	cout<<endl;
	return 1;
}


//Constructor for list class
list::list()
{
	head = NULL;
	tail = NULL;
}



//Destructor for list class
list::~list()
{
	while(head)
	{//deallocate list
		node*temp = head;
		head = head->next;
		delete temp;
	}
	head = tail = NULL;
}



//Function that creates a list of posts
int list::create(post & to_add)
{
	node*temp = new node;
	bool success = temp->data.copy(to_add);//copy data
	if(success)//if copied
	{
		if(!head)//create a list
		{
			head = tail = temp;
			tail->next = NULL;
		}
		else
		{//add to the list
			tail->next = temp;
			tail = tail->next;
			tail->next = NULL;
		}
	}
	else
	{//delete the node
		delete temp;
		return 0;
	}
	return success;//success or fail
}



//Function that creates a list of hashwords for a post
int post::create_hashlist(char*hash_w)
{
	h_node*temp = new h_node;
	if(!hash_w)
		return 0;
	
	if(!head)//create a list
	{
		head = tail = temp;
		temp->hash = hash_w;
		tail->next = NULL;
	}
	else//add to the list
	{
		tail->next = temp;
		temp ->hash = hash_w;
		tail = tail->next;
		tail->next = NULL;
	
	}
	return 1;
}


//Function that displays the list of hashwords
int post::display_hash()
{
	if(!head)//no list
		return 0;
	h_node*current = head;
	while(current)//display the list
	{
		cout<<current->hash<<" ";
		
		current = current->next;
	}
	return 1;
}


	
//Function that displays the list of posts
int list::display_all()
{
	if(!head)//no list
		return 0;
	node*current = head;
	while(current)//display the list
	{
		current->data.display();
		current = current->next;
	}
	return 1;
}



//Constructor for table class
table::table(int size)
{
	hash = new node*[size];//initialize table
	for(int i = 0;i < size;++i)
	{
		*(hash + i) = NULL;
	}
	hash_size = size;//set size
}




//Destructor for table class
table::~table()
{
	for(int i = 0;i < hash_size;++i)
	{//delete the hashtable
		while(hash[i])
		{	
			
			node*temp = hash[i];
			hash[i] = hash[i]->next;
			delete temp;

		}
		hash[i] = NULL;
	}
	delete [] hash;//delete arrays
}




//Function that creates a hashfunction from
//hashtag keywords
int table::hash_fun(char*key)const
{
	int size = strlen(key);
	int sum = 0;
	for(int i = 0;i<size;++i)
	{
		sum = key[i] + sum;//add all characters in 
	//hashtag
	}
	return sum % hash_size;//return position
}




//Function that creates a table from hashtag
//keywords
int table::insert(char*key, post & to_add)
{
	
	int pos = hash_fun(key);
	node*insert = new node;
	insert->next = *(hash + pos);//add to the table
	*(hash + pos) = insert;
	
	return 1;
}

//Function that displays a hashtable and the location
//of items within the hashtable
int table::display_all()
{
	
	for(int i = 0;i < hash_size;++i)//iterate
	{
		node*current = hash[i];
		while(current)
		{//show location in hash table
			cout<<"Location: "<<i + 1;
			current->data.display();//display list
			current = current->next;
		}
	}
	return 1;
}





//Function that uses the search function to display
//items that were searched for
int table::retrieve(char *key)
{
	int pos = hash_fun(key);
	if(hash[pos])//if data exists
	{
		node*current =hash[pos];
		while(current)//display the list at this location
		{
			current->data.display();
			current = current->next;
		}
	return 1;
	}
	else
		return 0;
}
