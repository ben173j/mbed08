#ifndef CONFIG_H_
#define CONFIG_H_

// The number of labels (without negative)
#define label_num 2

struct Config {

  // This must be the same as seq_length in the src/model_train/config.py
  const int seq_length = 64;

  // The number of expected consecutive inferences for each gesture type.
  const int consecutiveInferenceThresholds[label_num] = {20, 10};

  const char* output_message[label_num] = {
        "RING:\n\r"
        "          *       \n\r"
        "       *     *    \n\r"
        "     *         *  \n\r"
        "    *           * \n\r"
        "     *         *  \n\r"
        "       *     *    \n\r"
        "          *       \n\r",
        "SLOPE:\n\r"
        "        *        \n\r"
        "       *         \n\r"
        "      *          \n\r"
        "     *           \n\r"
        "    *            \n\r"
        "   *             \n\r"
        "  *              \n\r"
        " * * * * * * * * \n\r"};
};

Config config;
#endif // CONFIG_H_
Create a new build profile tflite.json for compiling TensorFlow Lite.

$ code tflite.json

{
    "GCC_ARM": {
        "common": ["-Wall", "-Wextra",
                   "-Wno-unused-parameter", "-Wno-missing-field-initializers",
                   "-fmessage-length=0", "-fno-exceptions",
                   "-ffunction-sections", "-fdata-sections", "-funsigned-char",
                   "-MMD",
                   "-fomit-frame-pointer", "-Os", "-DNDEBUG", "-g"],
        "asm": ["-c", "-x", "assembler-with-cpp"],
        "c": ["-c", "-std=gnu11"],
        "cxx": ["-c", "-std=gnu++14", "-fpermissive", "-fno-rtti", "-Wvla"],
        "ld": ["-Wl,--gc-sections", "-Wl,--wrap,main", "-Wl,--wrap,_malloc_r",
               "-Wl,--wrap,_free_r", "-Wl,--wrap,_realloc_r", "-Wl,--wrap,_memalign_r",
               "-Wl,--wrap,_calloc_r", "-Wl,--wrap,exit", "-Wl,--wrap,atexit",
               "-Wl,-n"]
    }
}