//
//  Bankomat.cpp
//  hw17
//
//  Created by Дима on 07.10.23.
//

#include "Bankomat.hpp"
#include <iostream>
#include <string>
using namespace std;


Bankomat:: Bankomat(){
    id = 0;
}
bool Bankomat:: checkNominal(int userMoney){
    for(int i = 0; i < 7; i++){
        if(userMoney == nominal[i]){
            return true;
        }
    }
           return false;
}

string Bankomat:: toString(int userMoney){
    string result = to_string(userMoney);
       return result;
}

void Bankomat:: inputCash(){
    int currentInput = 0;
    int userMoney = 0;
    int amount;
    cout << "enter your id: ";
    cin >> id;

    cout << "enter the amount of banknote: ";
    cin >> amount;
    int* deposit = new int[amount]; //создаём массив с ведёнными банкнотами
    
    
    for(int i = 0; i < amount; i++){
    cout << "enter the banknote: ";
    cin >> userMoney;

    
        if(checkNominal(userMoney)){
            deposit[i] = userMoney;
            currentSum += deposit[i]; //добавляем каждый элемент массива с введёнными банкнотами в общую сумму //банкомата
            currentInput += deposit[i]; //считаем, сколько мы вели
        }
    
        else{
            cout << "incorrect value" << endl;
            i--;
        }

      }
    cout << "you entered: " << currentInput << endl;
    
    delete[] deposit;
    }

void Bankomat:: getCash(){
    int sumToGet;
    cout << "enter the sum to get: ";
    cin >> sumToGet;
    if(sumToGet < minSum){
        cout << "you can't get so little sum :(" << endl;
    }
  
    if(sumToGet > currentSum || sumToGet > maxSum){
        cout << "you can't get so much money :(" << endl;
    }
    
    else if(sumToGet < currentSum && sumToGet > minSum && sumToGet < maxSum){
        cout << "take your money: " << sumToGet << endl;
        currentSum -= sumToGet;
    }
}

