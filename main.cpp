#include <iostream>
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

    for (Polygon<double>::Point point : plg.points) {
        std::cout << point.x << " " << point.y << std::endl;
    }

    plg.area();

//     #ifdef CHECK_TIME
//     auto start = std::chrono::high_resolution_clock::now();
//     #endif
//     octotree_t octotree{triangles, max_min_crds};

//     std::set<int> ans = octotree.get_intersections();

//     for (auto it = ans.begin(); it != ans.end(); it++)
//         std::cout << *it << std::endl;

//     #ifdef CHECK_TIME
//     const double tm = std::chrono::duration_cast<std::chrono::milliseconds>(
//                       std::chrono::high_resolution_clock::now() - start).count() / 1000.0;
//     std::cout << "time = " << tm << "s" << std::endl;
//    #endif

    return 0;
}