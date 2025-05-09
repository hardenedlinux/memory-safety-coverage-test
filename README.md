## Meory safety coverage tests

|Bug type     | Sanitizers | Fil-C             | Clang bounds-safety |
|:-----------:|:-----------------:|:-----------------:|:-------------------:|
|0-out-of-bounds-access.c| YES (ASAN)    | NO                | NO                  |
|2-out-of-bounds-access.c| YES (ASAN)   | YES               | NO                  |
|3-out-of-bounds-in-bounds.c| YES (ASAN) | YES               | NO                  |
|1-overflowing-out-of-bounds.c | NO (ASAN) | YES             | N/A                 |
|4-bad-syscall.c | NO (ASAN)             | YES               | N/A                 |
|5-type-confusion.c | NO (ASAN)         | YES               | N/A                 |
|6-use-after-free.c | YES (ASAN)        | YES               | N/A                 |
|7-pointer-races.c | YES (ASAN/TSAN)    | Partially               | N/A                 |
|8-data-races.c | YES (TSAN)        | NO               | N/A                 |
|9-stack-use-after-return.c | YES (ASAN)        | NO               | N/A                 |

* The Path to Memory Safety is Inevitable <https://hardenedlinux.org/blog/2025-05-07-the-path-to-memory-safety-is-inevitable/>
