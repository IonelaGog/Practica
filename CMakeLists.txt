cmake_minimum_required(VERSION 3.10.0)

project(practica)

### Local Variables ###

set(SOURCES
	Main.cpp    
)

set(HEADERS 
    include/Vector.hpp
    include/List.hpp
	include/ListNode.hpp
	include/Queue.hpp
	include/PriorityQueue.hpp
	include/Task.hpp
	include/VectorIteraror.hpp
	include/ListIterator.hpp
	include/SynchPriorityQueue.hpp
	include/TaskArgument.hpp
	include/TaskResult.hpp
	include/TaskScheduler.hpp
)

set(INCLUDE_DIRECTORIES
	PUBLIC include/
)

### Test Targets ###
# add_executable(vector_test_target VectorTest.cpp)
# target_include_directories(vector_test_target ${INCLUDE_DIRECTORIES})
# target_compile_options(vector_test_target PUBLIC -fprofile-instr-generate -fcoverage-mapping)
# target_link_libraries(vector_test_target PRIVATE -fprofile-instr-generate -fcoverage-mapping )

# add_test(vector_unit_test vector_test_target)

# enable_testing()


### Main Target ###

add_executable(RELEASE ${SOURCES})
target_compile_options(RELEASE PUBLIC -std=c++20 -Wall -Wextra -Wpedantic -Werror -O3 -pthread)
target_include_directories(RELEASE ${INCLUDE_DIRECTORIES})
target_link_libraries(RELEASE PRIVATE -lpthread)


add_executable(DEBUG ${SOURCES})
target_compile_options(DEBUG PUBLIC -std=c++20 -Wall -Wextra -Wpedantic -Werror -Og -g -pthread)
target_include_directories(DEBUG ${INCLUDE_DIRECTORIES})
target_link_libraries(DEBUG PRIVATE -lpthread)

### Custom Targets ###