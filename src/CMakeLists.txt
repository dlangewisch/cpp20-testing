
# find_package(fmt CONFIG REQUIRED)
# find_package(Eigen3 CONFIG REQUIRED)
# find_package(Boost REQUIRED COMPONENTS graph CONFIG)

add_executable(test1)
target_sources(test1 PRIVATE test1.cpp)
# target_link_libraries(test
#   PRIVATE
#     Eigen3::Eigen
#     fmt::fmt
#     Boost::graph
# )
set_target_properties(test1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

install(
  TARGETS
    test1
  RUNTIME
    COMPONENT Runtime
    DESTINATION "${CMAKE_INSTALL_BINDIR}"
  # OPTIONAL
)
