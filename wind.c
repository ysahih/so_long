#include <mlx.h>

int main() {
    
    void *mlx;
    void *win;
    //void *img;
    void *img1;
    int width;
    int height;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1500, 2000, "so_long");
    // img = mlx_xpm_file_to_image(mlx, "sample.xpm", &width, &height);
    //mlx_put_image_to_window(mlx, win,img , 0, 0);

    img1 = mlx_xpm_file_to_image(mlx, "koala2.xpm", &width, &height);
    mlx_put_image_to_window(mlx, win,img1 , 0, 0);
    
    mlx_loop(mlx);
    return 0;
}