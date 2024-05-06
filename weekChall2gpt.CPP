#include <iostream>
#include <vector>
#include <string>

// Base class
class GroceryItem {
protected:
    std::string name;
    double price;

public:
    GroceryItem(const std::string& _name, double _price) : name(_name), price(_price) {}

    virtual double calculateTotalCost(int quantity) {
        return price * quantity;
    }
};

// Derived class for fresh produce
class FreshProduce : public GroceryItem {
private:
    std::string origin;
    double weightInKg;

public:
    FreshProduce(const std::string& _name, double _price, const std::string& _origin, double _weight)
        : GroceryItem(_name, _price), origin(_origin), weightInKg(_weight) {}

    double calculateTotalCost(int quantity) override {
        return price * weightInKg * quantity;
    }
};

// Derived class for canned goods
class CannedGoods : public GroceryItem {
private:
    int quantityInCans;

public:
    CannedGoods(const std::string& _name, double _price, int _quantity)
        : GroceryItem(_name, _price), quantityInCans(_quantity) {}

    double calculateTotalCost(int quantity) override {
        return price * quantityInCans * quantity;
    }
};

// Derived class for bakery items
class BakeryItems : public GroceryItem {
private:
    int quantityInPieces;

public:
    BakeryItems(const std::string& _name, double _price, int _quantity)
        : GroceryItem(_name, _price), quantityInPieces(_quantity) {}

    double calculateTotalCost(int quantity) override {
        return price * quantityInPieces * quantity;
    }
};

// Template function to calculate total cost of a collection of grocery items
template <typename T>
double calculateTotalCost(const std::vector<T>& items, int quantity) {
    double totalCost = 0;
    for (const auto& item : items) {
        totalCost += item.calculateTotalCost(quantity);
    }
    return totalCost;
}

int main() {
    std::vector<GroceryItem*> shoppingCart;

    while (true) {
        std::cout << "Menu:\n"
                     "1. Add Fresh Produce\n"
                     "2. Add Canned Goods\n"
                     "3. Add Bakery Items\n"
                     "4. Checkout\n"
                     "5. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            break; // Exit the program
        }

        std::string itemName;
        double itemPrice;
        int quantity;

        switch (choice) {
            case 1:
                std::string origin;
                double weight;
                std::cout << "Enter Fresh Produce details:\n";
                std::cout << "Name: ";
                std::cin >> itemName;
                std::cout << "Price per Kg: ";
                std::cin >> itemPrice;
                std::cout << "Origin: ";
                std::cin >> origin;
                std::cout << "Weight in Kg: ";
                std::cin >> weight;
                shoppingCart.push_back(new FreshProduce(itemName, itemPrice, origin, weight));
                break;
            case 2:
                int quantityInCans;
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
                int quantityInPieces;
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
                int discountPercent;
                std::cout << "Enter discount code (in percentage, 0 if none): ";
                std::cin >> discountPercent;
                double totalCost = calculateTotalCost(shoppingCart, 1);
                double discountedCost = totalCost - (totalCost * discountPercent / 100);
                std::cout << "Total cost after discount: $" << discountedCost << "\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // Clean up allocated memory
    for (const auto& item : shoppingCart) {
        delete item;
    }

    return 0;
}
