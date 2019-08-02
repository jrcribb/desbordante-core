//
// Created by kek on 30.07.2019.
//

#pragma once

#include <vector>
#include <memory>

using std::vector, std::shared_ptr;

class PositionListIndex {
private:
    vector<vector<int>> index;
    vector<int> nullCluster;
    int size;
    double entropy;
    long nep;
    int relationSize;
    int originalRelationSize;
    vector<int> probingTableCache;

    PositionListIndex(vector<vector<int>> index, vector<int> nullCluster, int size, double entropy,
                      long nep, int relationSize, int originalRelationSize);

    static long calculateNep(long numElements);
    static void sortClusters(vector<vector<int>> & clusters);

public:
    static const int singletonValueId;
    static shared_ptr<PositionListIndex> createFor(vector<int>& data, bool isNullEqNull);
    vector<int> getProbingTable();
    vector<int> getProbingTable(bool isCaching);
};