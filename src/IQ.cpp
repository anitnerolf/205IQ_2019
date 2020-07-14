/*
** EPITECH PROJECT, 2020
** 205IQ
** File description:
** IQ.cpp
*/

#include "../include/IQ.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

#define _USE_MATH_DEFINES

IQ::IQ()
{
}

IQ::~IQ()
{
}

void	IQ::calculate(int mean, int sdeviation)
{
    for (int i = 0; i <= 200; i++) {
        double result = (1.0 / ((double)sdeviation * \
        sqrt(2.0 * M_PI))) * 1.0 / \
        (pow(M_E ,((pow(((double)i - (double)mean), 2.0)) / \
        (2.0 * pow((double)sdeviation, 2.0)))));
        std::cout << i << " " << std::fixed << std::setprecision(5) << result << std::endl;
    }
}

void	IQ::calculate_iq(int mean, int sdeviation, int iq1)
{
    double result = 0.0;

    for (int i = 0; i < iq1 * 100; i++) {
        result += ((1.0 / 100.0) / ((double)sdeviation * \
        sqrt(2.0 * M_PI))) * 1.0 / \
        (pow(M_E, ((pow(((double)i / 100.0 - (double)mean), 2.0)) / \
        (2.0 * pow((double)sdeviation, 2.0)))));
    }
    std::cout << std::fixed << std::setprecision(1) << result * 100 << "% of people have an IQ inferior to " << iq1 << std::endl;
}

void	IQ::calculate_iq_iq2(int mean, int sdeviation, int iq1, int iq2)
{
    double result = 0.0;

    for (int i = iq1 * 100; i < iq2 * 100; i++) {
        result += ((1.0 / 100.0) / ((double)sdeviation * sqrt(2.0 * M_PI))) * 1.0 / \
        (pow(M_E, ((pow(((double)i / 100.0 - (double)mean), 2.0)) / \
        (2.0 * pow((double)sdeviation, 2.0)))));
    }
    std::cout << std::fixed << std::setprecision(1) << result * 100 << "% of people have an IQ between " << iq1 << " and " << iq2 << std::endl;
}

int	IQ::check_if_number(std::string str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 57 || str[i] < 48)
            return 84;
        i++;
    }
    return 0;
}

int	IQ::get_arguments(int ac, char **av)
{
    if (ac == 3) {
        if (this->check_if_number(av[1]) == 0 && \
            this->check_if_number(av[2]) == 0 && \
            atoi(av[1]) <= 200) {
            this->calculate(atoi(av[1]), atoi(av[2]));
            return 0;
        } else {
            print_usage();
            return 84;
        }
    } else if (ac == 4) {
        if (this->check_if_number(av[1]) == 0 && \
            this->check_if_number(av[2]) == 0 && \
            this->check_if_number(av[3]) == 0 && \
            atoi(av[1]) <= 200 && \
            (atoi(av[3]) >= 0 && atoi(av[3]) <= 200)) {
            this->calculate_iq(atoi(av[1]), atoi(av[2]), atoi(av[3]));
            return 0;
        } else {
            print_usage();
            return 84;
        }
    } else {
        if (this->check_if_number(av[1]) == 0 && \
            this->check_if_number(av[2]) == 0 && \
            this->check_if_number(av[3]) == 0 && \
            this->check_if_number(av[4]) == 0 && \
            atoi(av[1]) <= 200 && \
            (atoi(av[3]) >= 0 && atoi(av[3]) <= 200 && \
             atoi(av[3]) <= atoi(av[4])) && \
            (atoi(av[4]) >= 0 && atoi(av[4]) <= 200 &&  \
             atoi(av[4]) >= atoi(av[3]))) {
            this->calculate_iq_iq2(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]));
            return 0;
        } else {
            print_usage();
            return 84;
        }
    }
    return 0;
}
