#pragma once

#include "idler.h"

#include <vector>

namespace fox::components {

namespace detail {

struct to_vectors {
    template <typename... Ts> consteval auto operator()(std::tuple<Ts...> tuple) {
        return std::tuple<std::vector<Ts>...>{};
    }
};
} // namespace detail

using component_types = std::tuple<idler_component>;
using component_lists_t = std::invoke_result_t<detail::to_vectors, component_types>;

class component_system {
public:
    template <typename... Ts> void add_component(Ts&&... component) {
        (std::get<std::vector<Ts>>(m_component_lists).push_back(std::forward<Ts>(component)), ...);
    }

    template <typename component_t, typename... Ts> void update_components(Ts&&... args) {
        for (auto& component : std::get<std::vector<component_t>>(m_component_lists))
            update(component, std::forward<Ts>(args)...);
    }

    template <typename component_t> auto get_components() const {
        return std::get<std::vector<component_t>>(m_component_lists);
    }

private:
    component_lists_t m_component_lists;
};

} // namespace fox::components
