#ifndef CONSTANT_H
#define CONSTANT_H

namespace Constant{
    enum GLTriangleType{ SELECTED, NOT_SELECTED};

    enum IncludeCase{ NOT_INCLUDED, INCLUDED, BORDER_INCLUDED, CORNER_INCLUDED};

    enum PreProcess{ NONE, EDGE_DIAMETER_CIRCLE};
    enum TriangleSelection{ MANUAL, SMALLEST_INTERNAL_ANGLE, SMALLEST_EDGE, SMALLEST_EDGE_BORDER_TRIANGLE_FIRST};
    enum NewPoint{ BISECTION, CIRCUMCENTER, LEPP_BISECTION, LEPP_CENTROID, LEPP_DELAUNAY, OFF_CENTER};
    enum InsideInsertion{ BASIC_INSERTION, FLIP_DIAGONAL, CAVITY };
    enum OutsideInsertion{ BISECT_LONGEST_EDGE};
    enum OneEdgeRestrictedInsertion{ONE_BASIC_INSERTION};
    enum TwoEdgeRestrictedInsertion{TWO_BASIC_INSERTION};
    enum ThreeEdgeRestrictedInsertion{THREE_NONE};
}

#endif // CONSTANT_H
