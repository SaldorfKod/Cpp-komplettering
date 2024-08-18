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
    GroceryItem(const std::string &_name, double _price) : name(_name), price(_price) {}

    virtual double calculateTotalCost(int quantity)
    {
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
    FreshProduce(const std::string &_name, double _price, const std::string &_origin, double _weight) : GroceryItem(_name, _price), origin(_origin), weightInKilos(_weight) {}

    double calculateTotalCost(int quantity) override
    {
        return price * weightInKilos * quantity;
    }
};

class CannedGoods : public GroceryItem
{
private:
    int quantityInCans;

public:
    CannedGoods(const std::string &_name, double _price, int _quantity) : GroceryItem(_name, _price), quantityInCans(_quantity) {}

    double calculateTotalCost(int quantity) override
    {
        return price * quantityInCans * quantity;
    }
};

class BakeryItems : public GroceryItem
{
private:
    int quantityInPieces;

public:
    BakeryItems(const std::string &_name, double _price, int _quantity) : GroceryItem(_name, _price), quantityInPieces(_quantity) {}

    double calculateTotalCost(int quantity) override
    {
        return price * quantityInPieces * quantity;
    }
};

template <typename T>
double calculateTotalCost(const std::vector<T> &items, int quantity)
{
    double totalCost = 0;
    for (const auto &item : items)
    {
        totalCost += item->calculateTotalCost(quantity);
    }
    return totalCost;
}

// Function to handle input and verify it is compatible with desired data type
double inputVerification()
{
    bool choiceIsValid = 0;
    double verifiedInput = 0;
    double newRawInput = 0;
    // Go into loop and check if cin stream is good (the desired data type) or bad
    while (choiceIsValid != 1)
    {
        // We can access the iostream from main here
        if (!std::cin)
        {
            // If not good: output error message...
            std::cout << "Invalid input. Please input a number." << std::endl;
            //...Then clear the bad state of stream...
            std::cin.clear();
            // I can't seem to ignore[all] so i just ignore 1000 chars or untill \n
            // This is not perfect. I will research this further.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    // In the end we return the verified number as a double
    return verifiedInput;
};

int main()
{
    std::vector<GroceryItem *> shoppingCart;
    std::string origin;
    std::string itemName;
    double itemPrice = 0;
    int quantity = 0;
    int choice = 0;
    double discountPercent = 0;
    int quantityInCans = 0;
    int quantityInPieces = 0;
    double totalCost = 0;
    double discountedCost = 0;
    double weight = 0;

    while (choice != 5)
    {
        std::cout << "Menu:\n"
                     "1. Add Fresh Produce\n"
                     "2. Add Canned Goods\n"
                     "3. Add Bakery Items\n"
                     "4. Checkout\n"
                     "5. Exit\n"
                  << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choice;
        // Check the input stream, if it could successfully save input as int "choice"
        if (!std::cin)
        {
            // Only if the stream is bad will we use the function
            choice = inputVerification();
        }

        switch (choice)
        {
        case 1:
            std::cout << "Enter Fresh Produce details:\n";
            std::cout << "Name: ";
            std::cin >> itemName;
            std::cout << "Price per Kg: ";
            std::cin >> itemPrice;
            // Check the input stream, if it could successfully save input as int "itemPrice"
            if (!std::cin)
            {
                // Only if the stream is bad will we use the function
                itemPrice = inputVerification();
            }
            std::cout << "Weight in Kg: ";
            std::cin >> weight;
            if (!std::cin)
            {
                // Only if the stream is bad will we use the function
                weight = inputVerification();
            }
            std::cout << "Origin: ";
            std::cin >> origin;
            shoppingCart.push_back(new FreshProduce(itemName, itemPrice, origin, weight));
            std::cout << "Item(s) added to shopping cart";
            break;
        case 2:
            std::cout << "Enter Canned Goods details:\n";
            std::cout << "Name: ";
            std::cin >> itemName;
            std::cout << "Price per can: ";
            std::cin >> itemPrice;
            if (!std::cin)
            {
                // Only if the stream is bad will we use the function
                itemPrice = inputVerification();
            }
            std::cout << "Quantity in cans: ";
            std::cin >> quantityInCans;
            if (!std::cin)
            {
                // Only if the stream is bad will we use the function
                quantityInCans = inputVerification();
            }
            shoppingCart.push_back(new CannedGoods(itemName, itemPrice, quantityInCans));
            std::cout << "Item(s) added to shopping cart";
            break;
        case 3:
            std::cout << "Enter Bakery Items details:\n";
            std::cout << "Name: ";
            std::cin >> itemName;
            std::cout << "Price per piece: ";
            std::cin >> itemPrice;
            if (!std::cin)
            {
                // Only if the stream is bad will we use the function
                itemPrice = inputVerification();
            }
            std::cout << "Quantity in pieces: ";
            std::cin >> quantityInPieces;
            if (!std::cin)
            {
                // Only if the stream is bad will we use the function
                quantityInPieces = inputVerification();
            }
            shoppingCart.push_back(new BakeryItems(itemName, itemPrice, quantityInPieces));
            std::cout << "Item(s) added to shopping cart";
            break;
        case 4:
            totalCost = calculateTotalCost(shoppingCart, 1);
            std::cout << "Total cost is: $" << totalCost << "\n";
            std::cout << "Do you have a discount? (In percentage, 0 if none): ";
            std::cin >> discountPercent;
            discountedCost = totalCost - (totalCost * discountPercent / 100);
            std::cout << "Total cost after discount: $" << discountedCost << "\n";
            std::cout << "Good bye!" << std::endl;
            for (const auto &item : shoppingCart)
            {
                delete item;
            }
            choice = 5;
            break;
        case 5:
            std::cout << "Good bye!" << std::endl;
            for (const auto &item : shoppingCart)
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