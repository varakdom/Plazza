/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** Chef
*/

#ifndef CHEF_HPP_
#define CHEF_HPP_
#include "commande.hpp"
#include "main.hpp"
#include "Ingredient.hpp"
#include <ctime>
#include <vector>


class Chef {

    public:
        Chef(int, char **, Ingredient *, std::vector<commande>, int *);
        ~Chef();
        void start_cooking(commande *);
        Ingredient *get_fridge();
        int get_multiplier();
        int get_free();
        commande *get_cooking();
    protected:
        int multuplier;
        commande *cooking;
        commande *waiting;
        Ingredient *fridge;
        std::vector<commande> commande_encour;
        int free;
        char **msg;
        int *nb_com_keep;
        pthread_t cook_thread;
    private:
};

#endif /* !CHEF_HPP_ */
