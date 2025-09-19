#include <iostream>
#include <chrono>
#include "area.hpp"

using namespace polygon;

int main() {
    int points_num = 0;

    if (!(std::cin >> points_num)) {
        std::cerr << "Bad points amount" << std::endl;
        exit(1);
    }

    Polygon<double> plg;
    plg.points.reserve(points_num);
    

    for (int i = 0; i < points_num; i++) {
        double x = 0.0, y = 0.0;

        if (!(std::cin >> x) || !(std::cin >> y)) {
            std::cerr << "Bad coordinates" << std::endl;
            exit(1);
        }

        plg.points.push_back({x, y});
    }

    
    omp_set_num_threads(8);

    auto start = std::chrono::high_resolution_clock::now();
    double area = plg.area();
    double tm = std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::high_resolution_clock::now() - start).count() / 1000.0;

    std::cout << "parallel time = " << tm << "ms" << std::endl;
    std::cout << "parallel area = " << area << " m^2" << std::endl << std::endl;


    omp_set_num_threads(1);

    start = std::chrono::high_resolution_clock::now();
    area = plg.area();
    tm = std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::high_resolution_clock::now() - start).count() / 1000.0;

    std::cout << "serial time   = " << tm << "ms" << std::endl;
    std::cout << "parallel area = " << area << " m^2" << std::endl;

    return 0;
}