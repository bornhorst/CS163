//.h file for presidential candidate

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


class candidate
{
	public:
		candidate();
		~candidate();
		int read(char a_name[],int a_rank,char a_thought[],char a_view[]);
		int copy(candidate & copy);
		int display();

	private:
		char * name;
		char * thought;
		char * views;
		int rank;
};

struct node
{
	candidate data;
	node*next;
};

class list
{
	public:
		list();
		~list();
		int build(candidate & to_add);
		int display();
	private:
		node*head;
};
