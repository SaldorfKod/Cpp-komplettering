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

    void writeToFile() 
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
        fs << "\n"
           << name
           << "\n"
           << price
           << "\n"
           << quantity
           << "\n"
           << warrantyDays
           << "\n";
    }

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }
};

class Clothing : public Product
{
    private: 
    char size;

    public:
    Clothing(const std::string& _name, double _price, int _quantity, char _size) : Product(_name, _price, _quantity), size(_size) {}

    void writeToFile()
    {
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
           << size
           << "\n";
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
        fs << "\n"
           << name
           << "\n"
           << price
           << "\n"
           << quantity
           << "\n"
           << expiration
           << "\n";
    }

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }
};

int main() {
    int choice = 0;
    std::string& newName;
    double newPrice = 0; 
    int newQuantity = 0;
    int newWarranty = 0;
    int newSize = 0;
    int newExpiration = 0;

    //this creates the file we will use for our inventory. The second flag makes sure we overwrite any existing file with the same name.
    std::fstream myfs{"inventory.txt", std::ios::out};
    //Write a string to the file, for easier debugging.
    myfs << "Items in inventory:\n";

    while (choice != 5)
    {
        std::cout << "Menu:\n"
                     "1. Add a electronics product to inventory.\n"
                     "2. Add a clothing product to inventory.\n"
                     "3. Add a food product to inventory.\n"
                     "4. Display inventory.\n"
                     "5. Exit\n"
                  << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choice;

        /*if (choiche == 5)
        {
            std::cout << "Good bye!" << std::endl;
            break; // Exit the program
        }*/

        switch (choice)
        {
        case 1:
            {
            std::cout << "Enter the details of the electronics product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Warranty in number of days: ";
            std::cin >> newWarranty;
            //create object of type Electronics, object is called e1
            Electronics e1 (newName, newPrice, newQuantity, newWarranty);
            //Call function to write all info to file
            e1.writeToFile();
            //Call function to calculate total cost and write this to file
            //Delete the object. It will only persist in the file.
            break;
            }
        case 2:
            std::cout << "Enter the details of the electronics product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Warranty in number of days: ";
            std::cin >> newWarranty;
            // create object of type Electronics, object is called e1
            Electronics e1(newName, newPrice, newQuantity, newWarranty);
                // Call function to write all info to file
                // Call function to calculate total cost and write this to file
                // Delete the object. It will only persist in the file.
                break;
        case 3:
            std::cout << "Enter the details of the electronics product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Warranty in number of days: ";
            std::cin >> newWarranty;
            // create object of type Electronics, object is called e1
            Electronics e1(newName, newPrice, newQuantity, newWarranty);
                // Call function to write all info to file
                // Call function to calculate total cost and write this to file
                // Delete the object. It will only persist in the file.
                break;
        case 4:
            std::cout << "Enter the details of the electronics product to add:\n";
            std::cout << "Name: ";
            std::cin >> newName;
            std::cout << "Price: ";
            std::cin >> newPrice;
            std::cout << "Quantity: ";
            std::cin >> newQuantity;
            std::cout << "Warranty in number of days: ";
            std::cin >> newWarranty;
            // create object of type Electronics, object is called e1
            Electronics e1(newName, newPrice, newQuantity, newWarranty);
                // Call function to write all info to file
                // Call function to calculate total cost and write this to file
                // Delete the object. It will only persist in the file.
                break;
        case 5:
            std::cout << "Good bye!" << std::endl;
            
            break; // Exit the program

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}