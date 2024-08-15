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
    double quantity;

public:
    Product(const std::string &_name, double _price, double _quantity) : name(_name), price(_price), quantity(_quantity) {}

    

    virtual void writeToFile()
    {
        // Call calculate function from inside this function, easy wam bam
        double totalCost = calculateTotalCost();
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << "\n"
           << name
           << "\n"
           << price
           << "\n"
           << quantity
           << "\n"
           << totalCost
           << "\n";
    }

    virtual double calculateTotalCost()
    {
        return price * quantity;
    }

    virtual ~Product() {}
};

class Electronics : public Product
{
private:
    double warrantyDays;

public:
    Electronics(const std::string &_name, double _price, double _quantity, double _warrantyDays) : Product(_name, _price, _quantity), warrantyDays(_warrantyDays) {}

    void writeToFile()
    {
        // Call calculate function from inside this function, easy wam bam
        double totalCost = calculateTotalCost();
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << std::endl
           << "Product: " << name << std::endl
           << "Price: " << price << std::endl
           << "Quantity: " << quantity << std::endl
           << "Warranty days: " << warrantyDays << std::endl
           << "Total cost: " << totalCost << std::endl;

        std::cout << "Info written to file." << std::endl;
    }

    virtual double calculateTotalCost()
    {
        return price * quantity;
    }
};

class Clothing : public Product
{
private:
    std::string size;

public:
    Clothing(const std::string &_name, double _price, double _quantity, std::string _size) : Product(_name, _price, _quantity), size(_size) {}

    void writeToFile()
    {
        // Call calculate function from inside this function, easy wam bam
        double totalCost = calculateTotalCost();
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << std::endl
           << "Product: " << name << std::endl
           << "Price: " << price << std::endl
           << "Quantity: " << quantity << std::endl
           << "Size: " << size << std::endl
           << "Total cost: " << totalCost << std::endl;
        std::cout << "Info written to file." << std::endl;
    }

    virtual double calculateTotalCost()
    {
        return price * quantity;
    }
};

class Food : public Product
{
private:
    // string?
    std::string expiration;

public:
    Food(const std::string &_name, double _price, double _quantity, std::string &_expiration) : Product(_name, _price, _quantity), expiration(_expiration) {}

    void writeToFile()
    {
        // Call calculate function from inside this function, easy wam bam
        double totalCost = calculateTotalCost();
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"inventory.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << std::endl
           << "Product: " << name << std::endl
           << "Price: " << price << std::endl
           << "Quantity: " << quantity << std::endl
           << "Expiration date: " << expiration << std::endl
           << "Total cost: " << totalCost << std::endl;
        std::cout << "Info written to file." << std::endl;
    }

    virtual double calculateTotalCost()
    {
        return price * quantity;
    }
};

void showInventory()
{
    // Set up inbound filestream to the file created in main
    std::ifstream fs{"inventory.txt"};
    // Read from the file, line by line.
    std::string shower;
    while (fs)
    {
        std::getline(fs, shower); // read each line into a string
        std::cout << shower << std::endl;
    }
};

// Function to handle input and verify it is compatible with desired data type
double inputVerification()
{
    bool choiceIsValid = 0;
    double verifiedInput = 0;
    double newRawInput = 0;
    // Go into loop and check if cin stream is good (int) or bad (not an int)
    while (choiceIsValid != 1)
    {
        //We can access the iostream from main here
        if (!std::cin)
        {
            // If not good: output error message...
            std::cout << "This wasn't a number. Try again." << std::endl;
            //...Then clear the bad state of stream...
            std::cin.clear();
            // I can't seem to ignore[all] so i just ignore 1000 chars or untill \n
            // This is not perfect
            std::cin.ignore(1000, '\n');
            // Ask for new input in the function. Thus we don't need any args calling the function
            std::cin >> newRawInput;
        }
        // Check if the stream now is good
        if (std::cin)
        {
            // If good: set my flag (bool) to true and we will exit the loop
            choiceIsValid = 1;
            verifiedInput = newRawInput;
        }
    }
    return verifiedInput;
};

int main()
{
    bool menuRunning = 1;
    bool choiceIsValid = 0;
    int choiceInteger = 0;
    double newQuantity = 0;
    double newWarranty = 0;
    double newPrice = 0;
    std::string choiceString;
    std::string newSize;
    std::string newExpiration;
    std::string newName;

    // this creates the file we will use for our inventory.
    // The second flag makes sure we overwrite any existing file with the same name.
    std::fstream myfs{"inventory.txt", std::ios::out};
    // Write a string to the file, for easier debugging and readability.
    myfs << "Items in inventory:\n";

    //Enter the menu loop
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
        //First om many function calls
        //This is the best way I found: Only use function if the...
        //... Stream is found to be bad
        if (!std::cin)
        {
            choiceInteger = inputVerification();
        }

        //Electronis
        if (choiceInteger == 1)
        {
            std::cout << "Enter the details of the electronics product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            // Here i tried using the function
            std::cin >> newPrice;
            if (!std::cin)
            {
                newPrice = inputVerification();
            }
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            if (!std::cin)
            {
                newQuantity = inputVerification();
            }
            std::cout << "Warranty in number of days: ";
            std::cin >> newWarranty;
            if (!std::cin)
            {
                newWarranty = inputVerification();
            }
            // create object of class Electronics, object is called e1
            Electronics e1(newName, newPrice, newQuantity, newWarranty);
            // Call function to write all info to file
            std::cout << "Object created" << std::endl;
            e1.writeToFile();
            //These messages are partly for debugging, but it looks good so I leave them
            std::cout << "Returning to menu" << std::endl;
            // Call function to calculate total cost and write this to file
            // Delete the object. It will only persist in the file.
            // It should be deleted when it goes out of scope i.e. here.
            //Reset menu choice
            choiceInteger = 0;
        }
        //Add Clothing
        if (choiceInteger == 2)
        {
            std::cout << "Enter the details of the clothing product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            if (!std::cin)
            {
                newPrice = inputVerification();
            }
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            if (!std::cin)
            {
                newQuantity = inputVerification();
            }
            std::cout << "Size (s, m, l, xl, or xxl): ";
            std::cin >> newSize;
            // create object of class clothing, object is called c1
            Clothing c1(newName, newPrice, newQuantity, newSize);
            // Call function to write all info to file
            std::cout << "Object created" << std::endl;
            c1.writeToFile();
            std::cout << "Returning to menu" << std::endl;
            // Call function to calculate total cost and write this to file
            // Delete the object. It will only persist in the file.
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        if (choiceInteger == 3)
        {
            std::cout << "Enter the details of the food product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            if (!std::cin)
            {
                newPrice = inputVerification();
            }
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            if (!std::cin)
            {
                newQuantity = inputVerification();
            }
            std::cout << "Expiration date yymmdd (like so:231230): ";
            std::cin >> newExpiration;
            // create object of class food, object is called f1
            Food f1(newName, newPrice, newQuantity, newExpiration);
            // Call function to write all info to file
            std::cout << "Object created" << std::endl;
            f1.writeToFile();
            std::cout << "Returning to menu" << std::endl;
            // Call function to calculate total cost and write this to file
            // Delete the object. It will only persist in the file.
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        if (choiceInteger == 4)
        {
            // call function to display contents of inventory file
            showInventory();
            // Reset menu choice to 0
            choiceInteger = 0;
        }
        if (choiceInteger == 5)
        {
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
