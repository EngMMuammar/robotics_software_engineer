cmake_minimum_required(VERSION 3.8)
project(module_1_assignment)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)


add_executable(task1 src/task1.cpp)
install(TARGETS task1
  DESTINATION lib/${PROJECT_NAME}
)

add_executable(task2 src/task2.cpp)
install(TARGETS task2
  DESTINATION lib/${PROJECT_NAME}
)


include_directories(include)

add_executable(task3
  src/task3/main.cpp
)

ament_target_dependencies(task3)

install(TARGETS task3
  DESTINATION lib/${PROJECT_NAME}
)



add_executable(task4_robot_actuators
  src/Actuator.cpp
  src/Robot.cpp
  src/main.cpp
)

install(TARGETS task4_robot_actuators
  DESTINATION lib/${PROJECT_NAME}
)

# Install header files
install(DIRECTORY include/
  DESTINATION include/
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
