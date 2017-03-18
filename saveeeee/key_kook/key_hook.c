//
// Created by tom billard on 17/03/2017.
//

#include "fdf.h"



static void		ft_tab_ft_init_6(int (**tab_ft)(t_env*))
{
    tab_ft[119] = &nil;
    tab_ft[120] = &nil;
    tab_ft[121] = &nil;
    tab_ft[122] = &nil;
    tab_ft[123] = &go_left;
    tab_ft[124] = &go_right;
    tab_ft[125] = &go_bot;
    tab_ft[126] = &go_top;
}

static void     ft_tab_ft_init(int (**tab_ft)(t_env*))
{
    ft_tab_ft_init_1(tab_ft);
    ft_tab_ft_init_2(tab_ft);
    ft_tab_ft_init_3(tab_ft);
    ft_tab_ft_init_4(tab_ft);
    ft_tab_ft_init_5(tab_ft);
    ft_tab_ft_init_6(tab_ft);
}

//#define NB1 0b0000000000100000011000010100000000111111111111100111101011110111

#define NB1 (Uint32)0b00111111111111100111101011110111
#define NB2 (Uint32)0b00000000001000000110000101000000

//#define NB1 0b00000000010000000000001010000000000000000000001100111101011110111
int		key_hook(int k, t_env *e)
{
    static int    (*t_hook[150])(t_env*) = {NULL};
    if (!t_hook[0])
        ft_tab_ft_init(t_hook);
    if (k > 126)
        return (0);
//    if ((k < 32 && !(NB1 & (1 << k))) || ((k < 64 && !(NB1 & (1 << (k - 32))))))
//        return 0;
    t_hook[k](e);
    render(e);
    return (0);
}