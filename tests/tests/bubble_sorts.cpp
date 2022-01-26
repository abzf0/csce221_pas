#include "executable.h"
#include <vector>

TEST(bubble_sort) {
    Typegen t;

    for(size_t sz = 0; sz < 1000; sz++) {
        std::vector<int> vec(sz);
        std::vector<int> gt(sz);

        t.fill(vec.begin(), vec.end());
        std::copy(vec.begin(), vec.end(), gt.begin());

        bubble_sort(vec.begin(), vec.end());
        std::sort(gt.begin(), gt.end());

        ASSERT_TRUE(std::equal(vec.begin(), vec.end(), gt.begin()));
    }
}
