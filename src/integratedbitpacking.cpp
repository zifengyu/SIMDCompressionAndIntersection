/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#include "integratedbitpacking.h"

namespace SIMDCompressionLib
{

  void __integratedfastunpack0(const uint32_t initoffset,
                               const uint32_t *__restrict__,
                               uint32_t *__restrict__ out)
  {
    for (uint32_t i = 0; i < 128; ++i)
      *(out++) = initoffset;
  }
  void __integratedfastpack0(const uint32_t, const uint32_t *__restrict__,
                             uint32_t *__restrict__) {}

  void __integratedfastunpack32(const uint32_t, const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    for (int k = 0; k < 128; ++k)
      out[k] = in[k]; // no sense in wasting time with deltas
  }

  void __integratedfastpack32(const uint32_t, const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    for (int k = 0; k < 128; ++k)
      out[k] = in[k]; // no sense in wasting time with deltas
  }

  void __integratedfastunpack2(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 2);
      out += 4;
      *out = (*in >> 2) % (1U << 2);

      out += 4;
      *out = (*in >> 4) % (1U << 2);

      out += 4;
      *out = (*in >> 6) % (1U << 2);

      out += 4;
      *out = (*in >> 8) % (1U << 2);

      out += 4;
      *out = (*in >> 10) % (1U << 2);

      out += 4;
      *out = (*in >> 12) % (1U << 2);

      out += 4;
      *out = (*in >> 14) % (1U << 2);

      out += 4;
      *out = (*in >> 16) % (1U << 2);

      out += 4;
      *out = (*in >> 18) % (1U << 2);

      out += 4;
      *out = (*in >> 20) % (1U << 2);

      out += 4;
      *out = (*in >> 22) % (1U << 2);

      out += 4;
      *out = (*in >> 24) % (1U << 2);

      out += 4;
      *out = (*in >> 26) % (1U << 2);

      out += 4;
      *out = (*in >> 28) % (1U << 2);

      out += 4;
      *out = (*in >> 30);

      in += 4;
      out += 4;
      *out = (*in >> 0) % (1U << 2);

      out += 4;
      *out = (*in >> 2) % (1U << 2);

      out += 4;
      *out = (*in >> 4) % (1U << 2);

      out += 4;
      *out = (*in >> 6) % (1U << 2);

      out += 4;
      *out = (*in >> 8) % (1U << 2);

      out += 4;
      *out = (*in >> 10) % (1U << 2);

      out += 4;
      *out = (*in >> 12) % (1U << 2);

      out += 4;
      *out = (*in >> 14) % (1U << 2);

      out += 4;
      *out = (*in >> 16) % (1U << 2);

      out += 4;
      *out = (*in >> 18) % (1U << 2);

      out += 4;
      *out = (*in >> 20) % (1U << 2);

      out += 4;
      *out = (*in >> 22) % (1U << 2);

      out += 4;
      *out = (*in >> 24) % (1U << 2);

      out += 4;
      *out = (*in >> 26) % (1U << 2);

      out += 4;
      *out = (*in >> 28) % (1U << 2);

      out += 4;
      *out = (*in >> 30);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack3(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 3);
      out += 4;
      *out = (*in >> 3) % (1U << 3);
      out += 4;
      *out = (*in >> 6) % (1U << 3);
      out += 4;
      *out = (*in >> 9) % (1U << 3);
      out += 4;
      *out = (*in >> 12) % (1U << 3);
      out += 4;
      *out = (*in >> 15) % (1U << 3);
      out += 4;
      *out = (*in >> 18) % (1U << 3);

      out += 4;
      *out = (*in >> 21) % (1U << 3);

      out += 4;
      *out = (*in >> 24) % (1U << 3);

      out += 4;
      *out = (*in >> 27) % (1U << 3);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 1)) << (3 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 3);

      out += 4;
      *out = (*in >> 4) % (1U << 3);

      out += 4;
      *out = (*in >> 7) % (1U << 3);

      out += 4;
      *out = (*in >> 10) % (1U << 3);

      out += 4;
      *out = (*in >> 13) % (1U << 3);

      out += 4;
      *out = (*in >> 16) % (1U << 3);

      out += 4;
      *out = (*in >> 19) % (1U << 3);

      out += 4;
      *out = (*in >> 22) % (1U << 3);

      out += 4;
      *out = (*in >> 25) % (1U << 3);

      out += 4;
      *out = (*in >> 28) % (1U << 3);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 2)) << (3 - 2);
      out += 4;
      *out = (*in >> 2) % (1U << 3);

      out += 4;
      *out = (*in >> 5) % (1U << 3);

      out += 4;
      *out = (*in >> 8) % (1U << 3);

      out += 4;
      *out = (*in >> 11) % (1U << 3);

      out += 4;
      *out = (*in >> 14) % (1U << 3);

      out += 4;
      *out = (*in >> 17) % (1U << 3);
      out += 4;
      *out = (*in >> 20) % (1U << 3);

      out += 4;
      *out = (*in >> 23) % (1U << 3);

      out += 4;
      *out = (*in >> 26) % (1U << 3);

      out += 4;
      *out = (*in >> 29);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack5(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 5);
      out += 4;
      *out = (*in >> 5) % (1U << 5);

      out += 4;
      *out = (*in >> 10) % (1U << 5);

      out += 4;
      *out = (*in >> 15) % (1U << 5);

      out += 4;
      *out = (*in >> 20) % (1U << 5);

      out += 4;
      *out = (*in >> 25) % (1U << 5);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 3)) << (5 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 5);

      out += 4;
      *out = (*in >> 8) % (1U << 5);

      out += 4;
      *out = (*in >> 13) % (1U << 5);

      out += 4;
      *out = (*in >> 18) % (1U << 5);

      out += 4;
      *out = (*in >> 23) % (1U << 5);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 1)) << (5 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 5);

      out += 4;
      *out = (*in >> 6) % (1U << 5);

      out += 4;
      *out = (*in >> 11) % (1U << 5);

      out += 4;
      *out = (*in >> 16) % (1U << 5);

      out += 4;
      *out = (*in >> 21) % (1U << 5);

      out += 4;
      *out = (*in >> 26) % (1U << 5);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 4)) << (5 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 5);

      out += 4;
      *out = (*in >> 9) % (1U << 5);

      out += 4;
      *out = (*in >> 14) % (1U << 5);

      out += 4;
      *out = (*in >> 19) % (1U << 5);

      out += 4;
      *out = (*in >> 24) % (1U << 5);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 2)) << (5 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 5);

      out += 4;
      *out = (*in >> 7) % (1U << 5);

      out += 4;
      *out = (*in >> 12) % (1U << 5);

      out += 4;
      *out = (*in >> 17) % (1U << 5);

      out += 4;
      *out = (*in >> 22) % (1U << 5);

      out += 4;
      *out = (*in >> 27);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack6(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 6);
      out += 4;
      *out = (*in >> 6) % (1U << 6);

      out += 4;
      *out = (*in >> 12) % (1U << 6);

      out += 4;
      *out = (*in >> 18) % (1U << 6);

      out += 4;
      *out = (*in >> 24) % (1U << 6);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 4)) << (6 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 6);

      out += 4;
      *out = (*in >> 10) % (1U << 6);

      out += 4;
      *out = (*in >> 16) % (1U << 6);

      out += 4;
      *out = (*in >> 22) % (1U << 6);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 2)) << (6 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 6);

      out += 4;
      *out = (*in >> 8) % (1U << 6);

      out += 4;
      *out = (*in >> 14) % (1U << 6);

      out += 4;
      *out = (*in >> 20) % (1U << 6);

      out += 4;
      *out = (*in >> 26);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 6);

      out += 4;
      *out = (*in >> 6) % (1U << 6);

      out += 4;
      *out = (*in >> 12) % (1U << 6);

      out += 4;
      *out = (*in >> 18) % (1U << 6);

      out += 4;
      *out = (*in >> 24) % (1U << 6);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 4)) << (6 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 6);

      out += 4;
      *out = (*in >> 10) % (1U << 6);

      out += 4;
      *out = (*in >> 16) % (1U << 6);

      out += 4;
      *out = (*in >> 22) % (1U << 6);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 2)) << (6 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 6);

      out += 4;
      *out = (*in >> 8) % (1U << 6);

      out += 4;
      *out = (*in >> 14) % (1U << 6);

      out += 4;
      *out = (*in >> 20) % (1U << 6);

      out += 4;
      *out = (*in >> 26);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack7(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 7);
      out += 4;
      *out = (*in >> 7) % (1U << 7);
      out += 4;
      *out = (*in >> 14) % (1U << 7);

      out += 4;
      *out = (*in >> 21) % (1U << 7);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 3)) << (7 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 7);

      out += 4;
      *out = (*in >> 10) % (1U << 7);

      out += 4;
      *out = (*in >> 17) % (1U << 7);

      out += 4;
      *out = (*in >> 24) % (1U << 7);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 6)) << (7 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 7);

      out += 4;
      *out = (*in >> 13) % (1U << 7);

      out += 4;
      *out = (*in >> 20) % (1U << 7);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 2)) << (7 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 7);

      out += 4;
      *out = (*in >> 9) % (1U << 7);

      out += 4;
      *out = (*in >> 16) % (1U << 7);

      out += 4;
      *out = (*in >> 23) % (1U << 7);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 5)) << (7 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 7);

      out += 4;
      *out = (*in >> 12) % (1U << 7);

      out += 4;
      *out = (*in >> 19) % (1U << 7);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 1)) << (7 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 7);

      out += 4;
      *out = (*in >> 8) % (1U << 7);

      out += 4;
      *out = (*in >> 15) % (1U << 7);

      out += 4;
      *out = (*in >> 22) % (1U << 7);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 4)) << (7 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 7);

      out += 4;
      *out = (*in >> 11) % (1U << 7);

      out += 4;
      *out = (*in >> 18) % (1U << 7);

      out += 4;
      *out = (*in >> 25);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack9(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 9);
      out += 4;
      *out = (*in >> 9) % (1U << 9);

      out += 4;
      *out = (*in >> 18) % (1U << 9);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 4)) << (9 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 9);

      out += 4;
      *out = (*in >> 13) % (1U << 9);

      out += 4;
      *out = (*in >> 22) % (1U << 9);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 8)) << (9 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 9);

      out += 4;
      *out = (*in >> 17) % (1U << 9);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 3)) << (9 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 9);

      out += 4;
      *out = (*in >> 12) % (1U << 9);

      out += 4;
      *out = (*in >> 21) % (1U << 9);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 7)) << (9 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 9);

      out += 4;
      *out = (*in >> 16) % (1U << 9);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 2)) << (9 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 9);

      out += 4;
      *out = (*in >> 11) % (1U << 9);

      out += 4;
      *out = (*in >> 20) % (1U << 9);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 6)) << (9 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 9);

      out += 4;
      *out = (*in >> 15) % (1U << 9);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 1)) << (9 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 9);

      out += 4;
      *out = (*in >> 10) % (1U << 9);

      out += 4;
      *out = (*in >> 19) % (1U << 9);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 5)) << (9 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 9);

      out += 4;
      *out = (*in >> 14) % (1U << 9);

      out += 4;
      *out = (*in >> 23);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack10(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 10);
      out += 4;
      *out = (*in >> 10) % (1U << 10);

      out += 4;
      *out = (*in >> 20) % (1U << 10);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 8)) << (10 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 10);

      out += 4;
      *out = (*in >> 18) % (1U << 10);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 6)) << (10 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 10);

      out += 4;
      *out = (*in >> 16) % (1U << 10);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 4)) << (10 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 10);

      out += 4;
      *out = (*in >> 14) % (1U << 10);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 2)) << (10 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 10);

      out += 4;
      *out = (*in >> 12) % (1U << 10);

      out += 4;
      *out = (*in >> 22);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 10);

      out += 4;
      *out = (*in >> 10) % (1U << 10);

      out += 4;
      *out = (*in >> 20) % (1U << 10);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 8)) << (10 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 10);

      out += 4;
      *out = (*in >> 18) % (1U << 10);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 6)) << (10 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 10);

      out += 4;
      *out = (*in >> 16) % (1U << 10);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 4)) << (10 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 10);

      out += 4;
      *out = (*in >> 14) % (1U << 10);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 2)) << (10 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 10);

      out += 4;
      *out = (*in >> 12) % (1U << 10);

      out += 4;
      *out = (*in >> 22);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack11(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 11);
      out += 4;
      *out = (*in >> 11) % (1U << 11);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 1)) << (11 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 11);

      out += 4;
      *out = (*in >> 12) % (1U << 11);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 2)) << (11 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 11);

      out += 4;
      *out = (*in >> 13) % (1U << 11);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 3)) << (11 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 11);

      out += 4;
      *out = (*in >> 14) % (1U << 11);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 4)) << (11 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 11);

      out += 4;
      *out = (*in >> 15) % (1U << 11);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 5)) << (11 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 11);

      out += 4;
      *out = (*in >> 16) % (1U << 11);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 6)) << (11 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 11);

      out += 4;
      *out = (*in >> 17) % (1U << 11);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 7)) << (11 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 11);

      out += 4;
      *out = (*in >> 18) % (1U << 11);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 8)) << (11 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 11);

      out += 4;
      *out = (*in >> 19) % (1U << 11);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 9)) << (11 - 9);

      out += 4;
      *out = (*in >> 9) % (1U << 11);

      out += 4;
      *out = (*in >> 20) % (1U << 11);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 10)) << (11 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 11);

      out += 4;
      *out = (*in >> 21);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack12(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 12);
      out += 4;
      *out = (*in >> 12) % (1U << 12);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 4)) << (12 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 12);

      out += 4;
      *out = (*in >> 16) % (1U << 12);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 8)) << (12 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 12);

      out += 4;
      *out = (*in >> 20);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 12);

      out += 4;
      *out = (*in >> 12) % (1U << 12);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 4)) << (12 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 12);

      out += 4;
      *out = (*in >> 16) % (1U << 12);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 8)) << (12 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 12);

      out += 4;
      *out = (*in >> 20);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 12);

      out += 4;
      *out = (*in >> 12) % (1U << 12);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 4)) << (12 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 12);

      out += 4;
      *out = (*in >> 16) % (1U << 12);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 8)) << (12 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 12);

      out += 4;
      *out = (*in >> 20);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 12);

      out += 4;
      *out = (*in >> 12) % (1U << 12);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 4)) << (12 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 12);

      out += 4;
      *out = (*in >> 16) % (1U << 12);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 8)) << (12 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 12);

      out += 4;
      *out = (*in >> 20);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack13(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {

    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 13);
      out += 4;
      *out = (*in >> 13) % (1U << 13);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 7)) << (13 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 13);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 1)) << (13 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 13);

      out += 4;
      *out = (*in >> 14) % (1U << 13);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 8)) << (13 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 13);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 2)) << (13 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 13);

      out += 4;
      *out = (*in >> 15) % (1U << 13);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 9)) << (13 - 9);

      out += 4;
      *out = (*in >> 9) % (1U << 13);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 3)) << (13 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 13);

      out += 4;
      *out = (*in >> 16) % (1U << 13);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 10)) << (13 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 13);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 4)) << (13 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 13);

      out += 4;
      *out = (*in >> 17) % (1U << 13);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 11)) << (13 - 11);

      out += 4;
      *out = (*in >> 11) % (1U << 13);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 5)) << (13 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 13);

      out += 4;
      *out = (*in >> 18) % (1U << 13);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 12)) << (13 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 13);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 6)) << (13 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 13);

      out += 4;
      *out = (*in >> 19);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack14(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {

    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 14);
      out += 4;
      *out = (*in >> 14) % (1U << 14);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 10)) << (14 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 14);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 6)) << (14 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 14);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 2)) << (14 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 14);

      out += 4;
      *out = (*in >> 16) % (1U << 14);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 12)) << (14 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 14);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 8)) << (14 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 14);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 4)) << (14 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 14);

      out += 4;
      *out = (*in >> 18);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 14);

      out += 4;
      *out = (*in >> 14) % (1U << 14);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 10)) << (14 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 14);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 6)) << (14 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 14);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 2)) << (14 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 14);

      out += 4;
      *out = (*in >> 16) % (1U << 14);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 12)) << (14 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 14);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 8)) << (14 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 14);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 4)) << (14 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 14);

      out += 4;
      *out = (*in >> 18);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack15(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 15);
      out += 4;
      *out = (*in >> 15) % (1U << 15);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 13)) << (15 - 13);

      out += 4;
      *out = (*in >> 13) % (1U << 15);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 11)) << (15 - 11);

      out += 4;
      *out = (*in >> 11) % (1U << 15);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 9)) << (15 - 9);

      out += 4;
      *out = (*in >> 9) % (1U << 15);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 7)) << (15 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 15);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 5)) << (15 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 15);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 3)) << (15 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 15);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 1)) << (15 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 15);

      out += 4;
      *out = (*in >> 16) % (1U << 15);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 14)) << (15 - 14);

      out += 4;
      *out = (*in >> 14) % (1U << 15);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 12)) << (15 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 15);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 10)) << (15 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 15);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 8)) << (15 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 15);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 6)) << (15 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 15);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 4)) << (15 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 15);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 2)) << (15 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 15);

      out += 4;
      *out = (*in >> 17);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack17(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 17);
      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 2)) << (17 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 17);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 4)) << (17 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 17);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 6)) << (17 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 17);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 8)) << (17 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 17);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 10)) << (17 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 17);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 12)) << (17 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 17);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 14)) << (17 - 14);

      out += 4;
      *out = (*in >> 14) % (1U << 17);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 16)) << (17 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 1)) << (17 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 17);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 3)) << (17 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 17);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 5)) << (17 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 17);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 7)) << (17 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 17);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 9)) << (17 - 9);

      out += 4;
      *out = (*in >> 9) % (1U << 17);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 11)) << (17 - 11);

      out += 4;
      *out = (*in >> 11) % (1U << 17);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 13)) << (17 - 13);

      out += 4;
      *out = (*in >> 13) % (1U << 17);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 15)) << (17 - 15);

      out += 4;
      *out = (*in >> 15);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack18(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {

    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 18);
      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 4)) << (18 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 18);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 8)) << (18 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 18);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 12)) << (18 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 18);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 16)) << (18 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 2)) << (18 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 18);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 6)) << (18 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 18);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 10)) << (18 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 18);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 14)) << (18 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 4)) << (18 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 18);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 8)) << (18 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 18);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 12)) << (18 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 18);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 16)) << (18 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 2)) << (18 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 18);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 6)) << (18 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 18);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 10)) << (18 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 18);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 14)) << (18 - 14);

      out += 4;
      *out = (*in >> 14);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack19(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 19);
      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 6)) << (19 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 19);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 12)) << (19 - 12);

      out += 4;
      *out = (*in >> 12) % (1U << 19);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 18)) << (19 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 5)) << (19 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 19);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 11)) << (19 - 11);

      out += 4;
      *out = (*in >> 11) % (1U << 19);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 17)) << (19 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 4)) << (19 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 19);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 10)) << (19 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 19);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 16)) << (19 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 3)) << (19 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 19);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 9)) << (19 - 9);

      out += 4;
      *out = (*in >> 9) % (1U << 19);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 15)) << (19 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 2)) << (19 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 19);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 8)) << (19 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 19);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 14)) << (19 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 1)) << (19 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 19);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 7)) << (19 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 19);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 13)) << (19 - 13);

      out += 4;
      *out = (*in >> 13);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack20(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 20);
      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 8)) << (20 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 20);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 16)) << (20 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 4)) << (20 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 20);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 12)) << (20 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 8)) << (20 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 20);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 16)) << (20 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 4)) << (20 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 20);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 12)) << (20 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 8)) << (20 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 20);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 16)) << (20 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 4)) << (20 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 20);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 12)) << (20 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 8)) << (20 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 20);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 16)) << (20 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 4)) << (20 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 20);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 12)) << (20 - 12);

      out += 4;
      *out = (*in >> 12);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack21(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 21);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 10)) << (21 - 10);

      out += 4;
      *out = (*in >> 10) % (1U << 21);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 20)) << (21 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 9)) << (21 - 9);

      out += 4;
      *out = (*in >> 9) % (1U << 21);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 19)) << (21 - 19);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 8)) << (21 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 21);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 18)) << (21 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 7)) << (21 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 21);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 17)) << (21 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 6)) << (21 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 21);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 16)) << (21 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 5)) << (21 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 21);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 15)) << (21 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 4)) << (21 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 21);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 14)) << (21 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 3)) << (21 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 21);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 13)) << (21 - 13);

      out += 4;
      *out = (*in >> 13);
      in += 4;
      *out |= (*in % (1U << 2)) << (21 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 21);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 12)) << (21 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 1)) << (21 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 21);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 11)) << (21 - 11);

      out += 4;
      *out = (*in >> 11);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack22(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 22);
      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 12)) << (22 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 2)) << (22 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 22);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 14)) << (22 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 4)) << (22 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 22);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 16)) << (22 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 6)) << (22 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 22);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 18)) << (22 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 8)) << (22 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 22);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 20)) << (22 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 10)) << (22 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 12)) << (22 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 2)) << (22 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 22);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 14)) << (22 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 4)) << (22 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 22);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 16)) << (22 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 6)) << (22 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 22);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 18)) << (22 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 8)) << (22 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 22);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 20)) << (22 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 10)) << (22 - 10);

      out += 4;
      *out = (*in >> 10);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack23(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 23);
      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 14)) << (23 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 5)) << (23 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 23);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 19)) << (23 - 19);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 10)) << (23 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 1)) << (23 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 23);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 15)) << (23 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 6)) << (23 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 23);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 20)) << (23 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 11)) << (23 - 11);

      out += 4;
      *out = (*in >> 11);
      in += 4;
      *out |= (*in % (1U << 2)) << (23 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 23);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 16)) << (23 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 7)) << (23 - 7);

      out += 4;
      *out = (*in >> 7) % (1U << 23);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 21)) << (23 - 21);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 12)) << (23 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 3)) << (23 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 23);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 17)) << (23 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 8)) << (23 - 8);

      out += 4;
      *out = (*in >> 8) % (1U << 23);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 22)) << (23 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 13)) << (23 - 13);

      out += 4;
      *out = (*in >> 13);
      in += 4;
      *out |= (*in % (1U << 4)) << (23 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 23);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 18)) << (23 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 9)) << (23 - 9);

      out += 4;
      *out = (*in >> 9);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack24(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 24);
      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 16)) << (24 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 8)) << (24 - 8);

      out += 4;
      *out = (*in >> 8);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack25(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 25);
      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 18)) << (25 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 11)) << (25 - 11);

      out += 4;
      *out = (*in >> 11);
      in += 4;
      *out |= (*in % (1U << 4)) << (25 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 25);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 22)) << (25 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 15)) << (25 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 8)) << (25 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 1)) << (25 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 25);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 19)) << (25 - 19);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 12)) << (25 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 5)) << (25 - 5);

      out += 4;
      *out = (*in >> 5) % (1U << 25);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 23)) << (25 - 23);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 16)) << (25 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 9)) << (25 - 9);

      out += 4;
      *out = (*in >> 9);
      in += 4;
      *out |= (*in % (1U << 2)) << (25 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 25);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 20)) << (25 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 13)) << (25 - 13);

      out += 4;
      *out = (*in >> 13);
      in += 4;
      *out |= (*in % (1U << 6)) << (25 - 6);

      out += 4;
      *out = (*in >> 6) % (1U << 25);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 24)) << (25 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 17)) << (25 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 10)) << (25 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 3)) << (25 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 25);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 21)) << (25 - 21);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 14)) << (25 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 7)) << (25 - 7);

      out += 4;
      *out = (*in >> 7);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack26(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 26);
      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 20)) << (26 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 14)) << (26 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 8)) << (26 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 2)) << (26 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 26);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 22)) << (26 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 16)) << (26 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 10)) << (26 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 4)) << (26 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 26);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 24)) << (26 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 18)) << (26 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 12)) << (26 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 6)) << (26 - 6);

      out += 4;
      *out = (*in >> 6);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 26);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 20)) << (26 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 14)) << (26 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 8)) << (26 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 2)) << (26 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 26);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 22)) << (26 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 16)) << (26 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 10)) << (26 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 4)) << (26 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 26);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 24)) << (26 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 18)) << (26 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 12)) << (26 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 6)) << (26 - 6);

      out += 4;
      *out = (*in >> 6);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack27(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 27);
      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 22)) << (27 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 17)) << (27 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 12)) << (27 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 7)) << (27 - 7);

      out += 4;
      *out = (*in >> 7);
      in += 4;
      *out |= (*in % (1U << 2)) << (27 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 27);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 24)) << (27 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 19)) << (27 - 19);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 14)) << (27 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 9)) << (27 - 9);

      out += 4;
      *out = (*in >> 9);
      in += 4;
      *out |= (*in % (1U << 4)) << (27 - 4);

      out += 4;
      *out = (*in >> 4) % (1U << 27);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 26)) << (27 - 26);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 21)) << (27 - 21);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 16)) << (27 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 11)) << (27 - 11);

      out += 4;
      *out = (*in >> 11);
      in += 4;
      *out |= (*in % (1U << 6)) << (27 - 6);

      out += 4;
      *out = (*in >> 6);
      in += 4;
      *out |= (*in % (1U << 1)) << (27 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 27);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 23)) << (27 - 23);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 18)) << (27 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 13)) << (27 - 13);

      out += 4;
      *out = (*in >> 13);
      in += 4;
      *out |= (*in % (1U << 8)) << (27 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 3)) << (27 - 3);

      out += 4;
      *out = (*in >> 3) % (1U << 27);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 25)) << (27 - 25);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 20)) << (27 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 15)) << (27 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 10)) << (27 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 5)) << (27 - 5);

      out += 4;
      *out = (*in >> 5);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack28(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 28);
      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 24)) << (28 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 20)) << (28 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 16)) << (28 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 12)) << (28 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 8)) << (28 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 4)) << (28 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 24)) << (28 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 20)) << (28 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 16)) << (28 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 12)) << (28 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 8)) << (28 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 4)) << (28 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 24)) << (28 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 20)) << (28 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 16)) << (28 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 12)) << (28 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 8)) << (28 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 4)) << (28 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 24)) << (28 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 20)) << (28 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 16)) << (28 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 12)) << (28 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 8)) << (28 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 4)) << (28 - 4);

      out += 4;
      *out = (*in >> 4);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack29(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 29);
      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 26)) << (29 - 26);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 23)) << (29 - 23);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 20)) << (29 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 17)) << (29 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 14)) << (29 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 11)) << (29 - 11);

      out += 4;
      *out = (*in >> 11);
      in += 4;
      *out |= (*in % (1U << 8)) << (29 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 5)) << (29 - 5);

      out += 4;
      *out = (*in >> 5);
      in += 4;
      *out |= (*in % (1U << 2)) << (29 - 2);

      out += 4;
      *out = (*in >> 2) % (1U << 29);

      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 28)) << (29 - 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 25)) << (29 - 25);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 22)) << (29 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 19)) << (29 - 19);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 16)) << (29 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 13)) << (29 - 13);

      out += 4;
      *out = (*in >> 13);
      in += 4;
      *out |= (*in % (1U << 10)) << (29 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 7)) << (29 - 7);

      out += 4;
      *out = (*in >> 7);
      in += 4;
      *out |= (*in % (1U << 4)) << (29 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;
      *out |= (*in % (1U << 1)) << (29 - 1);

      out += 4;
      *out = (*in >> 1) % (1U << 29);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 27)) << (29 - 27);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 24)) << (29 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 21)) << (29 - 21);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 18)) << (29 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 15)) << (29 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 12)) << (29 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 9)) << (29 - 9);

      out += 4;
      *out = (*in >> 9);
      in += 4;
      *out |= (*in % (1U << 6)) << (29 - 6);

      out += 4;
      *out = (*in >> 6);
      in += 4;
      *out |= (*in % (1U << 3)) << (29 - 3);

      out += 4;
      *out = (*in >> 3);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack30(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 30);
      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 28)) << (30 - 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 26)) << (30 - 26);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 24)) << (30 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 22)) << (30 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 20)) << (30 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 18)) << (30 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 16)) << (30 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 14)) << (30 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 12)) << (30 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 10)) << (30 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 8)) << (30 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 6)) << (30 - 6);

      out += 4;
      *out = (*in >> 6);
      in += 4;
      *out |= (*in % (1U << 4)) << (30 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;
      *out |= (*in % (1U << 2)) << (30 - 2);

      out += 4;
      *out = (*in >> 2);
      in += 4;

      out += 4;
      *out = (*in >> 0) % (1U << 30);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 28)) << (30 - 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 26)) << (30 - 26);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 24)) << (30 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 22)) << (30 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 20)) << (30 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 18)) << (30 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 16)) << (30 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 14)) << (30 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 12)) << (30 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 10)) << (30 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 8)) << (30 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 6)) << (30 - 6);

      out += 4;
      *out = (*in >> 6);
      in += 4;
      *out |= (*in % (1U << 4)) << (30 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;
      *out |= (*in % (1U << 2)) << (30 - 2);

      out += 4;
      *out = (*in >> 2);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack31(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in >> 0) % (1U << 31);
      out += 4;
      *out = (*in >> 31);
      in += 4;
      *out |= (*in % (1U << 30)) << (31 - 30);

      out += 4;
      *out = (*in >> 30);
      in += 4;
      *out |= (*in % (1U << 29)) << (31 - 29);

      out += 4;
      *out = (*in >> 29);
      in += 4;
      *out |= (*in % (1U << 28)) << (31 - 28);

      out += 4;
      *out = (*in >> 28);
      in += 4;
      *out |= (*in % (1U << 27)) << (31 - 27);

      out += 4;
      *out = (*in >> 27);
      in += 4;
      *out |= (*in % (1U << 26)) << (31 - 26);

      out += 4;
      *out = (*in >> 26);
      in += 4;
      *out |= (*in % (1U << 25)) << (31 - 25);

      out += 4;
      *out = (*in >> 25);
      in += 4;
      *out |= (*in % (1U << 24)) << (31 - 24);

      out += 4;
      *out = (*in >> 24);
      in += 4;
      *out |= (*in % (1U << 23)) << (31 - 23);

      out += 4;
      *out = (*in >> 23);
      in += 4;
      *out |= (*in % (1U << 22)) << (31 - 22);

      out += 4;
      *out = (*in >> 22);
      in += 4;
      *out |= (*in % (1U << 21)) << (31 - 21);

      out += 4;
      *out = (*in >> 21);
      in += 4;
      *out |= (*in % (1U << 20)) << (31 - 20);

      out += 4;
      *out = (*in >> 20);
      in += 4;
      *out |= (*in % (1U << 19)) << (31 - 19);

      out += 4;
      *out = (*in >> 19);
      in += 4;
      *out |= (*in % (1U << 18)) << (31 - 18);

      out += 4;
      *out = (*in >> 18);
      in += 4;
      *out |= (*in % (1U << 17)) << (31 - 17);

      out += 4;
      *out = (*in >> 17);
      in += 4;
      *out |= (*in % (1U << 16)) << (31 - 16);

      out += 4;
      *out = (*in >> 16);
      in += 4;
      *out |= (*in % (1U << 15)) << (31 - 15);

      out += 4;
      *out = (*in >> 15);
      in += 4;
      *out |= (*in % (1U << 14)) << (31 - 14);

      out += 4;
      *out = (*in >> 14);
      in += 4;
      *out |= (*in % (1U << 13)) << (31 - 13);

      out += 4;
      *out = (*in >> 13);
      in += 4;
      *out |= (*in % (1U << 12)) << (31 - 12);

      out += 4;
      *out = (*in >> 12);
      in += 4;
      *out |= (*in % (1U << 11)) << (31 - 11);

      out += 4;
      *out = (*in >> 11);
      in += 4;
      *out |= (*in % (1U << 10)) << (31 - 10);

      out += 4;
      *out = (*in >> 10);
      in += 4;
      *out |= (*in % (1U << 9)) << (31 - 9);

      out += 4;
      *out = (*in >> 9);
      in += 4;
      *out |= (*in % (1U << 8)) << (31 - 8);

      out += 4;
      *out = (*in >> 8);
      in += 4;
      *out |= (*in % (1U << 7)) << (31 - 7);

      out += 4;
      *out = (*in >> 7);
      in += 4;
      *out |= (*in % (1U << 6)) << (31 - 6);

      out += 4;
      *out = (*in >> 6);
      in += 4;
      *out |= (*in % (1U << 5)) << (31 - 5);

      out += 4;
      *out = (*in >> 5);
      in += 4;
      *out |= (*in % (1U << 4)) << (31 - 4);

      out += 4;
      *out = (*in >> 4);
      in += 4;
      *out |= (*in % (1U << 3)) << (31 - 3);

      out += 4;
      *out = (*in >> 3);
      in += 4;
      *out |= (*in % (1U << 2)) << (31 - 2);

      out += 4;
      *out = (*in >> 2);
      in += 4;
      *out |= (*in % (1U << 1)) << (31 - 1);

      out += 4;
      *out = (*in >> 1);
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack1(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = *in & 1;
      out += 4;
      *out = ((*in >> 1) & 1);
      out += 4;
      for (uint32_t i = 2; i < 32; i += 1)
      {
        *out = ((*in >> i) & 1);
        ++i;
        out += 4;
        *out = ((*in >> i) & 1);
        out += 4;
      }
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack4(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 4)
      {
        *out = ((*in >> i) % (1U << 4));
        out += 4;
      }
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack8(const uint32_t initoffset,
                               const uint32_t *__restrict__ in,
                               uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in % (1U << 8));
      out += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 8)
      {
        *out = ((*in >> i) % (1U << 8));
        out += 4;
      }
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastunpack16(const uint32_t initoffset,
                                const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in % (1U << 16));
      out += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
      in += 4;
      for (uint32_t i = 0; i < 32; i += 16)
      {
        *out = ((*in >> i) % (1U << 16));
        out += 4;
      }
    }

    out = output_start;
    out[0] += initoffset;
    for (int i = 1; i < 128; ++i)
    {
      out[i] += out[i - 1];
    }
  }

  void __integratedfastpack2(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 18;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 20;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 22;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 24;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 26;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 28;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 18;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 20;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 22;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 24;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 26;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 2)) << 28;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
    }
  }

  void __integratedfastpack3(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 3;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 9;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 15;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 18;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 21;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 24;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 27;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 3)) >> (3 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 7;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 13;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 19;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 22;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 25;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 28;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 3)) >> (3 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 5;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 11;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 17;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 20;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 23;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 3)) << 26;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
    }
  }

  void __integratedfastpack5(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 5;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 15;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 20;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 25;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 5)) >> (5 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 3;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 13;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 18;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 23;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 5)) >> (5 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 11;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 21;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 26;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 5)) >> (5 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 9;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 19;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 24;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 5)) >> (5 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 7;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 17;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 5)) << 22;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
    }
  }

  void __integratedfastpack6(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 18;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 24;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 6)) >> (6 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 22;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 6)) >> (6 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 18;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 24;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 6)) >> (6 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 22;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 6)) >> (6 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 6)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
    }
  }

  void __integratedfastpack7(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 7;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 14;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 21;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 7)) >> (7 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 3;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 17;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 24;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 7)) >> (7 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 13;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 7)) >> (7 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 9;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 16;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 23;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 7)) >> (7 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 5;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 19;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 7)) >> (7 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 15;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 22;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 7)) >> (7 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 11;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 7)) << 18;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
    }
  }

  void __integratedfastpack9(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 9);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 9;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 18;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 13;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 22;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 17;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 3;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 12;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 21;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 7;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 11;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 15;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 19;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 9)) >> (9 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 5;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 9)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 23;
    }
  }

  void __integratedfastpack10(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 18;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 10;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 18;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 10)) >> (10 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 10)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
    }
  }

  void __integratedfastpack11(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 11);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 11;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 13;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 3;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 15;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 5;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 6;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 17;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 7;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 18;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 8;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 19;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 9);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 9;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 20;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 11)) >> (11 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 11)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 21;
    }
  }

  void __integratedfastpack12(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 12)) >> (12 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 12)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
    }
  }

  void __integratedfastpack13(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 13);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 13;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 7;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 15;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 9);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 9;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 3;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 4;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 17;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 11);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 11;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 5;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 18;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 13)) >> (13 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 13)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 19;
    }
  }

  void __integratedfastpack14(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 14);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 14);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 2;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 14)) >> (14 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 14)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 18;
    }
  }

  void __integratedfastpack15(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 15);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 15;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 13);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 13;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 11);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 11;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 9);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 9;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 7;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 5;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 3;
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 1;
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 16;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 14);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 15)) >> (15 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 15)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 17;
    }
  }

  void __integratedfastpack17(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 14);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 14;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 1;
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 3;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 5;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 7;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 9);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 9;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 11);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 11;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 13);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 17)) << 13;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 17)) >> (17 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
    }
  }

  void __integratedfastpack18(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 18)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 18)) >> (18 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
    }
  }

  void __integratedfastpack19(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 19);
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 12);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 12;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 5;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 11);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 11;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 10);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 10;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 3;
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 9);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 9;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 1;
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 19)) << 7;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 19)) >> (19 - 13);
      in += 4;
      *out |= ((*in - in[-1])) << 13;
    }
  }

  void __integratedfastpack20(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 20)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 20)) >> (20 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
    }
  }

  void __integratedfastpack21(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    uint32_t *out1 = out + 1;
    uint32_t *out2 = out1 + 1;
    uint32_t *out3 = out2 + 1;
    *out = (*in - initoffset) % (1U << 21);
    *out1 = (in[1] - in[0]) % (1U << 21);
    *out2 = (in[2] - in[1]) % (1U << 21);
    *out3 = (in[3] - in[2]) % (1U << 21);

    *out |= ((in[4] - in[3])) << 21;
    *out1 |= ((in[5] - in[4])) << 21;
    *out2 |= ((in[6] - in[5])) << 21;
    *out3 |= ((in[7] - in[6])) << 21;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[4] - in[3]) % (1U << 21)) >> (21 - 10);
    *out1 = ((in[5] - in[4]) % (1U << 21)) >> (21 - 10);
    *out2 = ((in[6] - in[5]) % (1U << 21)) >> (21 - 10);
    *out3 = ((in[7] - in[6]) % (1U << 21)) >> (21 - 10);

    *out |= ((in[8] - in[7]) % (1U << 21)) << 10;
    *out1 |= ((in[9] - in[8]) % (1U << 21)) << 10;
    *out2 |= ((in[10] - in[9]) % (1U << 21)) << 10;
    *out3 |= ((in[11] - in[10]) % (1U << 21)) << 10;

    *out |= ((in[12] - in[11])) << 31;
    *out1 |= ((in[13] - in[12])) << 31;
    *out2 |= ((in[14] - in[13])) << 31;
    *out3 |= ((in[15] - in[14])) << 31;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[12] - in[11]) % (1U << 21)) >> (21 - 20);
    *out1 = ((in[13] - in[12]) % (1U << 21)) >> (21 - 20);
    *out2 = ((in[14] - in[13]) % (1U << 21)) >> (21 - 20);
    *out3 = ((in[15] - in[14]) % (1U << 21)) >> (21 - 20);

    *out |= ((in[16] - in[15])) << 20;
    *out1 |= ((in[17] - in[16])) << 20;
    *out2 |= ((in[18] - in[17])) << 20;
    *out3 |= ((in[19] - in[18])) << 20;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[16] - in[15]) % (1U << 21)) >> (21 - 9);
    *out1 = ((in[17] - in[16]) % (1U << 21)) >> (21 - 9);
    *out2 = ((in[18] - in[17]) % (1U << 21)) >> (21 - 9);
    *out3 = ((in[19] - in[18]) % (1U << 21)) >> (21 - 9);

    *out |= ((in[20] - in[19]) % (1U << 21)) << 9;
    *out1 |= ((in[21] - in[20]) % (1U << 21)) << 9;
    *out2 |= ((in[22] - in[21]) % (1U << 21)) << 9;
    *out3 |= ((in[23] - in[22]) % (1U << 21)) << 9;

    *out |= ((in[24] - in[23])) << 30;
    *out1 |= ((in[25] - in[24])) << 30;
    *out2 |= ((in[26] - in[25])) << 30;
    *out3 |= ((in[27] - in[26])) << 30;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[24] - in[23]) % (1U << 21)) >> (21 - 19);
    *out1 = ((in[25] - in[24]) % (1U << 21)) >> (21 - 19);
    *out2 = ((in[26] - in[25]) % (1U << 21)) >> (21 - 19);
    *out3 = ((in[27] - in[26]) % (1U << 21)) >> (21 - 19);

    *out |= ((in[28] - in[27])) << 19;
    *out1 |= ((in[29] - in[28])) << 19;
    *out2 |= ((in[30] - in[29])) << 19;
    *out3 |= ((in[31] - in[30])) << 19;
    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[28] - in[27]) % (1U << 21)) >> (21 - 8);
    *out1 = ((in[29] - in[28]) % (1U << 21)) >> (21 - 8);
    *out2 = ((in[30] - in[29]) % (1U << 21)) >> (21 - 8);
    *out3 = ((in[31] - in[30]) % (1U << 21)) >> (21 - 8);

    *out |= ((in[32] - in[31]) % (1U << 21)) << 8;
    *out1 |= ((in[33] - in[32]) % (1U << 21)) << 8;
    *out2 |= ((in[34] - in[33]) % (1U << 21)) << 8;
    *out3 |= ((in[35] - in[34]) % (1U << 21)) << 8;

    *out |= ((in[36] - in[35])) << 29;
    *out1 |= ((in[37] - in[36])) << 29;
    *out2 |= ((in[38] - in[37])) << 29;
    *out3 |= ((in[39] - in[38])) << 29;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[36] - in[35]) % (1U << 21)) >> (21 - 18);
    *out1 = ((in[37] - in[36]) % (1U << 21)) >> (21 - 18);
    *out2 = ((in[38] - in[37]) % (1U << 21)) >> (21 - 18);
    *out3 = ((in[39] - in[38]) % (1U << 21)) >> (21 - 18);

    *out |= ((in[40] - in[39])) << 18;
    *out1 |= ((in[41] - in[40])) << 18;
    *out2 |= ((in[42] - in[41])) << 18;
    *out3 |= ((in[43] - in[42])) << 18;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[40] - in[39]) % (1U << 21)) >> (21 - 7);
    *out1 = ((in[41] - in[40]) % (1U << 21)) >> (21 - 7);
    *out2 = ((in[42] - in[41]) % (1U << 21)) >> (21 - 7);
    *out3 = ((in[43] - in[42]) % (1U << 21)) >> (21 - 7);

    *out |= ((in[44] - in[43]) % (1U << 21)) << 7;
    *out1 |= ((in[45] - in[44]) % (1U << 21)) << 7;
    *out2 |= ((in[46] - in[45]) % (1U << 21)) << 7;
    *out3 |= ((in[47] - in[46]) % (1U << 21)) << 7;

    *out |= ((in[48] - in[47])) << 28;
    *out1 |= ((in[49] - in[48])) << 28;
    *out2 |= ((in[50] - in[49])) << 28;
    *out3 |= ((in[51] - in[50])) << 28;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[48] - in[47]) % (1U << 21)) >> (21 - 17);
    *out1 = ((in[49] - in[48]) % (1U << 21)) >> (21 - 17);
    *out2 = ((in[50] - in[49]) % (1U << 21)) >> (21 - 17);
    *out3 = ((in[51] - in[50]) % (1U << 21)) >> (21 - 17);

    *out |= ((in[52] - in[51])) << 17;
    *out1 |= ((in[53] - in[52])) << 17;
    *out2 |= ((in[54] - in[53])) << 17;
    *out3 |= ((in[55] - in[54])) << 17;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[52] - in[51]) % (1U << 21)) >> (21 - 6);
    *out1 = ((in[53] - in[52]) % (1U << 21)) >> (21 - 6);
    *out2 = ((in[54] - in[53]) % (1U << 21)) >> (21 - 6);
    *out3 = ((in[55] - in[54]) % (1U << 21)) >> (21 - 6);

    *out |= ((in[56] - in[55]) % (1U << 21)) << 6;
    *out1 |= ((in[57] - in[56]) % (1U << 21)) << 6;
    *out2 |= ((in[58] - in[57]) % (1U << 21)) << 6;
    *out3 |= ((in[59] - in[58]) % (1U << 21)) << 6;

    *out |= ((in[60] - in[59])) << 27;
    *out1 |= ((in[61] - in[60])) << 27;
    *out2 |= ((in[62] - in[61])) << 27;
    *out3 |= ((in[63] - in[62])) << 27;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[60] - in[59]) % (1U << 21)) >> (21 - 16);
    *out1 = ((in[61] - in[60]) % (1U << 21)) >> (21 - 16);
    *out2 = ((in[62] - in[61]) % (1U << 21)) >> (21 - 16);
    *out3 = ((in[63] - in[62]) % (1U << 21)) >> (21 - 16);

    *out |= ((in[64] - in[63])) << 16;
    *out1 |= ((in[65] - in[64])) << 16;
    *out2 |= ((in[66] - in[65])) << 16;
    *out3 |= ((in[67] - in[66])) << 16;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[64] - in[63]) % (1U << 21)) >> (21 - 5);
    *out1 = ((in[65] - in[64]) % (1U << 21)) >> (21 - 5);
    *out2 = ((in[66] - in[65]) % (1U << 21)) >> (21 - 5);
    *out3 = ((in[67] - in[66]) % (1U << 21)) >> (21 - 5);

    *out |= ((in[68] - in[67]) % (1U << 21)) << 5;
    *out1 |= ((in[69] - in[68]) % (1U << 21)) << 5;
    *out2 |= ((in[70] - in[69]) % (1U << 21)) << 5;
    *out3 |= ((in[71] - in[70]) % (1U << 21)) << 5;

    *out |= ((in[72] - in[71])) << 26;
    *out1 |= ((in[73] - in[72])) << 26;
    *out2 |= ((in[74] - in[73])) << 26;
    *out3 |= ((in[75] - in[74])) << 26;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[72] - in[71]) % (1U << 21)) >> (21 - 15);
    *out1 = ((in[73] - in[72]) % (1U << 21)) >> (21 - 15);
    *out2 = ((in[74] - in[73]) % (1U << 21)) >> (21 - 15);
    *out3 = ((in[75] - in[74]) % (1U << 21)) >> (21 - 15);

    *out |= ((in[76] - in[75])) << 15;
    *out1 |= ((in[77] - in[76])) << 15;
    *out2 |= ((in[78] - in[77])) << 15;
    *out3 |= ((in[79] - in[78])) << 15;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[76] - in[75]) % (1U << 21)) >> (21 - 4);
    *out1 = ((in[77] - in[76]) % (1U << 21)) >> (21 - 4);
    *out2 = ((in[78] - in[77]) % (1U << 21)) >> (21 - 4);
    *out3 = ((in[79] - in[78]) % (1U << 21)) >> (21 - 4);

    *out |= ((in[80] - in[79]) % (1U << 21)) << 4;
    *out1 |= ((in[81] - in[80]) % (1U << 21)) << 4;
    *out2 |= ((in[82] - in[81]) % (1U << 21)) << 4;
    *out3 |= ((in[83] - in[82]) % (1U << 21)) << 4;

    *out |= ((in[84] - in[83])) << 25;
    *out1 |= ((in[85] - in[84])) << 25;
    *out2 |= ((in[86] - in[85])) << 25;
    *out3 |= ((in[87] - in[86])) << 25;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[84] - in[83]) % (1U << 21)) >> (21 - 14);
    *out1 = ((in[85] - in[84]) % (1U << 21)) >> (21 - 14);
    *out2 = ((in[86] - in[85]) % (1U << 21)) >> (21 - 14);
    *out3 = ((in[87] - in[86]) % (1U << 21)) >> (21 - 14);

    *out |= ((in[88] - in[87])) << 14;
    *out1 |= ((in[89] - in[88])) << 14;
    *out2 |= ((in[90] - in[89])) << 14;
    *out3 |= ((in[91] - in[90])) << 14;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[88] - in[87]) % (1U << 21)) >> (21 - 3);
    *out1 = ((in[89] - in[88]) % (1U << 21)) >> (21 - 3);
    *out2 = ((in[90] - in[89]) % (1U << 21)) >> (21 - 3);
    *out3 = ((in[91] - in[90]) % (1U << 21)) >> (21 - 3);

    *out |= ((in[92] - in[91]) % (1U << 21)) << 3;
    *out1 |= ((in[93] - in[92]) % (1U << 21)) << 3;
    *out2 |= ((in[94] - in[93]) % (1U << 21)) << 3;
    *out3 |= ((in[95] - in[94]) % (1U << 21)) << 3;

    *out |= ((in[96] - in[95])) << 24;
    *out1 |= ((in[97] - in[96])) << 24;
    *out2 |= ((in[98] - in[97])) << 24;
    *out3 |= ((in[99] - in[98])) << 24;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[96] - in[95]) % (1U << 21)) >> (21 - 13);
    *out1 = ((in[97] - in[96]) % (1U << 21)) >> (21 - 13);
    *out2 = ((in[98] - in[97]) % (1U << 21)) >> (21 - 13);
    *out3 = ((in[99] - in[98]) % (1U << 21)) >> (21 - 13);

    *out |= ((in[100] - in[99])) << 13;
    *out1 |= ((in[101] - in[100])) << 13;
    *out2 |= ((in[102] - in[101])) << 13;
    *out3 |= ((in[103] - in[102])) << 13;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[100] - in[99]) % (1U << 21)) >> (21 - 2);
    *out1 = ((in[101] - in[100]) % (1U << 21)) >> (21 - 2);
    *out2 = ((in[102] - in[101]) % (1U << 21)) >> (21 - 2);
    *out3 = ((in[103] - in[102]) % (1U << 21)) >> (21 - 2);

    *out |= ((in[104] - in[103]) % (1U << 21)) << 2;
    *out1 |= ((in[105] - in[104]) % (1U << 21)) << 2;
    *out2 |= ((in[106] - in[105]) % (1U << 21)) << 2;
    *out3 |= ((in[107] - in[106]) % (1U << 21)) << 2;

    *out |= ((in[108] - in[107])) << 23;
    *out1 |= ((in[109] - in[108])) << 23;
    *out2 |= ((in[110] - in[109])) << 23;
    *out3 |= ((in[111] - in[110])) << 23;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[108] - in[107]) % (1U << 21)) >> (21 - 12);
    *out1 = ((in[109] - in[108]) % (1U << 21)) >> (21 - 12);
    *out2 = ((in[110] - in[109]) % (1U << 21)) >> (21 - 12);
    *out3 = ((in[111] - in[110]) % (1U << 21)) >> (21 - 12);

    *out |= ((in[112] - in[111])) << 12;
    *out1 |= ((in[113] - in[112])) << 12;
    *out2 |= ((in[114] - in[113])) << 12;
    *out3 |= ((in[115] - in[114])) << 12;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[112] - in[111]) % (1U << 21)) >> (21 - 1);
    *out1 = ((in[113] - in[112]) % (1U << 21)) >> (21 - 1);
    *out2 = ((in[114] - in[113]) % (1U << 21)) >> (21 - 1);
    *out3 = ((in[115] - in[114]) % (1U << 21)) >> (21 - 1);

    *out |= ((in[116] - in[115]) % (1U << 21)) << 1;
    *out1 |= ((in[117] - in[116]) % (1U << 21)) << 1;
    *out2 |= ((in[118] - in[117]) % (1U << 21)) << 1;
    *out3 |= ((in[119] - in[118]) % (1U << 21)) << 1;

    *out |= ((in[120] - in[119])) << 22;
    *out1 |= ((in[121] - in[120])) << 22;
    *out2 |= ((in[122] - in[121])) << 22;
    *out3 |= ((in[123] - in[122])) << 22;

    out += 4;
    out1 = out + 1;
    out2 = out1 + 1;
    out3 = out2 + 1;
    *out = ((in[120] - in[119]) % (1U << 21)) >> (21 - 11);
    *out1 = ((in[121] - in[120]) % (1U << 21)) >> (21 - 11);
    *out2 = ((in[122] - in[121]) % (1U << 21)) >> (21 - 11);
    *out3 = ((in[123] - in[122]) % (1U << 21)) >> (21 - 11);

    *out |= ((in[124] - in[123])) << 11;
    *out1 |= ((in[125] - in[124])) << 11;
    *out2 |= ((in[126] - in[125])) << 11;
    *out3 |= ((in[127] - in[126])) << 11;
  }

  void __integratedfastpack22(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 22)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 22)) >> (22 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
    }
  }

  void __integratedfastpack23(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 23);
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 5;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 19);
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 1;
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 11);
      in += 4;
      *out |= ((*in - in[-1])) << 11;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 7);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 7;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 21);
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 3;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 8);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 8;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 13);
      in += 4;
      *out |= ((*in - in[-1])) << 13;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 23)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 23)) >> (23 - 9);
      in += 4;
      *out |= ((*in - in[-1])) << 9;
    }
  }

  void __integratedfastpack24(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 24)) >> (24 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
    }
  }

  void __integratedfastpack25(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 25);
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 11);
      in += 4;
      *out |= ((*in - in[-1])) << 11;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 25)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 25)) << 1;
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 19);
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 5);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 25)) << 5;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 23);
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 9);
      in += 4;
      *out |= ((*in - in[-1])) << 9;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 25)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 13);
      in += 4;
      *out |= ((*in - in[-1])) << 13;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 6);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 25)) << 6;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 25)) << 3;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 21);
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 25)) >> (25 - 7);
      in += 4;
      *out |= ((*in - in[-1])) << 7;
    }
  }

  void __integratedfastpack26(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 26)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 26)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 26)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 26)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 26)) >> (26 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
    }
  }

  void __integratedfastpack27(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 27);
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 7);
      in += 4;
      *out |= ((*in - in[-1])) << 7;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 27)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 19);
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 9);
      in += 4;
      *out |= ((*in - in[-1])) << 9;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 4);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 27)) << 4;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 21);
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 11);
      in += 4;
      *out |= ((*in - in[-1])) << 11;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 27)) << 1;
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 23);
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 13);
      in += 4;
      *out |= ((*in - in[-1])) << 13;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 3);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 27)) << 3;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 25);
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 27)) >> (27 - 5);
      in += 4;
      *out |= ((*in - in[-1])) << 5;
    }
  }

  void __integratedfastpack28(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 28)) >> (28 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
    }
  }

  void __integratedfastpack29(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 29);
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 23);
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 11);
      in += 4;
      *out |= ((*in - in[-1])) << 11;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 5);
      in += 4;
      *out |= ((*in - in[-1])) << 5;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 2);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 29)) << 2;
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 25);
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 19);
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 13);
      in += 4;
      *out |= ((*in - in[-1])) << 13;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 7);
      in += 4;
      *out |= ((*in - in[-1])) << 7;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 1);
      in += 4;
      *out |= ((*in - in[-1]) % (1U << 29)) << 1;
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 27);
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 21);
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 9);
      in += 4;
      *out |= ((*in - in[-1])) << 9;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 29)) >> (29 - 3);
      in += 4;
      *out |= ((*in - in[-1])) << 3;
    }
  }

  void __integratedfastpack30(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 30);
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 2);
      in += 4;
      *out |= ((*in - in[-1])) << 2;
      out += 4;
      in += 4;
      *out = (*in - in[-1]) % (1U << 30);
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 30)) >> (30 - 2);
      in += 4;
      *out |= ((*in - in[-1])) << 2;
    }
  }

  void __integratedfastpack31(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = (*in - (i == 0 ? initoffset : in[-1])) % (1U << 31);
      in += 4;
      *out |= ((*in - in[-1])) << 31;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 30);
      in += 4;
      *out |= ((*in - in[-1])) << 30;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 29);
      in += 4;
      *out |= ((*in - in[-1])) << 29;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 28);
      in += 4;
      *out |= ((*in - in[-1])) << 28;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 27);
      in += 4;
      *out |= ((*in - in[-1])) << 27;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 26);
      in += 4;
      *out |= ((*in - in[-1])) << 26;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 25);
      in += 4;
      *out |= ((*in - in[-1])) << 25;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 24);
      in += 4;
      *out |= ((*in - in[-1])) << 24;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 23);
      in += 4;
      *out |= ((*in - in[-1])) << 23;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 22);
      in += 4;
      *out |= ((*in - in[-1])) << 22;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 21);
      in += 4;
      *out |= ((*in - in[-1])) << 21;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 20);
      in += 4;
      *out |= ((*in - in[-1])) << 20;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 19);
      in += 4;
      *out |= ((*in - in[-1])) << 19;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 18);
      in += 4;
      *out |= ((*in - in[-1])) << 18;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 17);
      in += 4;
      *out |= ((*in - in[-1])) << 17;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 16);
      in += 4;
      *out |= ((*in - in[-1])) << 16;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 15);
      in += 4;
      *out |= ((*in - in[-1])) << 15;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 14);
      in += 4;
      *out |= ((*in - in[-1])) << 14;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 13);
      in += 4;
      *out |= ((*in - in[-1])) << 13;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 12);
      in += 4;
      *out |= ((*in - in[-1])) << 12;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 11);
      in += 4;
      *out |= ((*in - in[-1])) << 11;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 10);
      in += 4;
      *out |= ((*in - in[-1])) << 10;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 9);
      in += 4;
      *out |= ((*in - in[-1])) << 9;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 8);
      in += 4;
      *out |= ((*in - in[-1])) << 8;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 7);
      in += 4;
      *out |= ((*in - in[-1])) << 7;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 6);
      in += 4;
      *out |= ((*in - in[-1])) << 6;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 5);
      in += 4;
      *out |= ((*in - in[-1])) << 5;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 4);
      in += 4;
      *out |= ((*in - in[-1])) << 4;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 3);
      in += 4;
      *out |= ((*in - in[-1])) << 3;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 2);
      in += 4;
      *out |= ((*in - in[-1])) << 2;
      out += 4;
      *out = ((*in - in[-1]) % (1U << 31)) >> (31 - 1);
      in += 4;
      *out |= ((*in - in[-1])) << 1;
    }
  }

  /*assumes that integers fit in the prescribed number of bits*/
  void __integratedfastpack1(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = *in - (i == 0 ? initoffset : in[-1]);
      in += 4;
      for (uint32_t i = 1; i < 32; i += 1)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
    }
  }

  /*assumes that integers fit in the prescribed number of bits*/
  void __integratedfastpack4(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = *in - (i == 0 ? initoffset : in[-1]);
      in += 4;
      for (uint32_t i = 4; i < 32; i += 4)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 4; i < 32; i += 4)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 4; i < 32; i += 4)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 4; i < 32; i += 4)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
    }
  }

  /*assumes that integers fit in the prescribed number of bits*/
  void __integratedfastpack8(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = *in - (i == 0 ? initoffset : in[-1]);
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 8; i < 32; i += 8)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
    }
  }

  /*assumes that integers fit in the prescribed number of bits*/
  void __integratedfastpack16(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out)
  {
    const uint32_t *input_start = in;
    uint32_t *output_start = out;
    for (int i = 0; i < 4; ++i)
    {
      out = output_start + i;
      in = input_start + i;
      *out = *in - (i == 0 ? initoffset : in[-1]);
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
      out += 4;
      *out = *in - in[-1];
      in += 4;
      for (uint32_t i = 16; i < 32; i += 16)
      {
        *out |= (*in - in[-1]) << i;
        in += 4;
      }
    }
  }

} // namespace SIMDCompressionLib
