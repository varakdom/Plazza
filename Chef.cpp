/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** Chef
*/

#include "Chef.hpp"
#include <thread>
#include <iomanip>
#include <iostream>

Chef::Chef(int multiplier, char **msg, Ingredient *_fridge, std::vector<commande> t, int *m) {
    this->multuplier = multiplier;
    this->cooking = nullptr;
    this->waiting = nullptr;
    this->msg = msg;
    this->fridge = _fridge;
    this->free = 1;
    this->commande_encour = t;
    this->nb_com_keep = m;
}

Chef::~Chef()
{

}

Ingredient *Chef::get_fridge()
{
    return (this->fridge);
}

int Chef::get_multiplier()
{
    return (this->multuplier);
}

int Chef::get_free()
{
    return (this->free);
}

void cook_margarita(int multi, Ingredient *fridge)
{
    int delay = multi;
    clock_t now;
    while (fridge->get_ing(tomato) <= 0 || fridge->get_ing(doe) <= 0 || fridge->get_ing(gruyere) <= 0);

    std::thread th(&Ingredient::use, fridge, doe);
    std::thread th2(&Ingredient::use, fridge, tomato);
    std::thread th3(&Ingredient::use, fridge, gruyere);
    delay *= CLOCKS_PER_SEC;
    now = clock();
    while(clock() - now < delay);
}

void  cook_regina(int multi, Ingredient *fridge)
{
    int delay = multi;
    clock_t now;
    while (fridge->get_ing(tomato) <= 0 || fridge->get_ing(doe) <= 0 || fridge->get_ing(gruyere) <= 0 ||
    fridge->get_ing(ham) <= 0 || fridge->get_ing(mushrooms) <= 0);

    std::thread th(&Ingredient::use, fridge, doe);
    std::thread th2(&Ingredient::use, fridge, tomato);
    std::thread th3(&Ingredient::use, fridge, gruyere);
    std::thread th4(&Ingredient::use, fridge, ham);
    std::thread th5(&Ingredient::use, fridge, mushrooms);
    delay =(delay * 2) * CLOCKS_PER_SEC;    now = clock();
    while(clock() - now < delay);
}

void cook_americana(int multi, Ingredient *fridge)
{
    int delay = multi;
    clock_t now;
    while (fridge->get_ing(tomato) <= 0 || fridge->get_ing(doe) <= 0 || fridge->get_ing(gruyere) <= 0 
    || fridge->get_ing(steak) <= 0);

    std::thread th(&Ingredient::use, fridge, doe);
    std::thread th2(&Ingredient::use, fridge, tomato);
    std::thread th3(&Ingredient::use, fridge, gruyere);
    std::thread th4(&Ingredient::use, fridge, steak);
    delay =(delay * 2) * CLOCKS_PER_SEC;    now = clock();
    while(clock() - now < delay);
}

void cook_fantasia(int multi, Ingredient *fridge)
{
    int delay = multi;
    clock_t now;
    while (fridge->get_ing(tomato) <= 0 || fridge->get_ing(doe) <= 0 || fridge->get_ing(gruyere) <= 0 
    || fridge->get_ing(steak) <= 0);

    std::thread th(&Ingredient::use, fridge, doe);
    std::thread th2(&Ingredient::use, fridge, tomato);
    std::thread th3(&Ingredient::use, fridge, eggplant);
    std::thread th4(&Ingredient::use, fridge, goat_cheese);
    delay =(delay * 4) * CLOCKS_PER_SEC;    now = clock();
    while(clock() - now < delay);
}

commande *Chef::get_cooking()
{
    return (this->cooking);
}

void *cooking2(void * p_data)
{
    Chef *chef = (Chef *) p_data;
    const char *t = chef->get_cooking()->get_type();
    int multi = chef->get_multiplier();
    Ingredient *l = chef->get_fridge();

    if (t == "Margarita" )
        cook_margarita(multi, l);
    if (t == "Regina") {
        cook_regina(multi, l);
    } else if (t == "Americana") {
        cook_americana(multi, l );
    }else if (t == "Fantasia") {
        cook_fantasia(multi, l);
    }
}


void Chef::start_cooking(commande *t)
{
    commande *tmp;    

    if (this->cooking != nullptr && this->waiting == nullptr) {
        this->waiting = t;
        *this->msg = "COMMANDE ACCEPTED";
        this->free = 2;
        return;
    } else {
        this->cooking = t;
        *this->msg = "COMMANDE ACCEPTED";
        this->free = 1;
        pthread_create(&this->cook_thread, NULL,&cooking2, (void *) this);
        pthread_join(this->cook_thread,NULL);
        std::cout << "COMMANDE FINI :" << this->cooking->get_type() << " " << this->cooking->get_size() << " " << std::endl;
        for (int i = 0; i < this->commande_encour.size(); i++) {
            if (this->commande_encour[i].get_type() == this->cooking->get_type())
                this->commande_encour.erase(this->commande_encour.begin() + (i - 1));
        }
        *this->nb_com_keep -= 1;
        if (this->waiting != nullptr) {
            tmp = this->waiting;
            delete (this->cooking);
            this->waiting = nullptr;
            start_cooking(tmp);
        }
        this->free = 0;
        return;
    }
    *this->msg = "COMMANDE REFUSED";
}