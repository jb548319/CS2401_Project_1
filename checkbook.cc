#include<iostream>
#include<string>
#include "checkbook.h"
using namespace std;

Checkbook::Checkbook (){
    used = 0;
    balance = 0.00;
    next_checknum = 0;
}

void Checkbook::load_from_file(istream& ins){
    Check c;

    ins >> balance;
    ins >> next_checknum;
    while (!ins.eof()){
        c.write_check(ins);

        checkbook[used] = c;
        used++;
    }    
}

void Checkbook::deposit(double depamount){
    balance += depamount;
}

//
void Checkbook::write_check(istream& ins){
    Check c;
    if (&ins == &cin){
        c.set_check_num (next_checknum);
        c.write_check(ins);
    }
    else{
        c.write_check(ins);
    }
    
    checkbook[used] = c;

    balance -= c.get_amount();
    next_checknum++;
    used++;
}

//
void Checkbook::show_all(ostream& outs){
    for (int i = 0; i < used; i++){
        checkbook[i].output(outs);
    }
}

void Checkbook::remove(int rm_num){

}

void Checkbook::number_sort(){

}
void Checkbook::payto_sort(){

}

void Checkbook::date_sort(){
    
}

void Checkbook::show(string payto_find){

}

void Checkbook::save(ostream& outs){

}
