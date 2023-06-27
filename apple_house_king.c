#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOODS 1000
#define MAX_NAME_LEN 50

// Structure Definition 
// Food Item Structure
typedef struct food_item
{
    char name[MAX_NAME_LEN];
    int quantity;
    int price;
}FoodItem;

// Global Variables
FoodItem foods[MAX_FOODS];
int num_foods;

// Function and Procedure Prototypes
void init(void);
void display_menu(void);
void add_food(FoodItem new_food);
void display_foods(void);
void delete_food(char name[]);
void update_food(char name[], int quantity);

int main(){
    init();
    display_menu();
    return 0;
}

// Function Definitions

// Initalize food array to empty
void init(void){
    num_foods = 0;
} 

// Displays the main menu
void display_menu(void){
    int choice;
    do{
        printf("\nThe Food Connection\n\n");
        printf("1. Add Food\n");
        printf("2. Display Foods\n");
        printf("3. Delete Food\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                FoodItem new_food;
                // Prompt for Food Item Details
                printf("\nName: ");
                scanf("%s", new_food.name);
                printf("Quantity: ");
                scanf("%d", &new_food.quantity);
                printf("Price: ");
                scanf("%d", &new_food.price);
                add_food(new_food);
                break;
            case 2:
                display_foods();
                break;
            case 3:
                char name[MAX_NAME_LEN];
                printf("\nName: ");
                scanf("%s", name);
                delete_food(name);
                break;
            case 4:
                char upName[MAX_NAME_LEN];
                int upQuantity;
                printf("\nName: ");
                scanf("%s", upName);
                printf("Quantity: ");
                scanf("%d", &upQuantity);
                update_food(upName, upQuantity);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }while(choice != 5);
}

// Adds a new food item to the array of foods
void add_food(FoodItem new_food){
    foods[num_foods] = new_food;
    num_foods++;
    printf("\nFood Added!\n");
}

// Displays the list of foods
void display_foods(void){
    int i;
    if(num_foods == 0){
        printf("\nNo foods to display!\n");
        return;
    }
    for(i=0; i<num_foods; i++){
        printf("\nName: %s\n", foods[i].name);
        printf("Quantity: %d\n", foods[i].quantity);
        printf("Price: %d\n", foods[i].price);
    }
}

// Deletes a food item based on name
void delete_food(char name[]){
    int i;
    for(i=0; i<num_foods; i++){
        if(strcmp(name, foods[i].name) == 0){
            foods[i] = foods[num_foods-1];
            num_foods--;
            printf("\nFood Deleted!\n");
            return;
        }
    }
    printf("\nFood Not Found!\n");
}

// Updates the quantity of a food item
void update_food(char name[], int quantity){
    int i;
    for(i=0; i<num_foods; i++){
        if(strcmp(name, foods[i].name) == 0){
            foods[i].quantity = quantity;
            printf("\nQuantity Updated!\n");
            return;
        }
    }
    printf("\nFood Not Found!\n");
}