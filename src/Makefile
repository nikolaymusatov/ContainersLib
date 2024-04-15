CORES := $(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 1)

all: containers.a

containers.a:
	mkdir -p "build"
	cd build && cmake .. && cmake --build . --target containers -- -j$(CORES) && cp containers.a ..

build_test:
	mkdir -p "build"
	cd build && cmake .. && cmake --build . --target tests_run -- -j$(CORES)

test: build_test
	cd build && ./tests_run

test_leaks:
	mkdir -p "build"
	cd build && cmake .. && cmake --build . --target test_leaks -- -j$(CORES)

gcov_report: build_test
	cd build && make coverage_report

open_report:
	open build/coverage.html

clean:
	rm -rf build containers.a