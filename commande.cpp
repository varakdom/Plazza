/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** commande
*/

#include "commande.hpp"
#include <iostream>

commande::commande(PizzaSize size, PizzaType type, int nb)
{
    this->_nb = nb;
    this->_size = size;
    this->_type = type;
}

commande::~commande()
{

}

const char *commande::get_size()
{
    const char *type[] = {"S", "M", "L", "XL", "XXL"};
    PizzaSize num[]= {S, M, L, XL, XXL};

    for (int i = 0; i < 5; i++) 
        if (num[i] == this->_size)
            return (type[i]);
    return (0);
}

void commande::set_nb(int i)
{
    this->_nb = i;
}
const char *commande::get_type()
{
    const char *type[] = {"Regina", "Margarita", "Americana", "Fantasia"};
    PizzaType num[]= {Regina, Margarita, Americana, Fantasia};

    for (int i = 0; i < 4; i++) 
        if (num[i] == this->_type)
            return (type[i]);
    return (0);
}

int commande::get_nb()
{
    return (this->_nb);
}