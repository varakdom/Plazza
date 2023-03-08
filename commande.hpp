/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** commande
*/

#ifndef COMMANDE_HPP_
#define COMMANDE_HPP_

#include "main.hpp"
#include <iomanip>

class commande
{
    private:
    public:
        commande(PizzaSize, PizzaType, int);
        ~commande();
        const char *get_size();
        const char *get_type();
        int get_nb();
        void set_nb(int i);
    protected:
        PizzaSize _size;
        PizzaType _type;
        int _nb;
};


#endif /* !COMMANDE_HPP_ */
