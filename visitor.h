#ifndef VISITOR_H
#define VISITOR_H

#include "hospitalData.h"
#include "demogData.h"
#include "financeData.h"

/* a visitor can visit any of my specific data types */
class Visitor
{
    public:
        virtual void visit(const class demogData* d) = 0;
        virtual void visit(const class hospitalData* h) = 0;
        virtual void visit(class financeData* f) = 0;
};

#endif
