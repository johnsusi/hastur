// SPDX-FileCopyrightText: 2021 Robin Lindén <dev@robinlinden.eu>
//
// SPDX-License-Identifier: BSD-2-Clause

#ifndef LAYOUT_LAYOUT_H_
#define LAYOUT_LAYOUT_H_

#include "layout/box_model.h"

#include "geom/geom.h"
#include "style/styled_node.h"

#include <string>
#include <vector>

namespace layout {

enum class LayoutType {
    Inline,
    Block,
    AnonymousBlock, // Holds groups of sequential inline boxes.
};

struct LayoutBox {
    style::StyledNode const *node;
    LayoutType type;
    BoxModel dimensions;
    std::vector<LayoutBox> children;
    [[nodiscard]] bool operator==(LayoutBox const &) const = default;
};

LayoutBox create_layout(style::StyledNode const &node, int width);

LayoutBox const *box_at_position(LayoutBox const &, geom::Position);

std::string to_string(LayoutBox const &box);

} // namespace layout

#endif
