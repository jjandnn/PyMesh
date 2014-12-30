#pragma once 
#include <cassert>
#include <functional>
#include <list>
#include <sstream>
#include <queue>
#include <vector>

#include <Core/EigenTypedef.h>
#include <Core/Exception.h>

namespace SymmetryOperators {
    typedef std::vector<std::function<VectorF(const VectorF&)> > Operators;
    typedef std::vector<std::list<size_t> > SymmetryConnectivity;

    template<int DIM>
    Operators generate_reflective_symmetry_operators(const VectorF& center) {
        std::stringstream err_msg;
        err_msg << "Reflective symmetry operation in " << DIM << "D is not supported.";
        throw NotImplementedError(err_msg.str());
    }

    template<int DIM>
    Operators generate_rotational_symmetry_operators(const VectorF& center) {
        std::stringstream err_msg;
        err_msg << "Rotational symmetry operation in " << DIM << "D is not supported.";
        throw NotImplementedError(err_msg.str());
    }

    template<>
    Operators generate_reflective_symmetry_operators<2>(const VectorF& c);

    template<>
    Operators generate_reflective_symmetry_operators<3>(const VectorF& c);

    template<>
    Operators generate_rotational_symmetry_operators<2>(const VectorF& c);

    template<>
    Operators generate_rotational_symmetry_operators<3>(const VectorF& c);

    SymmetryConnectivity compute_vertex_connectivity(
            const MatrixFr& vertices, Operators& ops);

    SymmetryConnectivity compute_edge_connectivity(
            const MatrixFr& vertices, const MatrixIr& edges, Operators& ops);

    VectorI label_connected_components(size_t num_entries,
            const SymmetryConnectivity& connectivity);
}