//
// Created by tom billard on 17/03/2017.
//

#include "fdf.h"
#define NB 20


int    zoom_in(t_env *env)
{
    env->ratio += env->rzoom;
    return (0);
}

int    zoom_out(t_env *env)
{
    if (env->ratio - env->rzoom > 0)
        env->ratio -= env->rzoom;
    return (0);
}

int    zoom_p(t_env *env)
{
    env->rzoom += 0.1;
    return (0);
}

int    zoom_m(t_env *env)
{
    if (env->rzoom - 0.1 > 0)
        env->rzoom -= 0.1;
    return (0);
}

int    go_left(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winx += nb;
    return (0);
}

int    go_right(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winx -= nb;
    return (0);
}

int    go_top(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winy += nb;
    return (0);
}

int    go_bot(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winy -= nb;
    return (0);
}


int    matrix(t_env *env)
{
    env->matrix = !env->matrix;
    return (0);
}



int     ft_exit(t_env *env)
{
    ft_end(env);
    return (0);
}

int     ro_m(t_env *env)
{
    if (env->color.r1 - NB > 0  )
        env->color.r1 -= NB;
    return (0);
}

int     ro_p(t_env *env)
{
    if (env->color.r1 + NB < 255)
        env->color.r1 += NB;
    return (0);
}

int     rt_m(t_env *env)
{
    if (env->color.r2 - NB > 0  )
        env->color.r2 -= NB;
    return (0);
}

int     rt_p(t_env *env)
{
    if (env->color.r2 + NB < 255)
        env->color.r2 += NB;
    return (0);
}



int     go_m(t_env *env)
{
    if (env->color.g1 - NB > 0)
         env->color.g1 -= NB;
    return (0);
}

int     go_p(t_env *env)
{
 if (env->color.g1 + NB < 255)
         env->color.g1 += NB;
    return (0);
}

int     gt_m(t_env *env)
{
    if (env->color.g2 - NB > 0)
        env->color.g2 -= NB;
    return (0);
}

int     gt_p(t_env *env)
{
    if (env->color.g2 + NB < 255)
        env->color.g2 += NB;
    return (0);
}



int     bo_m(t_env *env)
{


    if (env->color.b1 - NB > 0)
        env->color.b1 -= NB;
    return (0);
}

int     bo_p(t_env *env)
{
    if (env->color.b1 + NB < 255)
       env->color.b1 += NB;
    return (0);
}

int     bt_m(t_env *env)
{
    if (env->color.b2 - NB > 0)
     env->color.b2 -= NB;
    return (0);
}

int     bt_p(t_env *env)
{
    if (env->color.b2 + NB < 255)
        env->color.b2 += NB;
    return (0);
}


int     ro_i(t_env *env)
{
    env->rot += env->mrot;
    return (0);
}

int     ro_d(t_env *env)
{
    env->rot -= env->mrot;
    return (0);
}

int     rt_i(t_env *env)
{
    env->rad += env->mrad;
    return (0);
}

int     rt_d(t_env *env)
{
    env->rad -= env->mrad;
    return (0);
}

int     rov_i(t_env *env)
{
    env->mrot += 0.01;
    return (0);
}

int     rov_d(t_env *env)
{
    env->mrot -= 0.01;
    return (0);
}


int     rtv_i(t_env *env)
{
    env->mrad += 0.01;
    return (0);
}

int     rtv_d(t_env *env)
{
    env->mrad -= 0.01;
    return (0);
}

int     c_color(t_env *env)
{
    env->col = (env->col + 1) % 4;
    return (0);
}

int     zo_i(t_env *env)
{
    env->cz += 0.05;
    return (0);
}

int     zo_d(t_env *env)
{
    env->cz -= 0.05;
    return (0);
}

int     opti(t_env *env)
{
    env->t = !env->t;
    return (0);
}

int     nil(t_env *env)
{
    return (0);
}

static void		ft_tab_ft_init(int (**tab_ft)(t_env*))
{
    tab_ft[0] = &zoom_out;
    tab_ft[1] = &zoom_m;
    tab_ft[2] = &opti;

    tab_ft[3] = &nil;

    tab_ft[4] = &rtv_i;
    tab_ft[5] = &rtv_d;
    tab_ft[6] = &zoom_in;
    tab_ft[7] = &zoom_p;

    tab_ft[8] = &nil;

    tab_ft[9] = &rt_d;

    tab_ft[10] = &nil;

    tab_ft[11] = &rt_i;
    tab_ft[12] = &c_color;
    tab_ft[13] = &zo_i;
    tab_ft[14] = &zo_d;

    tab_ft[15] = &nil;
    tab_ft[16] = &nil;

    tab_ft[17] = &matrix;
    tab_ft[18] = &ro_m;
    tab_ft[19] = &ro_p;
    tab_ft[20] = &rt_m;
    tab_ft[21] = &rt_p;

    tab_ft[22] = &go_p;
    tab_ft[23] = &go_m;
    tab_ft[24] = &bt_p;
    tab_ft[25] = &bo_m;
    tab_ft[26] = &gt_m;
    tab_ft[27] = &bt_m;
    tab_ft[28] = &gt_p;
    tab_ft[29] = &bo_p;

    tab_ft[30] = &nil;
    tab_ft[31] = &nil;
    tab_ft[32] = &nil;
    tab_ft[33] = &nil;
    tab_ft[34] = &nil;
    tab_ft[35] = &nil;
    tab_ft[36] = &nil;
    tab_ft[37] = &nil;

    tab_ft[38] = &rov_d;

    tab_ft[39] = &nil;

    tab_ft[40] = &rov_i;

    tab_ft[41] = &nil;
    tab_ft[42] = &nil;
    tab_ft[43] = &nil;
    tab_ft[44] = &nil;

    tab_ft[45] = &ro_d;
    tab_ft[46] = &ro_i;


    tab_ft[47] = &nil;
    tab_ft[48] = &nil;
    tab_ft[49] = &nil;
    tab_ft[50] = &nil;
    tab_ft[51] = &nil;
    tab_ft[52] = &nil;

    tab_ft[53] = &ft_exit;

    tab_ft[54] = &nil;
    tab_ft[55] = &nil;
    tab_ft[56] = &nil;
    tab_ft[57] = &nil;
    tab_ft[58] = &nil;
    tab_ft[59] = &nil;
    tab_ft[60] = &nil;

    tab_ft[60] = &nil;
    tab_ft[61] = &nil;
    tab_ft[62] = &nil;
    tab_ft[63] = &nil;
    tab_ft[64] = &nil;
    tab_ft[65] = &nil;
    tab_ft[66] = &nil;
    tab_ft[67] = &nil;
    tab_ft[68] = &nil;
    tab_ft[69] = &nil;

    tab_ft[70] = &nil;
    tab_ft[71] = &nil;
    tab_ft[72] = &nil;
    tab_ft[73] = &nil;
    tab_ft[74] = &nil;
    tab_ft[75] = &nil;
    tab_ft[76] = &nil;
    tab_ft[77] = &nil;
    tab_ft[78] = &nil;
    tab_ft[79] = &nil;

    tab_ft[80] = &nil;
    tab_ft[81] = &nil;
    tab_ft[82] = &nil;
    tab_ft[83] = &nil;
    tab_ft[84] = &nil;
    tab_ft[85] = &nil;
    tab_ft[86] = &nil;
    tab_ft[87] = &nil;
    tab_ft[88] = &nil;
    tab_ft[89] = &nil;

    tab_ft[90] = &nil;
    tab_ft[91] = &nil;
    tab_ft[92] = &nil;
    tab_ft[93] = &nil;
    tab_ft[94] = &nil;
    tab_ft[95] = &nil;
    tab_ft[96] = &nil;
    tab_ft[97] = &nil;
    tab_ft[98] = &nil;
    tab_ft[99] = &nil;

    tab_ft[100] = &nil;
    tab_ft[101] = &nil;
    tab_ft[102] = &nil;
    tab_ft[103] = &nil;
    tab_ft[104] = &nil;
    tab_ft[105] = &nil;
    tab_ft[106] = &nil;
    tab_ft[107] = &nil;
    tab_ft[108] = &nil;
    tab_ft[109] = &nil;

    tab_ft[110] = &nil;
    tab_ft[111] = &nil;
    tab_ft[112] = &nil;
    tab_ft[113] = &nil;
    tab_ft[114] = &nil;
    tab_ft[115] = &nil;
    tab_ft[116] = &nil;
    tab_ft[117] = &nil;
    tab_ft[118] = &nil;
    tab_ft[119] = &nil;

    tab_ft[120] = &nil;
    tab_ft[121] = &nil;
    tab_ft[122] = &nil;

    tab_ft[123] = &go_left;
    tab_ft[124] = &go_right;
    tab_ft[125] = &go_bot;
    tab_ft[126] = &go_top;

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

void key_handler(SDL_Event event, t_env *env)
{
        if (event.key.keysym.sym == SDLK_d)
            env->t = !env->t;
}