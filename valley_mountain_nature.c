#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/*
 *  Define constants
 */
#define MAX_STR_LEN 100 
#define MAX_LINE 1000

// Structure for food items
typedef struct
{
	char itemName[MAX_STR_LEN];
	int quantity;
	double unitPrice;
	double totalPrice;
} FoodItem;


// Function prototypes
int readInputFile(FILE *inputFile, FoodItem items[], int maxItems);
int findItem(FoodItem items[], int size, char itemName[]);
void printItems(FoodItem items[], int size);
double computeTotalPrice(FoodItem items[], int size);
void writeOutputFile(FILE *outputFile, FoodItem items[], int size);

int main()
{
	// open input and output file
	FILE *inputFile, *outputFile;
	inputFile = fopen("thefoodconnection.txt", "r");
	if (inputFile == NULL)
	{
		printf("Error: Could not open input file\n");
		return 1;
	}
	outputFile = fopen("thefoodconnection.out", "w");
	if (outputFile == NULL)
	{
		printf("Error: Could not open output file\n");
		fclose(inputFile);
		return 1;
	}
	
	// Read the input file and store data in items array
	FoodItem items[MAX_LINE];
	int numItems = readInputFile(inputFile, items, MAX_LINE);
	fclose(inputFile);
	
	// Print the items array
	printItems(items, numItems);
	
	// Compute the total price
	double totalPrice = computeTotalPrice(items, numItems);
	printf("Total price = %.2lf\n", totalPrice);
	
	// Write the items array to an output file
	writeOutputFile(outputFile, items, numItems);
	fclose(outputFile);
	
	return 0;
}


// Read the input file and store data in items array
int readInputFile(FILE *inputFile, FoodItem items[], int maxItems)
{
	// Initialize the items array
	int numItems = 0;
	for (int i = 0; i < maxItems; i++)
	{
		strcpy(items[i].itemName, "");
		items[i].quantity = 0;
		items[i].unitPrice = 0.0;
		items[i].totalPrice = 0.0;
	}
	
	// Read the input file line by line
	char line[MAX_STR_LEN];
	while (fgets(line, MAX_STR_LEN, inputFile) != NULL)
	{
		// Get the item name
		char itemName[MAX_STR_LEN];
		strcpy(itemName, strtok(line, ","));
		
		// Check if the item is already in the items array
		int itemIndex = findItem(items, numItems, itemName);
		if (itemIndex >= 0)
		{
			// The item is already in the items array
			// Update the item's quantity
			strtok(NULL, ",");  // skip unitPrice
			int quantity = atoi(strtok(NULL, ","));
			items[itemIndex].quantity += quantity;
			
			// Update the item's total price
			items[itemIndex].totalPrice += (items[itemIndex].unitPrice * quantity);
		}
		else
		{
			// The item is not in the items array
			// Store the item in the items array
			strcpy(items[numItems].itemName, itemName);
			items[numItems].unitPrice = atof(strtok(NULL, ","));
			items[numItems].quantity = atoi(strtok(NULL, ","));
			items[numItems].totalPrice = items[numItems].unitPrice * items[numItems].quantity;
			
			// Increment the number of items
			numItems++;
		}
	}
	
	return numItems;
}

// Find the index of an item in the items array
int findItem(FoodItem items[], int size, char itemName[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(items[i].itemName, itemName) == 0)
		{
			// Found the item
			return i;
		}
	}
	
	// Item not found
	return -1;
}

// Print the items array
void printItems(FoodItem items[], int size)
{
	printf("Items:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s, %d, %.2lf, %.2lf\n",
			items[i].itemName, items[i].quantity,
			items[i].unitPrice, items[i].totalPrice);
	}
}

// Compute the total price
double computeTotalPrice(FoodItem items[], int size)
{
	double totalPrice = 0.0;
	for (int i = 0; i < size; i++)
	{
		totalPrice += items[i].totalPrice;
	}
	
	return totalPrice;
}

// Write the items array to an output file
void writeOutputFile(FILE *outputFile, FoodItem items[], int size)
{
	fprintf(outputFile, "Items:\n");
	for (int i = 0; i < size; i++)
	{
		fprintf(outputFile, "%s, %d, %.2lf, %.2lf\n",
			items[i].itemName, items[i].quantity,
			items[i].unitPrice, items[i].totalPrice);
	}
}