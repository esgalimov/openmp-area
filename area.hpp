#include <vector>
#include <omp.h>

namespace polygon {

struct Polygon {
    struct Point {
        double x;
        double y;
    };

    std::vector<Point> points;

    double area() const {
        double answer = 0.0;
        #pragma omp parallel reduction(+: answer) num_threads(2)
        {
            int id = omp_get_thread_num();
            #pragma omp for schedule(guided)
            for(int i = 0; i < 10; i++) {
                answer += i;
                printf("Нить: %d, Итерация: %d\n", id, i);
            }
            printf("answer: %lf \n", answer);
        }
        printf("answer: %lf \n", answer);
        return 0.0;
    }

};

} // <-- namespace polygon