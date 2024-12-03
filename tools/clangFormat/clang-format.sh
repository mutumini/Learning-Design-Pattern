find ../src/ -name "*.h"   | xargs clang-format -i -style=file
find ../src/ -name "*.cpp" | xargs clang-format -i -style=file
find ../tests/ -name "*.cpp" | xargs clang-format -i -style=file