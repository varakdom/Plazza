/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include "Kitchen.hpp"
#include <iomanip>
#include <vector>
#include "main.hpp"
#include "commande.hpp"

class reception
{
    
    private:
    public:
        reception(double multiplier, int nb_cook, int ing_respawn);
        ~reception();
        commande parse_commande(std::string);
        int get_cook();
        int get_respawn();
        int get_multiplier();
        int get_error();
        void smart_Cook(std::vector<commande>, int i);
    protected:
        double multiplier;
        int nb_cook;
        int ing_respawn;
        std::vector<Kitchen> kitchen;
        int error;
};

#endif /* !RECEPTION_HPP_ */
