//Ryan Bornhorst
//CS163
//Program3

//File that contains the main of my program
//This file allows the program to be fully tested

#include "hash.h"


int main()
{

post_data a_post[20];//post struct array
list a_list;//list of posts
table a_hash;//hash table of posts
int i = 0;
int j = 0;
do
{
	read(a_post[j]);//read in from user
	write(a_post[j]);//write data to file
	post new_post;//create a post from data file
	do
	{
		

		read_hash(a_post[i]);//read hashtag
		if(!new_post.create_hashlist(a_post[i].hashword))//create list of hashtags
			cout<<"Error creating hashlist."<<endl;
		a_hash.insert(a_post[i].hashword,new_post);//insert into hashtable
		++i;
	}while(again());

	if(!a_list.create(new_post))//create list of posts
		cout<<"Error creating."<<endl;
	cout<<endl;
	cout<<"\nThis is the list of hashwords for this post.";
	cout<<endl;
	if(!new_post.display_hash())//display hash list
		cout<<"Hash failed."<<endl;
	cout<<endl;

	char search[30];
	do
	{
	cout<<"\nEnter a hashword to find a post: ";
	cin.get(search,100,'\n');//search using a hashtag
	cin.ignore(100,'\n');
	cout<<endl;
		//if found display post
		if(a_hash.retrieve(search))
			cout<<"\nThese are all the posts that we found!"<<endl;
		else//none found with hashtag
			cout<<"The post could not be found."<<endl;
	}while(again3());
	++j;
}while(again2());
	cout<<"\nThese are all the posts that were made."<<endl;

if(!a_list.display_all())
	cout<<"Error displaying list of posts."<<endl;	
	cout<<"\nThis is the hashtable showing the location of each post."<<endl;
	cout<<"Posts with matching hashtags will be displayed more than once."<<endl;

if(!a_hash.display_all())//display everything in hashtable
	cout<<"Error with hash display."<<endl;

	
return 0;
}


