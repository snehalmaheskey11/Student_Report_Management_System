#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;
class admin
{
	public:
    string name, roll, fatnam, motnam, std, contact_no;

public:
	void home();
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void admin::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Go to Login page" <<endl;
    cout << "\t\t\t 7. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6/7]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
    	home();
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void admin::insert() // add student details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" ;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll;
    cout << "\t\t\tEnter Class : ";
    cin >> std;
    cout << "\t\t\tEnter Father's Name': ";
    cin >> fatnam;
    cout << "\t\t\tEnter Mother's Name': ";
    cin >> motnam;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    
    file.open("student.txt", ios::app | ios::out);
    file << " " << name << " " << roll << " " << std << " " << fatnam << " " << motnam << " " << contact_no << "\n";
    file.close();
}

void admin::display() // display students details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------";
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll << endl;
            cout << "\t\t\t Student Class: " << std << endl;
            cout << "\t\t\t Student Father's Name: " << fatnam << endl;
            cout << "\t\t\t Student Mother's Name: " << motnam << endl;
            cout << "\t\t\t Student Contact_no: " << contact_no << endl;
            file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void admin::modify() // Modify Students Details
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" ;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        while (!file.eof())
        {
            if (rollno != roll)

                file1 << " " << name << " " << roll << " " << std << " " << fatnam << " " << motnam << " " << contact_no << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll;
                cout << "\t\t\tEnter Class : ";
			    cin >> std;
			    cout << "\t\t\tEnter Father's Name': ";
			    cin >> fatnam;
			    cout << "\t\t\tEnter Mother's Name': ";
			    cin >> motnam;
			    cout << "\t\t\tEnter Contact No: ";
			    cin >> contact_no;
                file1 << " " << name << " " << roll << " " << std << " " << fatnam << " " << motnam << " " << contact_no << "\n";
                found++;
            }
            file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("record.txt", "student.txt");
    }
}
void admin::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" ;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------";
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        while (!file.eof())
        {
            if (rollno == roll)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll << endl;
                cout << "\t\t\t Student Class: " << std << endl;
            	cout << "\t\t\t Student Father's Name: " << fatnam << endl;
           	 	cout << "\t\t\t Student Mother's Name: " << motnam << endl;
            	cout << "\t\t\t Student Contact_no: " << contact_no << endl;
                found++;
            }
            file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }
}
void admin::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string rollno;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------";
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        while (!file.eof())
        {
            if (rollno != roll)
            {
            	file1 << " " << name << " " << roll << " " << std << " " << fatnam << " " << motnam << " " << contact_no << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("record.txt", "student.txt");
    }
}
class teacher : public admin
{
	public:
		float per,tot,e,p,c,m,com,sst;
		void teachmenu();
		void teachadd();
		void teachdisplay();
		void teachsearch();
		void teachmodify();	
};
void teacher:: teachmenu()
{
	start:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t| STUDENT REPORT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t 1. Enter Report of another Student" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Go to Login Page"<<endl;
    cout << "\t\t\t 6. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            teachadd();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        teachdisplay();
        break;
    case 3:
        teachmodify();
        break;
    case 4:
        teachsearch();
        break;
    case 5:
    	home();
    	break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto start;
}

void teacher:: teachadd()
{
	system("cls");
    fstream file2;
    //string sname, rollno;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Report  ---------------------------------------------";
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll;
	cout << "\n\t\t\t Enter Marks(OUT OF 100) in following Subjects : ";
    cout<< "\n\t\t\t English : ";
    cin>>e;
    cout << "\t\t\t Maths : ";
    cin >> m;
    cout << "\t\t\t Physics : ";
    cin >> p;
    cout << "\t\t\t Chemistry : ";
    cin >> c;
    cout << "\t\t\t Computer SCience : ";
    cin >> com;
    cout << "\t\t\t Social Studies : ";
    cin >> sst;
    file2.open("newstudent.txt", ios::app | ios::out);
    file2 <<" "<< roll <<" "<< name << " " <<e<<" "<<m <<" "<<p<<" "<<c<<" "<<com<<" "<<sst<<"\n";
    file2.close();
}
void teacher:: teachdisplay()
{
	system("cls");
    fstream file2;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
	file2.open("newstudent.txt", ios::in);
    if (!file2)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file2.close();
    }
    else
    {
        file2 >> name >> roll >> e >> m >> p >> c >>com >>sst;
        while (!file2.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll << endl;
            cout << "\t\t\t Student's Marks(OUT OFF 100) in following Subjects "<< endl;
            cout << "\t\t\t English : "<< e<< endl;
            cout << "\t\t\t Maths : " << m << endl;
            cout << "\t\t\t Physics : " << p << endl;
            cout << "\t\t\t Chemistry : " << c << endl;
            cout << "\t\t\t Computer Science : " << com << endl;
            cout << "\t\t\t Social Sciences : " << sst << endl;
            file2 >> name >> roll >> e >> m >> p >> c >>com >>sst;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file2.close();
}
    
void teacher:: teachmodify()
{
	system("cls");
    fstream file2, file1;
    string roll_no;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" ;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file2.open("newstudent.txt", ios::in);
    if (!file2)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> roll_no;
        file1.open("record.txt", ios::app | ios::out);
        file2 >> name >> roll >> e >> m >> p >> c >>com >>sst ;
        while (!file2.eof())
        {
            if (roll_no == roll)
            {
            	cout << "\t\t\t Enter Name : ";
            	cin >> name;
			    cout << "\t\t\tEnter Roll No.: ";
			    cin >> roll;
				cout << "\n\t\t\t Enter Marks(OUT OF 100) in following Subjects : ";
			    cout<< "\n\t\t\t English : ";
			    cin>>e;
			    cout << "\t\t\t Maths : ";
			    cin >> m;
			    cout << "\t\t\t Physics : ";
			    cin >> p;
			    cout << "\t\t\t Chemistry : ";
			    cin >> c;
			    cout << "\t\t\t Computer SCience : ";
			    cin >> com;
			    cout << "\t\t\t Social Studies : ";
			    cin >> sst;
                file1 << " " << name << " " << roll << " " << e << " " << m << " " << p << " " << c <<" " <<com << " " <<sst << "\n";
                found++;
            }
			else
			{
				file1 << " " << name << " " << roll << " " << e << " " << m << " " << p << " " << c <<" " <<com << " " <<sst << "\n";
		    }    
            file2 >> name >> roll >> e >> m >> p >> c >>com >>sst ;
        }
        if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        file1.close();
        file2.close();
        //remove("student.txt");
        rename("record.txt", "newstudent.txt");
    }
}
void teacher:: teachsearch()
{
	system("cls");
    fstream file2;
    int found = 0;
    file2.open("newstudent.txt", ios::in);
    if (!file2)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" ;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file2 >> name >> roll >> e >> m >> p >> c >> com >> sst ; 
        while (!file2.eof())
        {
            if (rollno == roll)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll << endl;
                cout<<"\t\t\t   Subject Marks(out of 100): "<< endl;
				cout<<"\t\t\t   English: "<<e<< endl;
				cout<<"\t\t\t   Physics: "<<p<< endl;
				cout<<"\t\t\t   Chemisrty: "<<c<< endl;
				cout<<"\t\t\t   Maths: "<<m<< endl;
				cout<<"\t\t\t   Computer: "<<com<< endl;
				cout<<"\t\t\t   Social Studies : "<<sst<<endl;
                found++;
            }
            file2 >> name >> roll >> e >> m >> p >> c >> com >> sst;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file2.close();
    }
}
class student: public teacher
{
	public:
	void student_display();
};
void student:: student_display()
{
	system("cls");
	/*fstream file,file2,f3;
	string str1, str2;
	file.open("student.txt",ios::in);
	file2.open("newstudent.txt",ios::in);
	f3.open("studfinal.txt",ios::out);
	while(getline(file,str1))
	{
		f3<<str1;
		f3<<endl;
    }
    while(getline(file2, str2))
    {
    	f3<<str2;
    	f3<<endl;
	}
	file.close();
	file2.close();
	f3.close();
	int found = 0;
    f3.open("studfinal.txt", ios::in);
    if (!f3)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" ;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n Enter your Roll No. : ";
        cin >> rollno;
        f3 >> name >> roll >> std >> fatnam >> motnam >> contact_no >> e >> m >> p >> c >> com >> sst ; 
        while (!f3.eof())
        {
            if (rollno == roll)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll << endl;
                cout << "\t\t\t Student Class: " << std << endl;
            	cout << "\t\t\t Student Father's Name: " << fatnam << endl;
           	 	cout << "\t\t\t Student Mother's Name: " << motnam << endl;
            	cout << "\t\t\t Student Contact_no: " << contact_no << endl;
                cout << "\t\t\t   Subject Marks(out of 100): "<< endl;
				cout << "\t\t\t   English: "<<e<< endl;
				cout << "\t\t\t   Physics: "<<p<< endl;
				cout << "\t\t\t   Chemisrty: "<<c<< endl;
				cout << "\t\t\t   Maths: "<<m<< endl;
				cout << "\t\t\t   Computer: "<<com<< endl;
				cout << "\t\t\t   Social Studies : "<<sst<<endl;
                found++;
            }
            f3 >> name >> roll >> std >> fatnam >> motnam >> contact_no >> e >> m >> p >> c >> com >> sst;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        f3.close();
    }*/
    fstream file,file2;
	int found = 0, found1=0;
    file.open("student.txt", ios::in);
    file2.open("newstudent.txt",ios::in);
    if (!file || !file2)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" ;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------";
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        while (!file.eof())
        {
            if (rollno == roll)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll << endl;
                cout << "\t\t\t Student Class: " << std << endl;
            	cout << "\t\t\t Student Father's Name: " << fatnam << endl;
           	 	cout << "\t\t\t Student Mother's Name: " << motnam << endl;
            	cout << "\t\t\t Student Contact_no: " << contact_no << endl;
                found++;
            }
            file >> name >> roll >> std >> fatnam >> motnam >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent is not entered by admin.";
        }
        file.close();
        //for marks
        file2 >> name >> roll >> e >> m >> p >> c >> com >> sst ; 
        while (!file2.eof())
        {
            if (rollno == roll)
            {
                //cout << "\n\t\t\t Student Name: " << name << endl;
                //cout << "\t\t\t Student Roll No.: " << roll << endl;
                cout<<"\t\t\t   Subject Marks(out of 100): "<< endl;
				cout<<"\t\t\t   English: "<<e<< endl;
				cout<<"\t\t\t   Physics: "<<p<< endl;
				cout<<"\t\t\t   Chemisrty: "<<c<< endl;
				cout<<"\t\t\t   Maths: "<<m<< endl;
				cout<<"\t\t\t   Computer: "<<com<< endl;
				cout<<"\t\t\t   Social Studies : "<<sst<<endl;
                found1++;
            }
            file2 >> name >> roll >> e >> m >> p >> c >> com >> sst;
        }
        if (found1 == 0)
        {
            cout << "\n\t\t\tStudent Record is not entered by teacher. ";
        }
        file2.close();
    }
    getch();
}
void admin::home()
{
	system("cls");
	admin project;
    teacher teach;
    student stu;
    //string pass,str;
    int ch,pass;
    char x;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t| STUDENT REPORT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    do
    {
    	cout<<"\n \t\t\t Press 1 . Admin : ";
	    cout<<"\n \t\t\t Press 2 . Teacher : ";
	    cout<<"\n \t\t\t Press 3 . Student : ";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1:
	    		{
	    			cout<<"\n Enter Password for ADMIN : ";
	    			cin>>pass;
	    			//str= 'admin';
	    			if(pass==123)//if(strcmp(pass,str)==0)
	    			{
	    				cout<<"\n Logged in .... Successfully....";
	    				project.menu();
					}
					else
					cout<<"\n Invalid Credentials....Please Try Again..";
				}
	    		break;
	    	case 2:
	    		{
	    			cout<<"\n Enter Password for TEACHER : ";
	    			cin>>pass;
	    			//str= 'admin';
	    			if(pass==123)//if(strcmp(pass,str)==0)
	    			{
	    				cout<<"\n Logged in .... Successfully....";
	    				teach.teachmenu();
					}
					else
					cout<<"\n Invalid Credentials....Please Try Again..";
				}
	    		break;
	    	case 3:
	    		{
	    			stu.student_display();
				}
	    	default:
	        cout << "\n\t\t\t Invalid choice... Please Try Again..";	
		}
		cout<<"\n Do you again want to make choice (Y,N) : ";
        cin >> x;
        } while (x == 'y' || x == 'Y'); 
        
}
int main()
{
    admin project;
    teacher teach;
    student stu;
    //string pass,str;
    int ch,pass;
    char x;
    do
    {
    	system("cls");
    	cout << "\t\t\t------------------------------------" << endl;
    	cout << "\t\t\t| STUDENT REPORT MANAGEMENT SYSTEM |" << endl;
    	cout << "\t\t\t------------------------------------" << endl;
    	cout<<"\n \t\t\t Press 1 . Admin : ";
	    cout<<"\n \t\t\t Press 2 . Teacher : ";
	    cout<<"\n \t\t\t Press 3 . Student : ";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1:
	    		{
	    			cout<<"\n Enter Password for ADMIN : ";
	    			cin>>pass;
	    			//str= 'admin';
	    			if(pass==123)//if(strcmp(pass,str)==0)
	    			{
	    				cout<<"\n Logged in .... Successfully....";
	    				project.menu();
					}
					else
					cout<<"\n Invalid Credentials....Please Try Again..";
				}
	    		break;
	    	case 2:
	    		{
	    			cout<<"\n Enter Password for TEACHER : ";
	    			cin>>pass;
	    			//str= 'admin';
	    			if(pass==123)//if(strcmp(pass,str)==0)
	    			{
	    				cout<<"\n Logged in .... Successfully....";
	    				teach.teachmenu();
					}
					else
					cout<<"\n Invalid Credentials....Please Try Again..";
				}
	    		break;
	    	case 3:
	    		{
	    			stu.student_display();
				}
	    	default:
	        cout << "\n\t\t\t Invalid choice... Please Try Again..";	
		}
		cout<<"\n Do you again want to make choice (Y,N) : ";
        cin >> x;
        } while (x == 'y' || x == 'Y'); 
		
	  return 0;  
	}    
    
         