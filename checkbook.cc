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
    for (int i = 0; i < (next_checknum - 1); i++){
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
    int i, j, smallSp;
    Check tmp;

    for (i = 0; i < used - 1; i++){
        smallSp = i;

        for (j = i + 1; j < used; j++){
            if (checkbook[j].get_num() < checkbook[smallSp].get_num()){
                smallSp = j;
            }
        }

        tmp = checkbook[i];
        checkbook[i] = checkbook[smallSp];
        checkbook[smallSp] = tmp;
    }
}

void Checkbook::payto_sort(){
    int i, j, smallSp;
    Check tmp;

    for (i = 0; i < used - 1; i++){
        smallSp = i;

        for (j = i + 1; j < used; j++){
            if (checkbook[j].get_payto() < checkbook[smallSp].get_payto()){
                smallSp = j;
            }
        }

        tmp = checkbook[i];
        checkbook[i] = checkbook[smallSp];
        checkbook[smallSp] = tmp;
    }
}

void Checkbook::date_sort(){
    int i, j, smallSp;
    Check tmp;

    for (i = 0; i < used - 1; i++){
        smallSp = i;

        for (j = i + 1; j < used; j++){
            if (checkbook[j].get_date() < checkbook[smallSp].get_date()){
                smallSp = j;
            }
        }

        tmp = checkbook[i];
        checkbook[i] = checkbook[smallSp];
        checkbook[smallSp] = tmp;
    }
}

void Checkbook::show(string payto_find){
    for (int i = 0; i < used; i++){
        if (checkbook[i].get_payto() == payto_find){
            checkbook[i].output(cout);
        }
    }
}

void Checkbook::save(ostream& outs){
    outs << balance << endl << endl;
    outs << next_checknum << endl << endl;

    for (int i = 0; i < used; i++){
        checkbook[i].output(outs);
    }

}

double Checkbook::average(){
    double sum = 0.00;
    double avg;

    for (int i = 0; i < used; i++){
        sum += checkbook[i].get_amount();
    } 

    avg = sum / double(used);
    return avg;
}
