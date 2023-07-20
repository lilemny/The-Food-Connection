// Import statements
import java.io.{File, PrintWriter}
import scala.io.Source

// Create foodConnection object class
object FoodConnection {

    // Class variables
    var ingredientList: List[String] = List()
    var totalCalories: Int = 0

    // Reads in the ingredient file
    def getIngredientList(filePath: String): Unit = {
        for (line <- Source.fromFile(filePath).getLines) {
            ingredientList = line.split(",").toList
        }
    }

    // Calculates total calories for a recipe
    def calculateTotalCalories(ingredients: List[String]): Unit = {
        for (ingredient <- ingredients) {
            totalCalories += ingredient.split(" ")(2).toInt
        }
    }

    // Generates a random recipe with given ingredients
    def generateRandomRecipe(ingredients: List[String]): List[String] = {
        var recipe: List[String] = scala.util.Random.shuffle(ingredients).take(3)
        return recipe
    }

    // Writes recipe information to file
    def writeRecipeToFile(recipe: List[String], filePath: String): Unit = {
        val pw = new PrintWriter(new File(filePath))
        pw.write("Ingredients: " + recipe.mkString(", ") + "\n")
        pw.write("Total Calories: " + totalCalories)
        pw.close
    }

    // Main function
    def main(args: Array[String]): Unit = {
        // Retrieves the list of ingredients from file
        getIngredientList(args(0))

        // Calculates the total calories for the recipe
        calculateTotalCalories(ingredientList)

        // Generates a random recipe
        var recipe: List[String] = generateRandomRecipe(ingredientList)

        // Writes the recipe information to file
        writeRecipeToFile(recipe, args(1))
    }
}