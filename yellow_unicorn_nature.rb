# The Food Connection
# A Ruby program to connect people to local food sources

# Create class FoodConnection to store food information
class FoodConnection
  attr_accessor :name, :address, :phone, :website, :hours

  # Initialize with all necessary food information
  def initialize(name, address, phone, website, hours)
    @name = name
    @address = address
    @phone = phone
    @website = website
    @hours = hours
  end

  # Search food connection by name
  def self.search(name)
    found = nil
    FoodConnection.all.each do |item|
      if item.name == name
        found = item
        break
      end
    end
    return found
  end

  # Get all food connections
  def self.all
    @@all ||= []
  end
end

# Create class User to store user information
class User
  attr_accessor :name, :location

  # Initialize with user's name and location
  def initialize(name, location)
    @name = name
    @location = location
  end

  # Find food connections near user's location
  def find_foods
    nearby_foods = []
    FoodConnection.all.each do |food|
      if food.address == @location
        nearby_foods << food
      end
    end
    return nearby_foods
  end
end

# Create class FoodFinder to get food connections
class FoodFinder
  def self.get_food_connections
    # Get food connections from database
    food_connections = [
      FoodConnection.new('Farmers Market', 'New York', '123-456-7890', 'www.farmersmarket.com', '9am-6pm'),
      FoodConnection.new('Food Pantry', 'New Jersey', '123-456-7890', 'www.foodpantry.com', '9am-5pm'),
      FoodConnection.new('Community Garden', 'California', '123-456-7890', 'www.communitygarden.com', '10am-4pm')
    ]
    food_connections.each do |food|
      FoodConnection.all << food
    end
  end
end

# Get all food connections
FoodFinder.get_food_connections

# Create a user
user1 = User.new('John', 'New York')

# Find all food connections near user's location
nearby_foods = user1.find_foods
nearby_foods.each do |food|
  puts "#{food.name} - #{food.address} - #{food.phone} - #{food.website} - #{food.hours}"
end