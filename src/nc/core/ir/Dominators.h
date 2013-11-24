/* The file is part of Snowman decompiler.             */
/* See doc/licenses.txt for the licensing information. */

#pragma once

#include <nc/config.h>

#include <vector>

#include <boost/unordered_map.hpp>

#include <nc/common/Range.h>

namespace nc {
namespace core {
namespace ir {

class BasicBlock;
class CFG;

/**
 * Dominator sets.
 */
class Dominators {
    /** Mapping from a basic block to the set of its dominators. */
    boost::unordered_map<const BasicBlock *, std::vector<const BasicBlock *>> dominators_;

public:
    /**
     * Constructs dominator sets from the control flow graph.
     * Uses classic iterative algorithm for that.
     *
     * \param cfg Control flow graph.
     */
    Dominators(const CFG &cfg);

    /**
     * \param basicBlock Valid pointer to a basic block.
     *
     * \return The set of dominators of this basic block.
     */
    const std::vector<const BasicBlock *> &getDominators(const BasicBlock *basicBlock) const {
        assert(basicBlock != NULL);
        assert(nc::contains(dominators_, basicBlock));
        return nc::find(dominators_, basicBlock);
    }
};

} // namespace ir
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
