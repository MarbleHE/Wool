//
// Created by mario on 08.03.20.
//

#ifndef GRANITE_BATCHINGVISITOR_HPP
#define GRANITE_BATCHINGVISITOR_HPP

#include "ast_opt/visitor/Visitor.h"
#include "ast_opt/ast/AbstractExpr.h"
#include "ast_opt/ast/LiteralInt.h"

class BatchingVisitor : Visitor {
private:
    int maxSlots = 1;

    int sndMax = 0;
public:
    void visit(AbstractExpr &elem) override;

    void visit(LiteralInt &elem) override ;

    int getMaxSlots();

    int getSndMaxSlots();

};


#endif //GRANITE_BATCHINGVISITOR_HPP
