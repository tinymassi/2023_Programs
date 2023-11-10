/*
* (C) 2015,2016 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/

#include "fuzzers.h"
#include <botan/pk_keys.h>
#include <botan/pkcs8.h>
#include <botan/data_src.h>
#include <botan/ec_group.h>

void fuzz(const uint8_t in[], size_t len)
   {
   try
      {
      Botan::DataSource_Memory input(in, len);
      std::unique_ptr<Botan::Private_Key> key = Botan::PKCS8::load_key(input);
      }
   catch(Botan::Exception& e) { }

   /*
   * This avoids OOMs in OSS-Fuzz caused by storing precomputations
   * for thousands of curves randomly generated by the fuzzer.
   */
   Botan::EC_Group::clear_registered_curve_data();
   }
