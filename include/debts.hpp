//=======================================================================
// Copyright (c) 2013-2020 Baptiste Wicht.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#pragma once

#include <vector>
#include <string>
#include <map>

#include "module_traits.hpp"
#include "money.hpp"
#include "date.hpp"
#include "writer_fwd.hpp"

namespace budget {

struct debt_module {
    void load();
    void unload();
    void handle(const std::vector<std::string>& args);
};

template<>
struct module_traits<debt_module> {
    static constexpr const bool is_default = false;
    static constexpr const char* command = "debt";
};

struct debt {
    size_t id;
    int state;
    std::string guid;
    budget::date creation_date;
    bool direction;
    std::string name;
    money amount;
    std::string title = "";

    std::map<std::string, std::string> get_params() const ;
};

std::ostream& operator<<(std::ostream& stream, const debt& debt);
void operator>>(const std::vector<std::string>& parts, debt& debt);

void load_debts();
void save_debts();

void migrate_debts_3_to_4();

std::vector<debt> all_debts();

void set_debts_changed();
void set_debts_next_id(size_t next_id);

void display_all_debts(budget::writer& w);
void list_debts(budget::writer& w);

void add_debt(debt&& debt);
void edit_debt(const debt& debt);
bool debt_exists(size_t id);
void debt_delete(size_t id);
debt debt_get(size_t id);

} //end of namespace budget
