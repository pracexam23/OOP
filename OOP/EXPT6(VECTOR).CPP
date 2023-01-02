#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class student
{
	public:
		string name;
		int DOB;
		int tele_no;
		int roll_no;
		
		bool operator==(const student &s1)
		{
			if(name==s1.name)
			   return 1;
			 return 0;  
		}
		
		bool operator<(const student &s1)
		{
			if(roll_no<s1.roll_no)
			  return 1;
			 return 0; 
			  
		}
		
};
vector<student>o1;
void insert();
void display();
void print1(student &s1);
void search();
void del();


void insert()
		{    
		
		    student s1;
			cout<<"\n enter name:";
			cin>>s1.name;
			cout<<"enter date of birth:"<<endl;
			cin>>s1.DOB;
			cout<<"\n enter roll number:";
			cin>>s1.roll_no;
			cout<<"enter telephone number:"<<endl;
			cin>>s1.tele_no;
			
			o1.push_back(s1);
		}
		void display()
		{
           for_each(o1.begin(),o1.end(),print1);	
			
		}
		void print1(student &s1)
		{
			cout<<"name:"<<s1.name<<endl;
			cout<<"date of birth:"<<s1.DOB<<endl;
			cout<<"roll number:"<<s1.roll_no<<endl;
			cout<<"telephone number:"<<s1.tele_no<<endl;
			
		}
		void search()
		{
			student s1;
			vector<student>::iterator i;
			
			cout<<"\n enter name of student to be search";
			cin>>s1.name;
			
			i=find(o1.begin(),o1.end(),s1);
			if(i==o1.end())
			{
				cout<<"\n Not found";
			}
			else 
			{
				cout<<"\n student found";
			}
		}
		bool compare(const student &s1,const student &s2)
        {
     	return s1.roll_no<s2.roll_no;
        }

		void del()
		{
			vector<student>::iterator i;
			student s1;
			cout<<"\n enter name of student to be delete";
			cin>>s1.name;
			
			i=find(o1.begin(),o1.end(),s1);
			
			if(i==o1.end())
			{
				cout<<"\n not found";
			}
			else
			{
				o1.erase(i);
				cout<<"\n deleted";
			}
		}
int main()
{
	int ch;
	
   do
   {
   	cout<<"\n...menu...";
   	cout<<"\n 1.insert";
   	cout<<"\n 2.dsiplay";
   	cout<<"\n 3.search";
   	cout<<"\n 4.sort";
   	cout<<"\n 5.delete";
   	cout<<"\n 6.exit";
    
    
    cout<<"\n enter your choice:";
    cin>>ch;
    
    switch(ch)
    {
    	case 1: cout<<"\n enter datails of student:";
    	     insert();
    	     break;
    	case 2: cout<<"\n display details of student:";
		     display();
			 break;
		case 3: 
		     search();
			 break;
		case 4:
		     sort(o1.begin(),o1.end(),compare);
		     cout<<"\n sorted order on roll number";
		     display();
			 break;
		case 5:
		     del();
			 break;	 	 	      
    	case 6: cout<<"\n wrong choice"	;
    	     break;
	}
   }
   while(ch!=6);
	
	return 0;
}