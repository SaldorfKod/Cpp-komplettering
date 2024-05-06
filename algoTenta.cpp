//Uppgift 4 är inte klar men detta är vad jag hann med. 

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

class Konto
{
protected:
    std::string namn;
    int kontoNummer;
    int saldo;

public:
    Konto(const std::string &_namn, int _kontoNummer, int _saldo) : namn(_namn), kontoNummer(_kontoNummer), saldo(_saldo) {}

    void writeToFile()
    {
        // Set up outward filestream to the file created in main, append it.
        std::ofstream fs{"konton.txt", std::ios::app};
        // Stream all the info from the object to the file
        fs << "\n"
           << namn
           << "\n"
           << kontoNummer
           << "\n"
           << saldo
           << "\n";
    }
    int GetSaldo() { return saldo; }
    int GetKonto() { return kontoNummer; }
    std::string GetNamn() { return namn; }

    void skrivFil(int value){
        //funktion för att uppdatera fil
    }

    ~Konto() {}
};

int main()
{
    int choice = 0;
    std::string nyNamn;
    int nySaldo = 0;
    int nyKontoNummer = 0;

    int loggaKonto = 0;
    int choice2 = 0;
    int utintag = 0;
    // Skapa filen där vi sparar alla konton
    std::fstream myfs{"konton.txt", std::ios::out};
    // Write a string to the file, for easier debugging.
    myfs << "Konton:\n";

    while (choice != 3)
    {
        std::cout << "Menu:\n"
                     "1. Create new account.\n"
                     "2. Log in to account.\n"
                     "3. Exit\n"
                  << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Skriv in dina uppgifter:\n";
            std::cout << "Namn: ";
            std::cin >> nyNamn;
            std::cout << "Önskat kontonummer: ";
            std::cin >> nyKontoNummer;
            //Lägg till funktion för randomiserat kontonummer
            //Lägg till check att nummer inte är upptaget
            std::cout << "Saldo: ";
            std::cin >> nySaldo;
            // Skapa Konto objekt
            Konto k1(nyNamn, nyKontoNummer, nySaldo);
            // Call function to write all info to file
            std::cout << "Object created" << std::endl;
            k1.writeToFile();
            std::cout << "function called" << std::endl;
            // Delete the object. It will only persist in the file.
            // It should be deleted when it goes out of scope i.e. here.
            choice = 0;
        }
        if (choice == 2)
        {
            while (choice == 2)
            {
                std::cout << "Skriv in kontonummer för kontot du vill logga in på:\n";
                std::cin >> loggaKonto;
                // Sök i filen efter konto
                //"Hej [namn] ditt saldo är [saldo]."
                std::cout << "Vill du \n[1] Ta ut pengar eller\n[2] Sätta in pengar?" << std::endl;
                          std::cin >> choice2;
                if(choice2 == 1){
                    std::cout << "Hur mycket vill du ta ut" << std::endl;
                    std::cin >> utintag;
                    //check att input är integer
                    //nySaldo == getSaldo - utintag;
                    //setSaldo(nySaldo)
                    //skrivFil()         
                    }
            }     
        }
        
        if (choice == 3)
        {
            std::cout << "Good bye!" << std::endl;

            break; // Exit the program
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}