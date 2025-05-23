#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <cstdlib>

class bank
{
    private:
        int pin;
        float balance;
        std::string id, pass, name, fname, address, phone;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void already_user();
        void deposit();
        void withdraw();
        void transfer();
        void payment();
};


   void bank::menu()
   {
    p:
    system("cls");
    char ch;
    std::string input_pin, pass, email;
    int choice;
    std::cout <<"\n\n\t\t\tControl Panel"<< std::endl;
    std::cout <<"\n\n 1. Bank Management";
    std::cout <<"\n 2. ATM Management";
    std::cout <<"\n 3. Exit";
    std::cout <<"\n\nEnter Your Choice : ";
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
                input_pin += ch;
                std::cout << "*";
            }
            std::cout <<"\n\n Password : ";
            for(int i=1; i<=6; i++)
            {
                ch = getch();
                pass += ch;
                std::cout << "*";
            }
            if(email == "azad.mamedov777@gmail.com" && input_pin == "199777" && pass == "199666" )
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
            new_user();
            // user login & check balance
            break;
        case 2:
            already_user();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break; 
        case 6:
            payment();
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
        p:
        system("cls");
        int choice;
        std::cout << "\n\n\t\t\tATM Management System";
        std::cout << "\n\n 1. User Login & Check Balance";
        std::cout << "\n 2. Withdraw Amount";
        std::cout << "\n 3. Account Detailes";
        std::cout << "\n 4. Go Back";
        std::cout << "\n\n Enter Your Choice : ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
        break;
        case 3:
            break;
        case 4:
            menu();
        default:
            std::cout << "\n\n Invalid Value...Please Try Again...";
        }
        getch();
        goto p;
    }

    void bank::new_user()
    {
        p:
        system("cls");
        std::fstream file;
        int p;
        float b;
        std::string n, f, pa, a, ph, i;
        std::cout << "\n\n\t\t\tAdd New User";
        std::cout << "\n\n User ID : ";
        std::cin >> id;
        std::cout << "\n\n\t\tName : ";
        std::cin >> name;
        std::cout << "\n\n Father Name : ";
        std::cin >> fname;
        std::cout << "\n\n\t\tAddress : ";
        std::cin >> address;
        std::cout << "\n\n Pin Code (5 digit) : ";
        std::cin >> pin;
        std::cout << "\n\n\t\tPassword : ";
        std::cin >> pass;
        std::cout << "\n\n Phone No. :";
        std::cin >> phone;
        std::cout << "\n\n\t\tCurrent Balance : ";
        std::cin >> balance;
        file.open("bank.txt", std::ios::in);
        if(!file)
        {
            file.open("bank.txt", std::ios::app | std::ios::out);
            file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            file.close();
        }
        else
        {
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
            while(!file.eof())
            {
                if(i == id)
                {
                    std::cout << "\n\n User ID Already Exist...";
                    getch();
                    goto p;
                }
                file >> i >> n >> f >> a >> p >> pa >> ph >> b;
            }
            file.close();
            file.open("bank.txt", std::ios::app | std::ios::out);
            file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            file.close();
        }
        std::cout << "\n\n New Account Created Successfully...";
    }

    void bank::already_user()
{
    system("cls");
     std::fstream file;
    std::string t_id;
    int found=0;
    std::cout << "\n\n\t\t\tAlready User Account";
    file.open("bank.txt", std::ios::in);
    if(!file)
    {
        std::cout << "\n\n File Opening Error...";
    }
    else
    {
        std::cout << "\n\n User ID : ";
        std::cin >> t_id;
        file>> id >> name >> fname >> address >> pin >> pass >> phone >> balance;

        while(!file.eof())
        {
            if(t_id == id)
            {
                system("cls");
                std::cout << "\n\n\t\t\t Already User Account";
                std::cout << "\n\n User ID: " <<id<< "   Pin Code: " << pin <<"   Password: " << pass;
                found++;
            }
            file>> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if(found == 0)
        std::cout << "\n\n User ID Can't Found...";
    }
}

    void bank::deposit()
    {
        std::fstream file, file1;
        std::string t_id;
        float dep;
        int found=0;
        system("cls");
        std::cout <<"\n\n\t\t\tDeposit Amount Option";
        file.open("bank.txt", std::ios::in);
        if(!file)
        {
            std::cout << "\n\n File Opening Error...";
        }
        else
        {
            std::cout << "\n\n User ID : ";
            std::cin >> t_id;
            file1.open("bank1.txt", std::ios::app | std::ios::out);
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while(!file.eof())
            {
                if(t_id == id)
                {
                    std::cout <<"\n\n Amount For Deposit : ";
                    std::cin >> dep;
                    balance += dep;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    found++;
                    std::cout <<"\n\n\t\t\tYour Amount " <<dep << " Successfully Deposit...";
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
            if(found == 0)
            std::cout << "\n\n User ID Can't Found...";
        }
    }

        void bank::withdraw()
    {
        std::fstream file, file1;
        std::string t_id;
        float with;
        int found=0;
        system("cls");
        std::cout <<"\n\n\t\t\tWithraw Amount Option";
        file.open("bank.txt", std::ios::in);
        if(!file)
        {
            std::cout << "\n\n File Opening Error...";
        }
        else
        {
            std::cout << "\n\n User ID : ";
            std::cin >> t_id;
            file1.open("bank1.txt", std::ios::app | std::ios::out);
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while(!file.eof())
            {
                if(t_id == id)
                {
                    std::cout <<"\n\n Amount For Withdraw : ";
                    std::cin >> with;
                    if(with <= balance)
                    {
                        balance -= with;
                        file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                        found++;
                        std::cout <<"\n\n\t\t\tYour Amount " <<with << " Successfully Withdraw...";
                    }
                    else
                    {
                        std::cout << "\n\n\t\t\tYour Balance"<< balance << " is Less...";
                    }
                    found++;
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
            if(found == 0)
            std::cout << "\n\n User ID Can't Found...";
        }
    }

    void bank::transfer()
    {
        std::fstream file, file1;
        system("cls");
        std::string s_id, r_id;
        int found=0;
        float amount;
        std::cout << "\n\n\t\t\tPayment Tranfer Option";
        file.open("bank.txt", std::ios::in);
        if(!file)
        {
            std::cout << "\n\n File Opening Error...";
        }
        else
        {
            std::cout << "\n\n Sender User ID For Transaction : ";
            std::cin >> s_id;
            std::cout << "\n\n Receiver User ID For Transaction : ";
            std::cin >> r_id;
            std::cout << "\n\n Enter Transfer Amount : ";
            std::cin >> amount;
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while(!file.eof())
            {
                if(s_id == id && amount <= balance)
                found++; // As
                else if(r_id == id)
                found++;
                file>> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            if(found == 2)
            {
                file.open("bank.txt", std::ios::in);
                file1.open("bank1.txt", std::ios::app | std::ios::out);
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
                while(!file.eof())
                {
                    if(s_id == id)
                    {
                        balance -= amount; 
                        file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";                        
                    }
                    else if (r_id == id)
                    {
                        balance += amount;
                        file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    }
                    else
                    {
                        file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    }
                    file>> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt", "bank.txt");
                std::cout << "\n\n\t\t\tTransaction Successfully...";
            }
            else
            {
                std::cout << "\n\n\t\t\tBoth Transaction User ID's & Balance Invalid...";    
            }
        }
    }    

    void bank::payment()
    {
        system("cls");
        std::fstream file;
        int found=0;
        float amount;
        std::string t_id;
        std::cout << "\n\n\t\t\tBills Payment Option";
        file.open("bank.txt", std::ios::in);
        if(!file)
        {
            std::cout << "\n\n File Opening Error...";
        }
        else
        {
            std::cout << "\n\n User ID : ";
            std::cin >> t_id;
            std::cout << "\n\n Bill Name : ";
            std::string b_name;
            std::cout << "\n\n Bill Amount : ";
            std::cin >> amount;
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while(!file.eof())
            {
                if(t_id == id && amount <= balance)
                found++;
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }

        }
    }

int main ()
{

    bank obj;
    obj.menu();

    return 0;
}