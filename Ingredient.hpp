/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** Ingredient
*/

#ifndef INGREDIENT_HPP_
#define INGREDIENT_HPP_
#include "main.hpp"

class Ingredient {
    public:
        Ingredient(int);
        ~Ingredient();
        void refill(Ingredient_t);
        void use(Ingredient_t);
        int get_ing(Ingredient_t);
    protected:
        int _doe;
        int _tomato;
        int _gruyere;
        int _ham;
        int _mushrooms;
        int _steak;
        int _eggplant;
        int _goat_cheese;
        int _ing_respawn;
    private:
};

#endif /* !INGREDIENT_HPP_ */
