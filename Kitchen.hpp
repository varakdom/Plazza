/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_
#include <vector>
#include "Ingredient.hpp"
#include "Chef.hpp"
#include <thread>
#include <mutex>


class Kitchen {
    public:
        Kitchen(int nb_chef, int multiplier, int ing_respawn);
        ~Kitchen();
        void start_cooking(std::vector<commande> t);
        int get_nb_com_keep();
        std::vector<commande> get_all_com();
    protected:
        int nb_chef;
        int nb_com_keep;
        int multiplier;
        int ing_respawn;
        char *msg;
        std::vector<Chef> chef;
        Ingredient *fridge;
        std::vector<commande> commande_encour;
    private:
};

#endif /* !KITCHEN_HPP_ */
