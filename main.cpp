#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<limits>
using namespace std;
namespace EmployeeManagement
{
    class Employee//EmployeeManagement::Employee::printFinalFile()
    {
    private:
        int id;
        string name;
        bool willingToVolunteer;
        string volunteerPlace;
        string volunteerStore;
        string dietaryPreferences;

    public:
        void setData(int empId, const string &empName, bool volunteer, const string &place, const string &store, const string &diet)
        {
            id = empId;
            name = empName;
            willingToVolunteer = volunteer;
            volunteerPlace = place;
            volunteerStore = store;
            dietaryPreferences = diet;
        }
        string getTaskName() const
        {
            if (dietaryPreferences == "veg")
            {
                return "1. Working in the cosmetics section";
            }
            else
            {
                return "1. Assisting customers at the food counter";
            }
        }
        void saveToFile()
        {
            ofstream file("employees.csv", ios::app);
            if (file.is_open())
            {
                file << id << "," << name << "," << (willingToVolunteer ? "Yes" : "No") << "," << volunteerPlace << "," << volunteerStore << "," << dietaryPreferences << "\n";
                file.close();
                cout << "Data saved to employees.csv.\n";
            }
            else
            {
                cerr << "Unable to open the file.\n";
            }
        }
        void saveToFinal()
        {
            ofstream file("final.csv", ios::app);
            if (file.is_open())
            {
                string taskName = getTaskName();
                file << name << "," << id << "," << taskName.substr(3) << "\n";
                file.close();
                cout << "Data saved to final.csv.\n\n\n";
            }
            else
            {
                cerr << "Unable to open the file.\n";
            }
        }


        friend class EmployeeReader; // Declare EmployeeReader as a friend class
    };

    class EmployeeStoreDetails
    {
    protected:
        int id;
        string name;
        bool volunteer;
        string place;
        string store;
        string diet;

    public:
        EmployeeStoreDetails(int empId, const string &empName, bool empVolunteer, const string &empPlace, const string &empStore, const string &empDiet)
            : id(empId), name(empName), volunteer(empVolunteer), place(empPlace), store(empStore), diet(empDiet)
        {
        }
        virtual void displayTasks() const = 0;
        virtual void updateCapacity() const = 0;
    };

    class BigStore : public EmployeeStoreDetails
    {
    private:
        int capacity;

    public:
        BigStore(int empId, const string &empName, bool empVolunteer, const string &empPlace, const string &empStore, const string &empDiet, int empCapacity)
            : EmployeeStoreDetails(empId, empName, empVolunteer, empPlace, empStore, empDiet), capacity(empCapacity)
        {
        }

        void displayTasks() const override
        {
            // Display tasks specific to BigStore
            cout << "Tasks in BigStore:\n";
            if (diet == "veg")
            {
                cout << "1. Working in the cosmetics section\n";
                //cout << "2. Assisting customers at the food counter\n";
            }
            else
            {
                cout << "1. Assisting customers at the food counter\n";
                //cout << "2. Working in the cosmetics section\n";
            }
        }
void updateCapacity() const override {
    const char* folderPath = std::getenv("my_folder");

    if (folderPath != nullptr) {
        // The environment variable exists
        std::string filePath = std::string(folderPath) + "/bigstore_capacity.txt";
        std::ifstream file(filePath);

        if (file.is_open()) {
            // File opened successfully
            std::cout << "Current capacity:" << std::endl;
            std::string line;
            std::getline(file, line);  // Read the current capacity from the file
            int capacity = std::stoi(line);  // Convert the capacity to an integer
            file.close();

            // Decrement the capacity
            capacity--;

            // Update the file with the new capacity
            std::ofstream outputFile(filePath);
            if (outputFile.is_open()) {
                outputFile << capacity << std::endl;
                outputFile.close();
                std::cout << "Capacity decremented. New capacity: " << capacity << std::endl;
            } else {
                // Failed to open the file for writing
                std::cout << "Failed to update the file." << std::endl;
            }
        } else {
            // Failed to open the file for reading
            std::cout << "Failed to open the file." << std::endl;
        }
    } else {
        // The environment variable doesn't exist
        std::cout << "MY_FOLDER environment variable is not set." << std::endl;
    }
}


    };

    class MediumStore : public EmployeeStoreDetails
    {
    private:
        int capacity;

    public:
        MediumStore(int empId, const string &empName, bool empVolunteer, const string &empPlace, const string &empStore, const string &empDiet, int empCapacity)
            : EmployeeStoreDetails(empId, empName, empVolunteer, empPlace, empStore, empDiet), capacity(empCapacity)
        {
        }

        void displayTasks() const override
        {
            // Display tasks specific to MediumStore
            cout << "Tasks in MediumStore:\n";
            if (diet == "veg")
            {
                cout << "1. Working in the cosmetics section\n";
                //cout << "2. Assisting customers at the food counter\n";
            }
            else
            {
                cout << "1. Assisting customers at the food counter\n";
                //cout << "2. Working in the cosmetics section\n";
            }
        }

         void updateCapacity() const override {
    const char* folderPath = std::getenv("my_folder");

    if (folderPath != nullptr) {
        // The environment variable exists
        std::string filePath = std::string(folderPath) + "/mediumstore_capacity.txt";
        std::ifstream file(filePath);

        if (file.is_open()) {
            // File opened successfully
            std::cout << "Current capacity:" << std::endl;
            std::string line;
            std::getline(file, line);  // Read the current capacity from the file
            int capacity = std::stoi(line);  // Convert the capacity to an integer
            file.close();

            // Decrement the capacity
            capacity--;

            // Update the file with the new capacity
            std::ofstream outputFile(filePath);
            if (outputFile.is_open()) {
                outputFile << capacity << std::endl;
                outputFile.close();
                std::cout << "Capacity decremented. New capacity: " << capacity << std::endl;
            } else {
                // Failed to open the file for writing
                std::cout << "Failed to update the file." << std::endl;
            }
        } else {
            // Failed to open the file for reading
            std::cout << "Failed to open the file." << std::endl;
        }
    } else {
        // The environment variable doesn't exist
        std::cout << "MY_FOLDER environment variable is not set." << std::endl;
    }
}

    };

    class SmallStore : public EmployeeStoreDetails
    {
    private:
        int capacity;

    public:
        SmallStore(int empId, const string &empName, bool empVolunteer, const string &empPlace, const string &empStore, const string &empDiet, int empCapacity)
            : EmployeeStoreDetails(empId, empName, empVolunteer, empPlace, empStore, empDiet), capacity(empCapacity)
        {
        }

        void displayTasks() const override
        {
            // Display tasks specific to SmallStore
            cout << "Tasks in SmallStore:\n";
            if (diet == "veg")
            {
                cout << "1. Working in the cosmetics section\n";
                //cout << "2. Assisting customers at the food counter\n";
            }
            else
            {
                cout << "1. Assisting customers at the food counter\n";
                //cout << "2. Working in the cosmetics section\n";
            }
        }

         void updateCapacity() const override {
    const char* folderPath = std::getenv("my_folder");

    if (folderPath != nullptr) {
        // The environment variable exists
        std::string filePath = std::string(folderPath) + "/smallstore_capacity.txt";
        std::ifstream file(filePath);

        if (file.is_open()) {
            // File opened successfully
            std::cout << "Current capacity:" << std::endl;
            std::string line;
            std::getline(file, line);  // Read the current capacity from the file
            int capacity = std::stoi(line);  // Convert the capacity to an integer
            file.close();

            // Decrement the capacity
            capacity--;

            // Update the file with the new capacity
            std::ofstream outputFile(filePath);
            if (outputFile.is_open()) {
                outputFile << capacity << std::endl;
                outputFile.close();
                std::cout << "Capacity decremented. New capacity: " << capacity << std::endl;
            } else {
                // Failed to open the file for writing
                std::cout << "Failed to update the file." << std::endl;
            }
        } else {
            // Failed to open the file for reading
            std::cout << "Failed to open the file." << std::endl;
        }
    } else {
        // The environment variable doesn't exist
        std::cout << "MY_FOLDER environment variable is not set." << std::endl;
    }
}

    };

    class EmployeeReader
    {
    public:
        static void readDataFromFile()
        {
            ifstream file("employees.csv");
            if (file.is_open())
            {
                string line;
                string mostRecentLine;
                while (getline(file, line))
                {
                    mostRecentLine = line;
                }

                stringstream ss(mostRecentLine);
                string token;
                vector<string> employeeData;
                while (getline(ss, token, ','))
                {
                    employeeData.push_back(token);
                }

                const int expectedSize = 6;
                if (employeeData.size() != expectedSize)
                {
                    cerr << "Invalid line in employees.csv: " << mostRecentLine << endl;
                    file.close();
                    return;
                }

                int id = stoi(employeeData[0]);
                string name = employeeData[1];
                bool volunteer = (employeeData[2] == "Yes");
                string place = employeeData[3];
                string store = employeeData[4];
                string diet = employeeData[5];

                EmployeeStoreDetails *employeeStoreDetails = nullptr;

                if (store == "BigStore")
                {
                    int capacity = 100; // Example capacity value for BigStore
                    employeeStoreDetails = new BigStore(id, name, volunteer, place, store, diet, capacity);
                }
                else if (store == "MediumStore")
                {
                    int capacity = 50; // Example capacity value for MediumStore
                    employeeStoreDetails = new MediumStore(id, name, volunteer, place, store, diet, capacity);
                }
                else if (store == "SmallStore")
                {
                    int capacity = 20; // Example capacity value for SmallStore
                    employeeStoreDetails = new SmallStore(id, name, volunteer, place, store, diet, capacity);
                }
                else
                {
                    cerr << "Invalid store type: " << store << endl;
                    file.close();
                    return;
                }
                employeeStoreDetails->displayTasks();
                employeeStoreDetails->updateCapacity();
                file.close();
            }
            else
            {
                cerr << "Unable to open the file.\n";
            }
        }
    };


 void printFinalFile()
        {
            std::ifstream file("final.csv");
            std::string line;

            if (file.is_open())
            {
                while (std::getline(file, line))
                {
                    std::cout << line << std::endl;
                }
                cout<<"\n"<<"\n";

                file.close();
            }
            else
            {
                std::cerr << "Unable to open final.csv" << std::endl;
            }
        }

  void collectEmployeeInfo()
{Employee emp;

int id;
std::string name;
bool volunteer;
std::string place;
std::string store;
std::string diet;

std::cout << "Choose an option:\n";
std::cout << "1. Employee ID\n";
std::cout << "2. Manager ID\n";
int option;
std::cin >> option;

std::string idType;
if (option == 1) {
    idType = "Employee ID";
} else if (option == 2) {
    idType = "Manager ID";

    int managerID;
    std::cout << "Enter Manager ID: ";
    std::cin >> managerID;


    while(managerID != 2334 && managerID != 5643) {
        std::cerr << "Invalid Manager ID." << std::endl;
        std::cout << "Enter Manager ID: ";
        std::cin >> managerID;

        //return 1; // Return an error code or use a different mechanism to indicate an error
    }

    printFinalFile();
    exit(1);// Assuming emp is a valid instance of the Employee class

} else {
    std::cerr << "Invalid option selected." << std::endl;
    // return 1; // Return an error code or use a different mechanism to indicate an error
}

while (true) {
    std::cout << "Enter " << idType << " (4 digits): ";
    std::cin >> id;

    try {
        if (std::cin.fail() || id < 1000 || id > 9999) {
            throw std::invalid_argument("Invalid " + idType + ". Please enter a 4-digit ID.");
        }

        // ID is valid, break out of the loop
        break;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;

        // Clear the error flag and discard remaining input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::cout << "Valid " << idType << ": " << id << std::endl;

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// Rest of your code...

// Ignore the remaining newline character
cout << "Enter employee name: ";
        //cin.ignore();
        getline(cin, name);

while (true) {
    std::cout << "Enter the dietary preferences of the employee (veg/nonveg): ";
    std::getline(std::cin, diet);

    try {
        if (diet != "veg" && diet != "nonveg") {
            throw std::invalid_argument("Invalid dietary preference. Please enter either 'veg' or 'nonveg'.");
        }

        // Dietary preference is valid, break out of the loop
        break;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::cout << "Valid dietary preference: " << diet << std::endl;

std::cout << "Is the employee willing to volunteer (1 for Yes, 0 for No): ";
std::cin >> volunteer;

// Rest of your code...


        if (volunteer)
        {
            cout << "Please choose a location to volunteer:\n";
            vector<string> places;
            places.push_back("jayanagar");
            places.push_back("sahakaranagar");
            places.push_back("magadi road");
            places.push_back("rajajinagar");

            for (size_t i = 0; i < places.size(); i++)
            {
                cout << i + 1 << ". " << places[i] << "\n";
            }

            int placeChoice;
            cin >> placeChoice;

            if (placeChoice >= 1 && placeChoice <= places.size())
            {
                place = places[placeChoice - 1];

                vector<string> stores;
                if (place == "jayanagar")
                {
                    stores.push_back("BigStore");
                    stores.push_back("MediumStore");
                }
                else if (place == "sahakaranagar")
                {
                    stores.push_back("BigStore");
                    stores.push_back("SmallStore");
                }
                else if (place == "magadi road")
                {
                    stores.push_back("MediumStore");
                    stores.push_back("SmallStore");
                }
                else if (place == "rajajinagar")
                {
                    stores.push_back("BigStore");
                    stores.push_back("SmallStore");
                }

                cout << "Please choose a store within " << place << " to volunteer:\n";
                for (size_t i = 0; i < stores.size(); i++)
                {
                    cout << i + 1 << ". " << stores[i] << "\n";
                }

                int storeChoice;
                cin >> storeChoice;

                if (storeChoice >= 1 && storeChoice <= stores.size())
                {
                    store = stores[storeChoice - 1];
                    EmployeeStoreDetails *employeeStoreDetails = nullptr;
                    if (store == "BigStore")
                    {
                        int capacity = 100; // Example capacity value for BigStore
                        employeeStoreDetails = new BigStore(id, name, volunteer, place, store, diet, capacity);
                    }
                    else if (store == "MediumStore")
                    {
                        int capacity = 50; // Example capacity value for MediumStore
                        employeeStoreDetails = new MediumStore(id, name, volunteer, place, store, diet, capacity);
                    }
                    else if (store == "SmallStore")
                    {
                        int capacity = 20; // Example capacity value for SmallStore
                        employeeStoreDetails = new SmallStore(id, name, volunteer, place, store, diet, capacity);
                    }
                    else
                    {
                        cerr << "Invalid store type: " << store << endl;
                        return;
                    }
                    //employeeStoreDetails->displayTasks();
                    //employeeStoreDetails->updateCapacity();
                    //delete employeeStoreDetails;
                }
                else
                {
                    cerr << "Invalid store choice.\n";
                    return;
                }
            }
            else
            {
                cerr << "Invalid place choice.\n";
                return;
            }
        }

        emp.setData(id, name, volunteer, place, store, diet);
        emp.saveToFile();
        emp.saveToFinal();
       // emp.printFinalFile();


    }
}
int main()
{
    EmployeeManagement::collectEmployeeInfo();
    cout << "Reading data from file:\n";
    EmployeeManagement::EmployeeReader::readDataFromFile();
      // Get the value of the environment variable
   /* const char* folderPath = std::getenv("my_folder");

    if (folderPath != nullptr) {
        // The environment variable exists
        std::string filePath = std::string(folderPath) + "/bigstore_capacity.txt";
        std::ifstream file(filePath);

        if (file.is_open()) {
            // File opened successfully
            std::cout << "File content:" << std::endl;
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            // Failed to open the file
            std::cout << "Failed to open the file." << std::endl;
        }
    } else {
        // The environment variable doesn't exist
        std::cout << "my_folder environment variable is not set." << std::endl;

    }*/



    return 0;
}
