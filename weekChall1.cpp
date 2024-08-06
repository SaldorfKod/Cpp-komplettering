//program1: Weekly challenge
#include <iostream>
#include <string>
#include <cstdlib>

class Character {
    private:
        

    public:
        std::string name;
        int HP;
        bool isAlive;

        Character() : name("Filthy Goblin"), HP(100), isAlive(1) {}

        Character(const std::string name)
        : name(name), HP(100), isAlive(1) {}

        void doDMG() 
        {
            HP -= 10;
            if (HP > 0)
            {
                std::cout << "Goblin HP is now " << HP << std::endl;
            }
            
            if (HP < 1)
            {
                std::cout << "Goblin HP is now 0" << std::endl;
                isAlive = 0;
            }
            
        }
        void doDMG(int _DMG)
        {
            HP -= _DMG;
            if (HP > 0)
            {
                std::cout << "Your HP is now " << HP << std::endl;
            }
            
            if (HP < 1)
            {
                std::cout << "Your HP is now 0" << std::endl;
                isAlive = 0;
            }
        }
        /*~Student() {
            delete[] name;
        }
        */   
};

int main() {
    //create timestamp. joinked from https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
    time_t current_time = time(NULL);
    //provide seed number for random generator
    srand((unsigned) time(NULL));
    int dmg = 0;
    int choice = 0;
    std::string cname;

    //Create pointers to the HP values
    
    std::cout << "\nPlease input the name of your Character." << std::endl;
    std::cin >> cname;
    Character c1;
    Character c2(cname);
    
    while (c1.isAlive && c2.isAlive && choice != 3)
    {       
        std::cout << "\nIt is your turn. Would you like to: (1) Attack, (2) Skip turn or (3) Give up and quit the game?" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "\nYou attack the filthy goblin! You do 10 damage!" << std::endl;
            c1.doDMG();

            break;
        
        case 2:
            std::cout << "\nYou skip your turn! Brave or foolish?" << std::endl;

            break;

        case 3: 
            std::cout << "\nYou bravely run away! Good bye!" << std::endl;

            break;

        default:
            std::cout << "\nInvalid input. Please input a valid choice!" << std::endl;

            break;
        }
        if (choice == 2 || choice == 1)
        {
            std::cout << "\nThe filthy goblin strikes!" << std::endl;
            dmg = 5 + (rand() % 50);
            std::cout << "\nIt does " << dmg << "damage!" << std::endl;
            if (dmg > 40)
            {
                std::cout << "\nIt's a critical hit!" << std::endl;
            }
            
            c2.doDMG(dmg);
            choice = 0;
        }
        
        
    }

    if (!c1.isAlive)
    {
        std::cout << "\nYou have slain the goblin! Huzzah!" << "\nThank you for playing!" << std::endl;
    }
    
    if (!c2.isAlive)
    {
        std::cout << "\nOh no! You were defeated by the goblin..." << "\nThank you for playing, better luck next time!" << std::endl;
    }

    return 0;
}