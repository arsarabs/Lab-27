//map demo code 

#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

//Constants
const int FRIENDSHIP_MIN = 0;    // Minimum friendship level
const int FRIENDSHIP_MAX = 10;   // Maximum friendship level

using villagerData = tuple<int, string, string>;

//Function Prototypes
void addVillager(map<string, villagerData>& villagers);
void deleteVillager(map<string, villagerData>& villagers);
void increaseFriendship(map<string, villagerData>& villagers);
void decreaseFriendship(map<string, villagerData>& villagers);
void searchForVillager(const map<string, villagerData>& villagers);
void display(const map<string, villagerData>& villagers);


int main() {
    // declarations
    //map<string, vector<string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = { "Orange", "Yellow", "Red" };
    villagerColors["Raymond"] = { "Black", "Gray", "White" };
    villagerColors.insert({ "Marshal", {"Blue", "White", "Black"} });

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin();
        it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    }
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}


void addVillager(map<string, villagerData>& villagers) {
    //Local Variables
    string name, catchphrase, species = "";
    int friendship = 0;

    //Get name (& check if name exists)

    //Get friendship (&input validation)

    //and finally, get catchphrase and species

    //then add villager using make_tuple

}
void deleteVillager(map<string, villagerData>& villagers) {
    string name;

    //Prompt which villager to delete

    //delete (using if/else)
}
void increaseFriendship(map<string, villagerData>& villagers) {

}
void decreaseFriendship(map<string, villagerData>& villagers) {

}
void searchForVillager(const map<string, villagerData>& villagers) {

}
void display(const map<string, villagerData>& villagers) {
    if (villagers.empty()) {
        cout << "No villagers to display.\n";
        return;
    }

    cout << "************************************" << endl;
    cout << "********** VILLAGER DETAILS ******** " << endl;
}

