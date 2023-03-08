/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** reception
*/

#include "reception.hpp"
#include <iostream>
#include <string>
#include <algorithm>

reception::reception(double multiplier, int nb_cook, int ing_respawn)
{
    this->multiplier = multiplier;
    this->nb_cook = nb_cook;
    this->ing_respawn = ing_respawn;
    this->error = 0;
    
}

reception::~reception()
{
}

int reception::get_cook()
{
    return (this->nb_cook);
}

int reception::get_respawn()
{
    return (this->ing_respawn);
}

int reception::get_multiplier()
{
    return (this->multiplier);
}

PizzaType  get_type(std::string str)
{
    const char *type[] = {"regina", "margarita", "americana", "fantasia"};
    PizzaType num[]= {Regina, Margarita, Americana, Fantasia};

    
    for (int i = 0; i < 4; i++) 
        if (str.compare(type[i]) == 0)
            return (num[i]);
    return (NONE);
}

PizzaSize  get_size(std::string str)
{
    const char *type[] = {"S", "M", "L", "XL", "XXL"};
    PizzaSize num[]= {S, M, L, XL, XXL};

    for (int i = 0; i < 5; i++) 
        if (str.compare(type[i]) == 0)
            return (num[i]);
    return (NONE2);
}

int reception::get_error()
{
    return (this->error);
}

commande reception::parse_commande(std::string str)
{
    size_t pos = 0;
    std::string token;
    PizzaSize _size;
    PizzaType _type;
    int nb = 0;
    
    for (int i = 0;(pos = str.find(" ")) != std::string::npos; i++) {
        token = str.substr(0, pos);
        if (i == 0)
            _type = get_type(token);
        else if (i == 1)
            _size = get_size(token);
        str.erase(0, pos + 1);
    }
    nb = std::atoi(str.erase(0, 1).c_str());
    commande _new = commande(_size, _type, nb);
    if (_type == NONE || _size == NONE2 || nb == 0) {
        std::cout << "ERROR IN COMMANDE" << std::endl;
        this->error = 1;
    }
    return (_new);
}


int it_is_list(commande m, std::vector<commande> t)
{
    int y = t.size();

    for (int i = 0; i < y; i++) {
        if (t[i].get_type() == m.get_type()) {
            return (1);
        }
    }
    return (0);
}

std::vector<commande> tree_commande(std::vector<commande> *t, Kitchen p, int max_cook)
{
    std::vector<commande> tmp;
    std::vector<commande> comm_enncour = p.get_all_com();
    int nb_com = comm_enncour.size();

    for (int i = nb_com, j = 0;!((*t).empty()) && i < max_cook; i++, j++) {
        if (it_is_list((*t)[j], comm_enncour) == 0 && (it_is_list((*t)[j], tmp) == 0)) {
            (*t)[j].set_nb((*t)[j].get_nb() - 1);
            tmp.push_back((*t)[j]);
            if ((*t)[j].get_nb() == 0)
                (*t).erase((*t).begin() + j);
        }
    }
    return (tmp);
}


void reception::smart_Cook(std::vector<commande> t, int i)
{
    std::vector<commande> tmp;
    int k = 0;

    if (this->kitchen.empty()) {
        this->kitchen.emplace_back(Kitchen(this->nb_cook, this->multiplier, this->ing_respawn));
        for (int j = 0;!(t.empty()) && j < i && k < this->kitchen.size(); k++) {
            tmp = tree_commande(&t, this->kitchen[k], (this->nb_cook * 2));
            this->kitchen[k].start_cooking(tmp);
        }
        if (!t.empty()){
            this->kitchen.emplace_back(Kitchen(this->nb_cook, this->multiplier, this->ing_respawn));
            for (; !(t.empty());k++) {
                tmp = tree_commande(&t, this->kitchen[k], (this->nb_cook * 2));
                this->kitchen[k].start_cooking(tmp);
                this->kitchen.emplace_back(Kitchen(this->nb_cook, this->multiplier, this->ing_respawn));
            }
        }
    } else {
        for (int j = 0;!(t.empty()) && j < i && k < this->kitchen.size(); k++) {
            tmp = tree_commande(&t, this->kitchen[k], (this->nb_cook * 2));
            this->kitchen[k].start_cooking(tmp);
        }
        if (!t.empty()){
            this->kitchen.emplace_back(Kitchen(this->nb_cook, this->multiplier, this->ing_respawn));
            for (; !(t.empty());k++) {
                tmp = tree_commande(&t, this->kitchen[k], (this->nb_cook * 2));
                this->kitchen[k].start_cooking(tmp);
                this->kitchen.emplace_back(Kitchen(this->nb_cook, this->multiplier, this->ing_respawn));
            }
        }
    }
}