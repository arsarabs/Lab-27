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
    int userChoice;
    map<string, villagerData> villagers{
     {"Audie", {5, "Cat", "Nice fit"}},
     {"Raymond", {8, "Wolf", "Hubba hubba!"}},
     {"Marshal", {7, "Dog", "Let’s get it!"}}
    };

   //display menu using while loop & switch
    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Display All Villagers" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: " << endl;

        // Input validation for menu choice
        while (!(cin >> userChoice) || userChoice < 1 || userChoice > 7) {
            cout << "Invalid input. Please enter a number between 1 and 7: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        //swtich
        switch (userChoice) {
        case 1:
            break; 
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
         
    }
        cout << endl;

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
    string name;
    cout << "Villager name to increase friendship: " << endl;
    getline(cin, name);

    auto it = villagers.find(name); // searches villagers map for specific name (auto deduces the type of it as iterator for map)
    if (it != villagers.end()) { //validation to see if name in map
        int& friendship = get<0>(it->second); //here, it->second retrives the tuple associated with villager.
        //& get<0>() accesses the first element
        
        //if friendlevel is below max, then increase freindship by 1. if not, friendship level already at max
        if (friendship < FRIENDSHIP_MAX) {
            friendship += 1;
            cout << "Friendship level of " << name << " increased to " << friendship  << endl;
        }
        else {
            cout << "Friendship level of " << name << " already at max (" << FRIENDSHIP_MAX << ")" << endl;
        }
    }else {
        cout << name << " not found" << endl;
    }

}
void decreaseFriendship(map<string, villagerData>& villagers) {
    string name;
    cout << "Villager name to decrease friendship: " << endl;
    getline(cin, name);

    //nearly identical to increase!!
       
    auto it = villagers.find(name); // searches villagers map for specific name (auto deduces the type of it as iterator for map)
    if (it != villagers.end()) { //validation to see if name in map
        int& friendship = get<0>(it->second); //here, it->second retrives the tuple associated with villager.
        //& get<0>() accesses the first element

        //if friendlevel is below max, then increase freindship by 1. if not, friendship level already at max
        if (friendship < FRIENDSHIP_MAX) {
            friendship -= 1;
            cout << "Friendship level of " << name << " decrease to " << friendship << endl;
        }
        else {
            cout << "Friendship level of " << name << " already at min (" << FRIENDSHIP_MIN << ")" << endl;
        }
    }
    else {
        cout << name << " not found" << endl;
    }
}
void searchForVillager(const map<string, villagerData>& villagers) {
    string name;
    cout << "Villager name to search: ";
    getline(cin, name);

    auto it = villagers.find(name); // searches villagers map for specific name (auto deduces the type of it as iterator for map)
    if (it != villagers.end()) { //validation to see if name in map
        const villagerData& data = it->second; // // Retrieve the tuple (friendship, species, catchphrase) from the found villager's data
        int friendship;
        string species, catchphrase;

        // Unpack the tuple into the respective variables
        tie(friendship, species, catchphrase) = data; 
        //& display
        cout << name << " [" << friendship << ", " << species << ", \"" << catchphrase << "\"]" << endl;
    }else {
        // If the villager is not found, display an error message
        cout << name << " not found." << endl;
    }
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

