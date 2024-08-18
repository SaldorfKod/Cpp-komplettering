#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <limits>

class GroceryItem
{
    protected:
    std::string name;
    double price;

    public:
    GroceryItem(const std::string& _name, double _price) : name(_name), price(_price) {}

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }

    virtual ~GroceryItem() {}
};

class FreshProduce : public GroceryItem
{
    private:
    std::string origin;
    double weightInKilos;

    public:
    FreshProduce(const std::string& _name, double _price, const std::string& _origin, double _weight) : GroceryItem(_name, _price), origin(_origin), weightInKilos(_weight) {}

    double calculateTotalCost(int quantity) override {
        return price * weightInKilos * quantity;
    }
};

class CannedGoods : public GroceryItem
{
    private:
    int quantityInCans;

    public:
    CannedGoods(const std::string& _name, double _price, int _quantity) : GroceryItem(_name, _price), quantityInCans(_quantity) {}

    double calculateTotalCost(int quantity) override {
        return price * quantityInCans * quantity;
    }
};

class BakeryItems : public GroceryItem
{
    private:
    int quantityInPieces;

    public:
    BakeryItems(const std::string& _name, double _price, int _quantity) : GroceryItem(_name, _price), quantityInPieces(_quantity) {}
    
    double calculateTotalCost(int quantity) override {
        return price * quantityInPieces * quantity;
    }
};

template <typename T>
double calculateTotalCost(const std::vector<T>& items, int quantity) {
    double totalCost = 0;
    for (const auto& item : items) {
        totalCost += item->calculateTotalCost(quantity);
    }
    return totalCost;
};

int main()
{
    std::vector<GroceryItem*> shoppingCart;
    int choiche = 0;
    std::string itemName;
    int itemPrice = 0;
    int quantity = 0;
    std::string origin;
    double weight = 0;
    int discountPercent = 0;
    double totalCost = 0;
    double discountedCost = 0;
    int quantityInCans = 0;
    int quantityInPieces = 0;

    while (choiche != 5) 
    {
        std::cout << "Menu:\n"
                     "1. Add Fresh Produce\n"
                     "2. Add Canned Goods\n"
                     "3. Add Bakery Items\n"
                     "4. Checkout\n"
                     "5. Exit\n" << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choiche;

        /*if (choiche == 5) 
        {
            std::cout << "Good bye!" << std::endl;
            break; // Exit the program
        }*/

        switch (choiche) {
            case 1:
                std::cout << "Enter Fresh Produce details:\n";
                std::cout << "Name: ";
                std::cin >> itemName;
                std::cout << "Price per Kg: ";
                std::cin >> itemPrice;
                /*if (!cin) // or*/ 
                if(std::cin.fail())
                {
                    // user didn't input a number
                    std::cin.clear();                                                   // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
                    // next, request user reinput
                    std::cout << "Invalid input. Please input a whole number." << std::endl;
                    std::cin >> itemPrice;
                }
                /*while (intChecker(itemPrice) != 1)
                {
                    itemPrice = 0;
                    std::cout << "Invalid input. Please input a whole number." << std::endl;
                    std::cin >> itemPrice;
                }
                */
                
                
                std::cout << "Origin: ";
                std::cin >> origin;
                std::cout << "Weight in Kg: ";
                std::cin >> weight;
                shoppingCart.push_back(new FreshProduce(itemName, itemPrice, origin, weight));
                break;
            case 2:
                std::cout << "Enter Canned Goods details:\n";
                std::cout << "Name: ";
                std::cin >> itemName;
                std::cout << "Price per can: ";
                std::cin >> itemPrice;
                std::cout << "Quantity in cans: ";
                std::cin >> quantityInCans;
                shoppingCart.push_back(new CannedGoods(itemName, itemPrice, quantityInCans));
                break;
            case 3:
                std::cout << "Enter Bakery Items details:\n";
                std::cout << "Name: ";
                std::cin >> itemName;
                std::cout << "Price per piece: ";
                std::cin >> itemPrice;
                std::cout << "Quantity in pieces: ";
                std::cin >> quantityInPieces;
                shoppingCart.push_back(new BakeryItems(itemName, itemPrice, quantityInPieces));
                break;
            case 4:
                std::cout << "Do you have a discount? (In percentage, 0 if none): ";
                std::cin >> discountPercent;
                totalCost = calculateTotalCost(shoppingCart, 1);
                discountedCost = totalCost - (totalCost * discountPercent / 100);
                std::cout << "Total cost after discount: $" << discountedCost << "\n";
                break;
            case 5:
                std::cout << "Good bye!" << std::endl;
                for (const auto& item : shoppingCart) 
                {
                    delete item;
                }
                break; // Exit the program

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // Clean up allocated memory
    /*for (const auto& item : shoppingCart) {
        delete item;
    }
    */
    return 0;
}