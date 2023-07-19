public class TheFoodConnection {
	
	public static void main(String[] args) {
		
		// Set the main window
		JFrame mainWindow = new JFrame("The Food Connection");
		mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// Create the menu
		JMenuBar menuBar = new JMenuBar();
		JMenu fileMenu = new JMenu("File");
		
		// Add the components to the menu bar
		menuBar.add(fileMenu);
		
		// Create the submenu items and add them to the menu
		JMenuItem openMenuItem = new JMenuItem("Open");
		fileMenu.add(openMenuItem);
		
		JMenuItem saveMenuItem = new JMenuItem("Save");
		fileMenu.add(saveMenuItem);
		
		// Create the panel for the main window
		JPanel mainPanel = new JPanel();
		
		// Create the find food label and text field
		JLabel findFoodLabel = new JLabel("Find food:");
		JTextField findFoodTextField = new JTextField(20);
		
		// Add the components to the panel
		mainPanel.add(findFoodLabel);
		mainPanel.add(findFoodTextField);
		
		// Create the search button and add it to the panel
		JButton searchButton = new JButton("Search");
		mainPanel.add(searchButton);
		
		// Create the food search results table
		String[] columnNames = {"Name", "Type", "Restaurant"};
		Object[][] data = {
				{"Pizza", "Italian", "Dominos"},
				{"Burger", "Fast Food", "McDonalds"},
				{"Tacos", "Mexican", "Taco Bell"}
		};
		
		JTable foodTable = new JTable(data, columnNames);
		JScrollPane scrollPane = new JScrollPane(foodTable);
		
		// Add the table to the panel
		mainPanel.add(scrollPane);
		
		// Create the add to cart button and add it to the panel
		JButton addToCartButton = new JButton("Add to Cart");
		mainPanel.add(addToCartButton);
		
		// Create the shopping cart table
		String[] cartColumnNames = {"Item", "Quantity"};
		Object[][] cartData = {
				{"Pizza", 1},
				{"Burger", 2},
				{"Tacos", 3}
		};
		
		JTable cartTable = new JTable(cartData, cartColumnNames);
		JScrollPane cartScrollPane = new JScrollPane(cartTable);
		
		// Add the table to the panel
		mainPanel.add(cartScrollPane);
		
		// Create the checkout button and add it to the panel
		JButton checkoutButton = new JButton("Checkout");
		mainPanel.add(checkoutButton);
		
		// Add the menu bar and the panel to the main window
		mainWindow.setJMenuBar(menuBar);
		mainWindow.add(mainPanel);
		
		// Display the window
		mainWindow.pack();
		mainWindow.setVisible(true);
	
	}

}