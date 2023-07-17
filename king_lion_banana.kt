// imports
import java.io.*
import java.util.ArrayList
import kotlin.io.BufferedReader

// declaration
class TheFoodConnection {

// constants
    companion object {
        val MENU_ITEMS_FILE_NAME = "menuItems.txt"
        val SEPARATOR = "|"
    }

// fields
    private var menu: ArrayList<String> = ArrayList()

// constructors
    constructor() {
        loadData()
    }

// methods
    fun displayMenu(): Unit {
        menu.forEach { item ->
            println(item)
        }
    }

    fun sortMenu(): Unit {
        menu.sort()
    }

    fun addItem(item: String): Unit {
        menu.add(item)
    }

    fun removeItem(item: String): Unit {
        menu.remove(item)
    }

    fun findItem(searchTerm: String): Boolean {
        for (item in menu) {
            if (item.toLowerCase().contains(searchTerm.toLowerCase())) {
                println("Found item: $item")
                return true
            }
        }
        return false
    }

    private fun loadData(): Unit {
        val file = File(MENU_ITEMS_FILE_NAME)
        if (file.exists()) {
            val reader = BufferedReader(FileReader(file))
            var line = reader.readLine()
            while (line != null) {
                val items = line.split(SEPARATOR)
                menu.add(items[0])
                line = reader.readLine()
            }
            reader.close()
        } else {
            println("Error: Could not find $MENU_ITEMS_FILE_NAME")
        }
    }

// overrides
    override fun toString(): String {
        return "The Food Connection : $menu"
    }

}