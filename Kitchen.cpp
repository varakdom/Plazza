/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include <iostream>

Kitchen::Kitchen(int nb_chef, int multiplier, int ing_respawn)
{
    this->nb_chef = nb_chef;
    this->multiplier = multiplier;
    this->ing_respawn = ing_respawn;
    this->fridge = new Ingredient(ing_respawn);
    this->nb_com_keep = 0;
}

Kitchen::~Kitchen()
{
    
}

std::vector<commande> Kitchen::get_all_com()
{
    return (this->commande_encour);
}

int Kitchen::get_nb_com_keep()
{
    return (this->nb_com_keep);
}

void Kitchen::start_cooking(std::vector<commande> t)
{
    int nb_com = t.size();
    int a = 0;
    int y = 0;
    this->nb_com_keep += nb_com;

    if (this->chef.empty()) {
        for (int i = 0; i < nb_com; i++) {
            if (i % 2 == 0)
                this->chef.emplace_back(Chef(this->multiplier, &this->msg, this->fridge, this->commande_encour, &this->nb_com_keep));
        }
        for (int z = 0; z < nb_com; z++) {
            if (z + 1 < nb_com) {
                this->chef[a].start_cooking(&t[z]);
                this->chef[a].start_cooking(&t[z + 1]);
                this->commande_encour.emplace_back(t[z]);
                this->commande_encour.emplace_back(t[z + 1]);
                a++;
                z++;
            } else {
                this->chef[a].start_cooking(&t[z]);
                this->commande_encour.emplace_back(t[z]);
                a++;
            }
        }
    } else {
        for (; y < nb_com; y++) {
            if (this->chef[a].get_free() == 1){
                this->chef[a].start_cooking(&t[y]);
                this->commande_encour.emplace_back(t[y]);
                a++;
            }
            if (this->chef[a].get_free() == 0) {
                this->chef[a].start_cooking(&t[y]);
                this->chef[a].start_cooking(&t[y + 1]);
                this->commande_encour.emplace_back(t[y]);
                this->commande_encour.emplace_back(t[y + 1]);
                y++;
                a++;
            }
        }

        if (y < nb_com) {
            for (int i = 0; i < nb_com; i++) {
                if (i % 2 == 0)
                    this->chef.emplace_back(Chef(this->multiplier, &this->msg, this->fridge, this->commande_encour, &this->nb_com_keep));
            }
        }

        for (; y < nb_com; y++) {
            if (y + 1 < nb_com) {
                this->chef[a].start_cooking(&t[y]);
                this->chef[a].start_cooking(&t[y + 1]);
                this->commande_encour.emplace_back(t[y]);
                this->commande_encour.emplace_back(t[y + 1]);
                a++;
                y++;
            } else {
                this->chef[a].start_cooking(&t[y]);
                this->commande_encour.emplace_back(t[y]);
                a++;
            }
        }
    }
}