//
//  Polynomial_Shounak.cpp
//  Homework 7
//
//  Created by Shounak Rangwala on 10/22/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Polynomial_Shounak.h"

using namespace std;

Polynomial::Polynomial(){
    for(int i=0;i<10;i++){
        array[i]=0;
    }
}
void Polynomial::setArray(){
    int terms;
    cout<<"Enter the number of terms in the polynomial:";
    cin>> terms;
    int coef,expo;
    for(int i=0;i<terms;i++){
        cout<<"enter the coeffecient and the exponent:"<<endl;
        cin>>coef;
        cin>>expo;
        array[expo]=coef;
    }
}
Polynomial Polynomial::operator+(const Polynomial& input) {
    Polynomial result;

    for (int i = 0; i < 10; i++) {
        result.array[i] = input.array[i] + array[i];
    }

    return result;
}

Polynomial Polynomial::operator-(const Polynomial& input) {
    Polynomial result;

    for (int i = 0; i < 10; i++) {
        result.array[i] = array[i] - input.array[i];
    }
    return result;
}

void Polynomial::operator=(const Polynomial& input) {
    for (int i = 0; i < 10; i++) {
        array[i] = input.array[i];
    }
}

Polynomial Polynomial::operator*(const Polynomial& input) {
    Polynomial result;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j + k == i) {
                    result.array[i] += array[j] * input.array[k];
                }
            }
        }
    }
    return result;
}

void Polynomial::operator+=(const Polynomial& input) {
    for (int i = 0; i < 10; i++) {
        array[i] += input.array[i];
    }
}

void Polynomial::operator-=(const Polynomial& input) {
    for (int i = 0; i < 10; i++) {
        array[i] -= input.array[i];
    }
}

void Polynomial::operator*=(const Polynomial& input) {
    Polynomial result;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j + k == i) {
                    result.array[i] += array[j] * input.array[k];
                }
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        array[i] = result.array[i];
    }
}

ostream & operator<<(ostream & out, Polynomial &input) {
    
    bool empty = true;
    for (int i = 0; i < 10; i++) {
        if (input.array[i] != 0) empty = false;
    }
    if (empty == true) {
        out << 0;
        return out;
    }

    
    bool controller = true;
    for (int i = 0; i < 10; i++) {
        if (input.array[i] == 0) continue;
        else if (input.array[i] > 0) {
            if (i == 0) out << input.array[i];
            else if (i == 1) {
                if (controller == true) {
                    out << input.array[i] << "x";
                }
                else {
                    out << " + " << input.array[i] << "x";
                }
            }
            else {
                if (controller == true) {
                    out << input.array[i] << "x^" << i;
                }
                else {
                    out << " + " << input.array[i] << "x^" << i;
                }
            }
            controller = false;
        }else {
            if (i == 0) out << input.array[i];
            else if (i == 1) {
                if (controller == true) {
                    out << input.array[i] << "x";
                }
                else {
                    out << " - " << 0 - input.array[i] << "x";
                }
            }
            else {
                if (controller == true) {
                    out << input.array[i] << "x^" << i;
                }
                else {
                    out << " - " << 0 - input.array[i] << "x^" << i;
                }
            }
            controller = false;
        }
    }
    return out;
}
