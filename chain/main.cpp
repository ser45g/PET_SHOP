#include <iostream>
#include "mathimaticle_class.h"

using namespace std;

int main()
{
    unary_operation<sin_unary_operation_chain, cos_unary_operation_chain, tan_unary_operation_chain, ctan_unary_operation_chain, log_unary_operation_chain> operation;

    operation.push_back(new log_unary_operation_chain(2));
    operation.push_back(new log_unary_operation_chain(10));

    char choice;
    do
    {
        //
        cout << "Enter unary operation, please >";
        string _operation;
        cin >> _operation;

        auto first_breacket = _operation.begin() + _operation.find('(');
        auto second_breacket = _operation.begin() + _operation.find(')');

        string _unary_operation(_operation.begin(),first_breacket);
        double _value = stod(string(first_breacket+1,second_breacket));

        cout << _operation << " = " << operation.calculate(_unary_operation,_value) << endl;

        //Programm menue
        while(true)
        {
            cout << endl << "Do you want to leave the programm? [Y/N]:";
            cin >> choice;
            if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                break;
            cout << "Unrecognized ansver! Try agan please!";
        }
    }while(choice == 'n' || choice == 'N');
    return 0;
}