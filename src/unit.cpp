#include <iostream>

#include "binarypacking.h"
#include "bitpackinghelpers.h"
#include "codecfactory.h"
#include "compositecodec.h"
#include "delta.h"
#include "util.h"
#include "variablebyte.h"

using namespace std;
using namespace SIMDCompressionLib;

template <typename T> void testCodec() {
  T codec;
  const int max = 256;
  uint32_t ints[max];
  for (int i = 0; i < max; i++)
    ints[i] = i;
  // encode in a buffer
  vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
  size_t nvalue = compressedbuffer.size();
  codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);
  compressedbuffer.resize(nvalue);
  compressedbuffer.shrink_to_fit();

  // decode in a buffer
  vector<uint32_t> recoverybuffer(max * sizeof(uint32_t) + 1024);
  size_t recoveredvalues = recoverybuffer.size();
  codec.decodeArray(compressedbuffer.data(), nvalue, recoverybuffer.data(),
                    recoveredvalues);
  recoverybuffer.resize(recoveredvalues);

  for (int i = 0; i < max; i++) {
    uint32_t k = recoverybuffer[i];
    if (k != (uint32_t)i) {
      cout << codec.name() << "::decode failed with " << i << endl;
      throw std::logic_error("bug");
    }
  }

  cout << codec.name() << "::select ok" << endl;
}

int main()
{
  testCodec<CompositeCodec<BinaryPacking<IntegratedBlockPacker>, leftovercodec>>();
  cout << "Test Done!" << endl;
}
