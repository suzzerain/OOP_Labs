#include "application.h"
#include "matrix.h"
#include "complex.h"
#include <iostream>

using namespace std;



int Tapplication::exec() {

    TMatrix matrix;
    int ch;

    while(true){

        ch = menu();

        switch(ch){

           case 1: {

              matrix.inputMatrix();
              break;
           }
           case 2: {

              cout << "Determinant: " << matrix.calculateDet() << endl;
              break;
            }
            case 3: {

              matrix.transposedMatrix();
              cout << "Matrix is transposed\n";
              break;
            }
            case 4: {

               cout << "Rank: " << matrix.calculateRank() << endl;
               break;
            }
            case 5: {

               cout << matrix << endl;
               break;
            }
            case 0: {

                exit(0);
            }
            default: {

               cout << "Error\n";
               break;
            }
        }
    }
}



int Tapplication::menu(){
    int ch;
    cout << "---------------------------------------" << endl;
    cout << "|1 - Enter matrix" << endl;
    cout << "|2 - Determinant calculation" << endl;
    cout << "|3 - Transposed matrix" << endl;
    cout << "|4 - Rank calculation" << endl;
    cout << "|5 - Print matrix" << endl;
    cout << "|0 - Exit (Enter 0 twice in a row)" << endl << "> ";
    cin >> ch;
    cout << "---------------------------------------" << endl;
    return ch;
}
