#ifndef CONSTANT_H
#define CONSTANT_H

namespace Constant{

    enum GLTriangleType{ SELECTED,
                         NOT_SELECTED};
    enum IncludeCase{ NOT_INCLUDED,
                      INCLUDED,
                      BORDER_INCLUDED,
                      CORNER_INCLUDED};
    enum PreProcess{ NO_PREPROCESS,
                     FIX_ENCROACHED_VERTEXS};

    extern char *preProcessNames[];

    enum TriangleSelection{ NO_PRIORITY,
                            SMALLEST_INTERNAL_ANGLE,
                            SMALLEST_EDGE,
                            SMALLEST_ANGLE_CONSTRAINED_EDGE_FIRST,
                            SMALLEST_CIRCUMCIRCLE,
                            LONG_EDGE_ONLY_BORDER};

    extern char *triangleSelectionNames[];

    enum NewPoint{ LEPP_BISECTION,
                   RUPPERT,
                   LEPP_DELAUNAY,
                   LEPP_CENTROID,
                   UNGOR,
                   LEPP_CIRCUMCENTER};

    extern char *newPointNames[];

    enum InsideInsertion{ BASIC,
                          FLIP_DIAGONAL,
                          CAVITY };

    extern char *insertionNames[];

    enum RecoveryRestrictionAlgorithm{  NO_RECOVERY,
                                        STITCHING,
                                        COMPLETE};

    const double pi =  3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127;
}

#endif // CONSTANT_H
