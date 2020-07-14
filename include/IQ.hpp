/*
** EPITECH PROJECT, 2020
** 205IQ
** File description:
** header file
*/

#ifndef IQ_HPP_
#define IQ_HPP_

#include <string>

class IQ
{
public:
    IQ();
    ~IQ();
    int get_arguments(int ac, char **av);
    void calculate(int mean, int sdeviation);
    void calculate_iq(int mean, int sdeviation, int iq1);
    void calculate_iq_iq2(int mean, int sdeviation, int iq1, int iq2);
    int	check_if_number(std::string str);
};

void	print_usage(void);

#endif /* IQ_HPP_ */
