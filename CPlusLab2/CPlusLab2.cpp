// CPlusLab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
#include <ctime>
#include <xloctime>
#include <ostream>

using namespace std;

int const CURRENT_YEAR = 2019;
int const DEFAULT_LIST_SIZE = 25;
const char choice1 = '1', choice2 = '2', choice3 = '3', choice4 = '4', choice5 = '5', choice6 = '6';
int RESGISTRED_STUDENT_NUMBER = 0;
// DATE STRUCTURE
struct DOB
{
	int Year;
	int Month;
	int Day;
};

// ADDRESS STRUCTURE
struct Address
{
	string PostalCode;
	string Country;
	string Region;
	string Area;
	string City;
	string Street;
	string FlatNumer;
};



// My ERROR STRUCT
struct Error
{
	bool IsValid;
	string Message;
	string PropertyName;
};



struct Student {

	string FirstName;
	string MiddleName;
	string LastName;
	char Sex;
	string Nationality;
	double Height;
	double Weight;
	DOB DateOfBirth;
	string Phone;
	Address Address;
	string University;
	string Course;
	string Group;
	double AverageMark;
	string Speciality;
};
void DisplaySortAlphabetics(Student* studentList, char NameTag, int size);
Student* RegisterStudents(Student* NewStudents, int Count);
Error IsValidDOB(DOB dob, int CurrentYear);
Student FindStudentInfo(string firstName, string middleName, string lastName, Student* studentList, int size);
Student* InitiateStudentArray(int studentNumber);
//Method to display the Array content
void DisplayStudentsInfos(Student* studentsList,int count) 
{

	    cout << "******Students Infos*******" << endl;
		for (int i = 0; i < count; i++) {
			cout << "Student N#:" << i + 1 << endl;
			cout << "Student informations " << endl;
			cout << "First Name:" << studentsList[i].FirstName << endl;
			cout << "Middle Name:"<< studentsList[i].MiddleName<<endl;
			cout << "Last Name:"<< studentsList[i].LastName<<endl;
			//Check the sex 
			cout << "Sex:"<< studentsList[i].Sex<<endl;
			cout << "Nationality:"<< studentsList[i].Nationality<<endl;
			cout << "Height:"<< studentsList[i].Height<<endl;
			cout << "Weight:"<< studentsList[i].Weight<<endl;
			cout << "Date of birth:"<<studentsList[i].DateOfBirth.Day<<"/"<< studentsList[i].DateOfBirth.Month<<"/"<<studentsList[i].DateOfBirth.Day<<endl;
			cout << "Phone number:"<< studentsList[i].Phone<<endl;

			cout << "Address:"<<endl;
			cout << "Postal Code:"<< studentsList[i].Address.PostalCode<<endl;
			cout << "Country name:"<< studentsList[i].Address.Country << endl;
			cout << "Region:"<< studentsList[i].Address.Region << endl;
			cout << "Area:"<< studentsList[i].Address.Area << endl;
			cout << "City:"<< studentsList[i].Address.City << endl;
			cout << "Street:"<< studentsList[i].Address.Street << endl;
			cout << "Flat Number:"<< studentsList[i].Address.FlatNumer << endl;
			cout << "University name:"<< studentsList[i].University << endl;
			cout << "Course name:"<< studentsList[i].Course << endl;
			cout << "Group name:"<< studentsList[i].Group << endl;
			cout << "Average Mark:"<< studentsList[i].AverageMark << endl;
			cout << "Speciality:"<< studentsList[i].Speciality << endl;
		}
}
void RegisterStudent(Student* studentsList, int Position);
void DisplayStudentInfos(Student studentsList)
{
	cout << "******Student Infos*******" << endl;
		cout << "First Name:" << studentsList.FirstName << endl;
		cout << "Middle Name:" << studentsList.MiddleName << endl;
		cout << "Last Name:" << studentsList.LastName << endl;
		//Check the sex 
		cout << "Sex:" << studentsList.Sex << endl;
		cout << "Nationality:" << studentsList.Nationality << endl;
		cout << "Height:" << studentsList.Height << endl;
		cout << "Weight:" << studentsList.Weight << endl;
		cout << "Date of birth:" << studentsList.DateOfBirth.Day << "/" << studentsList.DateOfBirth.Month << "/" << studentsList.DateOfBirth.Day << endl;
		cout << "Phone number:" << studentsList.Phone << endl;

		cout << "Address:" << endl;
		cout << "Postal Code:" << studentsList.Address.PostalCode << endl;
		cout << "Country name:" << studentsList.Address.Country << endl;
		cout << "Region:" << studentsList.Address.Region << endl;
		cout << "Area:" << studentsList.Address.Area << endl;
		cout << "City:" << studentsList.Address.City << endl;
		cout << "Street:" << studentsList.Address.Street << endl;
		cout << "Flat Number:" << studentsList.Address.FlatNumer << endl;
		cout << "University name:" << studentsList.University << endl;
		cout << "Course name:" << studentsList.Course << endl;
		cout << "Group name:" << studentsList.Group << endl;
		cout << "Average Mark:" << studentsList.AverageMark << endl;
		cout << "Speciality:" << studentsList.Speciality << endl;
}
Student* InitiateStudentDefaultArray();
void DisplayChoice(Student* studentList, int size, char SexTag, double LowMark, double UpperMark);
// MAIN FUNCTION
int main()
{
	int StudentsNumber = 0;
	Student* StudentsList=new Student[DEFAULT_LIST_SIZE];
	char choice;
	DOB CurrentDate;
	Error ErrorProvider;
	//RESEARCH ELEMENTS
	string firstName, middleName, lastName;

	// COLLECTING THE CURRENT THE DATE WHEN APPS START
	CURRENT_DATE:
		cout << "Please enter the Current Date!\n";
		cout << "Day:";
		cin >> CurrentDate.Day;
		cout << "Month:";
		cin >> CurrentDate.Month;
		cout << "Year:";
		cin >> CurrentDate.Year;

		ErrorProvider=IsValidDOB(CurrentDate, CURRENT_YEAR);
		// checking the error provider
		if (ErrorProvider.IsValid == false)
		{
			cout<<ErrorProvider.Message<<endl;
			cout << "Enter a correct date"<<endl;
			goto CURRENT_DATE;
		}

	MAIN_MENU:



		// Possible choice 1,2 and FOR THE APPLICATION MAIN BUTTONS
		system("CLS");
		cout << "What do you wanna do?" << endl;
		cout << "[1]=> Register students." << endl;
		cout << "[2]=> Search students." << endl;
		cout << "[3]=> Display the students List." << endl;
		cout << "[4]=> Order students List by Alphabetical order." << endl;
		cout << "[5]=> Order students List by Sex and Marks." << endl;
		cout << "[6]=> Exit" << endl;
		cout << "[1,2,3,4,5 or 6], Choice :";
		cin >> choice;

		//CORRECT CHOICE FUNCTIONS
		
		switch (choice)
		{
			//*************************************************************************
			// REGISTER STUDENTS
			//**************************************************************************
		case choice1:
		REGISTER_STUDENTS:
			// OPTION TO REGISTER A STUDENTS
			system("CLS");
			cout << "************Registering students ************" << endl;
			cout << "Would you like to :" << endl;
			cout<<"[1] Enter a student list size ?" << endl;
			cout<<"[2] Use the default size (25)? " << endl;
			cout<<"[3] Register a Student in an existing list? " << endl;
			cout<<"[4] Exit"<<endl;
			cout << "[1,2,3 or 4] ?:";
			cin >> choice;
		
			// USER CHOICE FOR THE REGISTRATION LIST SIZE
			switch (choice)
			{
				//THE USER ENTER A SIZE FOR THE LIST
			case choice1:
				cout << "How many students do you want to register? :";
				cin >> StudentsNumber;

				//USE MY INITIALIZER
				StudentsList = InitiateStudentArray(StudentsNumber);

				//START REGISTRING STUDENTS
				StudentsList = RegisterStudents(StudentsList, StudentsNumber);
				//RETURNING TO THE MAIN MENU
				goto REGISTER_STUDENTS;

				//THE PROGRAM PROVIDE A DEFAULT SIZE
			case choice2:
				//USE MY DEFAULT INITIALIZER 25
				StudentsNumber = DEFAULT_LIST_SIZE;
				StudentsList = InitiateStudentDefaultArray();

				//START REGISTERING STUDENTS
				StudentsList = RegisterStudents(StudentsList, StudentsNumber);
				//RETURNING TO THE MAIN MENU
				goto REGISTER_STUDENTS;

			case choice3:
				//REGISTER A STUDENT IN AN EXISTING LIST
				StudentsNumber = RESGISTRED_STUDENT_NUMBER;
				if (StudentsNumber == 0)
				cout << "No existing list found!" << endl;
				else
				{
					//START REGISTERING THE STUDENT
					RegisterStudent(StudentsList, StudentsNumber);

				}
				//RETURNING TO THE MAIN MENU
				goto REGISTER_STUDENTS;

			case choice4:
				//RETURNING TO THE MAIN MENU
				goto MAIN_MENU;
			default:
				cout << "Unknown command!" << endl;
				goto REGISTER_STUDENTS;
			}


			//*********************************
			// LOOK FOR A STUDENT INFO
			//**********************************
		case choice2:
			system("CLS");
			cout << "************Search a Student************" << endl;

			cout << "Please enter the student name:" << endl;
			cout << "Fist Name:";
			getline(cin, firstName);
			cout << "Middle Name:";
			getline(cin, middleName);
			cout << "Last Name:";
			getline(cin, lastName);

			//DO A RESEARCH AND SIPLAY THE RESULT
			FindStudentInfo(firstName, middleName, lastName,StudentsList,StudentsNumber);
			goto MAIN_MENU;

			//*********************************
			// DISPLAY THE STUDENTs LIST
			//**********************************

		case choice3:
			// DISPLAY THE STUDENTs LIST

			if (StudentsNumber == 0) {
				cout << "No list found !" << endl;
				goto MAIN_MENU;
			}
			else
			{
				DisplayStudentsInfos(StudentsList, StudentsNumber);
				goto MAIN_MENU;
			}

		case choice4:

			//*********************************
			// DISPLAY THE STUDENTs LIST ALPHABETICALY
			//**********************************

			if (StudentsNumber == 0) {
				cout << "No list found !" << endl;
				goto MAIN_MENU;
			}
			else
			{
				cout << "Enter a letter :";
				cin >> choice;
				DisplaySortAlphabetics(StudentsList,choice,StudentsNumber);
				goto MAIN_MENU;
			}

		case choice5:
			//*********************************
			// DISPLAY THE STUDENTs LIST BY SEX AND MARK
			//**********************************

			if (StudentsNumber == 0) {
				cout << "No list found !" << endl;
				goto MAIN_MENU;
			}
			else
			{
				double low, up = 0;
				cout << "Enter the lower Mark :";
				cin >> low;
				cout << "Enter the Upper Mark :" << endl;
				cin >> up;

				DisplayChoice(StudentsList, StudentsNumber,choice,low,up);
				goto MAIN_MENU;
			}

		case choice6:
			//*********************************
			// EXIT
			//**********************************
			exit(0);
		default:
			//RETURNING TO THE MAIN MENU
			cout << "Unknown command!" << endl;
			goto MAIN_MENU;
		}
		
	
}



// SORTING the STUDENTs list BY SEX AND MARKS
void DisplayChoice(Student* studentList, int size, char SexTag, double LowMark, double UpperMark) {

	cout << "******Students Infos*******" << endl;
	for (int i = 0; i < size; i++) {



		cout << "Student N#:" << i + 1 << endl;
		cout << "Student informations " << endl;
		// DISPLAY THE SORTING RESULT
		if (studentList[i].Sex == SexTag && (studentList[i].AverageMark >= LowMark && studentList[i].AverageMark <= UpperMark))
			DisplayStudentInfos(studentList[i]);
	}
}

//SORTING THE STUDENT LIST BY ALPHABETICAL ORDER
void DisplaySortAlphabetics(Student* studentList, char NameTag, int size) {

	cout << "******Students Infos*******" << endl;
	for (int i = 0; i < size; i++) {

		cout << "Student N#:" << i + 1 << endl;
		cout << "Student informations " << endl;
		// DISPLAY THE SORTING RESULT
		if (studentList[i].LastName[0] == NameTag)
			DisplayStudentInfos(studentList[i]);
	}
}

// RESEARCH A STUDENT
Student FindStudentInfo(string firstName, string middleName, string lastName,Student* studentList,int size) {

	Student result;
	for (int i = 0; i < size; i++) {
		// RESEARCHING THE CORRESPONDING STUDENT
		if (studentList[i].FirstName == firstName && studentList[i].MiddleName == middleName && studentList[i].LastName == lastName)
		{
			result = studentList[i];
			return result;
		}
	}

	cout << "No result found" << endl;
	return result;
}


// method to register students in the list
Student* RegisterStudents(Student* NewStudents, int Count)
{
	char choice = 'Y';
	Error errorProvider;
	system("CLS");
	cout << "************Registering the Students************" << endl;

	int Continue = 2;
	for (int i = 0; i < Count; i++) {

		//ASK THE USER IF WE SHOULD CONTINUE OR EXIT
		if (Continue == 0) {
		CONTINUE_REGISTERING:
			cout << "Would you like to continue registering?" << endl;
			cout << "[Y,N] ?: ";
			cin >> choice;
				if (choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n')
				{
					cout << "Incorrect choice"<<endl;
					goto CONTINUE_REGISTERING;
				}

				//STOPING THE REGISTRATION
				if (choice == 'N' || choice == 'n')
					break;
				// REFILL THE COUNTER
				else
					Continue = 2;
		}
		else
		{
			Continue -= 1;
		}


		Student student;
		cout << "Student N#:" << i + 1 << endl;
		cout << "Fill the informations bellow" << endl;
		cout << "Enter First Name:";
		cin>>student.FirstName;
		cout << "Enter Middle Name:";
		cin>>student.MiddleName;
		cout << "Enter Last Name:";
		cin>>student.LastName;

		//Check the sex 
		cout << "Enter Sex:";
		cin >> student.Sex;
		cout << "Enter Nationality:";
		cin>> student.Nationality;

		cout << "Enter Height:";
		cin >> student.Height;

		cout << "Enter Weight:";
		cin >> student.Weight;

		cout << "Enter Date of birth:" << endl;
		cout << "Enter Year:";
		cin >> student.DateOfBirth.Year;

		cout << "Enter Month:";
		cin >> student.DateOfBirth.Month;

		cout << "Enter Day:";
		cin >> student.DateOfBirth.Day;

		cout << "Enter Phone number:";
		cin>>student.Phone;


		cout << "-Address-" << endl;
		cout << "Enter Postal Code:";
		cin>>student.Address.PostalCode;

		cout << "Enter Country name:";
		cin>>student.Address.Country;

		cout << "Enter Region:";
		cin>> student.Address.Region;

		cout << "Enter Area:";
		cin>>student.Address.Area;

		cout << "Enter City:";
		cin>>student.Address.City;

		cout << "Enter Street:";
		cin>>student.Address.Street;

		cout << "Enter Flat Number:";
		cin>> student.Address.FlatNumer;

		cout << "Enter University name:";
		cin>>student.University;

		cout << "Enter Course name:";
		cin>>student.Course;

		cout << "Enter Group name:";
		cin>>student.Course;

		cout << "Enter Average Mark:";
		cin >> student.AverageMark;

		cout << "Enter Speciality:";
		cin>>student.Speciality;


		//Adding student to the list
		NewStudents[i] = student;
		RESGISTRED_STUDENT_NUMBER += 1;
	}

	return NewStudents;
}

//REGISTER A STUDENT
void RegisterStudent(Student* studentsList, int Position)
{
	char choice = 'Y';
	//Error errorProvider;
	cout << "************Registering the Students************" << endl;

		Student student;
		cout << "Student N#:" <<Position<< endl;
		cout << "Fill the informations bellow" << endl;
		cout << "Enter First Name:";
		getline(cin, student.FirstName);
		cout << "Enter Middle Name:";
		getline(cin, student.MiddleName);
		cout << "Enter Last Name:";
		getline(cin, student.LastName);

		cout << "Enter Sex:";
		cin >> student.Sex;
		cout << "Enter Nationality:";
		getline(cin, student.Nationality);

		cout << "Enter Height:";
		cin >> student.Height;

		cout << "Enter Weight:";
		cin >> student.Weight;

		cout << "Enter Date of birth:" << endl;
		cout << "Enter Year:";
		cin >> student.DateOfBirth.Year;

		cout << "Enter Month:";
		cin >> student.DateOfBirth.Month;

		cout << "Enter Day:";
		cin >> student.DateOfBirth.Day;

		cout << "Enter Phone number:";
		getline(cin, student.Phone);


		cout << "Enter Address:" << endl;
		cout << "Enter Postal Code:";
		getline(cin, student.Address.PostalCode);

		cout << "Enter Country name:";
		getline(cin, student.Address.Country);

		cout << "Enter Region:";
		getline(cin, student.Address.Region);

		cout << "Enter Area:";
		getline(cin, student.Address.Area);

		cout << "Enter City:";
		getline(cin, student.Address.City);

		cout << "Enter Street:";
		getline(cin, student.Address.Street);

		cout << "Enter Flat Number:";
		getline(cin, student.Address.FlatNumer);

		cout << "Enter University name:";
		getline(cin, student.University);

		cout << "Enter Course name:";
		getline(cin, student.Course);

		cout << "Enter Group name:";
		getline(cin, student.Course);

		cout << "Enter Average Mark:";
		cin >> student.AverageMark;

		cout << "Enter Speciality:";
		getline(cin, student.Speciality);


		//Adding student to the list
		studentsList[Position-1] = student;
		RESGISTRED_STUDENT_NUMBER += 1;
}



//initiate the student list with the given size
Student* InitiateStudentArray(int studentNumber) {

	return new Student[studentNumber];
}


// INITIATE A DEFAULT STUDENT LIST SIZE
Student* InitiateStudentDefaultArray() {

	return new Student[DEFAULT_LIST_SIZE];
}

Error IsValidDOB(DOB dob, int CurrentYear)
{
	Error CustomError;
	CustomError.IsValid = true;
	CustomError.PropertyName = "DOB";
	CustomError.Message = "Valid DOB";
	CustomError.IsValid = true;

	if (dob.Day = 0 || dob.Day>31) {
		CustomError.IsValid = false;
		CustomError.PropertyName = "DAY";
		CustomError.Message = "The Given day is not correct";
		return CustomError;
	}
	if (dob.Month = 0 || dob.Month > 12) {
		CustomError.IsValid = false;
		CustomError.PropertyName = "Month";
		CustomError.Message = "The Given Month is not correct";
		return CustomError;
	}
	if (dob.Year <1900 || dob.Year >CurrentYear)
	{
		CustomError.IsValid = false;
		CustomError.PropertyName = "Year";
		CustomError.Message = "The Given Year is not correct";
		return CustomError;
	}

	return CustomError;
}
//
//// Verify the Entered Sex character
//Error IsSexValid(char Sex) {
//	Error CustomError;
//	CustomError.PropertyName = "Sex";
//	CustomError.Message = "Valid";
//	CustomError.IsValid = true;
//
//	if (Sex != 'F' || Sex != 'f' || Sex != 'M' || Sex != 'm') {
//		CustomError.PropertyName = "Sex";
//		CustomError.Message = "Invalid Characters. Please enter a valid Characters ('F','f','M' or 'm')";
//		CustomError.IsValid = false;
//		return CustomError;
//	}
//}
