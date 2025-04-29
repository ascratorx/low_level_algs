#include <iostream>
#include <fstream>
#include <complex>
#include <cmath>

using namespace std;

typedef unsigned int uint;

constexpr int width = 400;
constexpr int height = 400;
constexpr double t = 2.0;
constexpr double eps = 1e-3;
constexpr int max_iter = 100;

const uint COLOR_R = 0xFF0000;
const uint COLOR_G = 0x00FF00;
const uint COLOR_B = 0x0000FF;
const uint COLOR_WHITE = 0xFFFFFF;

const complex<double> r1 = {-1.0, 0.0};
const complex<double> r2 = {+1.0, 0.0};
const complex<double> r3 = {1.0, 2.0};

complex<double> f(complex<double> z) {
    return (z - r1) * (z - r2) * (z - r3);
}

complex<double> df(complex<double> z) {
    return (z - r1)*(z - r2) + (z - r1)*(z - r3) + (z - r2)*(z - r3);
}

uint get_color(complex<double> z) {
    for (int i = 0; i < max_iter; ++i) {
        complex<double> fz = f(z);
        complex<double> dfz = df(z);
        if (abs(dfz) < 1e-10) break;
        z = z - fz / dfz;

        if (abs(z - r1) < eps) return COLOR_R;
        if (abs(z - r2) < eps) return COLOR_G;
        if (abs(z - r3) < eps) return COLOR_B;
    }
    return COLOR_WHITE;
}

void write_ppm(const char* filename, uint** image) {
    ofstream os(filename);
    os << "P3\n" << width << " " << height << "\n255\n";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            uint color = image[y][x];
            uint r = (color >> 16) & 0xFF;
            uint g = (color >> 8) & 0xFF;
            uint b = color & 0xFF;
            os << r << " " << g << " " << b << "  ";
        }
        os << "\n";
    }
    os.close();
}

int main()
{
    constexpr unsigned n_row = 400;
    constexpr unsigned n_col = 400;
    constexpr double zz = 5.0;
    constexpr double x_min = -zz;
    constexpr double x_max = +zz;
    constexpr double y_min = -zz;
    constexpr double y_max = +zz;
    constexpr double Rx = (x_max - x_min) / ( n_col - 0.0 );
    constexpr double Ry = (y_max - y_min) / ( n_row - 0.0 );

    uint** image = new uint*[n_row];
    for (unsigned i = 0; i < n_row; ++i)
        image[i] = new uint[n_col];

    for (unsigned row = 0; row < n_row; ++row)
    {
        const double y = y_min + (row - 0) * Ry;
        for (unsigned col = 0; col < n_col; ++col)
        {
            const double x = x_min + (col - 0) * Rx;
            complex<double> z(x, y);
            image[row][col] = get_color(z);
        }
    }

    write_ppm("newton.ppm", image);

    for (unsigned i = 0; i < n_row; ++i)
        delete[] image[i];
    delete[] image;
}
