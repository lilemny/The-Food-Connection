# This is a Ruby code to help The Food Connection build a database.

# require necessary gems
require 'pg'
require 'active_record'

# create ActiveRecord connection
ActiveRecord::Base.establish_connection(
  adapter:  'postgresql',
  host:     'localhost',
  username: 'mrchef',
  database: 'the_food_connection'
)
 
# create a model for restaurants
class Restaurant < ActiveRecord::Base
end
 
# create a model for dishes
class Dish < ActiveRecord::Base
end
 
# create a model for reviews
class Review < ActiveRecord::Base
end

# create RestaurantTable
ActiveRecord::Migration.create_table :restaurants do |t|
  t.column :name, :string
  t.column :description, :text
  t.column :address, :string
  t.column :city, :string
  t.column :state, :string
  t.column :zip, :string
  t.timestamp
end
 
# create DishTable
ActiveRecord::Migration.create_table :dishes do |t|
  t.column :name, :string
  t.column :description, :text
  t.column :price, :integer
  t.column :restaurant_id, :integer
  t.timestamp
end
 
# create ReviewTable
ActiveRecord::Migration.create_table :reviews do |t|
  t.column :dish_id, :integer
  t.column :author, :string
  t.column :title, :string
  t.column :body, :text
  t.column :rating, :integer
  t.timestamp
end
 
# Create methods for Restaurant model
class Restaurant < ActiveRecord::Base
  has_many :dishes
 
  def self.search(query)
    where("name LIKE ?", "%#{query}%")
  end
 
  def name_with_city
    "#{name} - #{city}"
  end
end

# Create methods for Dish model
class Dish < ActiveRecord::Base
  belongs_to :restaurant
  has_many :reviews
 
  def self.search(query)
    where("name LIKE ?", "%#{query}%")
  end
 
  def price_in_dollars
    "$#{price / 100.0}"
  end
end

# Create methods for Review model
class Review < ActiveRecord::Base
  belongs_to :dish
 
  def self.rating_options
    (1..5).to_a
  end
 
  def stars
    "*" * rating
  end
end