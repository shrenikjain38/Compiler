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

enum class AssignOp : char {
	plus_equal,
	minus_equal,
	equal
};

enum class UnOp : char {
	minus_op,
	not_op
};

class ASTNode {
public:
	ASTNode();
	~ASTNode();
	virtual void accept() = 0;
};

class ASTProgram : public ASTNode
{
	std::string id;
	std::vector<ASTFieldDecl *> fdl;
	std::vector<ASTMethodDecl *> mdl;
public:
	ASTProgram(std::string id, std::vector<ASTFieldDecl *> fdl, std::vector<ASTMethodDecl *> mdl){
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
	void accept() {

	}
};

class ASTFieldDecl : public ASTNode
{
	Datatype type;
	std::vector<ASTIdentifier *> id_list;
public:
	ASTFieldDecl(std::vector<ASTIdentifier *> id_list, Datatype type){
		this->type = type;
		this->id_list = id_list;
	}
	std::vector<ASTIdentifier *> getId_list() {
		return this->id_list;
	}
	Datatype getType() {
		return this->type;
	}
	~ASTFieldDecl();
	void accept() {

	}
};

class ASTIdentifier : public ASTNode 
{
public:	
	ASTIdentifier();
	~ASTIdentifier();
	virtual void accept() = 0;
};

class ASTVarIdentifier : public ASTIdentifier
{
	std::string id;
public:
	ASTVarIdentifier(std::string id) {
		this->id = id;
	}
	std::string getId() {
		return this->id;
	}
	~ASTVarIdentifier();
	void accept() {

	}
};

class ASTArrayIdentifier : public ASTIdentifier 
{
	std::string id;
	int size;
public:
	ASTArrayIdentifier(std::string id, int size) {
		this->id = id;
		this->size = size;		
	}
	std::string getId() {
		return this->id;
	}
	int getSize() {
		return this->size;
	}
	~ASTArrayIdentifier();
	void accept() {

	}
};

class ASTMethodDecl : public ASTNode
{
	std::string id;
	Datatype returnType;
	std::vector<ASTTypeIdentifier *> arguments;
	ASTBlockStatement *block;
public:
	ASTMethodDecl(std::string id, Datatype returnType, std::vector<ASTTypeIdentifier *> arguments) {
		this->id = id;
		this->returnType = returnType;
		this->arguments = arguments;
		this->block = block;
	}
	std::string getId() {
		return this->id;
	}
	Datatype getReturnType() {
		return this->returnType;
	}
	std::vector<ASTTypeIdentifier *> getArguments() {
		return this->arguments;
	}
	ASTBlockStatement * getBlock() {
		return this->block;
	}
	~ASTMethodDecl();
	void accept() {

	}
};

class ASTTypeIdentifier : public ASTNode
{
	std::string id;
	Datatype type;
public:
	ASTTypeIdentifier(std::string id, Datatype type) {
		this->id = id;
		this->type = type;
	}
	~ASTTypeIdentifier();
	void accept() {

	}
};

class ASTStatement : public ASTNode 
{
public:
	ASTStatement();
	~ASTStatement();
	virtual void accept() = 0;
};


class ASTExpression : public ASTNode
{
public:
	ASTExpression();
	~ASTExpression();
	virtual void accept() = 0;
};

class ASTBlockStatement : public ASTStatement
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
	void accept() {

	}
};

class ASTAssignmentStatement : public ASTStatement
{
	AssignOp op;
	ASTLocation * location;
	ASTExpression * expr;
public:
	ASTAssignmentStatement(AssignOp op, ASTLocation *location, ASTExpression *expr) {
		this->op = op;
		this->location = location;
		this->expr = expr;
	}
	AssignOp getOp() {
		return this->op;
	}
	ASTLocation * getLocation() {
		return this->location;
	}
	ASTExpression * getExpr() {
		return this->expr;
	}
	~ASTAssignmentStatement();
	void accept() {

	}
};

class ASTMethodCall : public ASTStatement, public ASTExpression 
{
public:
	ASTMethodCall();
	~ASTMethodCall();
	virtual void accept() = 0;
};

class ASTNormalMethod : public ASTMethodCall 
{
	std::string id;
	std::vector<ASTExpression *> arguments;
	ASTBlockStatement * block;
public:
	ASTNormalMethod(std::string id, std::vector<ASTExpression *> arguments, ASTBlockStatement * block) {
		this->id = id;
		this->arguments = arguments;
		this->block = block;
	}
	std::string getId() {
		return this->id;
	}
	std::vector<ASTExpression *> getArguments() {
		return this->arguments;
	}
	ASTBlockStatement * getBlock() {
		return this->block;
	}
	~ASTNormalMethod();
	void accept() {

	}
};

class ASTCalloutMethod : public ASTMethodCall 
{
	std::string id;
	std::vector<ASTExpression *> arguments;
	ASTBlockStatement * block;
	ASTCalloutMethod(std::string id, std::vector<ASTExpression *> arguments, ASTBlockStatement * block) {
		this->id = id;
		this->arguments = arguments;
		this->block = block;
	}
	std::string getId() {
		return this->id;
	}
	std::vector<ASTExpression *> getArguments() {
		return this->arguments;
	}
	ASTBlockStatement * getBlock() {
		return this->block;
	}
	~ASTCalloutMethod();
	void accept() {

	}
};

class ASTIfStatement : public ASTStatement 
{
	ASTExpression * condition;
	ASTBlockStatement * if_block;
	ASTBlockStatement * else_block;
public:
	ASTIfStatement(ASTExpression * condition, ASTBlockStatement * if_block, ASTBlockStatement * else_block) {
		this->condition = condition;
		this->if_block = if_block;
		this->else_block = else_block;
	}
	ASTExpression * getCondition() {
		return this->condition;
	}
	ASTBlockStatement * getIf_block() {
		return this->if_block;
	}
	ASTBlockStatement * getElse_block() {
		return this->else_block;
	}
	~ASTIfStatement();
	void accept() {

	}
};

class ASTForStatement : public ASTStatement 
{
	ASTExpression * init_condition;
	ASTExpression * end_condition;
	ASTBlockStatement * block;
public:
	ASTForStatement(ASTExpression * init_condition, ASTExpression * end_condition, ASTBlockStatement * block) {
		this->init_condition = init_condition;
		this->end_condition = end_condition;
		this->block = block;
	}
	ASTExpression * getInit_condition() {
		return this->init_condition;
	}
	ASTExpression * getEnd_condition() {
		return this->end_condition;
	}
	ASTBlockStatement * getBlock() {
		return this->block;
	}
	~ASTForStatement();
	void accept() {

	}
};

class ASTReturnStatement : public ASTStatement
{
	ASTExpression * return_expr;
public:
	ASTReturnStatement(ASTExpression * return_expr) {
		this->return_expr = return_expr
	}
	ASTExpression * getReturn_expr() {
		return this->return_expr;
	}
	~ASTReturnStatement();
	void accept() {

	}
};

class ASTContinueStatement : public ASTStatement
{
public:
	ASTContinueStatement();
	~ASTContinueStatement();
	void accept() {

	}
};

class ASTBreakStatement : public ASTStatement
{
public:
	ASTBreakStatement();
	~ASTBreakStatement();
	void accept() {
		
	}
};

class ASTLocation : public ASTNode
{
public:
	ASTLocation();
	~ASTLocation();
	void accept() = 0;
};

class ASTVarLocation : public ASTLocation 
{
	std::string id;
public:
	ASTVarLocation(std::string id) {
		this->id = id;
	}
	std::string getId() {
		return this->id;
	}
	~ASTVarLocation();
	void accept() {

	}
};

class ASTArrayLocation : public ASTLocation
{
	std::string id;
	ASTExpression * index;
public:
	ASTArrayLocation(std::string id, ASTExpression * index) {
		this->id = id;
		this->index = index;
	}
	std::string getId() {
		return this->id;
	}
	ASTExpression * getIndex() {
		return this->index;
	}
	~ASTArrayLocation();
	void accept() {

	}
};

class ASTLiteralExpression : public ASTExpression
{
public:
	ASTLiteralExpression();
	~ASTLiteralExpression();
	virtual void accept() = 0;
};

class ASTIntegerLiteralExpression : public ASTLiteralExpression
{
	int value;
public:
	ASTIntegerLiteralExpression(int value) {
		this->value = value;
	}
	int getValue() {
		return this->value;
	}
	~ASTIntegerLiteralExpression();
	void accept() {

	}
};

class ASTCharLiteralExpression : public ASTLiteralExpression
{
	char value;
public:
	ASTCharLiteralExpression(char value) {
		this->value = value;
	}
	char getValue() {
		return this->value;
	}
	~ASTCharLiteralExpression();
	void accept() {

	}
};

class ASTTrueLiteralExpression : public ASTLiteralExpression
{
public:
	ASTTrueLiteralExpression();
	bool getValue() {
		return true;
	}
	~ASTTrueLiteralExpression();
	void accept() {

	}
};

class ASTFalseLiteralExpression : public ASTLiteralExpression
{
public:
	ASTFalseLiteralExpression();
	bool getValue() {
		return false;
	}
	~ASTFalseLiteralExpression();
	void accept() {

	}
};

class ASTBinaryOperationExpression : public ASTExpression
{
	ASTExpression * left;
	ASTExpression * right;
	BinOp op;
public:
	ASTBinaryOperationExpression(ASTExpression * left, ASTExpression * right, BinOp op) {
		this->left = left;
		this->right = right;
		this->op = op;
	}
	ASTExpression * getLeft() {
		return this->left;
	}
	ASTExpression * getRight() {
		return this->right;
	}
	BinOp getOp() {
		return this->op;
	}
	~ASTBinaryOperationExpression();
	void accept() {

	}
};

class ASTUnaryOperationExpression : public ASTExpression
{
	ASTExpression * expr;
	UnOp op;
	ASTUnaryOperationExpression(ASTExpression * expr, UnOp op) {
		this->expr = expr;
		this->op = op;
	}
	ASTExpression * getExpr() {
		return this->expr;
	}
	UnOp getOp () {
		return this->op;
	}
	~ASTUnaryOperationExpression();
};