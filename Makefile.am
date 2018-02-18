bin_PROGRAMS = code-sample

common_source_files = \
	src/Cmd.cpp \
	src/Cmd.hpp \
	src/docEvent.hpp \
	src/Observer.hpp \
	src/Index.cpp \
	src/Index.hpp \
	src/Indexer.cpp \
	src/Indexer.hpp \
	src/Storage.cpp \
	src/Storage.hpp \
	src/stringutility.hpp

code_sample_SOURCES = \
	$(common_source_files) \
	src/main.cpp

# For building GoogleTest
ACLOCAL_AMFLAGS = -I m4
check_LTLIBRARIES = tests/libgtest.la
tests_libgtest_la_SOURCES = googletest/googletest/src/gtest-all.cc
tests_libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest -pthread
tests_libgtest_la_LDFLAGS = -pthread

check_PROGRAMS = code-sample-test

code_sample_test_SOURCES = \
       tests/Cmd_test.cpp \
       $(common_source_files)
code_sample_test_LDADD = tests/libgtest.la
code_sample_test_LDFLAGS = -pthread
code_sample_test_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/src

TESTS = code-sample-test
