# FLAGS
# =====

# СodeForces c++17 flags
# ----------------------
# See https://codeforces.com/blog/entry/57646 (ru)
# Stack size is increased like here because I have Mac OS X
# https://stackoverflow.com/questions/10214363/increase-stack-size-in-os-x-lion
MY_FLAGS = -Wl,-stack_size -Wl,260000000 -O2 -std=c++17

# Flags that help catching errors
# -------------------------------
# Adapted from https://codeforces.com/blog/entry/15547 (ru)
# See also documentation about the warning flags
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html

MY_FLAGS += -Wall -Wextra

MY_FLAGS += -pedantic -Wshadow -Wformat=2 -Wfloat-equal

# If you don't want to get warnings just about signed/unsigned conversion
# you may use -Wno-sign-conversion with -Wconversion
# But I just don't want -Wconversion
# MY_FLAGS += -Wconversion

MY_FLAGS += -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond

# Instead of -Wcast-qual -Wcast-align I just forbid old style cast
# I use safe static_cast instead
MY_FLAGS += -Wold-style-cast

# Too slow, strange stack trace
# MY_FLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

MY_FLAGS += -D_FORTIFY_SOURCE=2
MY_FLAGS += -fsanitize=address,undefined -fno-sanitize-recover -fstack-protector

# COMPILATION
# ===========

a.out: main.cpp
	$(CXX) $< $(MY_FLAGS)