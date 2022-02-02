#include "executable.h"
#include <vector>

TEST(swap) {
    Typegen t;
    for(size_t sz = 0; sz < 100; ++sz) {
        std::vector<int> a_original(sz);
        std::vector<int> a_gt(sz);
        std::vector<int> b_original(sz);
        std::vector<int> b_gt(sz);
        for(size_t i = 0; i < sz; ++i) {
            a_original[i] = a_gt[i] = t.get<int>();
            b_original[i] = b_gt[i] = t.get<int>();
        }
        Memhook mh;
        swap(a_original, b_original);
        ASSERT_EQ(0UL, mh.n_allocs());
        ASSERT_EQ(0UL, mh.n_frees());
        for(size_t i = 0; i < sz; ++i) {
            ASSERT_EQ(a_original[i], b_gt[i]);
            ASSERT_EQ(b_original[i], a_gt[i]);
        }
    }
}
