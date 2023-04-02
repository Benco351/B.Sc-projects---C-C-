#define _CRT_SECURE_NO_WARNINGS
//Ben Cohen I.D- 209174549
#include <stdio.h>
#include <stdbool.h>
#define DEFAULT_PIZZA_PRICE 70.0 // Default pizza Price 
#define DEFAULTG_SIZE_LENGHT 40// Default Pizza lenght size
#define DEFAULTG_SIZE_WIDTH 50 // Default Pizza width size
#define DEFAULT_SURFACE 2000 //Surface of default pizza in cm
#define OLIVES_PRICE 10 // Olives Default Price
#define MUSHROOMS_PRICE 12 // Mushrooms Default Price
#define PINEAPPLE_PRICE 14 // Pineapple Default price
#define TOMATOES_PRICE 9 //Tomatoes Default price
#define WHOLE_PIZZA_TOPPING 1 // Whole pizza topping part
#define HALF_PIZZA_TOPPING 0.5 // Half pizza topping part
#define QUARTER_PIZZA_TOPPING 0.25 // Quarter pizza topping part
#define NONE 0 // No topping/default dough price / Zero
#define OPTION_HALF_PIZZA 2 // Half pizza option
#define OPTION_QUARTER_PIZZA 3 // Quarter pizza option
#define OPTION_WHOLE_PIZZA 1 // Whole pizza option
#define OPTION_DELIVERY 1 // Delivery option
#define OPTION_PICKUP 0 // Pick-up option
#define DELIVERY_PRICE 15 // Price of delivery
#define REGULAR_DOUGH_PRICE 0 // Regular dough price
#define VEGAN_DOUGH_PRICE 5 // Vegan dough price
#define WHOLE_WHEAT_DOUGH_PRICE 3 // Whole dough price
#define GLUTEN_FREE_DOUGH_PRICE 4 // Gluten-Free dough price
#define MAXIMUM_TOPPING 1 // Topping limit 
#define TEN 10 // Ten coin value
#define FIVE 5 // Five coin value
#define TWO 2 // Two coin value
#define ONE 1 // One coin Value
#define TAX 1.17 // Tax 17% added
#define MIN_PIZZA_LENGHT 10 // Minimum pizza lenght 
#define MIN_PIZZA_WIDTH 10  // Minimum pizza width
#define MAX_PIZZA_LENGHT 40 // Maximum pizza lenght
#define MAX_PIZZA_WIDTH 80 // Maximum pizza width
#define REGULAR 'r' // Regular dough option
#define WHOLE_WHEAT 'w' // Whole wheat dough option
#define VEGAN 'v' // Vegan dough option
#define GLUTEN_FREE 'f' // Gluten-free dough option
#define IS	== // Alias for ==
#define NOT != // Alias for !=
#define LOGO 0 // Print LOGO ,option
#define OUR_MENU 1  // Print Our_Menu ,option
#define INVALID_CHOICE 2  // Print Invalid Choise error option
#define INVALID_ID 3  // Print Invalid ID error option
#define INVALID_CHECK_DIGIT 4  // Print Invalid check digit error option
#define INVALID_LENGHT 5  // Print Invalid lenght error option
#define INVALID_WIDTH 6  // Print Invalid width error option
#define ENTER_LENGHT 7  // Print ENTER_LENGHT apply, option
#define ENTER_WIDTH 8  // Print ENTER WIDTH apply,option
#define ENTER_PIZZA_TO_MAKE 9  // Print ENTER HOW MUCH PIZZA TO MAKE apply, option
#define ENTER_ID_NUMBER 10  // Print ENTER ID NUMBER apply, option
#define DOUGH_MENU 11  // Print DOUGH_MENU ,option
#define OLIVES_MENU 12  // Print Olives Menu ,option
#define MUSHROOMS_MENU 13  // Print Mushrooms Menu, option
#define TOMATOES_MENU 14  // Print Tomato Menu, option
#define PINEAPPLES_MENU  15  // Print Pineapple Menu, option
#define TOPPING_CHOOSE_MENU 16  // Print The chooses of toppings, option 
#define EXCEEDED_TOPPING 17  // Print EXCEED_TOPPING error, option 
#define DELIVERY_MENU 18  // Print DELIVERY MENU  in case DELIVERY, option
#define PIZZA_DETAILS 19  // Print PIZZA DETAILS, option
#define DELIVERY_MENU2 20  // Print DELIVERY MENU in case PICK-UP, option
#define END_OF_ORDER 21 // Print the End Of Order line , option.
#define EPS (1e-10) // Tiny integer number to avoid test 9 failure( added to the total price )..

//Struct of all the specific pizza properties.
typedef struct PIZZA_PIZZA {
	int Lenght_Pizza; // Lenght of the current pizza
	int Width_Pizza;// Width of the current pizza
	int Surface; // Lenght * Width
	double Total_Pizza_Price; //Total pizza price
	double Addons_Price; // Price of all the addons(olives,mushrooms,Tomatoes,Pineapple) choosed
	double Dough_Addon; // Price of the dough type choosed for the current Surface choosed
	double PizzaPrice_NoAdds;// Price of pizza without addons.
}PIZZA;

// Struct of all the Costumer properties.
typedef struct Costumer {
	int ID_Number;//  ID number
	int Remaining_Balance; //The bill changer of the costumer
	int Total_Price_Taxes; //total price with taxes
	int Client_Payment;//Costumer Payment 
	int Change; // The change to return to the costumer
	int Delivery_Choose;// Costumer wants Delivery or pickup (1,0)
	int Ten_Coins, Fives_Coins, Twos_Coins, Ones_Coins; // Optional change formats for the costumer.
	double Olives_Choose, Mushrooms_Choose, Tometoes_Choose, Pineapple_Choose; // Addons the costumer choosed
	double Main_Order_Price; // Total price of the Order , the costumer made.
	char Dough_Choose;// Dough type choosed by the costumer.
	int Pizza_To_Make; // How much pizza the costumer choosed.
}COSTUMER;

//**************** All the notes are above the original function and not above the signature.
void SHOW(int Selection);
COSTUMER GET_Payment(COSTUMER costumer);
COSTUMER GET_Delivery_Choose(COSTUMER costumer);
COSTUMER GET_IDNumber(COSTUMER costumer);
COSTUMER GET_PizzaCount(COSTUMER costumer);
COSTUMER GET_Dough_Choose(COSTUMER costumer);
COSTUMER GET_Addons(COSTUMER costumer);
PIZZA UPDATE_Pizza_Price(COSTUMER costumer, PIZZA pizza);
PIZZA GET_LenghtWidth(PIZZA pizza);
void PrintPizza(PIZZA pizza, COSTUMER costumer);
void PrintOrderDetails(COSTUMER costumer);
PIZZA Reset_Pizza(PIZZA pizza);
COSTUMER Reset_Addons_Choose(COSTUMER costumer);
//-------------------------------------------------------------------------------------------
void main()
{
	PIZZA pizza = { 0 }; // Instilazied pizza struct
	COSTUMER costumer = { 0 }; //  ""    Costumer ""
	SHOW(LOGO);// Print LOGO 
	costumer = GET_IDNumber(costumer);// Read and check the ID number
	SHOW(OUR_MENU);// Print menu
	costumer = GET_PizzaCount(costumer); //Read and check the pizza count
	for (int Pizza_Number = 1; Pizza_Number <= costumer.Pizza_To_Make; Pizza_Number++) // Iterative loop times the pizza to make
	{
		printf("\n*************************************************\nPizza #%d:\n\n", Pizza_Number);
		pizza = GET_LenghtWidth(pizza);//Read and check the lenght&width of the pizza
		costumer = GET_Dough_Choose(costumer); // Read  and check the dough choosed by the Costumer
		costumer = GET_Addons(costumer); // Read and check the Addons choosed by the Costumer
		pizza = UPDATE_Pizza_Price(costumer, pizza); // Update the Specific pizza price.
		printf("\nPizza #%d details:\n*******************\nPizza size: %dx%d\nPizza price (without tax): %.2lf\n", Pizza_Number, pizza.Lenght_Pizza, pizza.Width_Pizza, pizza.Total_Pizza_Price);
		PrintPizza(pizza, costumer);// Printing the specific pizza
		costumer.Main_Order_Price += pizza.Total_Pizza_Price; // Sum up the Total's price of the Pizzas in the order.
		pizza = Reset_Pizza(pizza); // Reset the pizza properties for the next iteration if so..
		costumer = Reset_Addons_Choose(costumer);// Reset the Addons properties of the costumer for the next iteration if so.
	}
	costumer = GET_Delivery_Choose(costumer);//Read and check if the costumer wants a delivery and update the prices accordinally
	PrintOrderDetails(costumer); // Printing all the order detalis.
	costumer = GET_Payment(costumer);// Read and calculate the payment from the costumer
	SHOW(END_OF_ORDER);// Print end of order line.
}

//Function that Resets the Addons choose of the last iteration
//Gets costumer struct then Nullify the addons properties and return.
COSTUMER Reset_Addons_Choose(COSTUMER costumer)
{
	costumer.Olives_Choose = NONE;
	costumer.Mushrooms_Choose = NONE;
	costumer.Tometoes_Choose = NONE;
	costumer.Pineapple_Choose = NONE;
	return costumer;
}

//Function that resets the pizza struct .
//Gets Pizza struct and resets all the properties , then return
PIZZA Reset_Pizza(PIZZA pizza)
{
	pizza.Addons_Price = NONE;
	pizza.Lenght_Pizza = NONE;
	pizza.Width_Pizza = NONE;
	pizza.Dough_Addon = NONE;
	pizza.PizzaPrice_NoAdds = NONE;
	pizza.Surface = NONE;
	pizza.Total_Pizza_Price = NONE;
	return pizza;
}

//The Printer function xD
// Gets the selected menu/error to print and print then on the screen
void SHOW(int Selection) {
	switch (Selection) {
	case LOGO:
		printf(" Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");
		break;
	case OUR_MENU:
		printf("\nOur menu:\n*********\nBasic pizza: %.2f NIS for %dx%d size pizza\n\nToppings for basic size pizza:\nOlives: %d NIS\nMushrooms: %d NIS\nTomatoes: %d NIS\nPineapple: %d NIS\n\n", DEFAULT_PIZZA_PRICE, DEFAULTG_SIZE_LENGHT, DEFAULTG_SIZE_WIDTH, OLIVES_PRICE, MUSHROOMS_PRICE, TOMATOES_PRICE, PINEAPPLE_PRICE); //print the MTA pizza MENU
		printf("Dough type for basic size pizza:\nRegular: %d NIS\nVegan: %d NIS\nWhole wheat: %d NIS\nGluten free: %d NIS\n\n", REGULAR_DOUGH_PRICE, VEGAN_DOUGH_PRICE, WHOLE_WHEAT_DOUGH_PRICE, GLUTEN_FREE_DOUGH_PRICE);
		break;
	case INVALID_CHOICE:
		printf("Invalid choice! Try again.\n");
		break;
	case INVALID_ID:
		printf("Invalid ID number! Try again.\n");
		printf("Please enter your ID number:\n");
		break;
	case INVALID_CHECK_DIGIT:
		printf("Invalid check digit! Try again.\n");
		printf("Please enter your ID number:\n");
		break;
	case INVALID_LENGHT:
		printf("Invalid length! Try again.\n");
		printf("Please enter your pizza's length (cm): ");
		break;
	case INVALID_WIDTH:
		printf("Invalid width! Try again.\n");
		printf("Please enter your pizza's width (cm): ");
		break;
	case ENTER_LENGHT:
		printf("Please enter your pizza's length (cm): ");
		break;
	case ENTER_WIDTH:
		printf("Please enter your pizza's width (cm): ");
		break;
	case ENTER_PIZZA_TO_MAKE:
		printf("How many pizzas would you like to order? ");
		break;
	case ENTER_ID_NUMBER:
		printf("Please enter your ID number:\n");
		break;
	case DOUGH_MENU:
		printf("\nPlease enter the pizza's dough type:\nr - for regular\nv - for vegan\nw - for whole wheat\nf - for gluten-free\n");
		break;
	case OLIVES_MENU:
		printf("\nPlease choose the toppings:\n\n");
		printf("Olives (choose 0-3):\n%d. None\n%d. Whole pizza\n%d. Half pizza\n%d. Quarter pizza\n", NONE, OPTION_WHOLE_PIZZA, OPTION_HALF_PIZZA, OPTION_QUARTER_PIZZA);
		break;
	case MUSHROOMS_MENU:
		printf("\nMushrooms (choose 0-3):\n%d. None\n%d. Whole pizza\n%d. Half pizza\n%d. Quarter pizza\n", NONE, OPTION_WHOLE_PIZZA, OPTION_HALF_PIZZA, OPTION_QUARTER_PIZZA);
		break;
	case TOMATOES_MENU:
		printf("\nTomatos (choose 0-3):\n%d. None\n%d. Whole pizza\n%d. Half pizza\n%d. Quarter pizza\n", NONE, OPTION_WHOLE_PIZZA, OPTION_HALF_PIZZA, OPTION_QUARTER_PIZZA);
		break;
	case PINEAPPLES_MENU:
		printf("\nPineapple (choose 0-3):\n%d. None\n%d. Whole pizza\n%d. Half pizza\n%d. Quarter pizza\n", NONE, OPTION_WHOLE_PIZZA, OPTION_HALF_PIZZA, OPTION_QUARTER_PIZZA);
		break;
	case TOPPING_CHOOSE_MENU:
		printf("%d. None\n%d. Whole pizza\n%d. Half pizza\n%d. Quarter pizza\n", NONE, OPTION_WHOLE_PIZZA, OPTION_HALF_PIZZA, OPTION_QUARTER_PIZZA);
		break;
	case EXCEEDED_TOPPING:
		printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n");
		break;
	case DELIVERY_MENU:
		printf("\n*************************************************\nDo you want delivery for the price of %d NIS? Enter %d for delivery or %d for pick-up: ", DELIVERY_PRICE, OPTION_DELIVERY, OPTION_PICKUP);
		break;
	case DELIVERY_MENU2:
		printf("Do you want delivery for the price of %d NIS? Enter %d for delivery or %d for pick-up: ", DELIVERY_PRICE, OPTION_DELIVERY, OPTION_PICKUP);
		break;
	case END_OF_ORDER:
		printf("Thank you for your order!");
		break;
	default:
		break;
	}
}

//Function that checks the lenght of a given integer
//Gets Number and return the Lenght.
int LenghtOfNumber(int Number) {
	int counter = NONE;
	if (Number IS 0)
	{
		counter = 1;
	}
	while (Number > NONE)
	{
		Number /= TEN;
		counter++;
	}

	return counter;
}

// Assistant function of the CHECK_IDNumber function
// Gets specific digit and the Position (if we are in the position of multiply by 1 or by 2)
// and return the multiplation in Two cases : 1) more then 10 number 2) else..
int CalculateDigit(int Digit, int Position)
{
	int digit_X_position = Digit * Position;
	
	return (digit_X_position < TEN) ? digit_X_position : (digit_X_position % TEN + digit_X_position / TEN);
}

// Assistant Boolean function that return True or False if the Check ID of the number is valid or not in correlation.
// Gets Integer (IDnumber) and return the boolean result.
bool CHECK_IDNumber(int IDNumber)
{
	bool Checker = false;
	if (IDNumber > 0)
	{
		int Check_Number = IDNumber % TEN;
		IDNumber /= TEN;
		int sum = NONE;
		int Position = 2, ClosestDividerByTen = 0;
		int lenght = LenghtOfNumber(IDNumber);
		while (lenght > NONE && lenght < TEN)
		{
			Position = (Position % 2 NOT 0) ? ONE : TWO;
			sum += CalculateDigit(IDNumber % TEN, Position);
			IDNumber /= TEN;
			Position++;
			lenght--;
		}
		if (sum % 10 IS 0) // Cases the Check digit is 0. 
		{
			ClosestDividerByTen = sum;
		}
		else
		{
			ClosestDividerByTen = ((sum / TEN) + 1) * TEN;
		}
		Checker = (Check_Number IS ClosestDividerByTen - sum);
	}
	return Checker;
}

//Function that return only a Valid IDNumber after checks using input given by the costumer
// Gets costumer Struct , checks if the IDnumber is valid IF so return him,
// ELSE reading from the user his ID number until valid input. 
COSTUMER GET_IDNumber(COSTUMER costumer)
{
	SHOW(ENTER_ID_NUMBER);
	(void)scanf("%d", &costumer.ID_Number);// Reading from the user his ID number.
	while (!CHECK_IDNumber(costumer.ID_Number))
	{
		if (costumer.ID_Number > 0 && LenghtOfNumber(costumer.ID_Number) < 10)
		{
			SHOW(INVALID_CHECK_DIGIT);
			(void)scanf("%d", &costumer.ID_Number);// Reading from the user his ID number.
		}
		else
		{
			SHOW(INVALID_ID);
			(void)scanf("%d", &costumer.ID_Number);// Reading from the user his ID number.
		}
	}
	return costumer;
}

//Function that return  only a valid pizza count that the costumer choosed 
// Gets Costumer Struct and return the struct after validation of "how much pizza" to make property.
COSTUMER GET_PizzaCount(COSTUMER costumer)
{
	SHOW(ENTER_PIZZA_TO_MAKE);
	(void)scanf("%d", &costumer.Pizza_To_Make);// Reading how much pizza to make from the user
	while (costumer.Pizza_To_Make <= 0)
	{
		SHOW(INVALID_CHOICE);
		SHOW(ENTER_PIZZA_TO_MAKE);
		(void)scanf("%d", &costumer.Pizza_To_Make);// Reading how much pizza to make from the user
	}
	return costumer;
}

//Function that return only a valid pizza lenght&width that the costumer choosed
// Gets Pizza struct and return the struct after validation of lenght&width properties
// then Update the price properties related to the valid inputs.
PIZZA GET_LenghtWidth(PIZZA pizza) {
	SHOW(ENTER_LENGHT);
	(void)scanf("%d", &pizza.Lenght_Pizza);// Reading the lenght of pizza the user want to unique struct
	while (pizza.Lenght_Pizza < MIN_PIZZA_LENGHT || pizza.Lenght_Pizza > MAX_PIZZA_LENGHT || pizza.Lenght_Pizza % 2 NOT 0)
	{
		SHOW(INVALID_LENGHT);
		(void)scanf("%d", &pizza.Lenght_Pizza);
	}
	SHOW(ENTER_WIDTH);
	(void)scanf("%d", &pizza.Width_Pizza);/// Reading the Width of pizza the user want to unique struct
	while (pizza.Width_Pizza < MIN_PIZZA_LENGHT || pizza.Width_Pizza > MAX_PIZZA_WIDTH || pizza.Width_Pizza % 2 NOT 0)
	{
		SHOW(INVALID_WIDTH);
		(void)scanf("%d", &pizza.Width_Pizza);/// Reading the Width of pizza the user want to unique struct
	}
	pizza.Surface = pizza.Lenght_Pizza * pizza.Width_Pizza; // Calculate the Surface of the specific pizza without ADDONS
	pizza.PizzaPrice_NoAdds = ((double)pizza.Surface / DEFAULT_SURFACE) * DEFAULT_PIZZA_PRICE; // Calculate the Price of the specific pizza without ADDONS
	return pizza;
}

//Function that return only a valid Dough choose that the costumer choosed
// Gets Costumer struct and return the struct after validation of Dough property.
COSTUMER GET_Dough_Choose(COSTUMER costumer)
{
	SHOW(DOUGH_MENU);
	(void)scanf(" %c", &costumer.Dough_Choose);
	while (costumer.Dough_Choose NOT 'r' && costumer.Dough_Choose NOT 'v'
		&& costumer.Dough_Choose NOT 'w' && costumer.Dough_Choose NOT 'f')
	{
		SHOW(INVALID_CHOICE);
		SHOW(DOUGH_MENU);
		(void)scanf(" %c", &costumer.Dough_Choose);
	}
	return costumer;
}

//Function that Update the prices properties of specific pizza that the costumer choosed.
// Gets Costumer stuct and Pizza struct, checks which Dough the costumer choosed 
// then Update the prices of the Doughs related to a specific pizza 
//Further more, updates all the other  Price properties as well.
PIZZA UPDATE_Pizza_Price(COSTUMER costumer, PIZZA pizza)
{
	switch (costumer.Dough_Choose)
	{
	case VEGAN:
		pizza.Dough_Addon = ((double)pizza.Surface / DEFAULT_SURFACE) * VEGAN_DOUGH_PRICE;    // Calculate and installize the price of Vegan Dough to the pizza struct according to the Surface of the specific pizza
		break;
	case WHOLE_WHEAT:
		pizza.Dough_Addon = ((double)pizza.Surface / DEFAULT_SURFACE) * WHOLE_WHEAT_DOUGH_PRICE; // """""                           Whole Wheat Dough                                 """""
		break;
	case GLUTEN_FREE:
		pizza.Dough_Addon = ((double)pizza.Surface / DEFAULT_SURFACE) * GLUTEN_FREE_DOUGH_PRICE; // """""                           Gluten Free Dough                                 """""
		break;
	case REGULAR:
	default:
		pizza.Dough_Addon = REGULAR_DOUGH_PRICE;
		break;
	}
	pizza.Addons_Price = (pizza.Surface * costumer.Olives_Choose * OLIVES_PRICE) / DEFAULT_SURFACE; // Calculate the price of the Olives addons 
	pizza.Addons_Price += (pizza.Surface * costumer.Mushrooms_Choose * MUSHROOMS_PRICE) / DEFAULT_SURFACE;  // ""                 Mushrooms ""
	pizza.Addons_Price += (pizza.Surface * costumer.Tometoes_Choose * TOMATOES_PRICE) / DEFAULT_SURFACE; // ""                 Tomatoes ""
	pizza.Addons_Price += (pizza.Surface * costumer.Pineapple_Choose * PINEAPPLE_PRICE) / DEFAULT_SURFACE;// ""                 Pineapple ""
	pizza.Total_Pizza_Price = pizza.PizzaPrice_NoAdds + pizza.Dough_Addon + pizza.Addons_Price + EPS; // Sum up the TOTAL price of the specific pizza with addons and Dough selection
	return pizza;
}

//Assistant function of GET_addons function
// Gets Dough Selection index , according to this index reading from the user the choose and checks if valid,
//finally return the choose .
int CHECK_Choose(int Selection)
{
	int Choose = 0;
	switch (Selection)
	{
	case OLIVES_MENU:
		(void)scanf("%d", &Choose);// Reading the Part of the pizza the user wants olives on.
		while (Choose > OPTION_QUARTER_PIZZA || Choose < NONE)
		{
			SHOW(INVALID_CHOICE);
			SHOW(TOPPING_CHOOSE_MENU);
			(void)scanf("%d", &Choose);// Reading the Part of the pizza the user wants olives on.
		}
		break;
	case MUSHROOMS_MENU:
		(void)scanf("%d", &Choose);
		while (Choose > OPTION_QUARTER_PIZZA || Choose < NONE)
		{
			SHOW(INVALID_CHOICE);
			SHOW(TOPPING_CHOOSE_MENU);
			(void)scanf("%d", &Choose);
		}
		break;
	case TOMATOES_MENU:
		(void)scanf("%d", &Choose);
		while (Choose > OPTION_QUARTER_PIZZA || Choose < NONE)
		{
			SHOW(INVALID_CHOICE);
			SHOW(TOPPING_CHOOSE_MENU);
			(void)scanf("%d", &Choose);
		}
		break;
	case PINEAPPLES_MENU:
		(void)scanf("%d", &Choose);
		while (Choose > OPTION_QUARTER_PIZZA || Choose < NONE)
		{
			SHOW(INVALID_CHOICE);
			SHOW(TOPPING_CHOOSE_MENU);
			(void)scanf("%d", &Choose);
		}
		break;
	default:
		break;
	}
	return Choose;
}

//Assistant function of GET_addons function
// Gets the choose from the menu of the user (0,1,2,3) and return(0,1,0.5,0.25) in correlation
//for further calculation needed in the GET_addon function.
double CalculateTopping(int Choose)
{
	double ChoosedTopping;
	ChoosedTopping = (Choose IS OPTION_WHOLE_PIZZA) ? WHOLE_PIZZA_TOPPING : (Choose IS OPTION_HALF_PIZZA) ? HALF_PIZZA_TOPPING : (Choose IS OPTION_QUARTER_PIZZA) ? QUARTER_PIZZA_TOPPING : NONE;
	return ChoosedTopping;
}

//Function that return the costumer struct after validation of the costumer choosen addons.
// Gets Costumer struct and by order ,checks every addon choose , in addition to Exceeding check.
COSTUMER GET_Addons(COSTUMER costumer)
{
	int Current_Choose;
	double Toppings_Count = 0;// Topping Counter for the exceeding check
	SHOW(OLIVES_MENU);
	Current_Choose = CHECK_Choose(OLIVES_MENU);
	costumer.Olives_Choose = CalculateTopping(Current_Choose);
	Toppings_Count += costumer.Olives_Choose;
	if (Toppings_Count < 1)
	{
		SHOW(MUSHROOMS_MENU);
		Current_Choose = CHECK_Choose(MUSHROOMS_MENU);
		costumer.Mushrooms_Choose = CalculateTopping(Current_Choose);
		while (Toppings_Count + costumer.Mushrooms_Choose > MAXIMUM_TOPPING)
		{
			SHOW(EXCEEDED_TOPPING);
			SHOW(TOPPING_CHOOSE_MENU);
			Current_Choose = CHECK_Choose(MUSHROOMS_MENU);
			costumer.Mushrooms_Choose = CalculateTopping(Current_Choose);
		}
		Toppings_Count += costumer.Mushrooms_Choose;
		if (Toppings_Count < 1)
		{
			SHOW(TOMATOES_MENU);
			Current_Choose = CHECK_Choose(TOMATOES_MENU);
			costumer.Tometoes_Choose = CalculateTopping(Current_Choose);
			while (Toppings_Count + costumer.Tometoes_Choose > MAXIMUM_TOPPING)
			{
				SHOW(EXCEEDED_TOPPING);
				SHOW(TOPPING_CHOOSE_MENU);
				Current_Choose = CHECK_Choose(TOMATOES_MENU);
				costumer.Tometoes_Choose = CalculateTopping(Current_Choose);
			}
			Toppings_Count += costumer.Tometoes_Choose;
			if (Toppings_Count < 1)
			{
				SHOW(PINEAPPLES_MENU);
				Current_Choose = CHECK_Choose(PINEAPPLES_MENU);
				costumer.Pineapple_Choose = CalculateTopping(Current_Choose);
				while (Toppings_Count + costumer.Pineapple_Choose > MAXIMUM_TOPPING)
				{
					SHOW(EXCEEDED_TOPPING);
					SHOW(TOPPING_CHOOSE_MENU);
					Current_Choose = CHECK_Choose(PINEAPPLES_MENU);
					costumer.Pineapple_Choose = CalculateTopping(Current_Choose);
				}
			}
		}
	}
	return costumer;
}

//Assistant function of the PrintPizza function
// Gets some char variable, and the lenght then prints the frame of the pizza according to those values. 
void printFrameLine(char ch, int lenght)
{
	for (int i = 1; i <= lenght; i++)
		printf("%c", ch);
	printf("\n");
}

//Assistant function of the PrintPizza function
//Gets the final chars that will be in every Quarter as variables 
//in addition gets the pizza struct + current lenght&width in the print session.
// return the result of which char should be on this specific Quarter.
char getQuarterChar(char Q1, char Q2, char Q3, char Q4, PIZZA pizza, int CurLen, int CurWidth)
{
	char res;
	if (CurLen < pizza.Lenght_Pizza / 2)	// quarters 1 or 4
	{
		if (CurWidth < pizza.Width_Pizza / 2)
		{
			res = Q4;
		}
		else {
			res = Q1;
		}
	}
	else {                       // quarters 2 or 3
		if (CurWidth < pizza.Width_Pizza / 2)
		{
			res = Q3;
		}
		else {
			res = Q2;
		}
	}
	return res;
}

//Print Pizza function 
//Gets Pizza struct + Costumer struct and checks according to all the information , which addon will be in every Quarter .
// in use of some Assistant functions .
void PrintPizza(PIZZA pizza, COSTUMER costumer)
{
	char Quarter1 = ' ', Quarter2 = ' ', Quarter3 = ' ', Quarter4 = ' ';
	int Maximum_topping = MAXIMUM_TOPPING;
	double status = costumer.Olives_Choose + costumer.Mushrooms_Choose + costumer.Tometoes_Choose + costumer.Pineapple_Choose; // Status of how much addons in prectanges choosed on this pizza
	if (status NOT 0) // if there is addons at all
	{
		status -= costumer.Olives_Choose;
		if (Quarter1 IS ' ' && costumer.Olives_Choose NOT NONE)
		{
			Quarter1 = 'O';
			costumer.Olives_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter2 IS ' ' && costumer.Olives_Choose NOT NONE)
		{
			Quarter2 = 'O';
			costumer.Olives_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter3 IS ' ' && costumer.Olives_Choose NOT NONE)
		{
			Quarter3 = 'O';
			costumer.Olives_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter4 IS ' ' && costumer.Olives_Choose NOT NONE)
		{
			Quarter4 = 'O';
			costumer.Olives_Choose -= QUARTER_PIZZA_TOPPING;
		}
		status -= costumer.Mushrooms_Choose;
		if (Quarter1 IS ' ' && costumer.Mushrooms_Choose NOT NONE)
		{
			Quarter1 = 'M';
			costumer.Mushrooms_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter2 IS ' ' && costumer.Mushrooms_Choose NOT NONE)
		{
			Quarter2 = 'M';
			costumer.Mushrooms_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter3 IS ' ' && costumer.Mushrooms_Choose NOT NONE)
		{
			Quarter3 = 'M';
			costumer.Mushrooms_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter4 IS ' ' && costumer.Mushrooms_Choose NOT NONE)
		{
			Quarter4 = 'M';
			costumer.Mushrooms_Choose -= QUARTER_PIZZA_TOPPING;
		}
		status -= costumer.Tometoes_Choose;
		if (Quarter1 IS ' ' && costumer.Tometoes_Choose NOT NONE)
		{
			Quarter1 = 'T';
			costumer.Tometoes_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter2 IS ' ' && costumer.Tometoes_Choose NOT NONE)
		{
			Quarter2 = 'T';
			costumer.Tometoes_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter3 IS ' ' && costumer.Tometoes_Choose NOT NONE)
		{
			Quarter3 = 'T';
			costumer.Tometoes_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter4 IS ' ' && costumer.Tometoes_Choose NOT NONE)
		{
			Quarter4 = 'T';
			costumer.Tometoes_Choose -= QUARTER_PIZZA_TOPPING;
		}
		status -= costumer.Pineapple_Choose;
		if (Quarter1 IS ' ' && costumer.Pineapple_Choose NOT NONE)
		{
			Quarter1 = 'P';
			costumer.Pineapple_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter2 IS ' ' && costumer.Pineapple_Choose NOT NONE)
		{
			Quarter2 = 'P';
			costumer.Pineapple_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter3 IS ' ' && costumer.Pineapple_Choose NOT NONE)
		{
			Quarter3 = 'P';
			costumer.Pineapple_Choose -= QUARTER_PIZZA_TOPPING;
		}
		if (Quarter4 IS ' ' && costumer.Pineapple_Choose NOT NONE)
		{
			Quarter4 = 'P';
			costumer.Pineapple_Choose -= QUARTER_PIZZA_TOPPING;
		}
	}
	printFrameLine(costumer.Dough_Choose, pizza.Width_Pizza);// printing the frame chars
	for (int lenght = 1; lenght <= pizza.Lenght_Pizza - 2; lenght++)
	{
		printf("%c", costumer.Dough_Choose);
		for (int width = 1; width <= pizza.Width_Pizza - 2; width++)
		{
			printf("%c", getQuarterChar(Quarter1, Quarter2, Quarter3, Quarter4, pizza, lenght, width)); // Print the specific letter related to the specific Quarter (that related to the lenght&width)
		}
		printf("%c\n", costumer.Dough_Choose);
	}
	printFrameLine(costumer.Dough_Choose, pizza.Width_Pizza);
}

//Function that Checks the delivery choose validation and Update the prices properties.
// Gets Costumer stuct, read and validate delivery choose from the Costumer,
// then Update the prices of the Main order (/with taxes too) + reset the Remaining payment as the Price with taxes
// then return this updated Costumer struct as well.
COSTUMER GET_Delivery_Choose(COSTUMER costumer)
{
	SHOW(DELIVERY_MENU);
	(void)scanf("%d", &costumer.Delivery_Choose);// Reading from the user his ID number.
	while (costumer.Delivery_Choose NOT OPTION_DELIVERY && costumer.Delivery_Choose NOT OPTION_PICKUP)
	{
		SHOW(INVALID_CHOICE);
		SHOW(DELIVERY_MENU2);
		(void)scanf("%d", &costumer.Delivery_Choose);// Reading from the user his ID number.
	}
	if (costumer.Delivery_Choose IS 1)
	{
		costumer.Main_Order_Price += DELIVERY_PRICE;// Case the user wants delivery --> adding the price to the Main Total price changer.
	}
	costumer.Total_Price_Taxes += (int)(costumer.Main_Order_Price * TAX);//Calculate the total price with tax
	costumer.Remaining_Balance = costumer.Total_Price_Taxes; // CopyCat the Total Price with tax to a diffrent changer to work with , without touch the original changer.

	return costumer;
}

//Function that print all the Order details 
// Gets Costumer struct and print all the details of the order.
void PrintOrderDetails(COSTUMER costumer)
{
	if (costumer.Delivery_Choose IS OPTION_DELIVERY)
	{
		printf("\nYour order details:\n*******************\nID number: %09d\nNumber of pizzas: %d\nDelivery\nTotal price: %.2lf\nTotal price with tax (rounded down): %d\n\n", costumer.ID_Number, costumer.Pizza_To_Make, costumer.Main_Order_Price, costumer.Total_Price_Taxes);
	}
	else
	{
		printf("\nYour order details:\n*******************\nID number: %09d\nNumber of pizzas: %d\nPick-up\nTotal price: %.2lf\nTotal price with tax (rounded down): %d\n\n", costumer.ID_Number, costumer.Pizza_To_Make, costumer.Main_Order_Price, costumer.Total_Price_Taxes);
	}
}


//Function that calculate the change if there is  and gets the payment from the costumer.
// Gets Costumer struct and update all the struct information according to the payment Stage.
COSTUMER GET_Payment(COSTUMER costumer)
{
	while (costumer.Remaining_Balance > NONE) // While the costumer need to Pay the order DO......
	{
		printf("Please enter your payment: ");
		(void)scanf("%d", &costumer.Client_Payment); // Reading from the use how much he wants to pay.
		costumer.Remaining_Balance -= costumer.Client_Payment; // UPDATE the amount of money the User need to pay for .
		if (costumer.Remaining_Balance > 0) { // IF there is still more to pay ...
			printf("Your remaining balance is : %d\n", costumer.Remaining_Balance);
		}
		else if (costumer.Remaining_Balance NOT 0) { // Instead if The user pay more then he needs Give him Change..
			costumer.Change = -1 * costumer.Remaining_Balance; // The change we must return to the user.
			printf("Your change is %d NIS using:\n", costumer.Change);
			if (costumer.Change / TEN > 0) { // IF the change is more then 10 NIS ....
				costumer.Ten_Coins = costumer.Change / TEN;
				printf("%d coin(s) of ten\n", costumer.Ten_Coins);
				costumer.Change -= costumer.Ten_Coins * TEN; // UPDATE the change left to Coinify
			}
			if (costumer.Change / FIVE > 0) { // IF the change is more then 5 NIS ....
				costumer.Fives_Coins = costumer.Change / FIVE;
				printf("%d coin(s) of five\n", costumer.Fives_Coins);
				costumer.Change -= costumer.Fives_Coins * FIVE;//               """"""
			}
			if (costumer.Change / TWO > 0) { // IF the change is more then 2 NIS ....
				costumer.Twos_Coins = costumer.Change / TWO;
				printf("%d coin(s) of two\n", costumer.Twos_Coins);
				costumer.Change -= costumer.Twos_Coins * TWO;//               """"""
			}
			if (costumer.Change / ONE > 0) { // IF the change is more then 1 NIS ....
				costumer.Ones_Coins = costumer.Change / ONE;
				printf("%d coin(s) of one\n", costumer.Ones_Coins);
				costumer.Change -= costumer.Ones_Coins;//               """"""
			}
		}
	}
	return costumer;
}
