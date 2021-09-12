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

}

void Checkbook::write_check(istream& ins){

}

void Checkbook::show_all(ostream& outs){

}

void Checkbook::remove(int rmnum){

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

void Checkbook::output(ostream& outs){
    for (int i = 0; i < used; i++){
        cout << "yup" << endl;
        checkbook[i].output(outs);
    }
}
