/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_CODECFACTORY_H_
#define SIMDCompressionAndIntersection_CODECFACTORY_H_

#define NOSIMD_CODEC

#include "binarypacking.h"
#include "bitpackinghelpers.h"
#include "codecfactory.h"
#include "compositecodec.h"
#include "delta.h"
#include "util.h"
#include "variablebyte.h"

namespace SIMDCompressionLib
{
    typedef VariableByte<true> leftovercodec;
} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_CODECFACTORY_H_ */
