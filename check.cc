/*************************************************************************
    This is the implementation file for the Check class. For more 
		information about the class see check.h.
    Students are expected to implement some of the functions shown 
		below.
	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/
#include "check.h"
#include <string>
using namespace std;

Check::Check(Date d, string p, int num,double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
}

// Input and output functions
void Check::write_check(std::istream& ins){
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	payto.  */

	if (&ins == &cin){
		cout << "Enter date: ";
		ins >> date;

		cout << "Enter who is being payed: ";
		while (ins.peek() == '\n' || ins.peek() == '\r'){
			ins.ignore();
		}
		getline(ins, payto);

		cout << "Enter check amount: $";
		ins >> amount;
    }
    else{
        ins >> checknum;
		ins >> date;

		while (ins.peek() == '\n' || ins.peek() == '\r'){
			ins.ignore();
		}
		getline(ins, payto);

		ins >> amount;

		// this ignores the \n or \r between each check or eof
		while (ins.peek() == '\n' || ins.peek() == '\r'){ 
			ins.ignore();
		}
    }
}

void Check::output(std::ostream& outs)const{
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/

	if (&outs == &cout){
        outs << "Check number: " << checknum << endl;
		outs << "Date: " << date << endl;
		outs << "Payed to: " << payto << endl;
		outs << "Amount: $" << amount << endl;

		outs << endl;
    }
    else{
        outs << checknum << endl << endl;
		outs << date << endl << endl;
		outs << payto << endl << endl;
		outs << amount << endl << endl;
    }
}

ostream& operator << (ostream& outs, const Check& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Check& c){
	c.write_check(ins);
	return ins;
}