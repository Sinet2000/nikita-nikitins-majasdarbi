#ifndef core_file_h
#define core_file_h

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include "utils/input_validators.h"
#include "utils/program_utils.h"
#include "utils/math_utils.h"
#include "utils/file_util.h"
#include "utils/vector_utils.h"
#include "utils/output_utils.h"

// enums
#include "utils/enums/DefaultMenuItem.h"


class ProgramConstants {
    
    public:
        static constexpr const char* TEXT_FILE_EXT = ".txt";
        static constexpr const char* BIN_FILE_EXT = ".bin";

        static constexpr const char* FIRST_PROGRAM_FILENAME = "file-task1.txt";
        static constexpr const char* SECOND_PROGRAM_FILENAME = "file2.txt";
        static constexpr const char* SECOND_ADDITIONAL_TASK_FILENAME = "file2_1.txt";
};

#endif