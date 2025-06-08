export module bank;

//import std;
import <iostream>;
import <string>;
import <conio.h>;
import <stdio.h>;
import <fstream>;
import <windows.h>;
import <cstdlib>;


//export void introduction();
export class bank
{
    private:
        float balance;
        std::string id, pass, name, fname, address, phone, pin;
    public:
        bank() = default;
        static void introduction();
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void already_user();
        void deposit();
        void withdraw();
        void transfer();
        void payment();
        void search();
        void edit();
        void del();
        void show_records();
        void show_payment();
        void user_balance();
        void withdraw_atm();
        void check_detail();
};


export void bank::introduction();