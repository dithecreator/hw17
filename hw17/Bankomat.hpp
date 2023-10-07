//
//  Bankomat.hpp
//  hw17
//
//  Created by Дима on 07.10.23.
//

#ifndef Bankomat_hpp
#define Bankomat_hpp
#include <stdio.h>

class Bankomat{
    int id;
    int currentSum = 100000;
    int nominal[7] = {10, 20, 50, 100, 200, 500, 1000};
    int minSum = 10;
    int maxSum = 10000;
    public:
    Bankomat();
   void inputCash(); //ложим деньги
    void getCash(); //снимаем деньги
    bool checkNominal(int userMoney); //проверяем номинал
};

#endif /* Bankomat_hpp */
