#pragma once 

#include <map>
#include <tuple>

#include "matrix.h"

template <typename T, T Default>
class Matrix
{
public:
    class RowProxy;
    class CellProxy;

    class RowProxy {
    public:
        RowProxy(Matrix &m, int row) : x(row), matrix(m) {};

        CellProxy operator[](int y) {
            return CellProxy(matrix, x, y);
        }

    private:
        int x;
        Matrix &matrix;
    };

    class CellProxy {
    public:
        CellProxy(Matrix &m, int x, int y) : matrix(m), x(x), y(y) {};

        operator T() const {
            auto it = matrix.data.find({x, y});
            return it == matrix.data.end() ? Default : it->second;
        }

        CellProxy &operator=(const T &value)
        {
            if (value == Default)
                matrix.data.erase({x, y});
            else
                matrix.data[{x, y}] = value;
            return *this;
        }

    private:
        Matrix &matrix;
        int x;
        int y;
    };

    RowProxy operator[](int x)
    {
        return RowProxy(*this, x);
    }

    std::size_t size() const
    {
        return data.size();
    }

    auto begin() const
    {
        return data.begin();
    }

    auto end() const
    {
        return data.end();
    }

private:
    using key_t = std::pair<int, int>;
    std::map<key_t, T> data;
};
