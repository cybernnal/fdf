#include "fdf.h"


void        init_window(t_img *e)
{
    e = ft_memalloc(sizeof(t_img));
    e->mlx = mlx_init();
    e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fdf");
    e->data = mlx_new_image(e->mlx, WIN_X, WIN_Y);

}