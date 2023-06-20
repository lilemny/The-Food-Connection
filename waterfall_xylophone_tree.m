clear all
clc

% Create the figure window 
figure

% Create axes 
ax = axes('position',[0 0.05 1 0.9]); 

% Read in the background image
bg = imread('food_connection.jpg');
image(bg)
axis off
hold on

% Initialize the food connection map.
connections = containers.Map;
connections('eggs') = {'omelet', 'scrambled eggs'};
connections('omelet') = {'cheese', 'onions', 'spinach'};
connections('scrambled eggs') = {'ham', 'onions', 'green pepper'};
connections('cheese') = {'quesadilla'};
connections('onions') = {'quesadilla'};
connections('spinach') = {'quesadilla'};
connections('quesadilla') = {'salsa', 'guacamole'};
connections('ham') = {'hamburger'};
connections('green pepper') = {'hamburger'};
connections('hamburger') = {'cheese', 'ketchup', 'mustard'};
connections('salsa') = {'taco'};
connections('guacamole') = {'taco'};
connections('taco') = {'sour cream', 'onions', 'tomatoes'};
connections('ketchup') = {'fries'};
connections('mustard') = {'fries'};
connections('sour cream') = {'burrito'};
connections('onions') = {'burrito'};
connections('tomatoes') = {'burrito'};
connections('burrito') = {'guacamole'};
connections('fries') = {};

% Store images in a map.
images = containers.Map;
images('eggs') = imread('eggs.jpg');
images('omelet') = imread('omelet.jpg');
images('scrambled eggs') = imread('scrambled_eggs.jpg');
images('cheese') = imread('cheese.jpg');
images('onions') = imread('onions.jpg');
images('spinach') = imread('spinach.jpg');
images('quesadilla') = imread('quesadilla.jpg');
images('ham') = imread('ham.jpg');
images('green pepper') = imread('green_pepper.jpg');
images('hamburger') = imread('hamburger.jpg');
images('salsa') = imread('salsa.jpg');
images('guacamole') = imread('guacamole.jpg');
images('taco') = imread('taco.jpg');
images('ketchup') = imread('ketchup.jpg');
images('mustard') = imread('mustard.jpg');
images('sour cream') = imread('sour_cream.jpg');
images('tomatoes') = imread('tomatoes.jpg');
images('burrito') = imread('burrito.jpg');
images('fries') = imread('fries.jpg');

% Store positions in a map.
pos = containers.Map;
pos('eggs') = [0.4 0.60 0.2 0.3];
pos('omelet') = [0.2 0.40 0.2 0.3];
pos('scrambled eggs') = [0.7 0.70 0.2 0.3];
pos('cheese') = [0.2 0.2 0.2 0.3];
pos('onions') = [0.4 0.4 0.2 0.3];
pos('spinach') = [0.6 0.2 0.2 0.3];
pos('quesadilla') = [0.8 0.4 0.2 0.3];
pos('ham') = [0.2 0.7 0.2 0.3];
pos('green pepper') = [0.6 0.7 0.2 0.3];
pos('hamburger') = [0.2 0.1 0.2 0.3];
pos('salsa') = [0.8 0.2 0.2 0.3];
pos('guacamole') = [0.6 0.1 0.2 0.3];
pos('taco') = [0.2 0.5 0.2 0.3];
pos('ketchup') = [0.4 0.8 0.2 0.3];
pos('mustard') = [0.7 0.8 0.2 0.3];
pos('sour cream') = [0.2 0.3 0.2 0.3];
pos('tomatoes') = [0.4 0.5 0.2 0.3];
pos('burrito') = [0.6 0.3 0.2 0.3];
pos('fries') = [0.8 0.7 0.2 0.3];

% Initialize the food connection graph.
food_graph = graph;
for food_item = keys(connections)
    food_connections = connections(food_item{1});
    for i=1:length(food_connections)
        food_graph = addedge(food_graph, food_item{1}, food_connections{i});
    end
end

% Plot all of the food items on the connection map.
plot(food_graph,'Layout','force','NodeLabel',[]);

% Add the food item images.
for food_item = keys(pos)
    food_pos = pos(food_item{1});
    food_im = images(food_item{1});
    image(food_pos(1), food_pos(2), food_im, 'AlphaData', 0.7);
end

% Add labels.
text(0.4, 0.6, 'Eggs');
text(0.2, 0.4, 'Omelet');
text(0.7, 0.7, 'Scrambled Eggs');
text(0.2, 0.2, 'Cheese');
text(0.4, 0.4, 'Onions');
text(0.6, 0.2, 'Spinach');
text(0.8, 0.4, 'Quesadilla');
text(0.2, 0.7, 'Ham');
text(0.6, 0.7, 'Green Pepper');
text(0.2, 0.1, 'Hamburger');
text(0.8, 0.2, 'Salsa');
text(0.6, 0.1, 'Guacamole');
text(0.2, 0.5, 'Taco');
text(0.4, 0.8, 'Ketchup');
text(0.7, 0.8, 'Mustard');
text(0.2, 0.3, 'Sour Cream');
text(0.4, 0.5, 'Tomatoes');
text(0.6, 0.3, 'Burrito');
text(0.8, 0.7, 'Fries');

% Set title.
title('The Food Connection')