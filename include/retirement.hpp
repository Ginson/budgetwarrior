//=======================================================================
// Copyright (c) 2013-2020 Baptiste Wicht.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#pragma once

#include <vector>
#include <string>

#include "module_traits.hpp"
#include "writer_fwd.hpp"
#include "date.hpp"

namespace budget {

struct data_cache;

struct retirement_module {
    void load();
    void handle(std::vector<std::string>& args);
};

template<>
struct module_traits<retirement_module> {
    static constexpr const bool is_default = false;
    static constexpr const char* command   = "retirement";
};

struct asset_value;

float fi_ratio(budget::date d);
float fi_ratio(budget::date d, data_cache & cache);

void retirement_status(budget::writer& w);

} //end of namespace budget
