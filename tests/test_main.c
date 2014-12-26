#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "greatest.h"

SUITE(suite);

TEST blah(void)
{
    PASS();
}

SUITE(suite)
{
    RUN_TEST(blah);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite);
    GREATEST_MAIN_END();
    return 0;
}
