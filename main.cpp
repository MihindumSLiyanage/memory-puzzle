#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int cards[8][8];
int gridSize;

void opening(){
    int playGame;
    int grid;
   
    cout << "Press 1 to play, Press 0 to exit : ";
    cin >> playGame;
    //if the player wants to play the game
    if (playGame == 1){
        cout << endl;
        cout << "4 x 4 grid (Easy)" << endl;
        cout << "6 x 6 grid (Medium)" << endl;
        cout << "8 x 8 grid (Hard)" << endl << endl;
        cout << "Please enter grid row or coloumn size to proceed : ";
        cin  >> gridSize;
    }
   
    //if the player wants to exit
    else if(playGame == 0) {
        cout << "\tThank you";
    }
}

bool itemExist(int number){
    int count = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j< gridSize;j++){
            if(cards[i][j] ==  number){
                count ++;
            }
        }
    }
    if(count == 2){
        return true;
    }
    return false;
}

int getNumber(){
    int randomNumber = 0;
    int numSize = (gridSize*gridSize/2) + 1;
    while(true){
        randomNumber = rand()%numSize;
        bool exists = itemExist(randomNumber);
        if(randomNumber != 0 && !exists){
            break;
        }
    }
    return randomNumber;
}

void prepare() {
    int numArraySize = gridSize*gridSize/2;
    int numbers[numArraySize];
   
    for(int i = 1; i <= numArraySize; i++){
        numbers[i-1] = i;
    }
   
    for(int i = 0; i < gridSize*gridSize; i++){
        int row = i/gridSize;
        int coloumn = i%gridSize;
        cards[row][coloumn] = getNumber();
    }
}

void getInput(){
    int rowOne, coloumnOne, rowTwo, coloumnTwo;
    int numSize = gridSize*gridSize/2;
    char deviderStr[80] = "";
   
    for (int n=0; n<numSize; n++){
        while(true){
            cout<<"\nPlease insert the First card"<< endl;
            cout<<"----------------------------" << endl;
            cout<<"Row 1    : ";
            cin >> rowOne;
            cout<<"Column 1 : ";
            cin >> coloumnOne;
           
            cout << endl;
            if(rowOne <= gridSize && coloumnOne <= gridSize){
                break;
            }
            else {
                cout << "Please enter valid Row and Column numbers" << endl;
            }
        }
       
        while(true){
            cout<<"Please insert the Second card"<<endl;
            cout<<"----------------------------"<<endl;
            cout<<"Row 2     : ";
            cin >> rowTwo;
            cout<<"Column 2  : ";
            cin >> coloumnTwo;
            if(rowTwo <= gridSize && coloumnTwo <= gridSize){
                break;
            }
            else {
                cout << "Please enter valid Row and Column numbers" << endl;
            }
        }
       
        if(cards[rowOne][coloumnOne] == cards[rowTwo][coloumnTwo]){
            cout << endl << "---  Matched  ---" ;
        }
        else{
            cout << endl << " ---  Not Matched  ---" << endl ;
        }
       
        cout << endl;
       
        cout << "    ";
        deviderStr[0] = 0;
        for(int i = 1; i <= gridSize; i++){
            cout << i << "  ";
            strcat (deviderStr, "---");
        }
        cout << endl;
        cout << "---" << deviderStr ;
       
        for(int i = 0; i < gridSize; i++){
            cout << endl << i + 1 << " | ";
            for(int j = 0; j < gridSize; j++){
                if(i + 1 == rowOne && j +1 == coloumnOne){
                    cout << cards[i][j];
                    if(cards[i][j] < 10){
                        cout << " ";
                    }
                }
                else if(i + 1 == rowTwo && j +1 == coloumnTwo){
                    cout << cards[i][j];
                    if(cards[i][j] < 10){
                       cout << " ";
                    }
                }
                else{
                    cout << "* ";    
                }
                cout << " ";
            }
        }
        cout << endl;
        cout << endl;
       
        // for(int i = 0; i < gridSize; i++){
        //     for(int j = 0; j < gridSize; j++){
        //         cout << cards[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
}

int main() {
    opening();
    prepare();
    getInput();
}


