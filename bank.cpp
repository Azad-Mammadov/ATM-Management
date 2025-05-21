#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>

class bank
{
    public:
    void menu();
    void bank_management();
    void atm_management();  
};


   void bank::menu()
   {
    p:
    system("cls");
    char ch;
    std::string pin, pass, email;
    int choice;
    std::cout <<"\n\n\t\t\tControl Panel"<< std::endl;
    std::cout <<"\n\n 1. Bank Management";
    std::cout <<"\n 2. ATM Management";
    std::cout <<"\n 3. Exit";
    std::cout <<"\n\nEnter Your Choise : ";
    std::cin >> choice;
    switch (choice)
    {
        case 1:
            std::cout <<"\n\n\t\t\tLogin Account";
            std::cout <<"\n\n E-Mail : ";
            std::cin >> email;
            std::cout <<"\n\n\t\t Pin Code : "; 
            for(int i=1; i<=6; i++)
            {
                ch = getch();
                pin += ch;
                std::cout << "*";
            }
            std::cout <<"\n\n Password : ";
            for(int i=1; i<=6; i++)
            {
                ch = getch();
                pass += ch;
                std::cout << "*";
            }
            if(email == "azad.mamedov777@gmail.com" && pin == "199777" && pass == "199666" )
            {
                bank_management();  
            }
            else
            {
            std::cout << "\n\n Your Email, Pin & Password is Wrong ...";
            }
            break;
        case 2:
            atm_management();
            break;
        case 3:
            exit(0);
        default:
            std::cout <<"\n\n Invalid Value...Please Try Again...";
        }
        getch();
        goto p;
    }
    void bank::bank_management()
    {
        p:
        system("cls");
        int choice;
        std::cout << "\n\n\t\t\tATM Management System";
        std::cout << "\n\n 1. New User";
        std::cout << "\n 2. Already User";
        std::cout << "\n 3. Deposit Option";
        std::cout << "\n 4. Withdraw Option";
        std::cout << "\n 5. Transfer Option";
        std::cout << "\n 6. Payment Option";
        std::cout << "\n 7. Search User Record";
        std::cout << "\n 8. Edit User Record";
        std::cout << "\n 9. Delete User Record";
        std::cout << "\n 10. Show All Records";
        std::cout << "\n 11. Payment All Records";
        std::cout << "\n 12. Go Back";
        std::cout << "\n\n Enter Your Choice : ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            // user login & check balance
            break;
        case 2:
            // withdraw amount
            break;
        case 3:
            // account detailes
            break;
        case 4:
            break;
        case 5:
            // transfer amount
            break; 
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;     
        case 11:
            break;
        case 12:
            menu();               
        default:
            std::cout << "\n\n Invalid Value...Please Try Again...";
        }
        getch();
        goto p;
    }

    void bank::atm_management()
    {

    }





main ()
{

    bank obj;
    obj.menu();

    return 0;
}