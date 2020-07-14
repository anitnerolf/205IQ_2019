/*
** EPITECH PROJECT, 2020
** 205IQ
** File description:
** main
*/

#include "../include/IQ.hpp"
#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
    IQ iq;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_usage();
    } else if (ac == 3 || ac == 4 || ac == 5) {
        return (iq.get_arguments(ac, av));
    } else
        return 84;
    return 0;
}

void	print_usage(void)
{
    std::cout << "USAGE\n\t./205IQ u s [IQ1] [IQ2]\n" << std::endl;
    std::cout << "DESCRIPTION\n\tu\tmean\n\ts\tstandard deviation" << std::endl;
    std::cout << "\tIQ1\tminimum IQ\n\tIQ2\tmaximum IQ" << std::endl;
}
