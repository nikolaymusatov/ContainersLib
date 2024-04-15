CORES := $(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 1)

all: s21_containers.a

s21_containers.a:
	mkdir -p "build"
	cd build && cmake .. && cmake --build . --target s21_containers -- -j$(CORES) && cp s21_containers.a ..

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

style_test:
	find . -type f -name 's21*' -o -name 'test_s21*' -exec clang-format -n {} \;

style_format:
	find . -type f -name 's21*' -o -name 'test_s21*' -exec clang-format -i {} \;

clean:
	rm -rf build s21_containers.a