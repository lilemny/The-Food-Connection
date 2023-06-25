//main.rs

// Import the libraries:
extern crate reqwest;
extern crate serde_json;

// The "Food Connection" namespace:
mod food_connection {
    use std::collections::HashMap;
    use reqwest::{Error, Client};
    use serde_json::{Value, from_str};
    
    // Struct for restaurant information:
    pub struct Restaurant {
        pub restaurant_name: String,
        pub food_type: String,
        pub rating: String,
        pub cost: String,
        pub location: String,
    }
    
    // Enum to hold search types:
    pub enum SearchType {
        Name,
        FoodType,
        Rating,
        Cost,
        Location
    }
    
    // Helper function to get the JSON response from the API:
    fn get_json_response(url: &str) -> Result<Value, Error> {
        let client = Client::new();
        let mut res = client.get(url).send()?;
        let json_string = res.text()?;
        let result = from_str(&json_string);
        result
    }
    
    // Function to search restaurants by a keyword:
    pub fn search_restaurants(keyword: String, search_type: SearchType) -> Vec<Restaurant> {
        let mut restaurants: Vec<Restaurant> = vec![];
        let mut params: HashMap<&str, &str> = HashMap::new();
        let base_url = "http://foodconnection.org/api/restaurants";
        let search_type_str = match search_type {
            SearchType::Name => "name",
            SearchType::FoodType => "food_type",
            SearchType::Rating => "rating",
            SearchType::Cost => "cost",
            SearchType::Location => "location"
        };
        params.insert(search_type_str, &keyword);
        
        let url = base_url.to_owned() + "?" + &reqwest::get_params(&params).unwrap();
        let result = get_json_response(&url);
        
        match result {
            Ok(json) => {
                let restaurants_json = json["restaurants"];
                for restaurant_json in restaurants_json.as_array().unwrap() {
                    let restaurant_name = restaurant_json["name"].as_str().unwrap().to_owned();
                    let food_type = restaurant_json["food_type"].as_str().unwrap().to_owned();
                    let rating = restaurant_json["rating"].as_str().unwrap().to_owned();
                    let cost = restaurant_json["cost"].as_str().unwrap().to_owned();
                    let location = restaurant_json["location"].as_str().unwrap().to_owned();
                    let restaurant = Restaurant {
                        restaurant_name, 
                        food_type, 
                        rating, 
                        cost, 
                        location
                    };
                    restaurants.push(restaurant);
                }
            },
            Err(_) => ()
        }
        
        restaurants
    }
}

// User code:
fn main() {
    let restaurants = food_connection::search_restaurants("Italian".into(), food_connection::SearchType::FoodType);
    
    for restaurant in restaurants {
        println!("Name: {}, Food type: {}, Rating: {}", restaurant.restaurant_name, restaurant.food_type, restaurant.rating);
    }
}