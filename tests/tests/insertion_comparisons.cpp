#include "executable.h"
#include <vector>

TEST(insertion_comparisons) {
    Typegen t;

    for(size_t sz = 0; sz < 1000; sz++) {
        std::vector<double> vec(sz);
        std::vector<double> gt(sz);

        t.fill(vec.begin(), vec.end());
        std::copy(vec.begin(), vec.end(), gt.begin());

        size_t comparisons = 0;

        insertion_sort(vec.begin(), vec.end(), [&comparisons](double & i, double & j) {
            comparisons++;
            return i > j;
        });

        std::sort(gt.begin(), gt.end(), [](double & i, double & j) { return i > j; });

        ASSERT_TRUE(std::equal(vec.begin(), vec.end(), gt.begin()));
        // TODO
        ASSERT_EQ(0ULL, comparisons);
    }
}
