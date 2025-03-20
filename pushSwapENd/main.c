#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || argc == 2 && !argv[1][0])
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    if (!argv)
        return (0);
    a = completeStack(argv);
    if (!ordenado(a))
    {
        if (ft_lstsize(a) == 2)
            sa(a);
        else if (ft_lstsize(a) == 3)
            ordena_a(&a);
        else
            push_swap(a, b)
    }
}