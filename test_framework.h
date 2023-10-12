#include <iostream>

struct test_node
{
    test_node *next;
    void (*func)(void);
};

extern void add_test(test_node *tn);

#define test_assert(b)                          \
    do                                          \
    {                                           \
        if (b)                                  \
        {                                       \
            std::cout << "PASSED" << std::endl; \
            tests_passed++;                     \
        }                                       \
        else                                    \
        {                                       \
            std::cout << "FAILED" << std::endl; \
            tests_failed++;                     \
        }                                       \
    } while (0)

#define UNIT_TEST(f)                         \
    static void f(void);                     \
    static void __attribute__((constructor)) \
    __construct_##f(void)                    \
    {                                        \
        static test_node tn;                 \
        tn.next = nullptr;                   \
        tn.func = f;                         \
        add_test(&tn);                       \
    }                                        \
    static void __real_##f(void);            \
    static void f(void)                      \
    {                                        \
        std::cout << __func__ << "... ";     \
        std::cout.flush();                   \
        __real_##f();                        \
    }                                        \
    static void __real_##f(void)

int tests_passed = 0, tests_failed = 0;
test_node *start = nullptr;

void add_test(test_node *tn)
{
    test_node **current = &start;
    while (*current)
        current = &((*current)->next);
    *current = tn;
}

int main()
{
    test_node *current = start;
    while (current)
    {
        current->func();
        current = current->next;
    }
    int total_tests = tests_passed + tests_failed;
    if (total_tests == 0)
        std::cout << "No tests found" << std::endl;
    else
        std::cout << tests_passed << " test case passed" << std::endl
                  << tests_failed << " test case failed" << std::endl;

    return tests_failed > 0;
}
