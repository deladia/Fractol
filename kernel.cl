typedef struct      s_complex
{
    double          re;
    double          im;
}                   t_complex;

t_complex       init_complex(double re, double im)
{
    t_complex   complex;

    complex.re = re;
    complex.im = im;
    return (complex);
}

double          ft_fabs(double  num)
{
    if (num < 0)
        return (num * (-1));
    else
        return (num);
}

__kernel void vadd( __global int *arr, int side_x, int side_y, double move_x, double move_y, int repeat, int color, double xmin, double xmax, double ymin, double ymax, char key, int x, int y)
{
    double		xc;
    double 		yc;
    int 		i;
    double 		xn1;
    double		yn1;
    double 		xn0;
    double 		yn0;
    int         dot;
    double      t;
    int         red;
    int         green;
    int         blue;
    t_complex   c;
    t_complex   z;
    t_complex   k;

    dot = get_global_id(0);
    c.re = xmin + ((double)(dot % 1500) - move_x + side_x / 2) / 1500 * (xmax - xmin);
    c.im = ymax + ((double)(dot / 1500) - move_y + side_y / 2) / 1000 * (ymin - ymax);
    z = init_complex(c.re, c.im);
    i = 0;
    if (key == 'A')
    {
        while ((z.re * z.re + z.im * z.im) <= 4.0 && i < repeat)
        {
            z = init_complex(z.re * z.re - z.im * z.im + c.re, 2.0 * z.re * z.im + c.im);
    	    i++;
        }
    }
    if (key == 'B')
    {
        k = init_complex((2 * ((double)x / side_x - 0.5)), (2 * ((double)(side_y - y) / side_y - 0.5)));
        while ((z.re * z.re + z.im * z.im) <= 4.0 & i < repeat)
        {
            z = init_complex(z.re * z.re - z.im * z.im + k.re, 2.0 * z.re * z.im + k.im);
            i++;
        }
    }
    if (key == 'C')
    {
        while (z.re * z.re + z.im * z.im <= 4.0 & i < repeat)
        {
            z = init_complex(z.re * z.re - z.im * z.im + c.re, -2.0 * ft_fabs(z.re * z.im) + c.im);
            i++;
        }
    }
    if (key == 'D')
    {
        while (z.re * z.re + z.im * z.im <= 4.0 && i < repeat)
        {
            z = init_complex(z.re * z.re - z.im * z.im + c.re, -2.0 * z.re * z.im + c.im);
            i++;
        }
    }
    if (key == 'E')
    {
        while (z.re * z.re + z.im * z.im <= 4.0 && i < repeat)
        {
            z = init_complex(ft_fabs(z.re * z.re - z.im * z.im) + c.re, -2.0 * z.re * z.im + c.im);
            i++;
        }
    }
    if (key == 'F')
    {
        while (z.re * z.re + z.im * z.im <= 4 && i < repeat)
        {
            z = init_complex(z.re * z.re - z.im * z.im + c.re, -2.0 * ft_fabs(z.re) * z.im + c.im);
            i++;
        }
    }
    if (color == 0xFFFFFF || color == 0x00FFFF || color == 0x0000CD)
    {
        t = (double)i / (double)repeat;
        red = (color & 0xFF0000) >> 16;
        red = red * t;
        green = (color & 0x00FF00) >> 8;
        green = green * t;
        blue = (color & 0x0000FF);
        blue = blue * t;
        color = (red << 16) | (green << 8) | blue;
        arr[dot] = color;
    }
    else if (color == 40)
    {
        t = (double)i / (double)repeat;
        int s = 100;
        color = ((i * 255 / s) << 2) + ((i * 255 / s) << 16) + i * 255 / s;
        arr[dot] = color;
    }
    else
    {
        t = (double)i / (double)repeat;
        red = (int)((color - 6) * (1 - t) * t * t * t * 255);
        green = (int)((color) * t * t * (1 - t) * (1 - t) * 255);
        blue = (int)((color - 6.5) * (1 - t) * (1 - t) * (1 - t) * t * 255);
        arr[dot] = red * green * blue;
    }
}
