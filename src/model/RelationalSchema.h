//
// Created by kek on 17.07.19.
//

#pragma once

#include <boost/dynamic_bitset.hpp>
#include <string>
#include <vector>
#include "Vertical.h"
#include "Column.h"
#include <memory>

using boost::dynamic_bitset, std::string, std::vector;

class RelationalSchema : public std::enable_shared_from_this<RelationalSchema> {
private:
    vector<shared_ptr<Column>> columns;
    string name;
    bool isNullEqNull;

public:
    Vertical emptyVertical;

    RelationalSchema(string name, bool isNullEqNull);
    string getName();
    vector<shared_ptr<Column>> getColumns();
    shared_ptr<Column> getColumn(const string &colName);
    shared_ptr<Column> getColumn(int index);
    void appendColumn(const string& colName);
    int getNumColumns();
    //TODO: getVertical работает неверно, нужно будет подумать в зависимотси от его использования
    Vertical getVertical(dynamic_bitset<> indices);
    bool isNullEqualNull();
};