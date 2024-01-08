#!/usr/bin/env sh
set -xe

# Unpackageable modules:
#	ranges
#	span
#	mdspan (not found)
#	spanstream
#	print (not found)
#	execution

# Miscellaneous
for h in memory iterator chrono locale filesystem regex ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# Utilities
for h in format utility tuple optional expected variant any charconv bitset compare functional limits typeinfo ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# Diagnostics
for h in exception stacktrace ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# Strings
for h in string string_view cctype cstring ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# Containers
for h in array vector deque "set" map unordered_map unordered_set stack queue ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# Calculations
for h in algorithm numeric complex valarray ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# C
for h in cstdlib cinttypes cstddef clocale ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# IO
for h in ios streambuf ostream istream fstream sstream syncstream iostream iosfwd ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done

# Concurrency
for h in thread stop_token new atomic mutex shared_mutex condition_variable semaphore latch barrier future ; do \
	g++ -std=gnu++2b -fmodules-ts -x c++-system-header $h ; \
done
