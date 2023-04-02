#define _CRT_SECURE_NO_WARNINGS
//Ben Cohen I.D- 209174549
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LOGO 1 // Logo print option in the print function
#define ENTER_NAME 2 // ENTER_NAME print option in the print function
#define ENTER_INDETITY 3 // ENTER_INDETITY print option in the print function
#define ENTER_NUMBER_A 4 // ENTER_NUMBER_A print option in the print function
#define GROUP_A 5 // GROUP_A print option in the print function
#define GROUP_B 6 // GROUP_B print option in the print function
#define GROUP_C 7 // GROUP_C print option in the print function
#define ENTER_COURSE_NUM 8 // ENTER_COURSE_NUM option in the print function
#define LOIS_LANE 9  // LOIS_LANE option in the print function
#define DEL_LEX 10   //DEL_LEX option in the print function
#define MAX_NAME_LEN 100	//Constant that defines the limit of characters in the name ( choosed 100 - according to your executable file , that can get for example- qowkepoqwk;laskd;laslkdlk12-0kaspokdla;sk 
#define MAX_FULL_NAME_LEN 102 //                    """"""""""""            int the name + Group                                                                         """""""""""""""""""
#define MAX_COURSES 10 //Assumtion of 10 courses max per student
#define GROUP_STUDENT_NUMBER 6  //Constant that defines  Six students max at group 
#define COLS 8 // Number of columns in the stuData Matrix
#define DEFAULT_ROWS 3  // Number of rows in the stuData Matrix
#define STU_NAMES_ROWS 18  // Number of rows in the StuNames Matrix (6 students * 3 Groups (worst case) )
#define GROUP_A_LINE 0 // Constant that marks we are in the First line (GroupA) in the stuData matrix
#define GROUP_B_LINE 1 // Constant that marks we are in the Second line (GroupB) in the stuData matrix
#define GROUP_A_ROW 0 //Constant that marks the Start of the GroupA row in the stuData matrix
#define GROUP_B_ROW 1  //  """"""""""						 GroupB       """"""""""""""
#define GROUP_C_ROW 2 // """"""""""""						 GroupC			""""""""""""
#define TERMINATE 100 // Terminator for the FOR loop to exit  the loop at the very status
#define DEFAULT 0 //Constant that defines a selection option for the PRINT_StuNames function
typedef struct CourseInfo
{
	int courseNum; // Course number of the student
	int grade; // Grade of the student
} COURSE_INFO;

typedef struct Student
{
	char name[MAX_NAME_LEN]; // Contains the name of the specific student (string / char[])
	int identity; // Contains the ID number of the specific student.
	int nofCourses; //number of courses taken in semester.
	COURSE_INFO course_info[MAX_COURSES]; // COURSE_INFO array , contains all the grades and course numbers of the specific student/
}STUDENT;

//**	All the explains about the functions are above the functions.
int getStudentNames(STUDENT stuData[][GROUP_STUDENT_NUMBER], int rows, int cols,
	int courseNum,
	char stuNames[][MAX_FULL_NAME_LEN]);
void GETStudentData(STUDENT stuDATA[][GROUP_STUDENT_NUMBER], int rows, int cols);
int GETCourseNumber(int coursenumber);
void PRINT_StuNames(char StudentNames[][MAX_FULL_NAME_LEN], int LogicSize, int selection);
void CHANGE_lane_lois(char StudentNames[][MAX_FULL_NAME_LEN], int LogicSize);
int DELETELex(char StudentNames[][MAX_FULL_NAME_LEN], int LogicSize);
void GET_GradesChart(STUDENT stuData[][GROUP_STUDENT_NUMBER], int Grades[][COLS], int stuDataRows, int stuDataCols, int courseNum);
void Print_Grades(int StuGrades[][COLS], int Rows, int CourseNum);
void PRINT_MaximumGrades(int Grades[][COLS], int Rows, int cols, int courseNum);
void main()
{
	int StuGrades[DEFAULT_ROWS][COLS]; // Installize Student Grades matrix
	int StudentInTheCourse = 0, CourseNumber = 0; // Local variables , first is the logic size of Stunames, Second is the course number choosed
	char stuNames[STU_NAMES_ROWS][MAX_FULL_NAME_LEN]; // Installize a student Names matrix
	int stuNames_Logic_Size; // The Student Names matrixs rows.
	STUDENT stuData[DEFAULT_ROWS][GROUP_STUDENT_NUMBER]; // Installize  a stuData matrix 


	GETStudentData(stuData, DEFAULT_ROWS, GROUP_STUDENT_NUMBER); // Installizing all the information in the StuData matrix
	CourseNumber = GETCourseNumber(CourseNumber); // Gets the Course number the user want to search students for
	StudentInTheCourse = getStudentNames(stuData, DEFAULT_ROWS, GROUP_STUDENT_NUMBER, CourseNumber, stuNames); // Logic size of the stuNames matrix
	PRINT_StuNames(stuNames, StudentInTheCourse, DEFAULT); // Printing the StuNames matrix (DEFAULT scenario)
	CHANGE_lane_lois(stuNames, StudentInTheCourse); // Changing Lois to Lane in the Stu names matrix
	PRINT_StuNames(stuNames, StudentInTheCourse, LOIS_LANE); // Printing the StuNames matrix (after LOIS_LANE change)
	stuNames_Logic_Size = DELETELex(stuNames, StudentInTheCourse); //Gets the stuNames new Logic size after deleting Lex presentations.
	PRINT_StuNames(stuNames, stuNames_Logic_Size, DEL_LEX); // Printing the StuNames matrix (after DEL_LEX deletion)
	GET_GradesChart(stuData, StuGrades, DEFAULT_ROWS, GROUP_STUDENT_NUMBER, CourseNumber); // Installize the StuGrades matrix with all the information according to the course number.
	Print_Grades(StuGrades, DEFAULT_ROWS, CourseNumber); //Printing the StuGrades matrix after installation.
	PRINT_MaximumGrades(StuGrades, DEFAULT_ROWS, COLS, CourseNumber); // Printing StuGrades Max and second Max numbers.
}
//*****
//*
// *				The Printing function
//*	Gets the selection from the menu of the prints.
//* Prints: --> Depends on the selection, prints specific line.
//*****
void SHOW(int selection)
{
	switch (selection)
	{
	case LOGO:
		printf("********************\n"
			"* Welcome Students *\n"
			"********************\n\n");
		break;
	case ENTER_NAME:
		printf("\nEnter student first name and last name (seperated by spaces): ");
		break;
	case ENTER_INDETITY:
		printf("Enter student ID: ");
		break;
	case ENTER_NUMBER_A:
		printf("Enter number of courses taken in semester A: ");
		break;
	case GROUP_A:
		printf("Enter students data for GROUP A:\n"
			"________________________________\n");
		break;
	case GROUP_B:
		printf("Enter students data for GROUP B:\n"
			"________________________________\n");
		break;
	case GROUP_C:
		printf("Enter students data for GROUP C:\n"
			"________________________________\n");
		break;
	case ENTER_COURSE_NUM:
		printf("\nEnter a course number: ");
		break;
	case LOIS_LANE:
		printf("\nNames after changing \"Lois\""" to ""\"Lane\""":\n""");
		break;
	case DEL_LEX:
		printf("\nNames after deleting names with \"Lex\""":\n""");
		break;
	default:
		break;
	}
}
//*****
//*				Print_Grades Function
//*	Gets : --> integer matrix, Rows variable as int , CourseNum variable as int.  
//* Prints: --> The data in the integer matrix (student Grades matrix) starts from the second column to avoid printing the logic size of every row. 
//*****
void Print_Grades(int StuGrades[][COLS], int Rows,int CourseNum)
{
	printf("\nGrades in course#%d:\n", CourseNum);
	for (int i = 0; i < Rows; i++)
	{
		if (i == GROUP_A_ROW)
		{
			printf("GroupA: ");
		}
		else if (i == GROUP_B_ROW)
		{
			printf("GroupB: ");
		}
		else // GROUP_C_ROW
		{
			printf("GroupC: ");
		}
		for (int j = 1; j < StuGrades[i][0] + 1; j++) // every first collumn of each row is the Row logic size.
		{
			printf("%d ", StuGrades[i][j]);
		}
		printf("\n");
	}

}
//*****
//*				PRINT_StuNames Function
//*	Gets : --> Char matrix, LogicSize variable as int , selection variable as int.  
//* Prints: --> The data in the char matrix (student Names matrix) according to the task 
// for example when i want to print the matrix after erase LEX i use DEL_LEX define as the selection. 
//*****
void PRINT_StuNames(char StudentNames[][MAX_FULL_NAME_LEN], int LogicSize, int selection)
{
	if (selection == LOIS_LANE)
	{
		SHOW(LOIS_LANE);
	}
	if (selection == DEL_LEX)
	{
		SHOW(DEL_LEX);
	}
	for (int i = 0; i < LogicSize; i++)
	{
		printf("%s\n", StudentNames[i]);
		
	}
}
//*****
//*				GETCourseNumber Function
//*	Gets : --> coursenumber variable as int.  
//* DOING: --> Reads from the user the course number he want to search for .
//* Returns: --> the course number variable represent the selection of the user.
//*****
int GETCourseNumber(int coursenumber)
{
	SHOW(ENTER_COURSE_NUM);
	(void)scanf("%d", &coursenumber);
	return coursenumber;
}
//*****
//*				GET_Semester_L_Size Function
//*	Gets : --> COURSE_INFO array , nofCourses variable as int.
//* Return: --> nofCourses variable - Number of courses, to installize in the struct afterwards
//* Doing: --> Installizing the COURSE_INFO array that in the studata struct/.
// {Assumptions}: --> Not more than 10 courses per semester
//*****
int GET_Semester_L_Size(COURSE_INFO student[], int nofCourses)
{
	SHOW(ENTER_NUMBER_A);
	(void)scanf("%d", &nofCourses);
	for (int iter = 0; iter < nofCourses; iter++)
	{
		printf("Enter Course number and grade: ");
		(void)scanf("%d %d", &student[iter].courseNum, &student[iter].grade);
	}
	return nofCourses;
	
}
//*****
//*				GETIdentity Function
//*	Gets : --> identity variable as int.  
//* DOING: --> Reads from the user his ID number .
//* Returns: --> the identity variable represent the selection of the user to installize in the struct afterwards.
//*****
int GETIdentity(int identity)
{
	SHOW(ENTER_INDETITY);
	(void)scanf("%d", &identity);
	printf("\n");
	return identity;

}
//*****
//*				GETFullName Function
//*	Gets : --> NAME array from the stuData struct .
//* Doing: --> Reads the full name of the student and arrange him in the array we gets.
// {Assumptions}: --> Not more than 10 characters for first name or last name.
//*****
void GETFullName(char NAME[])
{
	char FirstName[MAX_NAME_LEN], LastName[MAX_NAME_LEN];
	SHOW(ENTER_NAME);
	(void)scanf("%s", FirstName);
	strcat(FirstName, " \0");
	strcpy(NAME, FirstName);
	(void)scanf("%s", LastName);
	strcat(LastName, "\0");
	strcat(NAME,LastName);
}
//*****
//*				GETStudentData Function
//*	Gets : --> STUDENT(stuData) matrix, rows as int , cols as int.
//* Doing: --> Installize each row and  each column the students information
// in this order: Gets the full name ----> Gets the identity number ---> number of courses and the grades and the course numbers. 
// {Assumptions}: --> Written in each function.
//*****
void GETStudentData(STUDENT stuDATA[][GROUP_STUDENT_NUMBER], int rows, int cols)
{
	int i;
	SHOW(LOGO);
	for (i = 0; i < rows; i++)
	{
		SHOW(i + 5);
		for (int j = 0; j < cols; j++)
		{
			GETFullName(stuDATA[i][j].name);
			stuDATA[i][j].identity = GETIdentity(stuDATA[i][j].identity);
			stuDATA[i][j].nofCourses = GET_Semester_L_Size(stuDATA[i][j].course_info, stuDATA[i][j].nofCourses);
		}
	}
}
//*****
//*				getStudentNames Function
//*	Gets : --> STUDENT(stuData) matrix, rows as int , cols as int, coruse number as in and char StuNames matrix for updating .
//* Doing: --> Installize each row of the stunames matrix with the combination of GROUP relation and full name --> from the Student Data matrix. 
//* Returns: --> The stuNames matrix Logicsize(ROWS).
//*****
int getStudentNames(STUDENT stuData[][GROUP_STUDENT_NUMBER], int rows, int cols, int courseNum, char stuNames[][MAX_FULL_NAME_LEN])
{
	int NumOfStudentsInList = 0;
	printf("Names of students in course#%d:\n", courseNum);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < stuData[i][j].nofCourses; k++)
			{
				if (stuData[i][j].course_info[k].courseNum == courseNum)
				{
					if (i == GROUP_A_ROW)
					{
						strcpy(stuNames[NumOfStudentsInList], "GroupA ");
					}
					else if (i == GROUP_B_ROW)
					{
						strcpy(stuNames[NumOfStudentsInList], "GroupB ");	
					}
					else // GROUP_C_ROW
					{
						strcpy(stuNames[NumOfStudentsInList], "GroupC ");
					}
					strcat(stuNames[NumOfStudentsInList], stuData[i][j].name);
					NumOfStudentsInList++;
				}
			}
		}
	}
	return NumOfStudentsInList;
}
//*****
//*				CHANGE_lane_lois Function
//*	Gets : --> char StudentNames matrix, LogicSize as int.
//* Doing: --> Update each presentation of the combination of chars "L o i s" to "L a n e"	in correlation. 
//*****
void CHANGE_lane_lois(char StudentNames[][MAX_FULL_NAME_LEN], int LogicSize)
{
	int Rows=0;
	char Lane[] = "Lane\0";
	char Lois[] = "Lois\0";
	int ReplaceWith = strlen(Lois), RewplaceTo = strlen(Lane), count;//some constant variables
	while (Rows < LogicSize)
	{
		for (unsigned int i = 7; i < strlen(StudentNames[Rows]); i++) {//search for the first character from StudentNames with ReplaceWith
			if (StudentNames[Rows][i] == Lois[0]) {//if it found it
				count = 1;//start searching from the next character to avoid repeats
				for (int j = 1; j < ReplaceWith; j++) {
					if (StudentNames[Rows][i+j] == Lois[j]) {//see if the next character in text is the same as the next in the ReplaceWith specific row if not break
						count++;
					}
					else {
						break;// get out if not found as sequence
					}
				}
				if (count == ReplaceWith) {//if count equals to the lenght of the ReplaceWith then we found the word that we want to replace in the StudentNames specific row
					for (int l = 0; l < RewplaceTo; l++) {//replace rep with ReplaceWith
						StudentNames[Rows][i + l] = Lane[l];
					}
				}
			}
		}
		Rows++;
	}

	
}
//*****
//*				DELETELex Function
//*	Gets : --> char StudentNames matrix, LogicSize as int.
//* Doing: --> Replace every presentation of name including the combination of chars "L e x"  with '\0'. 
//* Returns: --> The new Logicsize(rows) of the StudentNames matrix.
//*****
int DELETELex(char StudentNames[][MAX_FULL_NAME_LEN], int LogicSize)
{
	int Rows = 0, count = 0,JumpRow = 0;
	bool check = false;
	char Lex[] = "Lex\0";
	int DeleteLenght = strlen(Lex);
	while (Rows < LogicSize)
	{
		for (unsigned int i = 7; i < strlen(StudentNames[Rows]); i++) {
			if (StudentNames[Rows][i] == Lex[0]) {
				count = 1;//start searching from the next character to avoid repeats
				for (int j = 1; j < DeleteLenght; j++) {
					if (StudentNames[Rows][i + j] == Lex[j]) {//see if the next character in text is the same as the next in the ReplaceWith specific row if not break
						count++;
					}
					else {
						break;
					}
				}
				if (count == DeleteLenght) {//if count equals to the lenght of the rep then we found the word that we want to replace in the text
					strcpy(StudentNames[Rows], "\0");
					Rows++;
					check = true;
					i = TERMINATE; // terminate the for loop 
				}
			}
		}
		if (check) {
			
			check = false;
		}
		else if (!check) {
			Rows++;
		}
	}
	for (int Rows = 0; Rows < LogicSize; Rows++) // delete Lex rows and organize the matrix
	{

		if (strcmp(StudentNames[Rows], "\0") != 0)
		{
			strcpy(StudentNames[JumpRow++], StudentNames[Rows]);
		}

	}
	strcpy(StudentNames[JumpRow], "\0");
	return JumpRow;
}
//*****
//*				GET_GradesChart Function
//*	Gets : --> STUDENT(stuData) matrix,stuDataRows as int , stuDataCols as int, courseNum as int and Integer matrix (Grades) for updating.
//* Doing: --> Installized the Grades matrix with all the grades of the students that took course number (courseNum) in correlation to the Group. 
//*****
void GET_GradesChart(STUDENT stuData[][GROUP_STUDENT_NUMBER],int Grades[][COLS],int stuDataRows, int stuDataCols,int courseNum)
{
	int GroupACount = 0, GroupBCount = 0, GroupCCount = 0, GradesGroupACols = 1;
	int GradesGroupBCols = 1, GradesGroupCcols = 1;
	for (int i = 0; i < stuDataRows; i++)
	{
		for (int j = 0; j < stuDataCols; j++)
		{
			for (int k = 0; k < stuData[i][j].nofCourses; k++)
			{
				if (stuData[i][j].course_info[k].courseNum == courseNum)
				{
					if (i == GROUP_A_LINE)
					{
						Grades[GROUP_A_ROW][GradesGroupACols++] = stuData[i][j].course_info[k].grade;
						GroupACount++;
					}
					else if (i == GROUP_B_LINE)
					{
						
						Grades[GROUP_B_ROW][GradesGroupBCols++] = stuData[i][j].course_info[k].grade;
						GroupBCount++;
					}
					else
					{
					
						Grades[GROUP_C_ROW][GradesGroupCcols++] = stuData[i][j].course_info[k].grade;
						GroupCCount++;
					}
				}
				
			}
		}
	}
	Grades[GROUP_A_ROW][0] = GroupACount;
	Grades[GROUP_B_ROW][0] = GroupBCount;
	Grades[GROUP_C_ROW][0] = GroupCCount;
}
//*****
//*				PRINTMaxDetails Function
//*	Gets : --> Row as int, Cols as int, FirstBig as int, SecondBig as int 
//* Doing: --> According to GETFirstAndSecond function, this function prints the related situation according to the Rows and Cols status. 
//*****
void PRINTMaxDetails(int Row, int Cols,int FirstBig,int SecondBig)
{

	if (Row == 0)
	{
		if (Cols == 0)
		{
			printf("\nGroupA: no grades found in group");
		}
		else if (Cols == 1)
		{
			printf("\nGroupA: max grade is: %d (no second max found)", FirstBig);
		}
		else
		{
			printf("\nGroupA: max grade is: %d and second max is: %d", FirstBig, SecondBig);
		}
	}
	else if (Row == 1)
	{
		if (Cols == 0)
		{
			printf("\nGroupB: no grades found in group");
		}
		else if (Cols == 1)
		{
			printf("\nGroupB: max grade is: %d (no second max found)", FirstBig);
		}
		else
		{
			printf("\nGroupB: max grade is: %d and second max is: %d", FirstBig, SecondBig);
		}
	}
	else
	{
		if (Cols == 0)
		{
			printf("\nGroupC: no grades found in group");
		}
		else if (Cols == 1)
		{
			printf("\nGroupC: max grade is: %d (no second max found)", FirstBig);
		}
		else
		{
			printf("\nGroupC: max grade is: %d and second max is: %d", FirstBig, SecondBig);
		}
	}

}
//*****
//*				GETFirstAndSecond Function
//*	Gets : --> integer matrix (Grades), rows as int. 
//* Doing: --> Searching for the First Max number from an array , and the second big number from an array.
// if founded / not etc.. the PRINTMaxDetails function take care.
//*****
void GETFirstAndSecond(int Grades[][COLS], int rows)
{
	int fbig, sbig; // Firstbig number , Secondbig number
	int i = 0;
	int j;
	int temp;
	while (i < rows)
	{
		j = Grades[i][0];
		fbig = Grades[i][1];
		sbig = Grades[i][2];
		if (sbig > fbig)
		{
			temp = sbig;
			sbig = fbig;
			fbig = temp;
		}
		for (int k = 3; k <= j; k++)
		{
			if (Grades[i][k] > fbig)
			{
				sbig = fbig;
				fbig = Grades[i][k];
			}
			else if (Grades[i][k] > sbig)
			{
				sbig = Grades[i][k];
			}
		}
		PRINTMaxDetails(i, j,fbig,sbig);
		i++;
	}
}
//*****
//*				PRINT_MaximumGrades Function
//*	Gets : --> integer matrix (Grades), rows as int, corseNum as int. 
//* Doing: --> Prints the coursenumber , then call the GETFirstAndSecond function for further proccess
//*****
void PRINT_MaximumGrades(int Grades[][COLS], int Rows ,int cols,int courseNum)
{
	printf("\nMaximum grades in course#%d:", courseNum);
	GETFirstAndSecond(Grades, Rows);
}
