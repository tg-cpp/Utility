#pragma once

#include "Global.hpp"

#include <cstddef>

namespace TG
{
    namespace Meta
    {
        // TypeList
        template <typename... Types>
        class TypeList
        {
        public:
            enum {count = sizeof...(Types)};
        };

        // TypeListIndex
        template <typename TypeToFind, typename...>
        class TypeListIndex;

        template <typename TypeToFind,
                  typename... Types>
        class TypeListIndex<TypeToFind, TypeList<TypeToFind, Types...>>
        {
        public:
            enum {value = 0};
        };

        template <typename TypeToFind,
                  typename TypeOther,
                  typename... Types>
        class TypeListIndex<TypeToFind, TypeList<TypeOther, Types...>>
        {
        public:
            enum {value = 1 + TypeListIndex<TypeToFind, TypeList<Types...>>::value};
        };

        // TypeListGet
        template <size_t Index, typename...>
        class TypeListGet;

        template <typename First,
                  typename... Types>
        class TypeListGet<0, TypeList<First, Types...>>
        {
        public:
            using type = First;
        };

        template <size_t Index,
                  typename First,
                  typename... Types>
        class TypeListGet<Index, TypeList<First, Types...>>
        {
        public:
            using type = typename TypeListGet<Index - 1, TypeList<Types...>>::type;
        };
    }
}