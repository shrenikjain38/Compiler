#include "AST.h"

class Visitor
{
public:
	virtual void visit(ASTProgram*) = 0;
	virtual void visit(ASTFieldDecl*) = 0;
	virtual void visit(ASTMethodDecl*) = 0;
	virtual void visit(ASTIdentifier*) = 0;
	virtual void visit(ASTVarIdentifier*) = 0;
	virtual void visit(ASTArrayIdentifier*) = 0;
	virtual void visit(ASTTypeIdentifier*) = 0;
	virtual void visit(ASTStatement*) = 0;
	virtual void visit(ASTBlockStatement*) = 0;
	virtual void visit(ASTLocation*) = 0;
	virtual void visit(ASTExpression*) = 0;
	virtual void visit(ASTAssignmentStatement*) = 0;
	virtual void visit(ASTMethodCall*) = 0;
	virtual void visit(ASTNormalMethod*) = 0;
	virtual void visit(ASTCalloutMethod*) = 0;
	virtual void visit(ASTIfStatement*) = 0;
	virtual void visit(ASTForStatement*) = 0;
	virtual void visit(ASTReturnStatement*) = 0;
	virtual void visit(ASTVarLocation*) = 0;
	virtual void visit(ASTArrayLocation*) = 0;
	virtual void visit(ASTContinueStatement*) = 0;
	virtual void visit(ASTBreakStatement*) = 0;
	virtual void visit(ASTLiteralExpression*) = 0;
	virtual void visit(ASTIntegerLiteralExpression*) = 0;
	virtual void visit(ASTCharLiteralExpression*) = 0;
	virtual void visit(ASTTrueLiteralExpression*) = 0;
	virtual void visit(ASTFalseLiteralExpression*) = 0;
	virtual void visit(ASTBinaryOperationExpression*) = 0;
	virtual void visit(ASTUnaryOperationExpression*) = 0;
};


