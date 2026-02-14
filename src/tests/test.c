#include "test.h"

int main() {    
    int number_failed = 0;
    SRunner *sr = srunner_create(NULL);

    srunner_add_suite(sr, test_str_arithmetic());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return !number_failed ? 0 : 1;
}