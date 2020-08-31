/* expr_ast.h.  Generated automatically by treecc */
#ifndef __yy_expr_ast_h
#define __yy_expr_ast_h
#line 6 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"

#include <string>
#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_map>

using string_t = std::string;

namespace Ast
{
    class AstNode;
    using NodeVector = std::vector<AstNode*>;
    using SymbolTable = std::unordered_map<std::string, int>;
}
#line 21 "expr_ast.h"

#include <new>

namespace Ast
{

const int AstNode_kind = 1;
const int Expr_kind = 2;
const int Stmt_kind = 16;
const int BinaryExpr_kind = 3;
const int NumExpr_kind = 4;
const int IdExpr_kind = 5;
const int AddExpr_kind = 6;
const int SubExpr_kind = 7;
const int MulExpr_kind = 8;
const int DivExpr_kind = 9;
const int GTExpr_kind = 10;
const int LTExpr_kind = 11;
const int GEExpr_kind = 12;
const int LEExpr_kind = 13;
const int EqExpr_kind = 14;
const int NotExpr_kind = 15;
const int AssignStmt_kind = 17;
const int BlockStmt_kind = 18;
const int PrintStmt_kind = 19;
const int IfStmt_kind = 20;
const int WhileStmt_kind = 21;

class AstNode;
class Expr;
class Stmt;
class BinaryExpr;
class NumExpr;
class IdExpr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class GTExpr;
class LTExpr;
class GEExpr;
class LEExpr;
class EqExpr;
class NotExpr;
class AssignStmt;
class BlockStmt;
class PrintStmt;
class IfStmt;
class WhileStmt;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 85 "expr_ast.h"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual const char *currFilename() const;
	virtual long currLinenum() const;

};

class AstNode
{
protected:

	int kind__;
	const char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(const char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	AstNode();

public:

	virtual int eval(SymbolTable & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AstNode();

};

class Expr : public AstNode
{
protected:

	Expr();

public:

	virtual int eval(SymbolTable & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expr();

};

class Stmt : public AstNode
{
protected:

	Stmt();

public:

	virtual int eval(SymbolTable & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Stmt();

};

class BinaryExpr : public Expr
{
protected:

	BinaryExpr(Expr * expr1, Expr * expr2);

public:

	Expr * expr1;
	Expr * expr2;

	virtual int eval(SymbolTable & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpr();

};

class NumExpr : public Expr
{
public:

	NumExpr(int value);

public:

	int value;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class IdExpr : public Expr
{
public:

	IdExpr(string_t id);

public:

	string_t id;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdExpr();

};

class AddExpr : public BinaryExpr
{
public:

	AddExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class SubExpr : public BinaryExpr
{
public:

	SubExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class MulExpr : public BinaryExpr
{
public:

	MulExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinaryExpr
{
public:

	DivExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class GTExpr : public BinaryExpr
{
public:

	GTExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GTExpr();

};

class LTExpr : public BinaryExpr
{
public:

	LTExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LTExpr();

};

class GEExpr : public BinaryExpr
{
public:

	GEExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GEExpr();

};

class LEExpr : public BinaryExpr
{
public:

	LEExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LEExpr();

};

class EqExpr : public BinaryExpr
{
public:

	EqExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqExpr();

};

class NotExpr : public BinaryExpr
{
public:

	NotExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotExpr();

};

class AssignStmt : public Stmt
{
public:

	AssignStmt(string_t id, Expr * expr);

public:

	string_t id;
	Expr * expr;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStmt();

};

class BlockStmt : public Stmt
{
public:

	BlockStmt(NodeVector l);

public:

	NodeVector l;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStmt();

};

class PrintStmt : public Stmt
{
public:

	PrintStmt(Expr * expr);

public:

	Expr * expr;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmt();

};

class IfStmt : public Stmt
{
public:

	IfStmt(Expr * cond, Stmt * true_blk, Stmt * false_blk);

public:

	Expr * cond;
	Stmt * true_blk;
	Stmt * false_blk;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class WhileStmt : public Stmt
{
public:

	WhileStmt(Expr * cond, Stmt * block);

public:

	Expr * cond;
	Stmt * block;

	virtual int eval(SymbolTable & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};



}
#endif
