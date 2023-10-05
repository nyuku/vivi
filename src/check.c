#include "../includes/push_swap.h"

void check_all_arg(char **av, int ac, t_pushswap *ps)
{
    if (ac == 2)
    {
        ps->mono_arg = check_mono_arg(av, ps);
        if (ps->mono_arg == 0)
        {
            p_error();
            exit (0);
        }
    }
    else if (ac > 2)
    {
        if (check_multi_arg(av, ac)!= 0)// un seul argument
        {
            //printf("multi,c'est que des nombres\n");
            ps->multi_arg = check_multi_arg(av, ac);
            //printf("check_multi_arg d'arguments : %d\n", check_multi_arg(av, ac));
        }
        else
        {
            printf("c'est faux multi\n");
            //stop
        }

    }
}

//check si des nombres, retourne le nombre d'arguments. sinon return 0
int check_mono_arg(char **av, t_pushswap *ps)
{
    int i;
    int result;

    i = 0;
    result = 0;
    ps->tab_args_number = ft_split(av[1], ' '); // on utilise split pour isoler les nombres
    //ici checl si un seul argument.

    while (ps->tab_args_number[i]) // on parcout ce qu'on a obtenu pour verifier si c'est des nombres, case par case
    {
        if (check_if_number(ps->tab_args_number[i]) == 1)
        {
            result++;
            i++;
        }
        else
            return (0);
    }
    if (result == 0 || i == 1) // ok
    {
        printf("marche po. il z a un seul arguement chiffre\n");
        return (0);
    }



    return (result);
}

//retourne 1 si ok
//on parcout la str pour verifier si c'est un nombre (!)au neg
int check_if_number(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        return (0);
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return (0);
    }
    return (1);
}

int check_multi_arg(char **argv, int argc)
{
    int result;
    int i;

    result = 0;
    i = 1;
    while (i < argc)
    {
        if (check_if_number(argv[i]) == 1)
        {
            result++;
            i++;
        }
        else
            return (0);
    }
    return (result);
}
