#include "grid_color.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

int main(){

	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("same_colour", 0, 0);
	CU_pSuite suite2 = CU_add_suite("init_grid", 0, 0);
	CU_pSuite suite3 = CU_add_suite("set_grid", 0, 0);
	CU_pSuite suite4 = CU_add_suite("file", 0, 0);
	CU_pSuite suite5 = CU_add_suite("tache", 0, 0);

	CU_add_test(suite, "same_color", test_test_same_colour);
	CU_add_test(suite2, "init_random", test_init_grid);
	CU_add_test(suite2, "init_file", test_init_grid_file);
	CU_add_test(suite3, "set_grid", test_set_grid);
	CU_add_test(suite4, "fill_file", test_fill_file);
	CU_add_test(suite4, "fill_file_grid", test_fill_file_grid);
	CU_add_test(suite5, "indentiftache", test_detect_flood);
	CU_add_test(suite5, "changecolor", test_change_color);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}
