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
        {
            Memhook mh;
            sort::swap(a_original, b_original);
            if (mh.n_allocs() != 0) {
                std::cerr << "ERROR: Swap is allocating a new value.\n"
                    << "\tDoes your swap use copy or move semantics?\n";
            }
            ASSERT_EQ(0UL, mh.n_frees());
            if (mh.n_frees() != 0) {
                std::cerr << "ERROR: Swap is freeing (deleting) a value.\n"
                    << "\tShould swap do this?\n";
            }
            ASSERT_EQ(0UL, mh.n_frees());
            if (a_original != b_gt) {
                std::cerr << "ERROR: b_gt does not contain the same values that a_original contains.\n"
                    << "\tDid you swap the values?\n";
            }
            if (b_original != a_gt) {
                std::cerr << "ERROR: a_gt does not contain the same values that b_original contains.\n"
                    << "\tDid you swap the values?\n";
            }
            for(size_t i = 0; i < sz; ++i) {
                ASSERT_EQ(a_original[i], b_gt[i]);
                ASSERT_EQ(b_original[i], a_gt[i]);
            }
        }
    }
}
