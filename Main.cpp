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

    cout << "Villager name: " << endl;
    getline(cin, name);
    if (villagers.find(name) != villagers.end()) {
        cout << "Villager \"" << name << "\" already exists." << endl;
        return;
    }

      // Input validation for friendship level
    cout << "Friendship level (" << FRIENDSHIP_MIN << "-" << FRIENDSHIP_MAX << "): " << endl;
    while (!(cin >> friendship) || friendship < FRIENDSHIP_MIN || friendship > FRIENDSHIP_MAX) {
        cout << "Invalid input. Please enter a number between " << FRIENDSHIP_MIN << " and " << FRIENDSHIP_MAX << ": " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    //and finally, get catchphrase and species
    cout << "Species: " << endl;
    getline(cin, species);

    cout << "Catchphrase: " << endl;
    getline(cin, catchphrase);

    //then add villager using make_tuple
    villagers[name] = make_tuple(friendship, species, catchphrase);
    cout << name << " added.";

}
void deleteVillager(map<string, villagerData>& villagers) {
    string name;

    //Prompt which villager to delete
    cout << "Villager name to delete: " << endl;
    getline(cin, name);

    //delete (using if/else)
    if (villagers.erase(name)) {
        cout << name << " deleted" << endl;
    }
    else {
        cout << name << " not found" << endl;
    }
}
void increaseFriendship(map<string, villagerData>& villagers) {

}
void decreaseFriendship(map<string, villagerData>& villagers) {

}
void searchForVillager(const map<string, villagerData>& villagers) {

}
void display(const map<string, villagerData>& villagers) {
    //checks to see if there are villagers to display
    if (villagers.empty()) {
        cout << "No villagers to display.\n";
        return;
    }
    //DISPLAY
    cout << "************************************" << endl;
    cout << "********** VILLAGER DETAILS ******** " << endl;
    for (const auto& pair : villagers) {
        const string& name = pair.first;
        const villagerData& data = pair.second;
        int friendship;

        string species, catchphrase;
        tie(friendship, species, catchphrase) = data;
        cout << name << " [" << friendship << ", " << species << ", \"" << catchphrase << "\"]\n";
    }
    cout << "************************************" << endl;
}

