# The Food Connection

# Imports
import csv
from collections import defaultdict
import random

# Constants
CSV_FILE = 'the_food_connection.csv'

# Helper functions
def read_csv(csv_file):
    '''
    Reads in the csv file containing the
    food connection data.
    '''
    data = []
    with open(csv_file, 'r') as f:
        reader = csv.reader(f)
        for row in reader:
            data.append(row)
    return data

def parse_data(data):
    '''
    Parses the csv data into a defaultdict.
    '''
    d = defaultdict(list)
    for row in data:
        d[row[0]].append(row[1:])
    return d

def prompt_user():
    '''
    Prompts the user for their desired food connection.
    '''
    print("Welcome to The Food Connection!")
    print("Please enter a food category to get started (e.g. fruit, vegetable, grain):")
    food_category = input()
    return food_category

def generate_food_connection(food_category, data):
    '''
    Generates a random food connection for the user.
    '''
    if food_category in data:
        connection = random.choice(data[food_category])
        print("Your food connection is: {} and {}".format(food_category,
                                                          connection[0]))
    else:
        print("Sorry, we don't recognize that food category.")

# Main program
if __name__ == '__main__':
    # Read in the csv data
    data = read_csv(CSV_FILE)
    # Parse it into a defaultdict
    data = parse_data(data)
    # Prompt the user for their desired food connection
    food_category = prompt_user()
    # Generate and print out the food connection
    generate_food_connection(food_category, data)