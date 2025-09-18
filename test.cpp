#include <gtest/gtest.h>
#include "area.hpp"

using namespace polygon;

TEST(simple, sanity) {
    Polygon<int> plg;

    plg.points = std::vector<Polygon<int>::Point>({{0, 0}});
    ASSERT_EQ(plg.area(), 0);

    plg.points = std::vector<Polygon<int>::Point>({{0, 0}, {0, 10}});
    ASSERT_EQ(plg.area(), 0);

    plg.points = std::vector<Polygon<int>::Point>({{1, 1}, {1, 1}});
    ASSERT_EQ(plg.area(), 0);

    plg.points = std::vector<Polygon<int>::Point>({{1, 1}, {2, 2}, {3, 3}});
    ASSERT_EQ(plg.area(), 0);
}

TEST(simple, triangle_1) {
    Polygon<int> plg;
    plg.points = std::vector<Polygon<int>::Point>({{0, 0}, {10, 0}, {0, 10}});

    ASSERT_EQ(plg.area(), 50);
}

TEST(simple, triangle_2) {
    Polygon<double> plg;
    plg.points = std::vector<Polygon<double>::Point>({{0, 0}, {3, 4}, {4, 3}});

    ASSERT_EQ(plg.area(), 3.5);
}

TEST(simple, square) {
    Polygon<int> plg;
    plg.points = std::vector<Polygon<int>::Point>({{1, 1}, {1, 2}, {2, 2}, {2, 1}});

    ASSERT_EQ(plg.area(), 1);
}

TEST(simple, penta) {
    Polygon<int> plg;
    plg.points = std::vector<Polygon<int>::Point>({{3, 4}, {5, 11}, {12, 8}, {9, 5}, {5, 6}});

    ASSERT_EQ(plg.area(), 30);
}

TEST(simple, corner) {
    Polygon<int> plg;
    plg.points = std::vector<Polygon<int>::Point>({{1, 1}, {1, 5}, {4, 5}, {4, 4}, 
                                                   {2, 4}, {2, 2}, {4, 2}, {4, 1}});

    ASSERT_EQ(plg.area(), 8);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}