//
// Created by Mario Stöckli on 06.04.20.
//

#ifndef GRANITE_PARAMETERVISITOR_HPP
#define GRANITE_PARAMETERVISITOR_HPP

#include "ast_opt/visitor/Visitor.h"
#include "ast_opt/ast/Dimension.h"
#include "ast_opt/ast/LiteralInt.h"
#include "ast_opt/ast/Matrix.h"
#include "ast_opt/ast/LogicalExpr.h"
#include "ast_opt/ast/UnaryExpr.h"
#include "ast_opt/ast/AbstractBinaryExpr.h"
#include "ast_opt/ast/ArithmeticExpr.h"
#include "ast_opt/ast/AbstractExpr.h"
#include "ast_opt/ast/OpSymbEnum.h"

class ParameterVisitor: Visitor {
private:
    int maxSlots = 1;

    int sndMax = 0;

    int opcount = 0;

    int multCount = 0;
public:
    void visit(AbstractExpr &elem) override;

    void visit(LogicalExpr &elem) override;

    void visit(UnaryExpr &elem) override;

    void visit(ArithmeticExpr &elem) override;

    void visit(LiteralInt &elem) override ;

    int getMaxSlots();

    int getSndMaxSlots();

    int getMultCount();

    int getOpCount();

};

#endif //GRANITE_PARAMETERVISITOR_HPP
