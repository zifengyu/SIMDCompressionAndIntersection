/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_UTIL_H_
#define SIMDCompressionAndIntersection_UTIL_H_

#include "common.h"

namespace SIMDCompressionLib {

inline uint32_t random(int b) {
  if (b == 32)
    return rand();
  return rand() % (1U << b);
}

// taken from stackoverflow
#ifndef NDEBUG
#define ASSERT(condition, message)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "Assertion `" #condition "` failed in " << __FILE__         \
                << " line " << __LINE__ << ": " << message << std::endl;       \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (false)
#else
#define ASSERT(condition, message)                                             \
  do {                                                                         \
  } while (false)
#endif

CONST_FUNCTION
inline uint32_t gccbits(const uint32_t v) {
  return v == 0 ? 0 : 32 - __builtin_clz(v);
}

static CONST_FUNCTION bool divisibleby(size_t a, uint32_t x) {
  return (a % x == 0);
}

#ifdef __GNUC__
__attribute__((unused))
#endif
static void
checkifdivisibleby(size_t a, uint32_t x) {
  if (!divisibleby(a, x)) {
    std::ostringstream convert;
    convert << a << " not divisible by " << x;
    throw std::logic_error(convert.str());
  }
}

template <class iterator>
PURE_FUNCTION uint32_t maxbits(const iterator &begin, const iterator &end) {
  uint32_t accumulator = 0;
  for (iterator k = begin; k != end; ++k) {
    accumulator |= *k;
  }
  return gccbits(accumulator);
}

template <class T>
CONST_FUNCTION inline bool needPaddingTo128Bits(const T *inbyte) {
  return (reinterpret_cast<uintptr_t>(inbyte) & 15) != 0;
}

template <class T>
CONST_FUNCTION inline bool needPaddingTo32Bits(const T *inbyte) {
  return (reinterpret_cast<uintptr_t>(inbyte) & 3) != 0;
}

template <class T> CONST_FUNCTION T *padTo32bits(T *inbyte) {
  return reinterpret_cast<T *>((reinterpret_cast<uintptr_t>(inbyte) + 3) & ~3);
}

template <class T> CONST_FUNCTION const T *padTo32bits(const T *inbyte) {
  return reinterpret_cast<const T *>((reinterpret_cast<uintptr_t>(inbyte) + 3) &
                                     ~3);
}

template <class iterator>
bool is_strictlysorted(iterator first, iterator last) {
  iterator next = first;
  ++next;
  while (next < last) {
    if (*first >= *next)
      return false;
    ++first;
    ++next;
  }
  return true;
}
} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_UTIL_H_ */
