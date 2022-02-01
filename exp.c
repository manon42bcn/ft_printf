#include <stdio.h>
#include <unistd.h>

int ft_print_hexa(unsigned long nbr, char *base, int spc, char c)
{
    int     base_num;
    int     fill;

    base_num = 16;
    fill = 0;
    if (nbr > base_num)
        return (ft_print_hexa(nbr / base_num, base, (spc - 1), c) + write(1, &base[nbr % base_num], 1));
    else
    {
        if (spc > 0)
        {
            while (--spc > 0)
                fill += write(1, &c, 1);
        }
        return (write(1, &base[nbr], 1));
    }
}

int main (void)
{
    float na;
    int p;
    char *hola;
    unsigned int hexa;

    hexa = 857331;

    na = 3.1;
    //p = write(1, "hola", 4);

    printf("\n%# 4X\n", hexa);
    printf("\n%i\n", ft_print_hexa(hexa, "0123456789abcdef", 20, ' '));
}
