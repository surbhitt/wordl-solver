set -xe
if pkg-config --exists gtest; then
    clang++ -D_GTEST -o tests test.cpp -lgtest -lgtest_main -pthread
 ./tests
else
    echo "Google Test not found, _GTEST will not be defined"
    exit
fi
