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

        //When the player character attacks it always does 10 damage, so no arguments in function call
        void doDMG() 
        {
            //We output different messages depending on if the goblin died or not
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
        //When the goblin does damage we override the function with this one
        //Argument is the damage value
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

//This function worked so well in assigment 3 that I'll use it again here

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
            std::cout << "This wasn't a number. Try again." << std::endl;
            //...Then clear the bad state of stream...
            std::cin.clear();
            // I can't seem to ignore[all] so i just ignore 1000 chars or untill \n
            // This is not perfect. I will research this further.
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
    // In the end we return the verified number as a double
    return verifiedInput;
};

int main() {
    //create timestamp. joinked from https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
    time_t current_time = time(NULL);
    //provide seed number for random generator
    srand((unsigned) time(NULL));
    int dmg = 0;
    int choice = 0;
    std::string cname;
    
    std::cout << "\nPlease input the name of your Character." << std::endl;
    std::cin >> cname;
    //This is our enemy. He is also a Character object
    Character c1;
    //In this case we construct a Character object with the chosen name as an argument
    Character c2(cname);
    
    while (c1.isAlive && c2.isAlive && choice != 3)
    {       
        std::cout << "\nIt is your turn. Would you like to: (1) Attack, (2) Skip turn or (3) Give up and quit the game?" << std::endl;
        std::cin >> choice;
        //Check the input stream, if it could successfully save input as int "choice"
        if (!std::cin)
        {
            //Only if the stream is bad will we use the function
            choice = inputVerification();
        }

        //Go into menu with our verified integer
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
            //We already verified the input but that only makes sure it's a number
            //This message is for when the user chooses a "wrong" number
            std::cout << "\nInvalid input. Please input a valid choice!" << std::endl;

            break;
        }

        //The goblin will attack irregardless whether we attack or skip our turn
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

    //Check to see if the goblin is dead
    if (!c1.isAlive)
    {
        std::cout << "\nYou have slain the goblin! Huzzah!" << "\nThank you for playing!" << std::endl;
    }
    //Check to see if player character is dead
    if (!c2.isAlive)
    {
        std::cout << "\nOh no! You were defeated by the goblin..." << "\nThank you for playing, better luck next time!" << std::endl;
    }

    return 0;
}