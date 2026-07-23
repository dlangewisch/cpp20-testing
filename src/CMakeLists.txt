
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
# find_package(Eigen3 CONFIG REQUIRED)

add_executable(test1)
target_sources(test1 PRIVATE test1.cpp)
target_link_libraries(test1
  PRIVATE
    fmt::fmt
    spdlog::spdlog
)

set_target_properties(test1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_compile_features(test1
  PRIVATE
    # cxx_std_17
    cxx_std_20
)

install(
  TARGETS
    test1
  RUNTIME
    COMPONENT Runtime
    DESTINATION "${CMAKE_INSTALL_BINDIR}"
  # OPTIONAL
)
