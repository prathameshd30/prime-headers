add_executable(vector_primitive_test vector_primitive_test.c)
add_test(vector_primitive_test vector_primitive_test)

add_executable(vector_struct_test vector_struct_test.c)
add_test(vector_struct_test vector_struct_test)

add_link_options(prime-headers
    BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address
)