/*
Department maintains a student information. The file contains roll number,
name, division and address. Allow user to add, delete information of student.
Display information of particular employee. If record of student does not exist an
appropriate
*/
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

struct student
{
	int roll;
	char name[20];
};

class database
{
	struct student st;
	public:
		void insert_data();
		void read_data();
		void search_data();
		void update_data();
		void delete_data();
		void sort_data();
};
void database::sort_data()
{
	ifstream file;
	ofstream out;
	struct student st[50],temp;
	int i=0,n,j;

	file.open("database.txt",ios::binary|ios::in);
	file.read((char*)&st[i],sizeof(st[i])); 		//Important

	while(!file.eof())
	{
		i++;
		file.read((char*)&st[i],sizeof(st[i]));
	}
	file.close();

	n=i;

	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(st[i].roll>st[j].roll)
			{
				temp=st[i];
				st[i]=st[j];
				st[j]=temp;
			}
		}
	}
	out.open("database.txt",ios::binary|ios::trunc|ios::out);
	for(i=0;i<n;i++)
	{
		out.write((char*)&st[i],sizeof(struct student));
	}
	out.close();

}

void database::read_data()
{
	struct student st;
	ifstream file;

	file.open("database.txt",ios::binary|ios::in);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		cout<<"\n"<<st.roll<<"\t"<<st.name;
		file.read((char*)&st,sizeof(st));
	}

	cout<<"\n";

	file.close();
}

void database::update_data()
{
	struct student st;
	int roll_number,flag=0,flag1=0;
	ifstream file;
	ofstream ofile;

	cout<<"\nEnter the roll no. of the record that you want to search :";
	cin>>roll_number;

	file.open("database.txt",ios::binary|ios::in);
	ofile.open("db1.txt",ios::binary|ios::out|ios::trunc);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		if(roll_number==st.roll)
		{
			cout<<"\nRECORD FOUND!!!";
			cout<<"\nEnter new name of the student";
			cin>>st.name;
			ofile.write((char*)&st,sizeof(st));
			flag=1;flag1=1;
		}
			if(flag==0)
			{
				ofile.write((char*)&st,sizeof(st));
			}
			flag=0;
			file.read((char*)&st,sizeof(st));
	}
	if(flag1==0)
	{
		cout<<"\nRECORD NOT FOUND!!!\n";
	}
	cout<<"\n";
	remove("database.txt");
	rename("db1.txt","database.txt");

	file.close();
}

void database::delete_data()
{
	struct student st;
	int roll_number,flag=0,flag1=0;
	ifstream file;
	ofstream ofile;

	cout<<"\nEnter the roll no. of the record that you want to search :";
	cin>>roll_number;

	file.open("database.txt",ios::binary|ios::in);
	ofile.open("db1.txt",ios::binary|ios::out|ios::trunc);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		if(roll_number==st.roll)
		{
			cout<<"\nRECORD FOUND!!!";
			flag=1;flag1=1;
		}
		if(flag==0)
		{
			ofile.write((char*)&st,sizeof(st));
		}
		flag=0;
		file.read((char*)&st,sizeof(st));
	}
	if(flag1==0)
	{
		cout<<"\nRECORD NOT FOUND!!!\n";
	}
	cout<<"\n";
	remove("database.txt");
	rename("db1.txt","database.txt");

	file.close();
}

void database::search_data()
{
	struct student st;
	int roll_number,flag=0;
	ifstream file;

	cout<<"\nEnter the roll no. of the record that you want to search :";
	cin>>roll_number;

	file.open("database.txt",ios::binary|ios::in);

	file.read((char*)&st,sizeof(st)); 		//Important
	while(!file.eof())
	{
		if(roll_number==st.roll)
		{
			cout<<"\nRECORD FOUND!!!";
			cout<<"\n"<<st.roll<<"\t"<<st.name;
			flag=1;
			break;
		}
		file.read((char*)&st,sizeof(st));
	}
	if(flag==0)
	{
		cout<<"\nRECORD NOT FOUND!!!\n";
	}

	cout<<"\n";

	file.close();
}

void database::insert_data()
{
	ofstream file;

	file.open("database.txt",ios::binary|ios::out|ios::app);

	cout<<"Enter the roll and name of the student";
	cin>>st.roll>>st.name;


	file.write((char*)&st,sizeof(struct student));
	file.close();
}

int main()
{
	database obj;
	int choice;
	while(1)
	{
		cout<<"\n1.Insert Record";
		cout<<"\n2.Search Record";
		cout<<"\n3.Update Record";
		cout<<"\n4.Delete Record";
		cout<<"\n5.Sort Records";
		cout<<"\n6.Display Records";
		cout<<"\n7.Quit";
		cout<<"\nEnter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.insert_data();
				break;
			case 2:
				obj.search_data();
				break;
			case 3:
				obj.update_data();
				break;
			case 4:
				obj.delete_data();
				break;
			case 5:
				obj.sort_data();
				break;
			case 6:
				obj.read_data();
				break;
			case 7:
				return 0;
		};
	}
}


