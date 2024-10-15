#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

//For students
struct student
{
	string fname;//for student first name
	string lname;//for student last name
	string Registration;//for Registration No number
	string classes;//for class info
}studentData;//Variable of student type

//For teachers
struct teacher
{
	string fst_name;//first name of teacher
	string lst_name;//last name of teacher
	string qualification;//Qualification of teacher
	string exp;//Experience of the person
	string pay;//Pay of the Teacher
	string subj;//subject they teach
	string cel_no;//Phone number 

}tech[50];//Variable of teacher type

int main()
{

	int i = 0, j;//for processing usage 
	char choice;//for getting choice
	string find;//for sorting
	string srch;

	while (1)//outer loop
	{
	a:
		//Level 1-Display process 
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n\n\t\t\t\t\tSCHOOL MANAGEMENT PROGRAM\n\n";
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n\n\t\t\t\t\t\tMAIN SCREEN\n\n";
		cout << "Enter your choice: " << endl;
		cout << "1.Students information" << endl;
		cout << "2.Teacher information" << endl;
		cout << "3.Exit program" << endl;
		cin >> choice;


		switch (choice)//whether user wants wants to access std info or exit (switch 1)
		{

		case '1': //Student info
		{

			system("cls");//Clear screen


			cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
			cout << "\n\n\n\t\t\t\t\tSTUDENTS INFORMATION SECTION\n\n\n";
			cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "Enter your choice: " << endl;
			cout << "1.Create new entry" << endl;
			cout << "2.Find and display entry" << endl;
			cout << "3.Jump to main" << endl;
			cin >> choice;

			switch (choice)
				//(we are now inside std info. User chooses to either create new, find old or exit in this switch) Second switch

			{
			case '1'://new entries
			{
				ofstream write;
				write.open("student.txt", ios::app);
				//file is accessed to write, only adds to the end of doc
					//if user inputs case insensitive n

				system("cls");//Clear screen
				if ((choice == 'y') || (choice == 'Y') || (choice == '1'))//non-case sensitive input
				{
				hooda:
					cout << "Enter First name: ";
					cin >> studentData.fname;
					cout << "Enter Last name: ";
					cin >> studentData.lname;
					cout << "Enter Registration number: ";
					cin >> studentData.Registration;
					cout << "Enter class: ";
					cin >> studentData.classes;

					write << studentData.fname << endl << studentData.lname << endl << studentData.Registration << endl << studentData.classes << endl;
					cout << "Do you want to enter new data? ";
					cout << "Press Y for Continue and N to Finish:  ";
					cin >> choice;

					if ((choice == 'n') || (choice == 'N'))
					{
						system("cls");
						goto a;
					}
					else
					{
						system("cls");
						goto hooda;
					}
				}//o-if loop closes

				write.close();

			}
			//continue;//control back to inner loop -1. takes user back to main page.

			case '2'://Display data
			{
				system("cls");//Clear screen
				ifstream read;
				read.open("student.txt");

				cout << "Enter First name to be displayed: ";
				cin >> find;
				cout << endl;
				int notFound = 0;
				for (j = 0; (j < i) || (!read.eof()); j++)
				{

					getline(read, studentData.fname);

					if (studentData.fname == find)
					{
						notFound = 1;
						cout << "First name: " << studentData.fname << endl;
						getline(read, studentData.lname);
						cout << "Student name: " << studentData.lname << endl;
						getline(read, studentData.Registration);
						cout << "Registration number: " << studentData.Registration << endl;
						getline(read, studentData.classes);
						cout << "Class: " << studentData.classes << endl << endl;
					}

				}

				if (notFound == 0)
				{

					cout << "No Record Found" << endl;
				}
				read.close();
				cout << "Press any key two times to proceed" << endl;
				_getch();//To hold data on screen
				_getch();//To hold data on screen (this also allows to take input from user without it showing on screen)
				system("cls");

			}//s2 case 2 closed
			continue;//control back to inner loop -1


			case '3':
				//Jump to main
			{
				system("cls");
				break;//inner switch breaking
			}

			}//sec switch closes

			break;//inner loop-1 breaking
		} //s1 case1 closed
		continue;//Control pass to 1st loop    

		case '2'://Teachers biodata
		{
			while (1)//inner loop-2
			{
				system("cls");
				//Level-2 Display process
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n";
				cout << "\t\t\tTEACHERS INFORMATION AND BIODATA SECTION\n\n";
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";
				cout << "Enter your choice: " << endl;
				cout << "1.Create new entry\n";
				cout << "2.Find and display\n";
				cout << "3.Jump to main\n";
				cin >> choice;

				switch (choice)//Third switch
				{
				case '1'://Insert data
				{
					ofstream twrite("teacher.txt", ios::app);
					system("cls");
					if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
					{
					b:
						cout << "Enter First name of teacher: ";
						cin >> tech[i].fst_name;
						cout << "Enter Last name of teacher: ";
						cin >> tech[i].lst_name;
						cout << "Enter qualification: ";
						cin >> tech[i].qualification;
						cout << "Enter teaching experience in years: ";
						cin >> tech[i].exp;
						cout << "Enter Subject they teach: ";
						cin >> tech[i].subj;
						cout << "Enter pay: ";
						cin >> tech[i].pay;
						cout << "Enter Phone Number: ";
						cin >> tech[i].cel_no;


						twrite << tech[i].fst_name << endl << tech[i].lst_name << endl
							<< tech[i].qualification << endl << tech[i].exp << endl << tech[i].subj
							<< endl << tech[i].pay << endl << tech[i].cel_no << endl;
						cout << "Do you want to enter data: ";
						cin >> choice;

						if ((choice == 'n') || (choice == 'N'))
						{
							system("cls");
							goto a;
						}
						else
						{
							system("cls");
							goto b;
						}
					}//if
					system("cls");
					twrite.close();

				}//case 1

				continue;//Control pass to inner loop-2

				case '2'://Display data
				{
					ifstream tread("teacher.txt");
					system("cls");
					cout << "Enter name to be displayed: ";
					cin >> find;

					cout << endl;
					int notFound = 0;
					for (j = 0; ((j < i) || (!tread.eof())); j++)
					{

						getline(tread, tech[j].fst_name);

						if (tech[j].fst_name == find)
						{
							notFound = 1;
							cout << "First name: " << tech[j].fst_name << endl;
							getline(tread, tech[j].lst_name);
							cout << "Last name: " << tech[j].lst_name << endl;
							getline(tread, tech[j].qualification);
							cout << "Qualification: " << tech[j].qualification << endl;
							getline(tread, tech[j].exp);
							cout << "Experience: " << tech[j].exp << endl;

							getline(tread, tech[j].subj);
							cout << "Subject whos teach: " << tech[j].subj << endl;

							getline(tread, tech[j].pay);
							cout << "pay: " << tech[j].pay << endl;

							getline(tread, tech[j].cel_no);
							cout << "Phone Number: " << tech[j].cel_no << endl;

						}//if

					}//for loop

					if (notFound == 0) {

						cout << "No Record Found" << endl;
					}
					tread.close();
					cout << "Press any key two times to proceed";
					_getch();//To hold data on screen
					_getch();//To hold data on screen
					system("cls");
				}//case 2

				continue;//Control pass to inner loop-2
				case '3':
				{
					system("cls");
					goto a;//outer case 2
				}

				}//s1 closed
				break;
			} //while loop closed


		} break;
		} break;
	}
}//int main closed
