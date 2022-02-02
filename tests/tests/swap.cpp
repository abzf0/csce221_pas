#include "executable.h"
#include <vector>

TEST(swap) {
    Typegen t;
    for(size_t sz = 0; sz < 100; ++sz) {
        std::vector<int> a_gt(sz);
        std::vector<int> a(sz);
        std::vector<int> b_gt(sz);
        std::vector<int> b(sz);

        for(size_t i = 0; i < sz; ++i) {
            a_gt[i] = a[i] = t.get<int>();
            b_gt[i] = b[i] = t.get<int>();
        }

        {
            Memhook mh;
            sort::swap(a, b);

			if (mh.n_allocs() != 0) {
                std::cerr << "ERROR: Swap is allocating a new value.\n"
                    << "\tDoes your swap use copy or move semantics?\n";
            }
            ASSERT_EQ(0UL, mh.n_allocs());

            if (mh.n_frees() != 0) {
                std::cerr << "ERROR: Swap is freeing (deleting) a value.\n"
                    << "\tShould swap do this?\n";
            }
            ASSERT_EQ(0UL, mh.n_frees());

            if (a_gt != b) {
                std::cerr << "ERROR: b does not contain the same values that a_gt contains.\n"
                    << "\tDid you swap the values?\n";
            }
            if (b_gt != a) {
                std::cerr << "ERROR: a does not contain the same values that b_gt contains.\n"
                    << "\tDid you swap the values?\n";
            }
            for(size_t i = 0; i < sz; ++i) {
                ASSERT_EQ(a_gt[i], b[i]);
                ASSERT_EQ(b_gt[i], a[i]);
            }
        }
    }
}
