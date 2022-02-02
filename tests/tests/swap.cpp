#include "executable.h"
#include <vector>

TEST(swap) {
    Typegen t;
    for(size_t sz = 0; sz < 100; ++sz) {
        std::vector<int> a(sz);
        std::vector<int> b(sz);
        for(size_t i = 0; i < sz; ++i) {
            a[i] = t.get<int>();
            b[i] = t.get<int>();
        }
        Memhook mh;
        swap(a, b);
        ASSERT_EQ(0UL, mh.n_allocs());
        ASSERT_EQ(0UL, mh.n_frees());
    }
}
