#ifndef CheckbookClass
#define CheckbookClass

#include<iostream>
#include<string>
#include "date.h"
#include "check.h"

class Checkbook{
    public:
        static const int SIZE = 200;

        // Default Constructor
        Checkbook();

        // Accessors
        double get_balance()const {return balance;}

        // If user has file, the checks within are loaded into array
        void load_from_file(std::istream& ins);

        // Allows user to deposit money into their checkbook
        void deposit(double depamount);

        // Allows user to write check or import it from file
        void write_check(std::istream& ins);

        // Shows all checks in checkbook
        void show_all(std::ostream& outs)const;

        // Removes check with user prompted check number
        void remove(int rm_num);

        // Sorts checks off of check number
        void number_sort();

        // Sorts checks off of Payto
        void payto_sort();

        // Sorts checks based off of date
        void date_sort();

        // Shows all checks made to the same payto
        void show(std::string payto_find)const;

        // Returns average of all checks
        double average()const;

        // Saves all checks to original file
        void save(std::ostream& outs)const;     

    private:
        int used;
        Check checkbook[SIZE];
        double balance;
        int next_checknum;
};

#endif