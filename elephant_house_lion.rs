//importing necessary libraries for the program
use std::io;
use std::io::Write;
use std::str::FromStr;

//declaring a classic struct Food with would be used to store food information
struct Food {
    name: String,
    calorie: u32,
    carbs: u32,
    fat: u32,
    protein: u32,
    sodium: u32
}

//declaring an enum to store the operations a user can do
enum FoodOperation {
    AddFood,
    DisplayFood,
    RemoveFood,
    EditFood,
    Exit
}

// this function would be used to display the menu
fn display_menu() {
    println!("Please choose one of the following options:");
    println!("1 - Add Food");
    println!("2 - Display Food");
    println!("3 - Remove Food");
    println!("4 - Edit Food");
    println!("5 - Exit");
    print!("Your choice: ");
    io::stdout().flush().expect("Flush failed!");
}

// this function would be used to add a food item to the database
fn add_food() {
    println!("Please enter the food details");
    print!("Name: ");
    io::stdout().flush().expect("Flush failed!");
    let mut name = String::new();
    io::stdin().read_line(&mut name).expect("Failed to read from stdin");
    let name = name.trim();

    print!("Calorie: ");
    io::stdout().flush().expect("Flush failed!");
    let mut calorie = String::new();
    io::stdin().read_line(&mut calorie).expect("Failed to read from stdin");
    let calorie: u32 = u32::from_str(calorie.trim()).expect("Failed to parse input");

    print!("Carbs: ");
    io::stdout().flush().expect("Flush failed!");
    let mut carbs = String::new();
    io::stdin().read_line(&mut carbs).expect("Failed to read from stdin");
    let carbs: u32 = u32::from_str(carbs.trim()).expect("Failed to parse input");

    print!("Fat: ");
    io::stdout().flush().expect("Flush failed!");
    let mut fat = String::new();
    io::stdin().read_line(&mut fat).expect("Failed to read from stdin");
    let fat: u32 = u32::from_str(fat.trim()).expect("Failed to parse input");

    print!("Protein: ");
    io::stdout().flush().expect("Flush failed!");
    let mut protein = String::new();
    io::stdin().read_line(&mut protein).expect("Failed to read from stdin");
    let protein: u32 = u32::from_str(protein.trim()).expect("Failed to parse input");

    print!("Sodium: ");
    io::stdout().flush().expect("Flush failed!");
    let mut sodium = String::new();
    io::stdin().read_line(&mut sodium).expect("Failed to read from stdin");
    let sodium: u32 = u32::from_str(sodium.trim()).expect("Failed to parse input");

    // creating a food item and adding it to the database
    let food = Food {
        name: name.to_string(),
        calorie,
        carbs,
        fat,
        protein,
        sodium
    };
    {
        let mut connection = FoodConnection::connection();
        connection.add_food(food);
    }
    println!("Food added!");
}

// this function would be responsible for displaying the food
fn display_food() {
    let connection = FoodConnection::connection();
    let food_list = connection.get_all_food();
    for food in food_list {
        println!("{:?}", food);
    }
    println!("End of list");
}

// this function would be responsible for removing a food from the database
fn remove_food() {
    println!("Please enter the name of the food to be removed");
    print!("Name: ");
    io::stdout().flush().expect("Flush failed!");
    let mut name = String::new();
    io::stdin().read_line(&mut name).expect("Failed to read from stdin");
    let name = name.trim();

    let connection = FoodConnection::connection();
    connection.remove_food(name);

    println!("Food removed!");
}

// this function would be responsible for editing a food 
fn edit_food() {
    println!("Please enter the name of the food to be edited");
    print!("Name: ");
    io::stdout().flush().expect("Flush failed!");
    let mut name = String::new();
    io::stdin().read_line(&mut name).expect("Failed to read from stdin");
    let name = name.trim();

    let connection = FoodConnection::connection();
    let food = connection.get_food(name);
    if food.is_none() {
        println!("No such food exists!");
        return;
    }

    println!("Please enter the new food details");
    print!("Calorie: ");
    io::stdout().flush().expect("Flush failed!");
    let mut calorie = String::new();
    io::stdin().read_line(&mut calorie).expect("Failed to read from stdin");
    let calorie: u32 = u32::from_str(calorie.trim()).expect("Failed to parse input");

    print!("Carbs: ");
    io::stdout().flush().expect("Flush failed!");
    let mut carbs = String::new();
    io::stdin().read_line(&mut carbs).expect("Failed to read from stdin");
    let carbs: u32 = u32::from_str(carbs.trim()).expect("Failed to parse input");

    print!("Fat: ");
    io::stdout().flush().expect("Flush failed!");
    let mut fat = String::new();
    io::stdin().read_line(&mut fat).expect("Failed to read from stdin");
    let fat: u32 = u32::from_str(fat.trim()).expect("Failed to parse input");

    print!("Protein: ");
    io::stdout().flush().expect("Flush failed!");
    let mut protein = String::new();
    io::stdin().read_line(&mut protein).expect("Failed to read from stdin");
    let protein: u32 = u32::from_str(protein.trim()).expect("Failed to parse input");

    print!("Sodium: ");
    io::stdout().flush().expect("Flush failed!");
    let mut sodium = String::new();
    io::stdin().read_line(&mut sodium).expect("Failed to read from stdin");
    let sodium: u32 = u32::from_str(sodium.trim()).expect("Failed to parse input");

    // creating a food item and updating it in the database
    let food = Food {
        name: name.to_string(),
        calorie,
        carbs,
        fat,
        protein,
        sodium
    };
    {
        let mut connection = FoodConnection::connection();
        connection.edit_food(food);
    }

    println!("Food edited!");
}

// This struct would store the data.
struct FoodConnection {
    foods: Vec<Food>
}

impl FoodConnection {
    //this function would create or open the connection
    fn connection() -> FoodConnection {
        FoodConnection { foods: Vec::new() }
    }

    //this function adds food to database
    fn add_food(&mut self, food: Food) {
        self.foods.push(food);
    }

    //this function removes food from database
    fn remove_food(&mut self, name: &str) {
        let index = self.foods
            .iter()
            .position(|food| food.name == name)
            .expect("Food not found");
        self.foods.remove(index);
    }

    //this function get a specific food from database
    fn get_food(&self, name: &str) -> Option<&Food> {
        for food in &self.foods {
            if food.name == name {
                return Some(food);
            }
        }
        None
    }

    //this function get all food from the database
    fn get_all_food(&self) -> &[Food] {
        &self.foods
    }

    //this function edit food in the database
    fn edit_food(&mut self, food: Food) {
        let index = self.foods
            .iter()
            .position(|f| f.name == food.name)
            .expect("Food not found");
        self.foods[index] = food;
    }

}


// this is the main function, where the program starts execution
fn main() {
    loop {
        display_menu();
        let mut choice = String::new();
        io::stdin().read_line(&mut choice).expect("Failed to read from stdin");
        let choice: FoodOperation = match choice.trim() {
            "1" => FoodOperation::AddFood,
            "2" => FoodOperation::DisplayFood,
            "3" => FoodOperation::RemoveFood,
            "4" => FoodOperation::EditFood,
            "5" => FoodOperation::Exit,
            _ => {
                println!("Invalid choice!");
                continue;
            }
        };
        match choice {
            FoodOperation::AddFood => add_food(),
            FoodOperation::DisplayFood => display_food(),
            FoodOperation::RemoveFood => remove_food(),
            FoodOperation::EditFood => edit_food(),
            FoodOperation::Exit => break
        }
    }
}