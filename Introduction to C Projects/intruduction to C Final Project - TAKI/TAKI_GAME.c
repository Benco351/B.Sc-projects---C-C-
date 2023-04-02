//# Ben cohen ID: 209174549
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define PLUS "+"
#define STOP "STOP"
#define CHANGE_DIRECTION "<->"
#define COLOR "COLOR"
#define TAKI "TAKI"
#define LOGO 1 // Define for the SHOW function 
#define MEMORY_ERROR 2 // Define for the SHOW function 
#define ENTER_NUMBER_PLAYERS 3 // Define for the SHOW function 
#define RED 'R' // 1
#define BLUE 'B' // 2
#define GREEN 'G' // 3
#define YELLOW 'Y' // 4
#define YELLOW_S 1// Define for the COLOR card color choose .
#define RED_S 2// Define for the COLOR card color choose .
#define BLUE_S 3// Define for the COLOR card color choose .
#define GREEN_S 4 // Define for the COLOR card color choose .
#define MAX_NAME_LEN 21  // Define of the maximum len of the NAME string
#define DEFAULT_CARDS 4  // Define of the default number of cards
#define MAX_TYPE_LEN 10 // Define of the maximum len of the type string
#define CARD_LENGHT 6 // Define of the default Lenght of the card
#define CARD_WIDTH 9 // Define of the default width of the card
#define START_CARD 1// Define to mark if we are handle the START card.
#define PLAYER_CARD 2 // Define to mark if we are handle player card.
#define PLUS_SELECTION 10 // options for the switch and case in the function s.
#define STOP_SELECTION 11// options for the switch and case in the function s.
#define CHANGE_DIR_SELECTION 12// options for the switch and case in the function s.
#define COLOR_SELECTION 13// options for the switch and case in the function s.
#define TAKI_SELECTION 14// options for the switch and case in the function s.
#define STATISTICS_ARRAY 14 // options for the switch and case in the function s.
#define THROW 1 // Define  if the PLayer put a correct card on the table so decrease the number of cards .
#define TAKE 0 // Define that say if the player choosed to take a card or the system choosed so ( in case of last plus card selection etc....)
#define INVALID_DESICION 5// Define option to print from the SHOW functions
#define COLOR_MENU 6// Define option to print from the SHOW functions 
#define INVALID_COLOR 7 // Define option to print from the SHOW functions 
#define STATISTICSS 8 // Define option to print from the SHOW functions
#define CLOCK_DIR 1 // Define if the game is running as the clock nature direction 
#define NOT_CLOCK_DIR -1 // Define if  the game is running NOT as the clock nature direction
#define IS == // ALIAS for the == module
#define LAST_CARD 1 // Define that represent if there is a last card on the player hand 
#define DEFAULT_CHECK 1 // Define that represent if i need a default check so if there is no special cards on the table
#define TAKI_CHECK 0 // Define that represent If the game is in the TAKI operation 
#define SO_DO ? //  // ALIAS for the ? in the terenary operation .
#define IF ( //       """""""" ( """""""""""""""""""
#define ELSE : // ALIAS for the : in the terenery operation 
#define RETURN ? // ALIAS for the ? in the terenary operation , identical to the SO_DO define just a nother name
#define STOP_TAKI 0 // Define that marks that the TAKI as finished
typedef char* PTRtype_c; // ALIAS for char*
typedef int type_t; // ALIAS for int.
typedef unsigned int type_u_t; // ALIAS for unsigned int.
typedef struct Cards {
	char Type[MAX_TYPE_LEN]; // The Type of the card as a full string.
	char Color; //The color Y , G , R , B 
	type_t Type_number;// The Type number of the type ( 1-9 ) is 1-9 , 10 - "+" , 11 - "STOP" , 12 - "<->" , 13 - "COLOR" , 14- "TAKI".
}CARDS;
typedef struct Player {
	char Name[MAX_NAME_LEN]; // String name , to hold the name of the specific player
	CARDS* cards; // CARDS pointer the the cards information.
	type_t _num_of_cards; // The number of cards the player got in his hand
	type_t decision; // The card the player choosed to put on the upper card.
	type_t Logic_size;// The Logic size of the CARDS array that the player holds
}PLAYER;
typedef struct Players {

	PLAYER* _data; // PLAYER pointer -> a pointer to the specific player in the PLAYERS struct .
	type_t _num_of_players; // The number of players in the whole game. NO MORE THAN 10

}PLAYERS;
typedef struct Ruler {
	type_t Direct; // direct of the game (CLOCKWISE or not)
	type_t Turn_index; // the number of turn in the game.
	bool Winner; // Bulb to know if there is a winner or not
	bool is_color; // Bulb to know if there is a color choosed or not.
	bool is_TAKI; // Bulb to know if there is a TAKI operation or not.
	bool is_Plus; // Bulb to know if there is a PLUS opration or not .( so keep the turn_index as it is.)
	PLAYERS* Players_PTR; // PLAYERS pointer , to get access to the number of players any time.
	CARDS* _Upper_card; // CARDS pointer to the upper card , to have a control every time on the main card.

}RULER;
typedef struct Statistics {
	type_t statistics_array[2][STATISTICS_ARRAY];
}STATISTICS;

// some usefull shorcuts for dinamic allocations.
const type_u_t IntegerBytes = sizeof(type_t); 
const type_u_t CharacterBytes = sizeof(char);
const type_u_t PlayerBytes = sizeof(PLAYER);
const type_u_t CardBytes = sizeof(CARDS);
//****************Functions***************************
void Print_statistics(PLAYER* winner, RULER* Judge, STATISTICS* statistics);
void replace_upper_card(PLAYER* active_player, CARDS* Judge_card);
void read_decision(PLAYER* active_player, RULER* Jugde);
void Generate_color_true(CARDS* Card, type_t Color_discision);
bool Check_Plus(RULER* Judge);
void update_nof_cards(PLAYER* active_player, type_t selection);
void InstallizeAndStart(PLAYERS* my_player, RULER* Judge, STATISTICS* statistics);
void SHOW(type_t selection);
void read_a_player(PLAYER* player, type_t number_of_card);
void PrintCARD(CARDS* Card);
void take_card(PLAYER* active_player);
type_t PlaceTypeOfCard(char* Type, type_t Lenght);
void GenerateType(CARDS* card, type_t Option);
void Generate_color_false(CARDS* Card);
type_t getRandomNumber(type_t from, type_t to);
CARDS* read_start_card(CARDS* StartCard);
void START_game(PLAYERS* Players_PTR, RULER* Judge, STATISTICS* statistics);
void Player_turn(PLAYER* active_player, RULER* Judge);
CARDS* arrRealloc(PLAYER* active_player);
bool Check_desicion(type_t decision, PLAYER* active_player, RULER* Judge, type_t Check_type);
bool Check_color_card(CARDS* specific_card);
bool Check_last_card(PLAYER* active_player);
void START_TAKI(PLAYER* active_player, RULER* Judge, STATISTICS* statistics);
void Color_selection(PLAYER* active_player, RULER* Judge);
//****************************************************
void main()
{

	srand((type_u_t)time(NULL));
	PLAYERS Players = { NULL,0 };// installize the player with some data
	RULER Jugde = { 1,0, false,false,false,false,NULL,NULL }; // installize the JUDGE with some data.
	STATISTICS statistics = { 0 }; // installize the statistics struct with some data.
	SHOW(LOGO);
	InstallizeAndStart(&Players, &Jugde, &statistics);// Allocate and the start the game..
	//** importent notice..
	// i free all the pointers that allocated dinamiclly from the same function they dinamiclly allocated.
	// for instance ( in the InstallizeAndStart funciton )..

}
//**********************************************************************************
//CheckAllocation
// function that checks if malloc succeed or not .
//**********************************************************************************
void CheckAllocation(void* Mem)
{
	if (!Mem)
	{
		SHOW(MEMORY_ERROR);
		exit(EXIT_FAILURE);
	}
}
//**********************************************************************************
//				 PrintUpperCard
// prints the upper card  on the deck and update the statistics table.
//**********************************************************************************
void PrintUpperCard(CARDS* card, STATISTICS* statistics)
{

	printf("\nUpper card:\n");
	type_t Type_number = card->Type_number;
	statistics->statistics_array[0][Type_number + 1] += 1;
	PrintCARD(card);
	printf("\n");

}
//**********************************************************************************
//				 read_start_card
// returns: Pointer to the starter card after allocation.
//**********************************************************************************
CARDS* read_start_card(CARDS* StartCard)
{
	StartCard = (CARDS*)malloc(CardBytes);
	CheckAllocation(StartCard);
	GenerateType(StartCard, START_CARD);
	Generate_color_false(StartCard);
	// get card number between 1-9
	return StartCard;
}
//**********************************************************************************
//				 InstallizeAndStart
// Installize and allocate all the data structers needed and START the game afterwards.
//**********************************************************************************
void InstallizeAndStart(PLAYERS* my_player, RULER* Judge, STATISTICS* statistics)
{
	SHOW(ENTER_NUMBER_PLAYERS);
	(void)scanf("%d", &my_player->_num_of_players);
	my_player->_data = (PLAYER*)malloc(my_player->_num_of_players * PlayerBytes);
	CheckAllocation(my_player->_data);
	for (type_t i = 0; i < my_player->_num_of_players; i++)
	{
		printf("Please enter the first name of player #%d:\n", i + 1);
		read_a_player(my_player->_data + i, DEFAULT_CARDS);
	}
	START_game(my_player, Judge, statistics);
	free(my_player->_data);
}
//**********************************************************************************
//				**read_a_player*** Asistant function for InstallizeAndStart function  
// Installize and allocate specific player
//**********************************************************************************
void read_a_player(PLAYER* player, type_t number_of_card)
{
	(void)scanf("%s", player->Name);
	player->_num_of_cards = number_of_card;
	player->cards = (CARDS*)malloc(number_of_card * CardBytes);
	player->Logic_size = DEFAULT_CARDS;
	CheckAllocation(player->cards);
	for (type_t i = 1; i <= player->_num_of_cards; i++)
	{
		GenerateType(player->cards + (i - 1), PLAYER_CARD);
		Generate_color_false(player->cards + (i - 1));
	}

}
//**********************************************************************************
//				intToStr  
// Convert int number into a string  to char array 
//**********************************************************************************
void intToStr(type_t num, char Type[])
{
	type_t index = 0, tmp = 0;
	Type[index]  = '\0';
	tmp = num % 10;
	Type[index++] = tmp + '0';
	Type[index] = '\0';

}
//**********************************************************************************
//				GenerateType  
// Global function that generate a type for specific card .
// Gets-> card pointer and Option for the generate.
// Depends on START_CARD or PLAYER_CARD , generate 1-9 numbers or 1-14 including specials
//**********************************************************************************
void GenerateType(CARDS* card, type_t Option)
{
	type_t Type = IF Option IS PLAYER_CARD SO_DO getRandomNumber(1, 14) ELSE getRandomNumber(1, 9));
	switch (Type) {
	case 1:
		intToStr(Type, card->Type);
		card->Type_number = 1;
		break;
	case 2:
		intToStr(Type, card->Type);
		card->Type_number = 2;
		break;
	case 3:
		intToStr(Type, card->Type);
		card->Type_number = 3;
		break;
	case 4:
		intToStr(Type, card->Type);
		card->Type_number = 4;
		break;
	case 5:
		intToStr(Type, card->Type);
		card->Type_number = 5;
		break;
	case 6:
		intToStr(Type, card->Type);
		card->Type_number = 6;
		break;
	case 7:
		intToStr(Type, card->Type);
		card->Type_number = 7;
		break;
	case 8:
		intToStr(Type, card->Type);
		card->Type_number = 8;
		break;
	case 9:
		intToStr(Type, card->Type);
		card->Type_number = 9;
		break;
	case PLUS_SELECTION:
		strcpy(card->Type, (PTRtype_c)PLUS);
		card->Type_number = 10;
		break;
	case STOP_SELECTION:
		strcpy(card->Type, (PTRtype_c)STOP);
		card->Type_number = 11;
		break;
	case CHANGE_DIR_SELECTION:
		strcpy(card->Type, (PTRtype_c)CHANGE_DIRECTION);
		card->Type_number = 12;
		break;
	case COLOR_SELECTION:
		strcpy(card->Type, (PTRtype_c)COLOR);
		card->Type_number = 13;
		break;
	case TAKI_SELECTION:
		strcpy(card->Type, (PTRtype_c)TAKI);
		card->Type_number = 14;
		break;
	default:
		break;
	}
}
//**********************************************************************************
//				Generate_color_false  
// function that generate a color for specific card for the first time .
// //**********************************************************************************
// Gets-> card pointer . 
void Generate_color_false(CARDS* Card)
{
	type_t Color = getRandomNumber(1, 4);
	if (!Check_color_card(Card))
	{
		switch (Color) {
		case 1:
			Card->Color = RED;
			break;

		case 2:
			Card->Color = BLUE;
			break;

		case 3:
			Card->Color = GREEN;
			break;

		case 4:
			Card->Color = YELLOW;
			break;
		default:
			break;
		}
	}
	else
	{

		Card->Color = ' ';
	}
}
//**********************************************************************************
//				Generate_color_true  
// function that generate a color for  the COLOR card only , also gets the desired color the player choosed. .
// Gets-> card pointer, and integer number refers to the descision of the player. . 
//**********************************************************************************
void Generate_color_true(CARDS* Card, type_t Color_discision)
{
	switch (Color_discision) {
	case 1:
		Card->Color = YELLOW;
		break;

	case 2:
		Card->Color = RED;
		break;

	case 3:
		Card->Color = BLUE;
		break;

	case 4:
		Card->Color = GREEN;
		break;
	default:
		break;
	}
}
//**********************************************************************************
//				getRandomNumber  
// function that generate a number between "from-to" variables
// Gets-> (int) "from" which number to generate and (int) "to" which number to generate.
//**********************************************************************************
type_t getRandomNumber(type_t from, type_t to) {
	type_t num;
	num = from + rand() % to;
	return num;
}
//**********************************************************************************
//				SHOW  
// the Printer functinon, gets selection and print the desired sentence.
//Gets-> int selection .
//**********************************************************************************
void SHOW(type_t selection)
{
	switch (selection)
	{
	case LOGO:
		printf("************  Welcome to TAKI game !!! *********** \n");
		break;
	case MEMORY_ERROR:
		printf("memory could not be allocated");
		break;
	case ENTER_NUMBER_PLAYERS:
		printf("Please enter the number of players:\n");
		break;
	case INVALID_DESICION:
		printf("Invalid card! Try again.\n");
		break;
	case COLOR_MENU:
		printf("Please enter your color choice:\n"
			"1 - Yellow\n"
			"2 - Red\n"
			"3 - Blue\n"
			"4 - Green\n");
		break;
	case INVALID_COLOR:
		printf("Invalid color! Try again.\n");
		break;
	case STATISTICSS:
		printf("************ Game Statistics ************\n");
		printf("Card # | Frequency\n__________________\n");
		break;
	default:
		break;
	}

}
//**********************************************************************************
//				PlaceTypeOfCard  
// Assistant function for PrintCARD, 
// calculate how much whitespaces to put between the borders refers to the specific type of card.
//Gets-> char pointer to the Type string , and lenght of the string.
//**********************************************************************************
type_t PlaceTypeOfCard(char* Type, type_t Lenght)
{
	type_t index = CARD_WIDTH - Lenght;
	type_t run = IF index % 2 IS 0 SO_DO index / 2 - 1 ELSE(index - 1) / 2);
	//take the lenght of the type characters and calculate the space of whitespaces that needed
	for (type_t cur = 0; cur < run; cur++)
	{
		printf(" ");
	}
	printf("%s", Type);
	return run + 1 + Lenght;
}
//**********************************************************************************
//				PrintCARD  
//The print card function.
//Gets-> Card pointer and then prints the card refers to the specific data.
//**********************************************************************************
void PrintCARD(CARDS* Card)
{
	type_t Lenght = strlen(Card->Type);
	bool check = false;
	for (type_t Row = 1; Row <= CARD_LENGHT; Row++)
	{
		for (type_t Cols = 1; Cols <= CARD_WIDTH; Cols++)
		{
			if (Row IS 1 || Row IS CARD_LENGHT || Cols IS 1 || Cols IS CARD_WIDTH) {
				printf("*");
			}
			else if (Row IS 3 && Lenght > 1 && !check)
			{
				Cols = PlaceTypeOfCard(Card->Type, Lenght);
				check = true;
			}
			else if (Row IS 3 && Cols IS 5) {
				printf("%s", Card->Type);
			}
			else if (Row IS 4 && Cols IS 5) {
				printf("%c", Card->Color);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
//**********************************************************************************
//				Check_Plus  
//Boolean function that check either the card on the deck is plus or not.
//Gets-> RULER struct pointer that contains the uppercard pointer.
//**********************************************************************************
bool Check_Plus(RULER* Judge)
{
	return (!strcmp(Judge->_Upper_card->Type, (PTRtype_c)PLUS));
}
//**********************************************************************************
//				Check_last_card  
//Boolean function that check either the card is the last card of the player.
//Gets-> PLAYER struct pointer that contains number of cards variable to check from.
//**********************************************************************************
bool Check_last_card(PLAYER* active_player)
{
	if (active_player->_num_of_cards == LAST_CARD)
	{
		take_card(active_player);
		return true;
	}
	return false;
}
//**********************************************************************************
//				START_game  
// The MAIN function-> start the game.
//Gets-> PLAYERS pointer , RULER pointer, STATISTICS pointer.
//Do-> use of all the functions in the project, then print the statistics at the end
//**********************************************************************************.
void START_game(PLAYERS* Players_PTR, RULER* Judge, STATISTICS* statistics)
{
	Judge->Players_PTR = Players_PTR;
	Judge->_Upper_card = read_start_card(Judge->_Upper_card);
	type_t number_of_players = Players_PTR->_num_of_players;;
	while (!Judge->Winner)
	{
		PrintUpperCard(Judge->_Upper_card, statistics);
		Player_turn(Players_PTR->_data + (Judge->Turn_index), Judge);
		if (Judge->is_TAKI IS true)
		{
			START_TAKI(Players_PTR->_data + (Judge->Turn_index), Judge, statistics);
		}
		if (Players_PTR->_data[Judge->Turn_index]._num_of_cards == 0)
		{
			Judge->Winner = true;
			continue;
		}
		if (!Check_Plus(Judge))
		{
			Judge->Turn_index = (Judge->Turn_index + Judge->Direct + number_of_players) % number_of_players;
		}
		else {
			Judge->is_Plus = false;
		}
	}

	Print_statistics(Players_PTR->_data + (Judge->Turn_index), Judge, statistics);
	
}
//**********************************************************************************
//				swap  
// Assistant function for the HeapSort function
//**********************************************************************************
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }
//**********************************************************************************
//				heapify  
// Assistant function for the HeapSort function
// Gets-> matrix array , n as the size of the specific row in the matrix
// Recursivley make a tree in the heap to order the array.
//**********************************************************************************
void heapify(int arr[][STATISTICS_ARRAY], int n, int i)
{
	int largest = i; // Initialize largest as the root in the tree
	int left = 2 * i + 1; // Installize the left child 
	int right = 2 * i + 2; // Installize the right child  

	// If left child is larger than root -------> Recursion stop
	if (left < n && arr[0][left] > arr[0][largest])
		largest = left;

	// If right child is larger than largest so far -------> Recursion stop
	if (right < n && arr[0][right] > arr[0][largest])
		largest = right;

	// If largest is not root so replace.
	if (largest != i) {
		swap(&arr[1][i], &arr[1][largest]);
		swap(&arr[0][i], &arr[0][largest]);

		// Recursively call on the subtree.
		heapify(arr, n, largest);
	}
}
//**********************************************************************************
//				heapSort  
// Implementation of the heapsort algorithm.
// Gets-> matrix array , n as the size of the specific row in the matrix
// Call the heapify recursive function the arrange all the sub trees.
// notice**->  I explained every part because we dont learned this algorithm in the class.
// Complexity -> log(n).
//**********************************************************************************
void heapSort(int arr[][STATISTICS_ARRAY], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	int k = 0;
	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(&arr[1][0], &arr[1][i]);
		swap(&arr[0][0], &arr[0][i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
//**********************************************************************************
//				whitespaces  
// Assistant function for Print_statistics function
// Gets-> char pointer and the lenght of the type.
// ***Diffrent from the whitespace function because of the way i calculate the spaces.
//**********************************************************************************
void whitespaces(char* Type, type_t Lenght)
{
	type_t index = CARD_WIDTH - Lenght, deadline = 8;
	type_t run = IF index % 2 IS 0 SO_DO index / 2 - 1 ELSE(index - 1) / 2);
	//take the lenght of the type characters and calculate the space of whitespaces that needed
	for (type_t cur = 0; cur < run; cur++)
	{
		printf(" ");
	}
	printf("%s",Type);
	for (type_t deadlin = Lenght+run+1 ; deadlin < deadline; deadlin++)
	{
		printf(" ");
	}
	printf("|");
}
//**********************************************************************************
//				GenreateRealType  
// returns a string.
// Gets-> char type pointer and integer 
//	returns : the specific type according to the type number in the statistics matrix , 
//( converting the type number to the really form in string to print the statistics table)
//**********************************************************************************
char* GenreateRealType(int type, char* Type)
{
	int index = 0;
	switch (type)
	{
	case PLUS_SELECTION:
		return ("+");
		break;
	case STOP_SELECTION:
		return ("STOP");
		break;
	case CHANGE_DIR_SELECTION:
		return ("<->");
		break;
	case COLOR_SELECTION:
		return ("COLOR");
		break;
	case TAKI_SELECTION:
		return ("TAKI");
		break;
	default:
		return NULL;
		break;
	}

}
//**********************************************************************************
//				Print_statistics  
// Prints the statistics table.
// Gets-> The PLAYER winner pointer, RULER pointer , STATISTICS pointer.
// in use of the Heapsort, sorting the matrix in descending order then prints from the end to 0 the statistics table.
//**********************************************************************************
void Print_statistics(PLAYER* winner, RULER* Judge, STATISTICS* statistics)
{
	printf("\nThe winner is... %s! Congratulations!\n", winner->Name);
	SHOW(STATISTICSS);
	type_t size = sizeof(statistics->statistics_array[0]) /
		sizeof(statistics->statistics_array[0][0]);
	for (int i = 0; i < size; i++)
	{
		statistics->statistics_array[1][i] = i;
	}
	heapSort(statistics->statistics_array, size);
	char* pt = (char*)malloc(MAX_TYPE_LEN * sizeof(char));
	CheckAllocation(pt);
	for (type_t i = size - 1; i > 0; i--)
	{
		int pr = statistics->statistics_array[0][i];
		pt = GenreateRealType(statistics->statistics_array[1][i] + 1, pt);
		if (pt == NULL)// because types- (1-9) are the same as the variables in the second row in the matrix  i just print them .
		{
			printf("   %d   |    %d\n", statistics->statistics_array[1][i], pr);
		}
		else 
		{
			whitespaces(pt, strlen(pt));
			printf("    %d\n", pr);
		}
	}
	free(pt); // free the pt allocation.
}
//**********************************************************************************
//				START_TAKI  
// Start the taki operation.
// Gets-> The PLAYER active_player pointer, RULER pointer , STATISTICS pointer.
// implementation of all the rules refers to the TAKI card.
// **(active->decision -1 ) refers  to the index in the pointer of where is the card he selected.
//**********************************************************************************
void START_TAKI(PLAYER* active_player, RULER* Judge, STATISTICS* statistics)
{

	PrintUpperCard(Judge->_Upper_card, statistics);
	Player_turn(active_player, Judge);
	type_t decision = active_player->decision;
	while (decision != STOP_TAKI
		&& Check_desicion(active_player->decision, active_player, Judge, TAKI_CHECK)
		&& active_player->_num_of_cards != LAST_CARD)
	{
		CARDS* specific_card = active_player->cards + (active_player->decision - 1);
		type_t Type_number = specific_card->Type_number;
		switch (Type_number)
		{
		case TAKI_SELECTION:
			replace_upper_card(active_player, Judge->_Upper_card);
			START_TAKI(active_player, Judge, statistics);
			return;
			break;
		case COLOR_SELECTION:
			Judge->is_color = true;
			Color_selection(active_player, Judge);
			break;
		default:
			replace_upper_card(active_player, Judge->_Upper_card);
			PrintUpperCard(Judge->_Upper_card, statistics);
			Player_turn(active_player, Judge);
			break;
		}
	}
	if (active_player->decision != STOP_TAKI)
	{
		read_decision(active_player, Judge);
	}
	Judge->is_TAKI = false;
}
//**********************************************************************************
//				arrRealloc  
// arrRealloc  gets PLAYER active_player pointer and then re allocate and expand the capacity of cards the player can hold..
// O(n) complexity of the malloc , according to geomatric sequence summary.
//**********************************************************************************
CARDS* arrRealloc(PLAYER* active_player)
{
	type_t k = 0;
	CARDS* New_card_heap = (CARDS*)malloc(2 * active_player->Logic_size * CardBytes);
	CheckAllocation(New_card_heap);
	for (k; k < active_player->Logic_size; k++)
	{
		New_card_heap[k] = active_player->cards[k];
	}
	active_player->Logic_size *= 2;
	return New_card_heap;
}
//**********************************************************************************
//				take_card  
// take_card  gets PLAYER active_player pointer , checks if the array of cards of the player is full or not if so reallocate,
// else generatetype and color for the new card taken.
//**********************************************************************************
void take_card(PLAYER* active_player)
{
	update_nof_cards(active_player, TAKE);
	type_t future_size = active_player->_num_of_cards;
	if (future_size > active_player->Logic_size)
	{
		active_player->cards = arrRealloc(active_player);
	}
	GenerateType(active_player->cards + future_size - 1, PLAYER_CARD);
	Generate_color_false(active_player->cards + future_size - 1);
}
//**********************************************************************************
//				check_identication  
// Boolean function that checks according to the Check_type if the card is equals to the card on the deck in the color OR in the type.
// if START_TAKI calls this function so the function only checks the color else , color or type.
//**********************************************************************************
bool check_identication(CARDS* active_player_card, CARDS* Jugde_card, type_t Check_type)
{
	return IF Check_type IS TAKI_CHECK) RETURN active_player_card->Color IS Jugde_card->Color ELSE
	!strcmp(active_player_card->Type, Jugde_card->Type) || active_player_card->Color IS Jugde_card->Color;
}
//**********************************************************************************
//				swap_info  
// Assistant function of replace_upper_card function.
// swap basic function to change the choosen card from the player with the card on the deck.
//**********************************************************************************
void swap_info(CARDS* active_player, CARDS* Judge_card)
{
	Judge_card->Color = active_player->Color;
	strcpy(Judge_card->Type, active_player->Type);
	Judge_card->Type_number = active_player->Type_number;
}
//**********************************************************************************
//				update_nof_cards  
// Assistant function of replace_upper_card function.
// Update the number of cards the player hold according to IF he Take a card for the heap or Put the card on the table .
// in other words -- or ++
//**********************************************************************************
void update_nof_cards(PLAYER* active_player, type_t selection)
{
	switch (selection)
	{
	case TAKE:
		active_player->_num_of_cards++;
		break;
	case THROW:
		active_player->_num_of_cards--;
		break;
	default:
		break;
	}
}
//**********************************************************************************
//				Reset_card_details  
// Assistant function of replace_upper_card function.
// Reset the card data of which the player choosed to put on the deck..
//**********************************************************************************
void Reset_card_details(CARDS* active_player)
{
	active_player->Color = ' ';
	strcpy(active_player->Type, "");
	active_player->Type_number = 0;
}
//**********************************************************************************
//				Re_replace_cards  
// Assistant function of replace_upper_card function.
// very importent function,
// that Re arrange all the card heap of the player according to changes.
// so that in the next turn the player card heap will be up to date..
//**********************************************************************************
void Re_replace_cards(CARDS* active_player, type_t size)
{
	type_t k;
	type_t p = 0;
	for (k = 0; k <= size; k++)
	{
		if (active_player[k].Type_number != 0)
		{
			active_player[p++] = active_player[k];
		}
	}
	Reset_card_details(active_player + p);

}
//**********************************************************************************
// 				replace_upper_card  
// Main function who's responssible to replace the upper card with the choosed card..
//**********************************************************************************
void replace_upper_card(PLAYER* active_player, CARDS* Judge_card)
{
	swap_info((active_player->cards + active_player->decision - 1), Judge_card);
	update_nof_cards(active_player, THROW);
	Reset_card_details(active_player->cards + active_player->decision - 1);
	Re_replace_cards(active_player->cards, active_player->_num_of_cards);
}
//**********************************************************************************
// 				check_color_selection  
// Boolean function that check if the COLOR card color the player choosed is valid or not.
//**********************************************************************************
bool check_color_selection(type_t color_disicion)
{
	switch (color_disicion)
	{
	case YELLOW_S:
		return true;
		break;
	case RED_S:
		return true;
		break;
	case BLUE_S:
		return true;
		break;
	case GREEN_S:
		return true;
		break;
	default:
		return false;
		break;
	}
}
//**********************************************************************************
// 				Color_selection  
// function that checks the validation of the COLOR card color select.
// *  Judge->is_color = true; if entered
//**********************************************************************************
void Color_selection(PLAYER* active_player, RULER* Judge)
{
	type_t Color_disicion;
	SHOW(COLOR_MENU);
	(void)scanf("%d", &Color_disicion);
	while (!check_color_selection(Color_disicion))
	{
		SHOW(INVALID_COLOR);
		SHOW(COLOR_MENU);
		(void)scanf("%d", &Color_disicion);
	}
	replace_upper_card(active_player, Judge->_Upper_card);
	Generate_color_true(Judge->_Upper_card, Color_disicion);
	Judge->is_color = false;
}
//**********************************************************************************
// 				read_decision  
// function that view the upper card ( after the player choosed) 
// and do the proper and the right operation refers of the the descision of the player.
// According the rules.
// 0 - the number of cards the player holds.
//**********************************************************************************
void read_decision(PLAYER* active_player, RULER* Jugde)
{
	if (active_player->decision IS TAKE && !Jugde->is_TAKI) // if there is a taki operation dont take card.
	{
		take_card(active_player);
	}
	else
	{
		CARDS* specific_card = active_player->cards + (active_player->decision - 1);
		type_t Type_number = specific_card->Type_number;
		switch (Type_number)
		{
		case PLUS_SELECTION:
			Jugde->is_Plus = true;
			replace_upper_card(active_player, Jugde->_Upper_card);
			if (Check_Plus(Jugde))
			{
				Check_last_card(active_player);
			}
			break;
		case STOP_SELECTION:
			if (Jugde->Players_PTR->_num_of_players == 2)
			{
				Check_last_card(active_player);
			}
			replace_upper_card(active_player, Jugde->_Upper_card);

			switch (Jugde->Direct)
			{
			case CLOCK_DIR:
				Jugde->Turn_index++;
				break;
			case NOT_CLOCK_DIR:
				Jugde->Turn_index--;
				break;
			default:
				break;
			}
			break;
		case CHANGE_DIR_SELECTION:
			if (!Jugde->is_TAKI)
			{
				Jugde->Direct *= NOT_CLOCK_DIR; // change direction
			}
			replace_upper_card(active_player, Jugde->_Upper_card);

			break;
		case COLOR_SELECTION:
			Jugde->is_color = true; // marks so color STARTS
			Color_selection(active_player, Jugde);
			break;
		case TAKI_SELECTION:
			replace_upper_card(active_player, Jugde->_Upper_card);
			Jugde->is_TAKI = true; // mark so TAKI starts 
			break;
		default:
			replace_upper_card(active_player, Jugde->_Upper_card);
			break;
		}
	}
}
//**********************************************************************************
// 				Check_color_card  
// Assistant function of the Check_desicion function ,
// Boolean function that check if the type of the specific card choosen is the COLOR card.
//**********************************************************************************
bool Check_color_card(CARDS* specific_card)
{
	return(!strcmp(specific_card->Type, (PTRtype_c)COLOR));
}
//**********************************************************************************
// 				Check_desicion  
// Boolean function that returns if the card descision is correct or not according to the uppercard.
//**********************************************************************************
bool Check_desicion(type_t decision, PLAYER* active_player, RULER* Judge, type_t Check_type)
{
	CARDS* specific_card = active_player->cards + (decision - 1);
	if (Check_color_card(specific_card))
	{
		return true;
	}
	return check_identication(specific_card, Judge->_Upper_card, Check_type);
}
//**********************************************************************************
// 				print_menu  
// Print the menu of TAKI turns OR default turn menu/
//**********************************************************************************
void print_menu(type_t type_check, type_t number_of_cards)
{
	IF type_check IS DEFAULT_CHECK)
	SO_DO printf("Please enter %d if you want to take a card from the deck\n"
		"or 1-%d if you want to put one of your cards in the middle:\n",
		TAKE, number_of_cards)
		ELSE printf("Please enter %d if you want to finish your turn\n"
			"or 1-%d if you want to put one of your cards in the middle:\n",
			STOP_TAKI, number_of_cards);
}
//**********************************************************************************
// 				Print_player_cards  
//Function that gets PLAYER pointer and prints all the cards he holds.
//**********************************************************************************
void Print_player_cards(PLAYER* active_player)
{
	printf("%s's turn:\n\n", active_player->Name);
	for (type_t i = 0; i < active_player->_num_of_cards; i++)
	{
		printf("\nCard #%d:\n", i + 1);
		PrintCARD(active_player->cards + i);
	}
}
//**********************************************************************************
// 				Player_turn  
//Function that responssible on the player turn
// Gets-> PLAYER pointer and RULER pointer , then ask for the descision,
// afterwards check if the descision the player made is correct ( in use of all the assistant functions i explained before)
// then if there is a TAKI choosed returns to the START_TAKI function , else do the read_descision function to continue the game .
//**********************************************************************************
void Player_turn(PLAYER* active_player, RULER* Judge)
{
	type_t type_check;
	type_check = IF Judge->is_TAKI IS true) SO_DO TAKI_CHECK ELSE DEFAULT_CHECK;
	Print_player_cards(active_player);
	print_menu(type_check, active_player->_num_of_cards);
	(void)scanf("%d", &active_player->decision);
	switch (type_check)
	{
	case TAKI_CHECK:
		return;
		break;
	case DEFAULT_CHECK:

		while (active_player->decision != TAKE &&
			!Check_desicion(active_player->decision, active_player, Judge, DEFAULT_CHECK))
		{
			SHOW(INVALID_DESICION);
			print_menu(DEFAULT_CHECK, active_player->_num_of_cards);
			(void)scanf("%d", &active_player->decision);
		}
		break;
	default:
		break;
	}
	read_decision(active_player, Judge);
}



