file(COPY .clang-format DESTINATION ${CMAKE_BINARY_DIR})
file(COPY clang-format.sh DESTINATION ${CMAKE_BINARY_DIR})
execute_process(
  COMMAND ./clang-format.sh
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
