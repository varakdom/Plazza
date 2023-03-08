/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-margotte1.martins
** File description:
** main
*/

#include "main.hpp"
#include "reception.hpp"
#include "commande.hpp"
#include <iomanip>
#include <iostream>


int check_arg(char **argv)
{
    for (int i = 1; i < 4; i++)
        if (std::atoi(argv[i]) <= 0)
            return (0);
    return (1);
}

void parser(std::string buffer, reception recept, Kitchen *k)
{
    size_t pos = 0;
    int command = 1;
    int i = 0;
    std::string token;
    std::vector <commande> com;

    for (;(pos = buffer.find(";")) != std::string::npos; i++) {
        token = buffer.substr(0, pos);
        commande tmp = recept.parse_commande(token);
        if (recept.get_error() == 1)
            break;
        com.emplace_back(tmp);
        buffer.erase(0, pos + 2);
    }
    commande tmp = recept.parse_commande(buffer);
    if (recept.get_error() == 1)
        return;
    com.emplace_back(tmp);
    command += i;
    recept.smart_Cook(com, command);
}

void my_reception(reception recept)
{
    std::string buffer;
    Kitchen *k = new Kitchen(recept.get_cook(), recept.get_multiplier(), recept.get_respawn());
    do {
        std::getline(std::cin, buffer);
        if (buffer.compare("END") == 0)
            break;
        parser(buffer, recept, k);
    } while(1);
    delete(k);
}

int main(int argc, char **argv)
{
    if (argc != 4 || !check_arg(argv))
        return (84);
    double multi = std::atoi(argv[1]);
    int nb_cook = std::atoi(argv[2]);
    int ing_respawn = std::atoi(argv[3]);
    reception recept =  reception(multi,nb_cook,ing_respawn);
    my_reception(recept);
}