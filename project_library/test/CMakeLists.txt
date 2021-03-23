# -----------------------------------------------------------------------------
# TEST 1 (This one uses the dataset from file)
# -----------------------------------------------------------------------------
# Add the test.
add_executable(test_1_executable
    test_1.cpp
)
# Liking for the test.
target_link_libraries(test_1_executable
    approximath
)
add_test(test_1 test_1_executable ${CMAKE_SOURCE_DIR}/data/dataset_0.txt)

# -----------------------------------------------------------------------------
# TEST 1 (This one uses a dataset inside the code)
# -----------------------------------------------------------------------------
# Add the test.
add_executable(test_2_executable
    test_2.cpp
)
# Liking for the test.
target_link_libraries(test_2_executable
    approximath
)
add_test(test_2 test_2_executable)
