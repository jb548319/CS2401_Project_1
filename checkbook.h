#ifndef CheckbookClass
#define CheckbookClass

#include<iostream>
#include<string>
#include "date.h"
#include "check.h"

class Checkbook{
    public:
        static const int SIZE = 200;

        Checkbook();

        // Accessors
        double get_balance() {return balance;}

        void load_from_file(std::istream& ins);
        void deposit(double depamount);
        void write_check(std::istream& ins);
        void show_all(std::ostream& outs);
        void remove(int rm_num);
        void number_sort();
        void payto_sort();
        void date_sort();
        void show(std::string payto_find);
        double average();
        void save(std::ostream& outs);     

    private:
        int used;
        Check checkbook[SIZE];
        double balance;
        int next_checknum;
};

#endif