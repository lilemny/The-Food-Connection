//Imports
import javax.swing.*;
import java.util.*;

//Class Declaration
class TheFoodConnection {
  //Properties 
  var foodTypes = arrayOf("Italian", "Mexican", "Chinese", "American", "Thai")
  var foodOptions = ArrayList<String>()
  
  //Methods 
  private fun loadFoodOptions(){
    for (i in foodTypes.indices) {
      foodOptions.add(foodTypes[i])
    }
  }
  fun selectMeal(){
    loadFoodOptions()
    val selectedFood = JOptionPane.showInputDialog(null, "Please select your desired food type: ",
                                                   "The Food Connection", JOptionPane.QUESTION_MESSAGE, null,
                                                   foodOptions.toTypedArray(), foodOptions[0])
    if (selectedFood != null){
      println("You've chosen $selectedFood, enjoy your meal!")
    }
  } 
}

//Main
fun main(args: Array<String>) {
  val theFoodConnection = TheFoodConnection()
  theFoodConnection.selectMeal()
}