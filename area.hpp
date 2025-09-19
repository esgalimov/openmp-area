#include <vector>
#include <omp.h>

namespace polygon {

template <typename T> struct Polygon {
    struct Point {
        T x;
        T y;
    };

    std::vector<Point> points;

    T area() const {
        T answer = 0.0;
        int n = points.size();
        #pragma omp parallel reduction(+: answer)
        {
            #pragma omp for schedule(guided)
            for(int i = 0; i < n; i++) {
                int plus_one = i != n - 1 ? i + 1 : 0;
                answer += points[i].x * points[plus_one].y - points[plus_one].x * points[i].y;
            }
        }
        return std::abs(answer) / 2;
    }
};

} // <-- namespace polygon