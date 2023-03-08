/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** Ingredient
*/

#include "Ingredient.hpp"

#include<ctime>
#include <thread>

Ingredient::Ingredient(int _ing_respawn)
{
    this->_doe = 5;
    this->_eggplant = 5;
    this->_goat_cheese = 5;
    this->_gruyere = 5;
    this->_ham = 5;
    this->_mushrooms = 5;
    this->_steak = 5;
    this->_tomato = 5;
    this->_ing_respawn = _ing_respawn;
}

Ingredient::~Ingredient()
{

}

int Ingredient::get_ing(Ingredient_t t)
{
    switch (t) {
        case doe:
            return (this->_doe);
        case tomato:
            return (this->_tomato);
        case eggplant:
            return (this->_eggplant);
        case gruyere:
            return (this->_gruyere);
        case steak:
            return (this->_steak);
        case mushrooms:
            return (this->_mushrooms);
        case ham:
            return (this->_ham);
        case goat_cheese:
            return (this->_goat_cheese);
        default:
            break;
    }
    return (0);
}

void Ingredient::use(Ingredient_t t)
{
    switch (t) {
        case doe: {
            this->_doe--;
            std::thread th(&Ingredient::refill, this, t);
            }
            break;
        case tomato:{
            this->_tomato--;
            std::thread th(&Ingredient::refill, this, t);
            }
            break;
        case eggplant: {
            this->_eggplant--;
            std::thread th(&Ingredient::refill, this, t);
        }
            break;
        case gruyere: {
            this->_gruyere--;
            std::thread th(&Ingredient::refill, this, t);
        }
            break;
        case steak: {
            this->_steak--;
            std::thread th(&Ingredient::refill, this, t);
            }
            break;
        case mushrooms: {
            this->_mushrooms--;
            std::thread th(&Ingredient::refill, this, t);
        }
            break;
        case ham: {
            this->_ham--;
            std::thread th(&Ingredient::refill, this, t);
        }
            break;
        case goat_cheese: {
            this->_goat_cheese--;
            std::thread th(&Ingredient::refill, this, t);
        }
            break;
        default:
            break;
    }
}


void Ingredient::refill(Ingredient_t t)
{
    int delay = this->_ing_respawn;
    clock_t now = clock();
    
    delay *= CLOCKS_PER_SEC;

    while(clock() - now < delay);
    switch (t) {
        case doe:
            this->_doe++;
            break;
        case tomato:
            this->_tomato++;
            break;
        case eggplant:
            this->_eggplant++;
            break;
        case gruyere:
            this->_gruyere++;
            break;
        case steak:
            this->_steak++;
            break;
        case mushrooms:
            this->_mushrooms++;
            break;
        case ham:
            this->_ham++;
            break;
        case goat_cheese:
            this->_goat_cheese++;
            break;
        default:
            break;
    }
}