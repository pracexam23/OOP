//Write a C++ program that creates an output file, writes information to it, closes the file, open
//it again as an input file and read the information from the file.

#include <iostream>
#include <fstream>
 
using namespace std;


class employee
{
	char name[20];
	int emp_id;
	float salary;
	public:
	void accept()
	{
		cin>>name;
		cin>>emp_id;
		cin>>salary;
	}


	void display()
	{
		cout<<"\n"<<name<<"\t"<<emp_id<<"\t"<<salary;
	}
};


int main()
{
	employee o[5];  // employee o; array of object
	fstream f;
	int i,n;


	f.open("input.txt"); //create employee
	cout<<"\n How many employee information wanted to store:";

	cin>>n;
	cout<<"\n Enter information of "<<n<<" employees (Enter name, emp_id, salary)";
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter information of "<<i<<" employee";
		o[i].accept(); //accept input from user
		f.write((char *)&o[i], sizeof(o[i])); //write object in employee
	}
	f.close();


	f.open("input.txt", ios::in);
	cout<<"\n Information of employee is as follows";
	for(i=0;i<n;i++)
	{
		f.read((char*)&o[i], sizeof(o[i])); //read data from employee
		o[i].display();
	}
	f.close();


	return 0;
}
