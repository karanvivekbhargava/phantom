#pragma once

#ifdef PHTM_ENABLE_ASSERTS
    #define PHTM_ASSERT(x, ...) {if(!(x)) {PHTM_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); }}
    #define PHTM_CORE_ASSERT(x, ...) { if(!(x)) {PHTM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); }}
#else
    #define PHTM_ASSERT(x, ...)
    #define PHTM_CORE_ASSERT(x, ...)
#endif

//#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
#define float32_t float
#define float64_t double
#define BIT(x) (1<<x)
