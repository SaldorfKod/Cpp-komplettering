#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

class Product
{
    protected:
    std::string name;
    double price;
    int quantity;

    public:
    Product(const std::string& _name, double _price, int _quantity) : name(_name), price(_price), quantity(_quantity) {}

    virtual void writeToFile() 
    {   
        //Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        //Stream all the info from the object to the file
        fs << "\n"
           << name 
           << "\n"
           << price
           << "\n"
           << quantity 
           << "\n";
    }

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }

    virtual ~Product() {}
};

class Electronics : public Product
{
    private: 
    int warrantyDays;

    public:
    Electronics(const std::string& _name, double _price, int _quantity, int _warrantyDays) : Product(_name, _price, _quantity), warrantyDays(_warrantyDays) {}

    void writeToFile()
    {
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << std::endl
            << "Product: " << name << std::endl
            << "Price: " << price << std::endl
            << "Quantity: " << quantity << std::endl
            << "Warranty days: " << warrantyDays << std::endl;
        std::cout << "Info written to file." << std::endl;
    }

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }
};

class Clothing : public Product
{
    private: 
    std::string size;

    public:
    Clothing(const std::string& _name, double _price, int _quantity, std::string _size) : Product(_name, _price, _quantity), size(_size) {}

    void writeToFile()
    {
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << std::endl
           << "Product: " << name << std::endl
           << "Price: " << price << std::endl
           << "Quantity: " << quantity << std::endl
           << "Size: " << size << std::endl;
        std::cout << "Info written to file." << std::endl;
    }

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }
};

class Food : public  Product
{
    private:
    //string?
    std::string expiration;

    public:
    Food(const std::string& _name, double _price, int _quantity, std::string& _expiration) : Product(_name, _price, _quantity), expiration(_expiration) {}

    void writeToFile()
    {
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << std::endl
           << "Product: " << name << std::endl
           << "Price: " << price << std::endl
           << "Quantity: " << quantity << std::endl
           << "Expiration date: " << expiration << std::endl;
        std::cout << "Info written to file." << std::endl;
    }

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }
};

void showInventory() {
    // Set up inbound filestream to the file created in main
    std::ifstream fs{"inventory.txt"};
    // Read from the file, line by line.
    std::string shower;
    while (fs) {
        std::getline(fs, shower); // read each line into a string
        std::cout << shower << std::endl;
        }
};


int main() {
    bool menuRunning = 1;
    bool choiceIsValid = 0;
    int choiceInteger = 0;
    int newQuantity = 0;
    int newWarranty = 0;
    double newPrice = 0;
    std::string choiceString;
    std::string newSize;
    std::string newExpiration;
    std::string newName;

    //this creates the file we will use for our inventory. 
    //The second flag makes sure we overwrite any existing file with the same name.
    std::fstream myfs{"inventory.txt", std::ios::out};
    //Write a string to the file, for easier debugging.
    myfs << "Items in inventory:\n";

    while (menuRunning == 1)
    {
        std::cout << "Menu:\n"
                     "1. Add a electronics product to inventory.\n"
                     "2. Add a clothing product to inventory.\n"
                     "3. Add a food product to inventory.\n"
                     "4. Display inventory.\n"
                     "5. Exit\n"
                  << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choiceInteger;

        
        //Go into loop and check if cin stream is good (int) or bad (not an int)
        while (choiceIsValid != 1)
        {
            //Loop until we get a good stream
            if (std::cin)
            {
                //If good: set my flag (bool) to true and we will exit the loop
                choiceIsValid = 1;
            }
            if (!std::cin)
            {
                //If not good: output error message...
                std::cout << "This wasn't a number. Try again." << std::endl;
                //...Then clear the bad state of stream...
                std::cin.clear();
                // I'll be honest i don't fully understand this part..
                // Ignore 1000 characters or up to and including "\n" i think?
                // Ideally this should be cin.ignore([all of it]);
                std::cin.ignore(1000, '\n');
                // Same as before, input stream to my int
                std::cin >> choiceInteger;
            }
        }
        
        

        //choiceInteger = std::stoi(choiceString);

        /*if (choiceInteger == 1 || choiceInteger == 2 || choiceInteger == 3 || choiceInteger == 4 || choiceInteger == 5)
        {
            choiceIsValid = 1;
        }
        */

        if(choiceInteger == 1){
            std::cout << "Enter the details of the electronics product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Warranty in number of days: ";
            std::cin >> newWarranty;
            //create object of class Electronics, object is called e1
            Electronics e1 (newName, newPrice, newQuantity, newWarranty);
            //Call function to write all info to file
            std::cout << "Object created" << std::endl;
            e1.writeToFile();
            std::cout << "function called" << std::endl;
            //Call function to calculate total cost and write this to file
            //Delete the object. It will only persist in the file.
            //It should be deleted when it goes out of scope i.e. here.
            choiceInteger = 0;
        }
        if (choiceInteger == 2){
            std::cout << "Enter the details of the clothing product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Size (s, m, l, xl, or xxl): ";
            std::cin >> newSize;
            // create object of class clothing, object is called c1
            Clothing c1(newName, newPrice, newQuantity, newSize);
            // Call function to write all info to file
            std::cout << "Object created" << std::endl;
            c1.writeToFile();
            std::cout << "Written to file" << std::endl;
            // Call function to calculate total cost and write this to file
            // Delete the object. It will only persist in the file.
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        if(choiceInteger == 3){
            std::cout << "Enter the details of the food product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Expiration date yymmdd (like so:231230): ";
            std::cin >> newExpiration;
            // create object of class food, object is called f1
            Food f1(newName, newPrice, newQuantity, newExpiration);
            // Call function to write all info to file
            std::cout << "Object created" << std::endl;
            f1.writeToFile();
            std::cout << "function called"<< std::endl;
            // Call function to calculate total cost and write this to file
            // Delete the object. It will only persist in the file.
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        if(choiceInteger == 4){
            //call function to display contents of inventory file
            showInventory();
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        if(choiceInteger == 5){
            std::cout << "Good bye!" << std::endl;
            menuRunning = 0;
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        /*if(choiceIsValid == 0){
            std::cout << "Invalid choice. Please try again.\n";
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        */
        choiceIsValid = 0;
    }
return 0;
}

