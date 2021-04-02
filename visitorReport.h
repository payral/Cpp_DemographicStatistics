#ifndef VISITREP_H
#define VISITREP_H

#include "visitor.h"
#include "hospitalData.h"
#include "demogData.h"

class visitorReport
{
    public:
        void visit(const demogData* d) { cout << *d; }
        void visit(const hospitalData* h) { cout << *h; }
        void visit(financeData* f) { cout << *f; }
};

#endif
