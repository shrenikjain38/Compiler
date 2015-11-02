#include "AST.h"

enum class BinOp : char {
	plus_op,
	minus_op,
	multiply_op,
	divide_op,
	modulo_op,
	lessthan_op,
	greaterthan_op,
	lessthanequal_op,
	greaterthanequal_op,
	notequal_op,
	and_op,
	or_op
};

enum class Datatype : char {
	int_type,
	void_type,
	bool_type
};

class ASTNode {
public:
	ASTNode();
	~ASTNode();
	void accept() {
	}
};

class ASTProgram : public ASTNode
{
	std::string id;
	std::vector<ASTMethodDecl *> mdl;
	std::vector<ASTFieldDecl *> fdl;
public:
	ASTProgram(std::string id, std::vector<ASTMethodDecl *> mdl, std::vector<ASTFieldDecl *> fdl){
		this->id = id;
		this->mdl = mdl;
		this->fdl = fdl;
	}
	std::string getId(){
		return this->id;
	}
	std::vector<ASTMethodDecl *> getMdl() {
		return this->mdl;
	}
	std::vector<ASTFieldDecl *> getFdl() {
		return this->fdl;
	}
	~ASTProgram();
};

class ASTStatement : public ASTNode
{
public:
	ASTStatement();
	~ASTStatement();
};

class ASTExpression : public ASTNode
{
public:
	ASTExpression();
	~ASTExpression();
};

class ASTFieldDecl
{
	std::vector<std::string> id;
	Datatype type;
public:
	ASTFieldDecl(std::vector<std::string> id, Datatype type){
		this->id = id;
		this->type = type;
	}
	std::vector<std::string> getId() {
		return this->id;
	}
	Datatype getType() {
		return this->type;
	}
	~ASTFieldDecl();
};

class ASTMethodDecl
{
	std::string id;
	Datatype returnType;
	std::vector<ASTVarDecl
public:
	ASTMethodDecl(arguments);
	~ASTMethodDecl();

	/* data */
};

class ASTLocation : public ASTNode
{
	std::string id;
	ASTExpression *expr;  
public:
	ASTLocation(std::string id, ASTExpression *expr) {
		this->id = id;
		this->expr = expr;
	}
	std::string getId() {
		return this->id;
	}
	ASTExpression *getExpr() {
		return this->expr;
	}
	~ASTLocation();
};

class ASTBlockStatement : ASTStatement
{
	std::vector<ASTStatement *> stmtlist;
public:
	ASTBlockStatement(std::vector<ASTStatement *> stmtlist) {
		this->stmtlist = stmtlist;
	}
	std::vector<ASTStatement *> getStmtlist() {
		return this->stmtlist;
	}
	~ASTBlockStatement();
};

// class ASTAssignmentStatement : public ASTStatement
// {
// public:
// 	ASTAssignmentStatement();
// 	~ASTAssignmentStatement();
// };