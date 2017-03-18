// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_INTERNAL_TRIVIAL_HH
#define PEGTL_INTERNAL_TRIVIAL_HH

#include "../config.hh"

#include "skip_control.hh"

#include "../analysis/counted.hh"

namespace PEGTL_NAMESPACE
{
   namespace internal
   {
      template< bool Result >
      struct trivial
      {
         using analyze_t = analysis::counted< analysis::rule_type::ANY, unsigned( ! Result ) >;

         template< typename Input >
         static bool match( Input & )
         {
            return Result;
         }
      };

      template< bool Result >
      struct skip_control< trivial< Result > > : std::true_type {};

   } // namespace internal

} // namespace PEGTL_NAMESPACE

#endif