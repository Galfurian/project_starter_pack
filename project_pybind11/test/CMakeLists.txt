# -----------------------------------------------------------------------------
# TEST 1
# -----------------------------------------------------------------------------
# Add the first test.
add_test(
    NAME test_1
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_1.py
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
# We need to tell the python script where our library is.
set_tests_properties(test_1 PROPERTIES ENVIRONMENT "PYTHONPATH=${PYTHONPATH}:${CMAKE_BINARY_DIR}")

# -----------------------------------------------------------------------------
# TEST 2
# -----------------------------------------------------------------------------
# Add the first test.
add_test(
    NAME test_2
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_2.py
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
# We need to tell the python script where our library is.
set_tests_properties(test_2 PROPERTIES ENVIRONMENT "PYTHONPATH=${PYTHONPATH}:${CMAKE_BINARY_DIR}")
