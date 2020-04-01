add_executable(test-unit "")

target_sources(
		test-unit
		PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/gtest_main.cpp
		)

target_link_libraries(
		test-unit
		PRIVATE
		GTest::GTest
		GTest::Main
)

target_include_directories(test-unit
		PRIVATE
		$<INSTALL_INTERFACE:include>
		${CMAKE_CURRENT_BINARY_DIR}
		)

target_compile_definitions(
		test-unit
		PRIVATE
		"COMPONENT=\"${TARGET}\""
		"MOCKABLE=virtual"
)

add_test(all_unit_tests test-unit)