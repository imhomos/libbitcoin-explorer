/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>
#include <sx/sx.hpp>
#include "command.hpp"

SX_USING_NAMESPACES()

// This is a namespace for tests by class/file__method/function.
BOOST_AUTO_TEST_SUITE(balance__invoke)

BOOST_AUTO_TEST_CASE(balance__invoke__bogus_address__failure_error)
{
    // $ sx balance bogus
    SX_DECLARE_COMMAND(balance);
    command.set_addresss_argument({ "bogus" });
    SX_REQUIRE_FAILURE(command.invoke(input, output, error));
    SX_REQUIRE_ERROR(SX_BALANCE_INVALID_ADDRESS "\n");
}

// DISABLED until client-server calls are isolated for test.

//BOOST_AUTO_TEST_CASE(balance__invoke__address__okay)
//{
//    // $ sx balance 134HfD2fdeBTohfx8YANxEpsYXsv5UoWyz
//    SX_DECLARE_COMMAND(balance);
//    command.set_addresss_argument({ "134HfD2fdeBTohfx8YANxEpsYXsv5UoWyz" });
//    SX_REQUIRE_OKAY(command.invoke(input, output, error));
//}
//
//BOOST_AUTO_TEST_CASE(balance__invoke__address_json__okay)
//{
//    // $ sx balance -j true 134HfD2fdeBTohfx8YANxEpsYXsv5UoWyz
//    SX_DECLARE_COMMAND(balance);
//    command.set_addresss_argument({ "134HfD2fdeBTohfx8YANxEpsYXsv5UoWyz" });
//    command.set_json_option(true);
//    SX_REQUIRE_OKAY(command.invoke(input, output, error));
//}

BOOST_AUTO_TEST_SUITE_END()